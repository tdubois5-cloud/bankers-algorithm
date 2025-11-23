This program uses Banker’s Algorithm for deadlock avoidance in a system with multiple processes and resource types.<br><br>

What it does:

The program reads the number of processes (P), number of resources (R), the allocated resources, the maximum resources demanded, and the available resources from a text file.

It then calculates the need for each process. Need[i][j] = Max[i][j] - Allocation[i][j].

It then checks for safety by:

- Looking for a process whose needs can be met with the current available resources.
	
- If a process is found, assume the process finishes and releases its resources.
	
- Repeat until all processes finish or no process can proceed.
	
If all processes can finish, the program prints a safe sequence.

If not, it prints that the system is not in a safe state.<br><br>

Assignment Doc Question:

Is the system in a safe state? 

Yes

If Yes, then what is the safe sequence?

P3 -> P4 -> P1 -> P2 -> P0<br><br>

Input File Format:


```
5 3

0 1 0
2 0 0
3 0 2
2 2 1
0 0 2

7 5 3
3 3 2
9 0 2
2 2 2
4 3 3

3 2 2
```

First line: Number of processes (P) and number of resource types (R)

Next P lines: Allocation

Next P lines: Max

Last line: Available<br><br>

To compile and run:

g++ -std=c++11 banker.cpp -o banker

./banker input.txt<br><br>

Example Output:

System is in a safe state.

Safe sequence: P3 -> P4 -> P1 -> P2 -> P0

This output means the system is safe, and that is one valid sequence that allows all processes to complete without causing deadlock.
