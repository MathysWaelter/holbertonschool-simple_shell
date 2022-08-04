![alt text](https://rushhourtimes.com/wp-content/uploads/2022/04/8347f9bc74b893721854374b8df659b6.png)

# Simple Shell

This project, is our end-of-term project, carried out in groups of two, and we had to do it in just 15 days, we put into practice all our knowledge of the C language and the unix script ✅

## Description


Shell is a UNIX term for the interactive user interface with an operating system. The shell is the layer of programming 🕹

It collects information from you and runs programs based on that information. When a program finishes running, it displays the output of that program.

Shell is an environment where we can run our shell commands, programs and scripts. There are different versions of a shell, just like there are different versions of operating systems. Each type of shell has its own set of recognized commands and functions.

### Installing

* No installation is required
* it's native to your operating system

### interest of a shell

* Controls all computer operations.
* Coordinates all executing utilities
* Ensures that executing utilities do not interfere with each other or consume all system resources.
* Schedules and manages all system processes.


### Different Shell

| Shell | Path  | Default Prompt (non-root user)  | Default Prompt (Root user) |
| :---:   | :-: | :-: | :-: |
| Bourne Shell (sh) | /bin/sh and /sbin/sh | $ | # |
| The C Shell (csh) | /bin/csh | % | # |
| The Korn Shell (ksh) | /bin/ksh | $ | # |
| The GNU Bourne-Again Shell (Bash) | /bin/bash | bash-x.xx$ | bash-x.xx# |

## Different Modes

Our Shell works in two modes: 
* -Interactive Mode 
* -Non-Interactive Mode

***Interactive mode***

For enter in Shell prompt:

Compile with:
```
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```
Run with:
```
./hsh
```

For run with Shell prompt:

Compile with:
```
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```
Run with:
```
echo "command" | ./hsh
```
## Help

for help type this command in your shell terminal.
```
cat -help
```

## Version History

* 0.1
    * Just a UNIX command line interpreter.
    
* 0.2
    * Handle command lines with arguments

* 0.3
    * Handle the PATH

* 0.4
    * Implement the exit built-in, that exits the shell

* 0.5
    * Implement the env built-in, that prints the current environment

## Authors

Contributors names and contact info

***-Waelter Mathys*** --> https://www.linkedin.com/in/mathys-waelter-1055631a4/

***-Bayle Romain*** --> https://www.linkedin.com/in/romain-bayle-48a11a243/
