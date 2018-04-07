#!/bin/bash


NowTime=`date +"%Y-%m-%d__%H:%M:%S"`
#echo "Time:${NowTime}" >> MEMLog
TotalMem=`free -m | grep Mem | awk '{printf $2}'`
#echo "Total${TotalMem}M" >> MEMLog
AvailableMem=`free -m | grep Mem | awk '{printf $7}'`
#echo "Available${AvailableMem}M" >> MEMLog
AvgUsePer=`free -m | grep Mem | awk '{print($7/$2*100)}'`
#echo "AvgUsePer${AvgUsePer}%" >> MEMLog
LastUsePer=`free -m | grep Mem | awk '{print($7/$2*100*0.8)}'`
#echo "$LastUsePer"

for((i=1;i<=5;i++))
do
    echo "wait...";
    sleep 1
done

NewUsePer=`free -m | grep Mem | awk '{print($7/$2*100*0.2)}'`
#echo "$NewUsePer"

DynaUsePer=`echo "$NewUsePer+$LastUsePer" | bc`
#echo "DynaUsePer:${DynaUsePer}%" >> MEMLog
echo "$NowTime ${TotalMem}M ${AvailableMem}M ${AvgUsePer}% ${DynaUsePer}%" >> Mem.log
