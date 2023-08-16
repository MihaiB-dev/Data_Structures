# Proc2

***Link:https://www.infoarena.ro/problema/proc2***

We have a computer with N processors. There are M tasks to be executed, each with a start time Si and a processing duration Di . The tasks must be executed in chronological order and each task must be executed on the processor with the lowest index available at time Si .

### Requirement
The processor that will execute it must be calculated for each task.

### Input data
The input file proc2.in contains the values ​​N and M on the first line . On the next M lines you will find two numbers Si , Di separated by spaces, with the meaning in the statement.

### Output data
M lines should be displayed in the output file proc2.out . The index of the processor on which task i is executed will be written on line i .

### limitation
- 1 ≤ N ≤ 1.000.000
- 1 ≤ M ≤ 100.000
- For any i between 1 and M , 1 ≤ Si ≤ 2*10 9 and 1 ≤ Si +Di ≤ 2*10 9
- For any i between 1 and M-1 , Si < S i+1
- It is guaranteed that each task can be executed
- The processor executing task i is busy at times [Si , Si + Di )

### Example
proc2.in	  
3 3   
1 2  
2 3  
3 3 
proc2.out  
1  
2  
1  
### Explanation
- At time 1 , processors 1, 2, 3 are available . So task 1 will be executed by processor 1 .
- At time 2, processors 2, 3 are available . So task 2 will be executed by processor 2 .
- At time 3 , processors 1, 3 are available . So task 3 will be executed by processor 1 .