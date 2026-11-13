# Operating Systems Lab – Questions

This document contains the practical questions for all the programs included in this repository.

## 1. Process Management

**Q1. Basic Fork System Call**  
Write a C program using `fork()` to create a child process and display a message from both parent and child processes.

**Q2. Process ID Demonstration**  
Write a C program using `fork()` to display the Process ID (PID) and Parent Process ID (PPID) of parent and child processes.

**Q3. Fibonacci Series and Factorial**  
Write a C program using `fork()` where the child process prints the Fibonacci series and the parent process calculates the factorial of a given number.

**Q4. Multiple Fork System Calls**  
Write a C program using multiple `fork()` calls to create multiple processes and perform different operations, such as calculating a sum, Fibonacci series, and factorial.

**Q5. Wait System Call**  
Write a C program to demonstrate the use of `wait()` so that the parent process waits for the child process to complete.

**Q6. Even and Odd Numbers Using Fork**  
Write a C program using `fork()` where the child process prints odd numbers and the parent process prints even numbers.

**Q7. Creating Three Child Processes**  
Write a C program to create three child processes using `fork()` and display their process IDs.

**Q8. Child Process Exit Status**  
Write a C program to demonstrate how a parent process retrieves the exit status of a child process using `wait()` and `WEXITSTATUS()`.

**Q9. Orphan Process**  
Write a C program to demonstrate an orphan process, in which the parent process terminates before the child process.

**Q10. Zombie Process**  
Write a C program to demonstrate a zombie process, in which the child process terminates but the parent does not immediately collect its exit status.

**Q11. Fibonacci and Armstrong Numbers**  
Write a C program using `fork()` where the child process prints the Fibonacci series and the parent process prints Armstrong numbers up to a given limit.

**Q12. Prime Number and Factorial**  
Write a C program using `fork()` where the child process checks whether a number is prime and the parent process calculates the factorial of the same number.

**Q13. Array Sum and Prime Number**  
Write a C program using `fork()` where the child process calculates the sum of array elements and checks whether the sum is prime.

**Q14. String Permutations**  
Write a C program using `fork()` where the child process generates all permutations of a given string and the parent process waits for its completion.

**Q15. Zombie and Orphan Process Demonstration**  
Write a C program to demonstrate orphan and zombie process concepts using multiple child processes and the `wait()` system call.

**Q16. Even and Odd Array Sum**  
Write a C program using `fork()` where the child process calculates the sum of even array elements and the parent process calculates the sum of odd array elements.

## 2. Inter-Process Communication (IPC)

### A. Pipe

**Q17. Communication Using Pipe**  
Write a C program to demonstrate communication between parent and child processes using an unnamed pipe.

**Q18. Array Sum and Prime Check Using Pipe**  
Write a C program where the parent process calculates the sum of array elements and sends the result to the child process through a pipe. The child checks whether the received sum is prime.

### B. FIFO (Named Pipe)

**Q19. FIFO Writer**  
Write a C program to create a named pipe using `mkfifo()` and write a message into it.

**Q20. FIFO Reader**  
Write a C program to read a message from a named pipe using the `open()` and `read()` system calls.

**Q21. FIFO Writer – Alternative Implementation**  
Write an alternative C program to send a message through a named pipe using FIFO.

### C. Message Queue

**Q22. Message Queue Sender**  
Write a C program to create a System V message queue and send a message using `msgsnd()`.

**Q23. Message Queue Receiver**  
Write a C program to receive a message from a System V message queue using `msgrcv()` and remove the queue using `msgctl()`.

### D. Shared Memory

**Q24. Shared Memory Writer**  
Write a C program to create a shared memory segment and write data into it using `shmget()` and `shmat()`.

**Q25. Shared Memory Reader**  
Write a C program to read data from a shared memory segment and remove it using the appropriate system calls.

## 3. File Handling

**Q26. Parent-Child File Handling**  
Write a C program where the parent process creates a file and writes student details into it, while the child process reads and displays the contents.

**Q27. Opening a File Using Child Process**  
Write a C program using `fork()` where the child process opens an existing file in read mode and displays whether the file was opened successfully.

**Q28. Even Numbers Using File Handling**  
Write a C program where the child process writes even numbers into a file and the parent process reads and displays those numbers.

## 4. CPU Scheduling Algorithms

**Q29. First Come First Serve (FCFS)**  
Write a C program to implement the FCFS CPU scheduling algorithm and calculate the waiting time, turnaround time, average waiting time, and average turnaround time.

**Q30. Shortest Job First (SJF)**  
Write a C program to implement non-preemptive SJF CPU scheduling and calculate the waiting time and turnaround time of each process.

**Q31. Priority Scheduling**  
Write a C program to implement non-preemptive Priority CPU scheduling and calculate the waiting time and turnaround time of each process.

## 5. Page Replacement Algorithms

**Q32. FIFO Page Replacement**  
Write a C program to implement the FIFO page replacement algorithm and calculate the total number of page hits and page faults.

**Q33. LRU Page Replacement**  
Write a C program to implement the LRU page replacement algorithm and calculate the total number of page hits and page faults.

---

## End of Operating Systems Lab Questions