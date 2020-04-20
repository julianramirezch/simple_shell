<p align="center">
<img src="https://www.entreprises-magazine.com/wp-content/uploads/2019/11/Holberton-School-et-l%E2%80%99IHEC-Carthage.png">

<h1 align="center">The simple shell Project</h1>
Simple shell provides to users an interface to give simple orders to the system.
</p>

## Looks my content!
* [Requirements](#requirements)
* [Instalation](#instalation)
* [Compilation](#compilation)
* [What we use?](#written-in)
* [Use](#example-of-use)
* [Flowchart](#flowchart)
* [Files](#files)
* [Authors](#authors)
## Requirements (What you need to run me?)
* Ubuntu 14.04 LTS
* gcc version 4.8.4
## Instalation (Just Clone)
*  Clone this repository:
```sh
git clone https://github.com/julianramirezch/simple_shell
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
evilshell$ man ./man_1_simple_shell
```
* Run simple comands:
```sh
evilshell$ /bin/ls
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

## Flowchart

<p align="center">
<h3><a href="https://www.goconqr.com/es-ES/p/22089213-Simple-Shell-Flowchart-flowcharts?frame=true">-See the flowchart</a></h3>
</p>

### This project was developed by:
 - [Julian Ramirez chacón][https://github.com/julianramirezch]
 - [Jairo Fernando Sandoval][https://github.com/sandovbarr]
