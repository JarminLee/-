#!/bin/bash

NowTime=`date +"%Y-%m-%d__%H:%M:%S"`
#echo "时间：${Time}"

#TotalValue=`df -m | grep -v tmpfs | tail -n 2 | awk -v sum=0 '{sum=sum+$2} END {printf("%d\n", sum)}'`
#echo "0 disk ${TotalValue}M "
#echo `df -T -x tmpfs -m -x devtmpfs | tail -n +2 | awk '{printf("1 / %d %d %d %s    ", $3, $5, $6, $7);}'`

eval $(df -T -m -x tmpfs -x devtmpfs | tail -n +2 | grep "dev" | \
    awk -v DiskSum=0 -v LeftSum=0 '{printf("paramount["NR"]=%d;parleft["NR"]=%d;parname["NR"]=%s;\
    usedperc["NR"]=%s;", $3, $5, $7, $6);DiskSum=DiskSum+$3;LeftSum=LeftSum+$5}\
    END {printf("parnum=%d;DiskSum=%d;LeftSum=%d", NR, DiskSum, LeftSum)}')

for (( i = 1; i <= $parnum; i++ ));
do
    echo "$NowTime 1 ${parname[$i]} ${paramount[$i]} ${parleft[$i]}\
        ${usedperc[$i]}" >> Disk.Log
done
UsedPercSum=$[ 100-$LeftSum*100/$DiskSum ]
echo "$NowTime 0 disk $DiskSum $LeftSum ${UsedPercSum}%" >> Disk.Log
echo " " >> Disk.Log

