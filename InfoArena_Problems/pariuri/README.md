# Pariuri

***Link: https://www.infoarena.ro/problema/pariuri***

As the start time of the match is fast approaching, PalanRit started betting because he wants to be an experienced bettor until the starting whistle of the match between Greece and Romania. To catch the experience quickly he harnessed himself in a dangerous gang with N people. Each of the N people has a list containing pairs of the form (time, money) which means that in the time unit time he or she bet, and won, or lost, an amount of money equivalent to money . PalanRit wants to make a statistic, namely it wants to create a list of pairs of the form (time, amount_money)in which to count how much the gang won or lost at each moment of time in which it was bet.

### Input data
The pariuri.in input file contains on the first line a natural number N , representing the number of people in the gang. On the following N lines, the N lists will be described , as follows. Each line contains a number M , representing the number of elements in the respective list, followed by M pairs of two numbers each, time and money , with the required meaning. All numbers on a line are separated by a space.

### Output data
In the output file pariuri.out you will display on the first line a number P representing the number of elements in PalanRit 's list , and on the second line you will display P pairs of two numbers each time , suma_bani , with the same meaning as the unit of from time to time , the whole gang won, or lost, an amount of money equivalent to sum_money .

### limitation
- 1 ≤ N ≤ 100
- 1 ≤ M ≤ 20 000
- 1 ≤ time ≤ 10 9
- For 80% of tests 1 ≤ time ≤ 10 6
- 106 ≤ bani ≤ 106
- If money ≥ 0 then it is considered to be a gain, otherwise it is considered to be a loss.
- ATTENTION ! The order of the pairs in the output file does not matter.

### Example
pariuri.in  
3   
2 1 10 3 -60   
1 3 50   
3 1 -5 3 15 2 -5  
bets.out   
3  
1 5 2 -5 3 5  

### Explanation
The first person in the group gambled at moments 1 and 3 , the second only at moment 3 and the last person at moments 1, 2 and 3 . In conclusion, at time 1 the gang wins 10 - 5 = 5 , at time 2 it loses 5 , and at time 3 the gang has a profit of -60 + 50 + 15 = 5 .