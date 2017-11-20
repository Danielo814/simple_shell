# simple_shell

## Description
This project is a command line interpreter that is a simple implementation of the shell written by Ken Thompson. Simple_shell is was made using concept that students at Holberton School have used since starting the program on September 5, 2017.

## Tasks

Task | Description
---- | -----------
0    | Write a README, man page, and AUTHORS file for your shell.
1    | Write a beautiful code that passes the Betty checks.
2    | Write a UNIX command line interpreter with usage ```simple_shell```
3    | Handle command line with arguments
4    | Handle the ```PATH```
5    | Implement the ```exit``` built-in that exits the shell
6    | Implement the ```env``` built-in, that prints the current environment

## Requirements

* Allowed editors: ```vi```, ```vim```, ```emacs```
* All files will be compiled on Ubuntu 14.04 LTS
* Programs and functions will be compiled with ```gcc 4.8.4``` using the flats ```-Wall``` ```-Werror``` ```-Wextra``` ```and -pedantic```
* All files should end with a new line
* Code should use the ```Betty``` style. it will be checked using [betty-style.pl](https://github.com/holbertonschool/Betty/blob/master/betty-style\
.pl) and [betty-doc.pl](https://github.com/holbertonschool/Betty/blob/master/betty-doc.pl)
* No more than 5 functions per file
* All header files should be include guarded
* Authorized functions and system calls:
  * ```access``` (```man 2 access```)
  * ```chdir``` (```man 2 chdir```)
  * ```close``` (```man 2 close```)
  * ```closedir``` (```man 3 closedir```)
  * ```execve``` (```man 2 execve```)
  * ```exit``` (```man 3 exit```)
  * ```fork``` (```man 2 fork```)
  * ```stat``` (```__xstat```)(```man 2 stat```)
  * ```getline``` (```man 3 getline```)
  * ```kill``` (```man 2 kill```)
  * ```open``` (```man 2 open```)
  * ```opendir``` (```man 3 opendir```)
  * ```perror``` (```man 3 perror```)
  * ```read``` (```man 2 read```)
  * ```readdir``` (```man 3 readdir```)
  * ```signal``` (```man 2 signal```)
  * ```strtok``` (```man 3 strtok```)
  * ```wait``` (```man 2 wait```)
  * ```waitpid``` (```man 2 waitpid```)
  * ```wait3``` (```man 2 wait3```)
  * ```wait4``` (```man 2 wait4```)
  * ```_exit``` (```man 2 _exit```)
  * ```isatty``` (```man 3 isatty```)
  * ```fflush``` (```man 3 fflush```)
  * ```write``` (```man 2 write```)
  * ```malloc``` (```man 3 malloc```)
  * ```free``` (```man 3 free```)

** Usage

* Compile using ```gcc -Wall -Werror -Wextra -pedantic *.c -o hsh```
* Run the shell by typing ```./hsh``` and pressing "enter" on your keyboard as shown below:

```vagrant@vagrant-ubuntu-trusty-64:~/simple_shell$ ./hsh
$ ls -l
total 68
-rw-rw-r-- 1 vagrant vagrant  4038 Nov 20 02:46 #README.md#
-rw-rw-r-- 1 vagrant vagrant   118 Nov 13 02:52 AUTHORS
-rw-rw-r-- 1 vagrant vagrant   753 Nov 20 01:34 README.md
-rw-rw-r-- 1 vagrant vagrant   672 Nov 20 02:47 builtins.c
-rw-rw-r-- 1 vagrant vagrant   674 Nov 20 02:04 builtins.c~
-rw-rw-r-- 1 vagrant vagrant  1842 Nov 20 02:33 findPathFuncs.c
-rw-rw-r-- 1 vagrant vagrant   999 Nov 19 22:07 holberton.h
-rwxrwxr-x 1 vagrant vagrant 14246 Nov 20 02:48 hsh
-rwxrw-r-- 1 vagrant vagrant  2059 Nov 20 01:15 man_1_simple_shell
-rwxrw-r-- 1 vagrant vagrant  2123 Nov 20 01:13 man_1_simple_shell~
-rw-rw-r-- 1 vagrant vagrant  2253 Nov 20 02:48 myFuncs.c
-rw-rw-r-- 1 vagrant vagrant  2041 Nov 19 21:33 shell.c
drwxrwxr-x 2 vagrant vagrant  4096 Nov 18 04:46 src
-rw-rw-r-- 1 vagrant vagrant   370 Nov 19 20:58 utils.c
$```

 
## File Descriptions

* **AUTHORS:** This file contains contributors to this repository
* **holberton.h:** Header file containing all function prototypes and needed libraries
* **man_1_simple_shell:** man page for simple_shell
* **builtins.c:** contains functions to recognize the text ```exit``` to exit the shell and ```env``` to print the current environment. ```int built_ins(char **args) is a function that checks if the character string matches input, if it finds a match, it'll call the next element in the structure which will be the function to execute. That function could either be ```int _env(char **args)``` which will print the current environment, or ```int _bin_exit(char **args)``` which will execute the current shell.
* **findPathFuncs.c:**
  * ```getKeyValue(char *key)``` - 
  * ```getPathArgs(char *prog)``` - 
  * ```get_x_args(char **env_paths, char *program)``` - 
  * ```char *stralloc(int count, ...)``` - 
* **myFuncs.c:**
  * ```char *_memset(char *s, char b, unsigned int n)``` -
  * ```char *_strcat(char *dest, char *src)``` -
  * ```char *_strcpy(char *dest, char *src)``` -
  * ```int _strlen(char *s)
  * ```char *_strstr(char *haystack, char *needle)``` - 
* **shell.c:**
  * ```int main(void)``` - 
  * ```int promptShell(void)``` - 
  * ```char **getToken*(char **buf, char *pattern)``` - 
  * ```void execute(char *arg, char **args)``` - 
* **utils.c:**
  * ```unsigned int countToks(char *str, char *delim)``` - 

## Bugs
No bugs are known

## Authors
**Daniel Ojeda** [Twitter](https://twitter.com/DanielC_Ojeda) | [Github](https://github.com/Danielo814)
**Sid Carroll** [Twitter](https://twitter.com/sidCarroll7) | [Github](https://github.com/squidcarroll)