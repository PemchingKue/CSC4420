#! /bin/bash

echo -e "Enter current process ID: \c "
read num
echo `pstree -pls $num`
