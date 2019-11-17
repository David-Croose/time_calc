all:
	gcc -Wall -O0 -g -o demo.exe demo.c ti.c
clean:
	rm -f demo.exe

