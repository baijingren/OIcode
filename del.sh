#!/bin/bash
function getdir(){
    for element in `ls $1`
    do  
        dir_or_file=$1"/"$element
        if [ -d $dir_or_file ]
        then 
            getdir $dir_or_file
        else
            if [ -x $dir_or_file ]
            then rm $dir_or_file
            fi
        fi  
    done
}
root_dir="/home/bai/code"
getdir $root_dir