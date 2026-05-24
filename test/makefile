src = ../cmd.c
flags = -Wall

all:
	gcc -o a.exe main.c $(src) $(flags)
	./a.exe

	gcc -o b.exe long.c $(src) $(flags) -D'cmd_bbuf_ptr_t=uint16_t'
	./b.exe


test:
	gcc -o a.exe main.c $(src) $(flags)
	./a.exe

long:
	gcc -o b.exe long.c $(src) $(flags) -D'cmd_bbuf_ptr_t=uint16_t'
	./b.exe


