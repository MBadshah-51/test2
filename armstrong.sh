#!/bin/bash

echo "Enter a number to check for armstrong number : "
read num

sum=0


while [ $num -ne 0 ] ;
do
	r=$(($num % 10))
	sum=$(($sum + $r * $r * $r))
	num=$(( $num / 10))
done

if [ $sum -eq $num ]; then
		echo "The number is Armstrong Number"
else
		echo "The number is not an Armstrong Number"
fi 

_____________________________________________________________________________

Output:
	badshah@mujahid-Predator--5PH3151:~$ sh armstrong.sh
Enter a number to check for armstrong number : 
153
The number is not an Armstrong Number

badshah@mujahid-Predator--5PH3151:~$ sh armstrong.sh
Enter a number to check for armstrong number : 
143
The number is not an Armstrong Number
______________________________________________________________________________
