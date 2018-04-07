#!/bin/bash
NowTime=`date +'%Y-%m-%d__%H:%M:%S'`
echo $NowTime
HostName=`hostname`
echo $HostName
OSName=`cat /etc/issue | awk '{print($1, $2, $3)}'`
echo $OSName
CoreName=`uname -a | awk '{print($1, $2, $3)}'`
echo $CoreName
RunTime=`uptime | awk '{print($2, $3)}'`
echo $RunTime
LoadAvg=`uptime | awk '{print($8, $9, $10)}'`
echo $LoadAvg

eval $(df -T -m -x tmpfs -x devtmpfs | tail -n +2 | grep "dev" | \
    awk -v DiskSum=0 -v LeftSum=0 '{printf("paramount["NR"]=%d;parleft["NR"]=%d;parname["NR"]=%s;\
    usedperc["NR"]=%s;", $3, $5, $7, $6);DiskSum=DiskSum+$3;LeftSum=LeftSum+$5}\
    END {printf("parnum=%d;DiskSum=%d;LeftSum=%d", NR, DiskSum, LeftSum)}')


DiskUsedPerc=$[ 100-$LeftSum*100/$DiskSum ]
echo "${DiskSum}M ${DiskUsedPerc}%"

TotalMem=`free -m | grep Mem | awk '{printf $2}'`
MemUsePerc=`free -m | grep Mem | awk '{print($7/$2*100)}'`
echo "${TotalMem}M ${MemUsePerc}%"

#eval $(free -m | grep Mem | awk -v MemAvg=0 '{MemAvg=$7/$2*100} {printf("%.2f", MemAvg)}')
#echo $MemAvg

CPUTemp=50
eval $(head -n 1 /proc/stat | awk -v sum2=0 -v idle2=0 \
    '{for (i=2;i<=8;i++) {sum2=sum2+$i} printf("sum2=%d;idle2=%d;", sum2, $5)}'
    )

CPUUsePerc=`echo "scale=4;(1-($idle1-$idle2)/($sum1-$sum2))*100" | bc`
    
CPUUsePerc=`printf "%.2f\n" $CPUUsePerc`



DiskWarnLevel="normal"
if [[ `echo $DiskUsedPerc '>' 90 | bc -l` = 1 ]]; then #if中括号里的语句需要前后空一格
    DiskWarnLevel="warning"
elif [[ `echo $DiskUsedPerc '>' 80 | bc -l` = 1 ]]; then
    DiskWarnLevel="note"
fi
#echo $DiskWarnLevel

MemWarnLevel="normal"
if [[ `echo $MemUsePerc '>' 80 | bc -l` = 1 ]]; then #if中括号里的语句需要前后空一格
    MemWarnLevel="warning"
elif [[ `echo $MemUsePerc '>' 70 | bc -l` = 1 ]]; then
    MemWarnLevel="note"
fi
#echo $MemWarnLevel

CPUWarnLevel="normal"
if [[ `echo $CPUUsePerc '>' 80 | bc -l` = 1 ]]; then #if中括号里的语句需要前后空一格
    CPUWarnLevel="warning"
elif [[ `echo $CPUUsePerc '>' 70 | bc -l` = 1 ]]; then
    CPUWarnLevel="note"
fi 
echo $DiskWarnLevel $MemWarnLevel $CPUWarnLevel


