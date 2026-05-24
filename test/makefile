src = ../cmd.c ../cmd_dbg.c
flags = -Wall

all:
	gcc -o a.exe main.c $(src) $(flags)
	./a.exe

	gcc -o b.exe long.c $(src) $(flags) -D'cmd_bbuf_ptr_t=uint16_t'
	./b.exe

	gcc -o c.exe tx.c $(src) $(flags)
	./c.exe

test:
	gcc -o a.exe main.c $(src) $(flags)
	./a.exe

long:
	gcc -o b.exe long.c $(src) $(flags) -D'cmd_bbuf_ptr_t=uint16_t'
	./b.exe

tx:
	gcc -o c.exe tx.c $(src) $(flags)
	./c.exe
