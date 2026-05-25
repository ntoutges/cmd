src = ../cmd.c ../cmd_dbg.c ../cmd_str.c
flags = -Wall

all:
	gcc -o a.exe main.c $(src) $(flags)
	./a.exe

	gcc -o b.exe long.c $(src) $(flags) -D'cmd_bbuf_ptr_t=uint16_t'
	./b.exe

	gcc -o c.exe tx.c $(src) $(flags)
	./c.exe

	gcc -o d.exe ftoa.c $(src) $(flags)
	./d.exe

	gcc -o e.exe itoa.c $(src) $(flags)
	./e.exe

test:
	gcc -o a.exe main.c $(src) $(flags)
	./a.exe

long:
	gcc -o b.exe long.c $(src) $(flags) -D'cmd_bbuf_ptr_t=uint16_t'
	./b.exe

tx:
	gcc -o c.exe tx.c $(src) $(flags)
	./c.exe

ftoa:
	gcc -o d.exe ftoa.c $(src) $(flags)
	./d.exe

itoa:
	gcc -o e.exe itoa.c $(src) $(flags)
	./e.exe