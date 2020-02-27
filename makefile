myexec: myls.c myls.h stringout.c stringout.h
	gcc -o myls myls.c stringout.c -I.c