#!/bin/bash

exec 3< /etc/passwd

mapfile -u 3 passwd 

exec 3<&-

echo ${#passwd}

for ((i=0;i<${#passwd};++i))
do
	echo ${passwd[$i]}
done
