#!/bin/bash

# pCPU
CperS=$(lscpu | grep "Core(s)" | cut -d ":" -f2 | tr -d " ")
socket=$(lscpu | grep "Socket(s)" | cut -d ":" -f2 | tr -d " ")
pcpu=$(($CperS * $socket))

# Memory
allram=$(free -m | grep 'Mem' | awk -F' ' '{print $2}')
useram=$(free -m | grep 'Mem' | awk -F' ' '{print $3}')
numram=$(printf "%.2f" "$(($useram * 10000 / $allram))e-2")
unitram="$allram"MB

# Disk Usage
diskuse=$(df -m / | tail -1 | awk -F' ' '{print $3}')
diskfree=$(df -h / | tail -1 | awk -F' ' '{print $4}')
diskpercent=$(df -h / | tail -1 | awk -F' ' '{print $5}')

# CPU Usage
cpuidle=$(mpstat | grep 'all' | awk -F' ' '{print $13}')
cpu_num1=$(cut -d '.' -f1 <<< $cpuidle)
cpu_num2=$(cut -d '.' -f2 <<< $cpuidle)
cpu_num3=$(($cpu_num1 * 100 + $cpu_num2))
cpu_num3=$((10000 - $cpu_num3))
cpuuse=$(printf "%.1f" "$(($cpu_num3))e-2")

# Last reboot
date=$(who -b | awk -F' ' '{print $3}')
time=$(who -b | awk -F' ' '{print $4}')

# LVM
lvm=$(lsblk | grep "LVM")
if [ "$lvm" != "" ]; then
	lvmtrue="yes"
else
	lvmtrue="no"
fi

# User
line=$(who -q | head -1)
line1=$(cut -d ' ' -f1 <<< $line)
line2=""
user_i=2
user_c=0
while [ "$line1" != "" ]
do
	user_check=$(grep $line1 <<< $line2)
	if [ "$user_check" == "" ]; then
		line2="$line2 $line1"
		user_c=$(($user_c + 1))
	fi
	line1=$(cut -d ' ' -f $user_i <<< $line)
	user_i=$(($user_i + 1))
done

# IP4 + MAC
ipv4=$(hostname -I)
mor_mac=$(ip addr show enp0s3 | grep "ether" | awk -F' ' '{print $2}')

# sudo
sd=$(cat /var/log/sudo/sudo.log | grep "COMMAND" | wc -l)

wall "#Architecture: $(uname -a)
#CPU physical : $pcpu
#vCPU : $(nproc)
#Memory Usage: $useram/$unitram ($numram%)
#Disk Usage: $diskuse/$diskfree ($diskpercent)
#Cpu load: $cpuuse%
#Last boot: $date $time
#LVM use: $lvmtrue
#Connection TCP : $(netstat | grep "tcp" | wc -l) ESTABLISHED
#User log: $user_c
#Network: IP $ipv4 ($mor_mac)
#Sudo : $sd cmd
" 
