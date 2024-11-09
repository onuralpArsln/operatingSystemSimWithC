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
Even if you don't have the file already in place your text editor command creates a new file for you.

if you want to create a empty file you can use `touch <fileName>.<extension>` command.


```c
#include <stdio.h>

int main() {
    printf("Hello, Terminal!\n");
    return 0;
}

```

In vim you do  Ctrl + X or esc to switch normal mode then use `:wq` command to  save and exit or you can `:q` to quit or `:!q` discard changes and quit. in nano  Ctrl + X, then Y, and Enter to save and close the file.

# Compile and run

```bash 

gcc helloFromTerminal.c -o hello
```

-o stands for output file after what you type that will be name of the output compiled file. Then you can call the compiled file to run.

```bash
./hello

```