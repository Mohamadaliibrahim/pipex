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

### Resources

- [42 School Project Overview](https://42.fr/en/homepage/)
- [Unix Pipe Documentation](https://man7.org/linux/man-pages/man2/pipe.2.html)
- [Execve System Call](https://man7.org/linux/man-pages/man2/execve.2.html)

### Author

This project was developed by **mohamibr** as part of the 42 school curriculum.

---

You can customize it further based on any additional features or unique aspects you may have implemented.
