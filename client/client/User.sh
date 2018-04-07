#!/bin/bash
NowTime=`date +'%Y-%m-%d__%H:%M:%S'`
#echo $NowTime
eval 'cd /home/haizei'
eval 'cd /etc'
UnUser=` awk -F: -v sum=0 'BEGIN {printf("Here Begin:\n")}{if($3 >= 1000 && $3 != 65534) {sum++;printf("User["sum"]=%s\n", $1)}} END {print sum}' passwd `
#echo $UnUser

ActiveUser=`last | grep -v "reboot" | grep -v "wtmp" | cut -d " " -f 1 | sort | uniq -c | sort -r | head -3`
#echo $ActiveUser

eval 'cd /home/haizei'
eval 'cd /etc'
RootUser=` awk -F: -v sum=0 'BEGIN {printf("Here Begin:\n")}{if($3 == 0 && $4 == 0) {sum++;printf("User["sum"]=%s\n", $1)}} END {print sum}' passwd `
#echo $RootUser

OnlineUser=`w | tail -n +3 |awk '{printf("%s_%s_%s", $1, $3, $2)}'`
echo $NowTime $UnUser $OnlineUser $ActiveUser $RootUser



