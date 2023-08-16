# Hashes
***Link: https://www.infoarena.ro/problema/hashu***

Let be a set of natural numbers initially empty. The following types of operations are performed on this crowd:

- type 1 operation : element x is ***added*** to the set (where x is a parameter of the operation). If x is already in the set, then it remains unchanged.   
- type 2 operation : element x is ***deleted*** , if it is already in the set. Otherwise, the crowd remains unchanged.   
- type 3 operation : returns 1 if and only if ***x is in the set***, and otherwise returns 0 .

### Input data
The input file hashuri.in contains on the first line the number N of performed operations. Each of the following N lines contains a pair of natural numbers (op x) , where op is the number of the operation being performed (from 1 to 3 ), and x is the parameter of the operation.

### Output data
The output file hashuri.out will contain a number of lines equal to the number of type 3 operations in the input file. On each line will be the answer returned by the corresponding operation.

### limitation
3 ≤ N ≤ 1.000.000
Each operation has a natural number parameter in the range [1, 2,000,000,000]
### Example
hashuri.in	
7   
1 3   
1 20  
2 7  
3 4  
3 20  
2 20  
3 20  
hashuri.out  
0  
1  
0