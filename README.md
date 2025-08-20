# Mini Shell Project by Lapique Philippe

This project was developed as part of the Holberton School C curriculum for the end of the trimester.  
The goal of this exercise is to create a simple UNIX command-line shell that takes into account environment variables, user input commands, and includes an exit feature through either the `exit` command or the keyboard shortcut `Ctrl+D`.

---

## 🎯 Project Objectives

- Display a prompt and wait for the user to type a command.  
- Each command line must always end with a new line.  
- The prompt must be displayed again after each executed command.  
- If an executable cannot be found, print an error message and display the prompt again.  
- Properly handle errors and the “end of file” condition (`Ctrl+D`).  
- Handle command lines with arguments and the `PATH`.  
- Implement the built-in command `env` to print the current environment.  
- Implement the built-in command `exit` to exit the shell.  

---


## 📜 Allowed Functions and System Calls  

| Function / System Call | Manual Page |
|-------------------------|-------------|
| All functions from `string.h` | man 3 string |
| `access` | man 2 access |
| `chdir` | man 2 chdir |
| `close` | man 2 close |
| `closedir` | man 3 closedir |
| `execve` | man 2 execve |
| `exit` | man 3 exit |
| `_exit` | man 2 _exit |
| `fflush` | man 3 fflush |
| `fork` | man 2 fork |
| `free` | man 3 free |
| `getcwd` | man 3 getcwd |
| `getline` | man 3 getline |
| `getpid` | man 2 getpid |
| `isatty` | man 3 isatty |
| `kill` | man 2 kill |
| `malloc` | man 3 malloc |
| `open` | man 2 open |
| `opendir` | man 3 opendir |
| `perror` | man 3 perror |
| `printf` | man 3 printf |
| `fprintf` | man 3 fprintf |
| `vfprintf` | man 3 vfprintf |
| `sprintf` | man 3 sprintf |
| `putchar` | man 3 putchar |
| `read` | man 2 read |
| `readdir` | man 3 readdir |
| `signal` | man 2 signal |
| `stat (__xstat)` | man 2 stat |
| `lstat (__lxstat)` | man 2 lstat |
| `fstat (__fxstat)` | man 2 fstat |
| `strtok` | man 3 strtok |
| `wait` | man 2 wait |
| `waitpid` | man 2 waitpid |
| `wait3` | man 2 wait3 |
| `wait4` | man 2 wait4 |
| `write` | man 2 write |

## 🗂️ Project Organization

**Estimated project duration:** 80 hours  
The work was carried out in person on the Bordeaux campus.  

Development was organized using two separate branches:  
- **main**: stored the final project version.  
- **philippe_dev**: development branch used for testing and drafts.  

A dedicated folder called **exercise/** was also included in the repository.  
It contains test files for basic functions before they were assembled into the main shell project.  

Regular check-ins were conducted to review progress and ensure smooth integration.  
At the end of the project, a pull request was used to merge everything into the **main** branch.  

## 🧱 Project Structure

We decided to split the code into multiple files to better divide the tasks and to isolate functionalities for easier debugging and testing.

- **README.md** : Contains explanations about the project and its structure  
- **.gitignore** : Specifies intentionally untracked files to be ignored by Git  
- **_getenv.c** : Custom implementation of the `_getenv` function to retrieve environment variables  
- **cut.c** : Splits the command line into arguments (tokenization)  
- **execute.c** : Handles execution of commands (direct path or via PATH)  
- **find.c** : Searches for commands in the directories listed in the PATH environment variable  
- **handle.c** : Manages built-in commands such as `exit` and `env`  
- **main.c** : Main loop of the shell, handling user input and process management  
- **main.h** : Header file containing function prototypes and required libraries  
- **Man_shell** : Manual page describing how to use the shell  
- **Author** : File containing information about the project’s author(s)  

🛠️ Compilation :

To compile the project, use the following command.
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

Example Usage :

Man Page
For more information about how the function works or how to troubleshoot errors, refer to the manual page man_page_shell included in the project folder.

Flowcharts :

![Diagramme sans nom.drawio (1).png](Exercice/Diagramme sans nom.drawio (1).png)
 
