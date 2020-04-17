# <a href="https://www.holbertonschool.com/holberton-logo.png" alt="holberton_logo" width="60" height="60" border="0"></a> Simple shell

A simple UNIX command interpreter that provides a user interface to access and give orders to the operating system.

## Looks my content!
* [Requirements](#requirements)
* [Instalation](#instalation)
* [Compilation](#compilation)
* [What we use?](#written-in)
* [Use](#example-of-use)
* [Files](#files)
* [Authors](#authors)
## Requirements (What you need to run me?)
* Ubuntu 14.04 LTS
* gcc version 4.8.4
## Instalation (Just Clone)
*  Clone this repository:
```sh
git clone https://github.com/sandovbarr/printf
```
* Inside the repository, compile.
* Execute:
```sh
./hsh
```
* Or run in non-interactive mode, in this mode:
```sh
echo "ls" | ./hsh
```
## Compilation (Never forget the flags)
```sh
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```
## What we use? (to make the project ;)
* GNU Emacs 24.3.1
* C language #cisfun
## Use
* Run the man page for examples:
```sh
$ man ./man_1_simple_shell 
```
All commands and builtins that you can use are in the manual page.
## Files
* [jshell.c] - Main Functions.
* [_getenv.c] - in this files we gets the enviroment
* [_command_not] - Print the error messages
* [path_fnc0.c] - made tokens of Path
* [jshell.h] - header files
* [strn_func.c] - Funcionts for strings
* [simple_shell.h] - The header file
* [strfunc.c] - Manipulates strings, length, etc.
* [token_fnc.c] - Create tokens for arguments recived

### This project was developed by:
 - [Jairo Fernando Sandoval][https://github.com/sandovbarr?tab=repositories]
 - [Julian Ramirez chacón][https://github.com/julianramirezch]
 