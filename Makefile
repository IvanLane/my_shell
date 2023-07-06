#Makefile for my_shell

my_shell: main.o get_line.o check_symbols.o number_of_command.o parser.o command_table.o simple_command_tokens.o get_path.o exec_command.o memory_free.o
	gcc -o my_shell main.o get_line.o check_symbols.o number_of_command.o parser.o command_table.o simple_command_tokens.o get_path.o exec_command.o memory_free.o

main.o: main.c
	gcc -c main.c

check_symbols.o: check_symbols.c
	gcc -c check_symbols.c

get_line.o: get_line.c
	gcc -c get_line.c

number_of_command.o: number_of_command.c
	gcc -c number_of_command.c

parser.o: parser.c
	gcc -c parser.c

command_table.o: command_table.c
	gcc -c command_table.c 

simple_command_tokens.o: simple_command_tokens.c
	gcc -c simple_command_tokens.c

get_path.o: get_path.c
	gcc -c get_path.c

exec_command.o: exec_command.c
	gcc -c exec_command.c

memory_free.o: memory_free.c
	gcc -c memory_free.c

clean:
	rm -f *.o my_shell