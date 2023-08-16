# Ali Baba
***Link: https://www.infoarena.ro/problema/alibaba***

### Context
Ali Baba caught the 40 thieves rummaging through his treasures. There were many of them, he was alone, in conclusion he tried to get along with them. Among the treasures was a special chest on which was written the number of diamonds inside. Ali Baba proposed to the leader of the thieves to cut K digits from the representation of the number, then to give the thieves as many diamonds as the number that remains after cutting.

### Requirement
Help the master thief to determine the number that remains after cutting, so that it is as high as possible.

### Input data
On the first line of the alibaba.in input file there are two natural numbers (separated by a space) N and K , representing the number of digits in the configuration of the number written on the box, respectively the number of digits to be cut. On the second line is the string of numbers written on the box. There is no space between two numbers.

### Output data
On the first line of the alibaba.out output file, the number of diamonds that the thief will be able to take will be written.

### Restrictions and clarifications
- 1 ≤ N ≤ 10 000
- 0 ≤ K ≤ N-1
- Denoting by c1c2...cN the string of digits of the number written on the crate, 0 ≤ ci ≤ 9, i = 1, 2,...,N .
### Example
alibaba.in	
5 3
12312

alibaba.out
32

### Idea 

I will use a ***stack*** to put numbers in it on every turn.   
When the current number is greater than the top element from the stack, we pop untill the numbers from the stack are  in decending order. (view from up to bottom).   
Unfortunetly there is an exception. I take as an example 6 4 999999. Our previous approach will be useless. So we will ne a contor to make sure that if we don't pop enough elements, the code will pop till is needed.

Code: [click here](https://github.com/MihaiB-dev/Data_Structures/blob/main/InfoArena_Problems/alibaba/alibaba.cpp)