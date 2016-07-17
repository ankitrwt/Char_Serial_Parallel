#!/bin/bash

dmsg()
{
	echo "demsg[y/n]?"
	read dms
	if [ $dms = y ]
	then
		dmesg
	fi
}


make

echo "Insert[y/n]?"
read ins
if [ $ins = y ]
then
	insmod modules/lkm.ko
	lsmod | head -n2
	dmsg
	echo "run write.c[y/n]?"
	read run
	if [ $run = y ]
	then
		make write
		./write
	fi
	dmsg
	echo "run read.c[y/n]?"
	read run
	if [ $run = y ]
	then
		make read
		./read
	fi
	dmsg
else
	echo "Do u want to edit?[y/n]"
	read edt
	if [ $edt = y ]
	then
		exit
	fi
fi


echo "remove mod[y/n]?"
read rmv
if [ $rmv = y ]
then
	rmmod lkm
fi


