Mini Shell Project by Lapique Philippe

Mon projet pour la fin du trimestre en langage C chez Holberton School. L'exercice consiste en la réalisation d'un terminal de commande sous UNIX, qui prends en compte les variables d'environnement ainsi que les commandes rentrer par l'utilisateur avec une fonction de sortie par commande (exit) ou raccourcie clavier (ctrl + d).

Objectif du projet : 

  . Display a prompt and wait for the user to type a command. 
  . A command line always ends with a new line.
  . The prompt is displayed again each time a command has been executed.
  . If an executable cannot be found, print an error message and display the prompt again.
  . Handle errors, have to handle the “end of file” condition (Ctrl+D)
  . Handle command lines with arguments and the PATH.
  . Implement the env built-in, that prints the current environment.
  . Implement the exit built-in, that exits the shell.

Liste des fonctions autoriser pour mon projet :

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

 
