# Process Creation and File Management Demo

## Overview

This C program demonstrates fundamental operating system concepts including **process creation**, **process synchronization**, and **file system operations**. It serves as an educational example of how parent and child processes interact in a Unix-like environment.

## Description

The program creates a child process using the `fork()` system call, which then creates an empty file named `abc` in the current directory. Meanwhile, the parent process waits for the child to complete its task before displaying diagnostic information about the child's execution.

## Key Concepts Demonstrated

- **Process Creation**: Using `fork()` to create a new child process
- **Process Synchronization**: Using `wait()` to make the parent process wait for child completion
- **File Operations**: Creating files with specific permissions using `open()`
- **Error Handling**: Proper error checking and reporting for system calls
- **Process Status**: Retrieving and interpreting child process exit status

## Features

- Creates a child process that runs independently
- Child process creates an empty file with read-write permissions
- Parent process waits for child termination
- Displays child process ID and exit status
- Comprehensive error handling with descriptive error messages
- Demonstrates proper file descriptor management

## Requirements

- **Operating System**: Unix-like system (Linux, macOS, WSL, etc.)
- **Compiler**: GCC or any C compiler with POSIX support
- **Libraries**: Standard C libraries, unistd.h, sys/wait.h

## Compilation

Compile the program using GCC:

```bash
gcc -o process_demo process_demo.c
