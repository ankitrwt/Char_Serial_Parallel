#! /bin/bash
insert()
{ 
	if ( make )
	then
		echo "Do you want to insert the module? [y/n]"
		read choice 
		if [ $choice = 'y' ]
		then
			sudo insmod modules/lkm.ko nod=$1
			lsmod | grep lkm
			read
			dmesg
			read
			echo "Enter majorno:"
			read m
			sudo mknod /dev/scull_char_dev c $m 0
			echo "ls -l /dev/scull_char_dev"
			sudo ls -l /dev/scull_char_dev
			read
		fi
	else
		echo "make failed.. please check for build errors"
		exit
	fi
}

remove()
{
	echo "Do you want to remove the module? [y/n]"
	read choice 
	if [ $choice = 'y' ]
	then
		lsmod | grep lkm
		read
		sudo rmmod lkm
		dmesg
		echo "Cleaning & Removing now..."
		make clean
		echo "Removing /dev/scull_char_dev.."
		sudo rm /dev/scull_char_dev
	fi
}

commit() 
{
	echo "Do you want to commit the module? [y/n]"
	read choice 
	if [ $choice = 'y' ]
	then
		git log
		read
		git add '*.c'
		git add '*.h'
		git status
		read
		echo "Please enter your comments for this commit: "
		read comment
		git commit -m $comment
		git log
		read
		git status
		read
	fi
}

edit() 
{
	echo "Do you want to edit this module? [y/n]"
	read choice 
	if [ $choice = 'y' ]
	then
		make clean
		git status
		read
		git add '*.c'
		git add '*.h'
		git add 'Makefile'
		git add '*.sh'
		read
	fi
}

online() 
{
	echo "Do you want to commit online? [y/n]"
	read choice
	if [ $choice = 'y' ]
	then
		echo "master / dev"
		read branch
		git push -u origin $branch
		echo "Check: https://github.com/amiteshunique/char_driver"
	fi
	
}

writer() 
{
	if [ cc -o writer writer.c ]
	then 
		echo "Compiation of writer was success"
		sudo ./writer
	else
		echo "Compiation of writer had problems"
	fi
	
}
echo "Starting the script:"
if [ $1 = 'o'  ]
then
	online
	exit
fi
echo "Making the module now.."
if [ $1 = '']
then 
	insert 1
else
	insert $1
fi
cc -o writer writer.c
sudo ./writer
read
dmesg
read
cc -o reader reader.c
sudo ./reader
read
dmesg
read
remove 
#commit
#edit




