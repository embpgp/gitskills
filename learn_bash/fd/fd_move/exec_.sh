#!/bin/bash

exec 3< /etc/passwd  #let the fd 3 pointer "/etc/passwd"
exec 0<&3            
cat


exec 3>&-

exec 3> /tmp/stdout
exec 4> /tmp/stderr

exec 1>&3-
exec 2>&4-

find /etc/ -name "passwd"

exec 3>&-
exec 4>&-
