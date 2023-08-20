#Makefile for my_shell

OBJECTS = main.o display.o get_line.o exit_stat.o internal_commands.o check_internal_cmds.o \
		append_infile.o infile.o number_of_command.o parser.o command_table.o simple_command_tokens.o \
		tokens_number.o get_path.o exec_command.o memory_free.o


my_shell: $(OBJECTS)
	gcc -o my_shell $(OBJECTS) -ldl

clean:
	rm -f *.o my_shell