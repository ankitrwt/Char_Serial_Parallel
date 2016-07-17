#!/bin/bash

dmsg()
{
	echo "demsg(y/n)?\c"
	read dms
	if [ $dms = y ]
	then
		dmesg
	fi
}


make

echo "Insert(y/n)?\c"
read ins
if [ $ins = y ]
then
	insmod modules/lkm.ko
	lsmod | head -n2
	dmsg
	echo "run app(y/n)?\c"
	read run
	if [ $run = y ]
	then
		make -C ./apps
		./apps/app
	fi
	dmsg
else
	echo "Do u want to edit?(y/n)\c"
	read edt
	if [ $edt = y ]
	then
		exit
	fi
fi


echo "remove mod(y/n)?\c"
read rmv
if [ $rmv = y ]
then
	rmmod lkm
fi


