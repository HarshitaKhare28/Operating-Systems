# shellscript, commands
!#bin/bash
echo " Number of cpu processors"
nproc
echo " Number of cores"
cat /proc/cpuinfo | grep 'cpu cores'
cd /proc
echo "Total Memory"
cat /proc/meminfo | grep MemTotal
cd /proc
echo "Free Memory"
cat /proc/meminfo | grep MemFree
cd /proc
echo "Frequencies"
cat /proc/cpuinfo | grep MHz
echo "Number of forks"
vmstat -f
echo "Context Switches"
cat /proc/stat | grep ctxt
