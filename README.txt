README: Group 4, Nick Cleary and Matty Jester
Project Description: In this project, we created a customized verison of the ls command in unix, called "myls". It can be run either on its own, with a directory input, a flag to let it know which way to sort, or with both a directory and flag given. It outputs a list of the files in a given directory in the specified order.

Group Member Contributions: the contributions to this project were 50/50 on the part of both Nick and Matty. We both worked on all portions of the project, and built off each other and learned from each other's mistakes.

To compile the code, use the command "make". 
Next, enter the command in the format: ./myls [directory] [flag] where [directory] can be any valid directory on the system, and [flag] is either "-f" or "-b", with -f sorting the files in ascending alphabetical order, and -b sorting in descending alphabetical order.

An example test run using all of these options is:

spirit:~/Project3% make
gcc -o myls myls.c stringout.c -I.c
spirit:~/Project3% ./myls /home/student/nicleary/Project3 -b
Sorted: 
stringout.h
stringout.c
myls.h
myls.c
myls
makefile
README.txt

There are currently no known bugs in this program.
