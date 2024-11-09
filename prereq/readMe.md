# IDE Free Development 

This file explains what you need to know if you want to develop in C entirely through the terminal.

It highlights the value of working independently of IDEs, especially in cases like IDE installation issues or having to work in different development environments (such as WSL or SSH).

Knowing how to use a terminal-based text editor like nano, vim, or emacs can make this process much easier.


 # First Step : Check installation of gcc
gcc-> GNU Compiler Collection

Can compile C, C++, Objective-C, Fortran, Ada, Go

to ensure you have gcc run following command in your terminal.

```bash 
gcc --version

```

If you don't have  gcc ( or need to update )

```bash 
sudo apt update
sudo apt install gcc
```

# Create Your First Project From Terminal 

Folders are directories you can make directories with command `mkdir` and change directory with `cd` also you can list directories  with list `ls` command. 

```bash 

mkdir cFromTerminal
cd cFromTerminal

```

# Code your first lines 

At this point you will use c that we know and love 

use your favorite terminal base text editor.

```bash 
vim helloFromTerminal.c

```
Even if you dont have the file already in place your text editor command creates a new file for you.

if you want to create a empty file you can use `touch <fileName>.<extension>` command.
