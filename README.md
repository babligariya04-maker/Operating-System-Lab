# Operating System Lab

This repository contains C programs implemented as part of the Operating Systems Laboratory. It covers important concepts such as process management, inter-process communication, file handling, CPU scheduling, and page replacement algorithms.

## 📚 Table of Contents

1. [Process Management](#1-process-management)
2. [Inter-Process Communication](#2-inter-process-communication)
3. [File Handling](#3-file-handling)
4. [CPU Scheduling](#4-cpu-scheduling)
5. [Page Replacement](#5-page-replacement)
6. [How to Compile and Run](#how-to-compile-and-run)
7. [Requirements](#requirements)

## 1. Process Management

Programs demonstrating process creation and management using `fork()`, `wait()`, and process IDs.

Folder: `01-Process-Management/`

## 2. Inter-Process Communication

Programs demonstrating communication between processes using different IPC mechanisms.

Folder: `02-Inter-Process-Communication/`

Topics:
- Unnamed Pipes
- FIFO (Named Pipes)
- Message Queues
- Shared Memory

## 3. File Handling

Programs demonstrating file creation, writing, reading, and file operations using parent and child processes.

Folder: `03-File-Handling/`

## 4. CPU Scheduling

Implementation of the following CPU scheduling algorithms:

- First Come First Serve (FCFS)
- Shortest Job First (SJF)
- Priority Scheduling

Folder: `04-CPU-Scheduling/`

## 5. Page Replacement

Implementation of the following page replacement algorithms:

- FIFO (First In First Out)
- LRU (Least Recently Used)

Folder: `05-Page-Replacement/`

## How to Compile and Run

These programs use C and can be compiled using GCC.

**Step 1: Open a Linux terminal.**

**Step 2: Navigate to the folder containing the program.**

Example:

```bash
cd 01-Process-Management
```

**Step 3: Compile the program.**

```bash
gcc fork.c -o fork
```

**Step 4: Run the program.**

```bash
./fork
```

Replace `fork.c` and `fork` with the required source filename and executable name.

## Running IPC Programs

Some IPC programs require two separate terminals.

- FIFO: Run the reader and writer in separate terminals.
- Message Queue: Run the receiver and sender using the same working directory.
- Shared Memory: Run the writer first, followed by the reader, using the same working directory.

## Requirements

- C Programming Language
- GCC Compiler
- Linux/Unix operating system for programs using POSIX process and System V IPC functions
- Basic knowledge of Operating Systems

**Note:** Programs using `fork()`, `unistd.h`, and System V IPC functions generally cannot be compiled directly using native Windows MinGW GCC. Use a Linux environment to compile and execute them.

## Repository Structure

```text
Operating-System-Lab/
│
├── 01-Process-Management/
├── 02-Inter-Process-Communication/
│   ├── FIFO/
│   ├── Message-Queue/
│   └── Shared-Memory/
├── 03-File-Handling/
├── 04-CPU-Scheduling/
├── 05-Page-Replacement/
│
├── question.md
├── README.md
└── .gitignore
```

## Author

**Babli Gariya**

GitHub: [@babligariya04-maker](https://github.com/babligariya04-maker)

---

*This repository is maintained for learning and practicing Operating Systems concepts through C programming.*