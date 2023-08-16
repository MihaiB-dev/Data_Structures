# Loto

***Link: https://www.infoarena.ro/problema/loto***

Gigel is a big fan of gambling, and he likes to play the " 6 from N " lotto the most. In this game, he can write on a ticket 6 numbers, from N distinct natural numbers given by the National Lottery; a number can be used on a ticket more than once. Gigel dreamed one night that the sum of the numbers written on the winning ticket would be S , so the next day he went to put a winning ticket too!

### Requirement
Write a program that tells Gigel which numbers to choose to get a winning ticket (with sum S )

### Input data
On the first line of the file lotto.in you will find the natural numbers N and S , separated by a space. On the second line there will be N distinct natural numbers, given by the National Lottery.

### Output Data
In the file lotto.out you will find 6 values ​​representing the numbers chosen for Gigel's ticket. If a winning ticket cannot be obtained, the output file will contain only the number -1 .

### Restrictions and specifications
- 1 ≤ N ≤ 100
- 1 ≤ S ≤ 600.000.000
- The values ​​of the numbers given by the National Lottery will not exceed 100,000,000
If there are several solutions, only one will be displayed

### Example:  
loto.in	  
3 13   
1 2 3	

lotto.out: 1 1 2 3 3 3  

### Example 2:    
loto.in:  
3 19   
1 2 3	

Lotto.out:   
-1