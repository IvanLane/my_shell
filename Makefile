#Makefile for my_shell

my_shell: main.o get_line.o parser.o command_table.o exec_command.o
	gcc -o my_shell main.o get_line.o parser.o command_table.o exec_command.o

main.o: main.c
	gcc -c main.c

get_line.o: get_line.c
	gcc -c get_line.c

parser.o: parser.c
	gcc -c parser.c 

command_table.o: command_table.c
	gcc -c command_table.c

exec_command.o: exec_command.c
	gcc -c exec_command.c


clean:
	rm -f *.o my_shell