#Makefile for my_shell

my_shell: main.o get_line.o parser.o command_table.o simple_command_tokens.o get_path.o memory_free.o
	gcc -o my_shell main.o get_line.o parser.o command_table.o simple_command_tokens.o get_path.o memory_free.o

main.o: main.c
	gcc -c main.c

get_line.o: get_line.c
	gcc -c get_line.c

parser.o: parser.c
	gcc -c parser.c

command_table.o: command_table.c
	gcc -c command_table.c 

simple_command_tokens.o: simple_command_tokens.c
	gcc -c simple_command_tokens.c

get_path.o: get_path.c
	gcc -c get_path.c


clean:
	rm -f *.o my_shell