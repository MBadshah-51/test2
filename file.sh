#!/bin/bash
x=1
t=1
while [ $x -ne 6 ];do
echo "Menu 
 1.Create\n 2.Display\n 3.Search\n 4.Append\n 5.Delete\n 6.Modify\n 7.Exit."
echo "Enter your choice: "
read ch
case $ch in
	1) echo "Enter filename: "
		read filename
		echo "Enter contents of file"
		echo "Enter Roll no and Name: "

		cat >> $filename.txt;;

	2) echo "Enter filename:"
	   read filename
	   if [ -s $filename.txt ]; then
	   	echo "File exists"
	   	echo " ROLLNO. NAME"
		   cat $filename.txt
	   else
		   echo "File does not exist!"
	   fi;;
	   	  
	3) echo "Enter filename  to search"
		read filename
		if [ -s $filename.txt ]; then
			echo "File exists"
			echo "Enter record name:"
			read a
			echo "Record : "
			grep $a $filename.txt
			
		else
			echo "File does not exist!"
		fi
		;;
		
	4) echo "Enter file name to be appended: "
		read filename
		if [ -s $filename.txt ]; then
			echo "File exists"
			echo " Enter data to append: "
			cat >> $filename.txt
		else
			echo "File does not exist!"
		fi
		;;

	5) echo "Enter file name : "
		read filename
		if [ -s $filename.txt ]; then
			echo "File exists"
			echo "Enter data that you want to delete"
			read c
			grep  $c $filename.txt -v | cat >> $z.txt
			mv $z.txt $filename.txt
		
		else
			echo "File does not exist!"
		fi
		;;

	6) echo "Enter filename that you want to edit\n"
	    read filename
	    if [ -s $filename.txt ]; then
			echo "file exists"
			echo "Enter data that you want to modify"
			read d
			echo "Enter the new data : \n"
			read e
			sed 's/$d/$e/g' $filename.txt 

		else
			echo "File does not exist!"
		fi
		;;
		
	7) echo "Program ending...!!!"
	return 
	;;
	
	*) echo "Wrong choice!"
	;;

esac
done

