# Postage

***https://www.infoarena.ro/problema/timbre***

As you all know, Adriana is a big stamp collector. Every day she goes to the store on her street to increase her collection. One day, the seller (none other than the Archer Dragon) thought of giving him a surprise. He took out of an old cupboard some very valuable stamps on which natural numbers were written with gold and silver thread. Knowing that the girl does not have much money, the Dragon told her the following: "I can divide the stamps into M intervals of the form [1,...,m i ] . You can take from any interval a single subsequence of a maximum of K elements. Of course, if you chose a subsequence from the range, you will pay a certain amount..."

Adriana thought that it would be nice to number all the N pages of her folder with such stamps. Being a greedy little girl, she said to herself: "I would really like to eat an ice cream with the money I have with me, but I don't know if I will have enough to pay the stamps. How can I do it?"

### Requirement
Knowing the M intervals, as well as their costs, help Adriana buy the stamps necessary for the numbering of the folder, paying as little as possible.

### Input data
On the first line of the timbre.in file there are N , M , and K. N represents the number of pages of the folder, M represents the number of intervals, and K the maximum length of a subsequence. On the following M lines there are two numbers separated by a space, mi and ci , where mi represents the upper edge of the interval i , and ci its cost.

### Output data
On the first line of the file timbre.out will be Smin, representing the minimum amount that Adriana must pay to buy the stamps needed for the numbering of the folder.

### Restrictions and specifications
- 0 < N < 1 001
- 0 < M < 10 001
- 0 < K < 1 001
- 0 < mi < 100 000
- 0 < ci < 10,000
- to number all the N pages of the folder, Adriana needs stamps with the numbers from 1 to N

### Example
timbre.in	   
4 3 2   
5 3  
2 1  
6 2  

timbre.out  
3 
### Explanation  
We take the subsequence {1, 2} from the second interval and the subsequence {3, 4} from the third interval. We thus obtain the minimum cost 3 .