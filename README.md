
# pipex

## 42 School Project

### Description

The `pipex` project is part of the 42 curriculum and aims to recreate the functionality of the Unix pipe (`|`). This project teaches how to handle multiple processes, pipes, file descriptors, and system calls such as `fork`, `execve`, and `dup2`.

The goal of `pipex` is to reproduce the behavior of the following shell command:

```bash
<file1 cmd1 | cmd2 >file2
```

The project executes `cmd1`, redirects its output to the input of `cmd2`, and writes the final output to `file2`. 

### Features

- Executes commands through `execve`.
- Uses pipes to link the input and output of commands.
- Handles file operations with proper error handling.
- Supports the use of absolute and relative paths for commands.

### Installation

To get started with the `pipex` project, you'll need to clone the repository to your local machine. Ensure you have [Git](https://git-scm.com/) installed before proceeding.

#### Clone the Repository

You can clone the repository using the following HTTPS command:

```bash
git clone https://github.com/Mohamadaliibrahim/pipex.git
```

#### Navigate to the Project Directory

After cloning, navigate to the `pipex` directory:

```bash
cd pipex/pipex
```

### Usage

#### Compilation

To compile the program, run:

```bash
make
```

This will generate an executable called `pipex`.

#### Running the Program

The general usage of the program is as follows:

```bash
./pipex file1 cmd1 cmd2 file2
```

For example:

```bash
./pipex infile "ls -l" "grep txt" outfile
```

This command will run `ls -l` on `infile`, pipe the result to `grep txt`, and write the output to `outfile`.

### Example

Here’s how you can use `pipex` with some basic shell commands:

```bash
./pipex infile "cat" "wc -l" outfile
```

In this case, `pipex` will:

- Read from `infile` using `cat`,
- Pipe the result to `wc -l` to count the number of lines,
- Write the result to `outfile`.

### Requirements

- Must handle multiple processes using `fork()`.
- Properly handle pipes and file descriptors using `dup2()`.
- Must use `execve()` to execute commands.
- Handle error scenarios such as invalid commands or files that cannot be opened.

### Author

This project was developed by **mohamibr** as part of the 42 school curriculum.
