#Makefile for libinternal.so

# OBJECTS = main.o display.o get_line.o internal_commands.o check_internal_cmds.o \
# 		append_infile.o infile.o number_of_command.o parser.o command_table.o simple_command_tokens.o \
# 		tokens_number.o get_path.o exec_command.o memory_free.o


libinternal.so: list_init.o add_elem.o cd_cmd.o mkdir_cmd.o rmdir_cmd.o touch_cmd.o commands.o start.o 
	gcc -shared list_init.o add_elem.o cd_cmd.o mkdir_cmd.o rmdir_cmd.o touch_cmd.o commands.o start.o -o libinternal.so


list_init.o: list_init.c
	gcc -c list_init.c -fPIC

add_elem.o: add_elem.c
	gcc -c add_elem.c -fPIC


cd_cmd.o: cd_cmd.c
	gcc -c cd_cmd.c -fPIC

mkdir_cmd.o: mkdir_cmd.c
	gcc -c mkdir_cmd.c -fPIC

rmdir_cmd.o: rmdir_cmd.c
	gcc -c rmdir_cmd.c -fPIC

touch_cmd.o: touch_cmd.c
	gcc -c touch_cmd.c -fPIC

commands.o: commands.c
	gcc -c commands.c -fPIC

start.o: start.c
	gcc -c start.c -fPIC


clean:
	rm -f *.o libinternal.so