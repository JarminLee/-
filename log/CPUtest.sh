#!/bin/bash


#source ./PiHealth.conf

NowTime=`date +"%Y-%m-%d__%H:%M:%S"`
#echo $NowTime
LoadAvg=`cut -d " " -f 1-3 /proc/loadavg`
#echo $LoadAvg
CPUTemp=50
#CPUTemp=`echo "scale=2;$CPUTemp/1000" | bc` #管道前的字符串不能有换行, 
#echo $CPUTemp
eval $(head -n 1 /proc/stat | awk -v sum1=0 -v idle1=0 \
    '{for (i=2;i<=8;i++) {sum1=sum1+$i} printf("sum1=%d;idle1=%d;", sum1, $5)}'
    ) #eval 将后面的内容当成shell的
#echo $sum1

sleep 0.5

eval $(head -n 1 /proc/stat | awk -v sum2=0 -v idle2=0 \
    '{for (i=2;i<=8;i++) {sum2=sum2+$i} printf("sum2=%d;idle2=%d;", sum2, $5)}'
    )

CPUUsePerc=`echo "scale=4;(1-($idle1-$idle2)/($sum1-$sum2))*100" | bc`
    
CPUUsePerc=`printf "%.2f\n" $CPUUsePerc`

WarnLevel="normal"
if [[ `echo $CPUTemp '>=' 85 | bc -l` = 1 ]]; then #if中括号里的语句需要前后空一格
    WarnLevel="fault"
elif [[ `echo $CPUTemp '>=' 70 | bc -l` = 1 ]]; then
    WarnLevel="warning"
elif [[ `echo $CPUTemp '>=' 50 | bc -l` = 1 ]]; then
    WarnLevel="note"
fi

echo "$NowTime $LoadAvg ${CPUUsePerc}% ${CPUTemp}℃  $WarnLevel" >> CPU.log


