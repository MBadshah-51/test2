
#!/bin/bash
ch=0
while [ $ch -ne 5 ] ; do
	echo "-----------------------------------------------------------"
	echo " MENU
	1.Length
	2.Copy
	3.Concatenation
	4.Equality
	5.Exit"
	read -p "Enter your choice : " ch
	case $ch in
		1)
			echo "Enter string : "
			read str
			echo "\nLength of string $str is ${#str}"
			;;
		2)	
			echo "Enter the string : "
			read str
			str2="abc"
			echo "\nBefore copying:\nStr1 = $str\nStr2 = $str2"
			str2=$str
			echo "\nAfter copying Str1 to Str2: \nStr1 = $str\nStr2 = $str2"
			;;
		3)
			echo "Give strings to concatenate : "
			read -p "String 1 : " str1
			read -p "String 2 : " str2
				constr=$str1$str2
			echo "\nstring after concatenation is $constr"
			;;
		4)
			echo "Enter the strings"
			read -p "String 1 : " str1
			read -p "String 2 : " str2
			echo
			if ( test $str1 = $str2 )
			then 
				echo "\nStrings are equal"
			else 
				echo "\nStrings are not equal"
			fi
			;;
		5)
			echo "Program Ending...!!!"
			return
			;;
		*)
			echo "Wrong choice!"
			;;
	esac
done

__________________________________________________________________________________________________
Output:

badshah@mujahid-Predator--5PH3151:~$ sh string.sh
-----------------------------------------------------------
 MENU
	1.Length
	2.Copy
	3.Concatenation
	4.Equality
	5.Exit
Enter your choice : 1
Enter string : 
mujahid

Length of string mujahid is 7
-----------------------------------------------------------
 MENU
	1.Length
	2.Copy
	3.Concatenation
	4.Equality
	5.Exit
Enter your choice : 2
Enter the string : 
mujahid

Before copying:
Str1 = mujahid
Str2 = abc

After copying Str1 to Str2: 
Str1 = mujahid
Str2 = mujahid
-----------------------------------------------------------
 MENU
	1.Length
	2.Copy
	3.Concatenation
	4.Equality
	5.Exit
Enter your choice : 3
Give strings to concatenate : 
String 1 : mujahid 
String 2 : badshah

string after concatenation is mujahidbadshah
-----------------------------------------------------------
 MENU
	1.Length
	2.Copy
	3.Concatenation
	4.Equality
	5.Exit
Enter your choice : 4
Enter the strings
String 1 : abcd
String 2 : asdf


Strings are not equal
-----------------------------------------------------------
 MENU
	1.Length
	2.Copy
	3.Concatenation
	4.Equality
	5.Exit
Enter your choice : 4
Enter the strings
String 1 : asdf
String 2 : asdf


Strings are equal
-----------------------------------------------------------
 MENU
	1.Length
	2.Copy
	3.Concatenation
	4.Equality
	5.Exit
Enter your choice : 5
Program Ending...!!!
badshah@mujahid-Predator--5PH3151:~$ 

