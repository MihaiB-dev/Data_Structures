# Sort Project

The goal was to implement 5 sorting algorithms and test them in terms of speed, on different files. I've accomplished writing and comprehend the following algorithms: ***Merge, Shell, Insertion, Heap, Radix sort***.
## Understanding

### Part 1: Tested Files

In the folder *tester* there are : create_tester.py , random.txt, reversed.txt, sorted.txt. Each of them has 10^7 numbers. Random.txt has numbers between 1-10^5. 

**Why 3 files?** -> there are programs that are working fine with reversed text, others not (*insertion sort*). Others dodn't care about the worder (*heap_sort*). Some algorithms are looking for small numbers (*Radix*). I've wanted to see some pros and cons between each of them.

### Part 2: Sorting Algorithms

If you open test_code.cpp you will see some functions. On top, the *NUMBER* constant will let you change how many numbers are going to be sorted.

Let's start with *main* down the bottom of the file. Firts, there is the file which you wanna test on the algorithm. After this, there 5 comments representing the functions for the codes. Feel free to uncomment one of them and run the program. Next, if you scroll up, there are all the algortihms with their functions.
- 9 - 34 Merge Sort
- 36 - 44 Shell Sort
- 46 - 61 Insertion Sort
- 62 - 161 Heap Sort
- 163 - 192 Radix Sort

### Part 3: How testing program works

Now let's open the 134_Bivol_Mihai_sort.cpp and see what is happening.  

#### How the matrix works:    
For each algorithm is a matrix e.g.  V_merge[TEST_INPUT_NUMBER][NUMBER_TESTS*POWER_10]; By default: V_merge[3][30];

 test_input|  10.000  100.000  1.000.000  10.000.000

i=0 Reversed [0,...9,10,...19,20,...,29,30,...,39]     
i=1 Sorted   [----------------//----------------]   
i=2 Random   [----------------//----------------] 

Each position v_merge[i][j] defines the test j%10 for each test_input i (In seconds).
 - If 0<j<9 -> done on 10.000 numbers
 - If 10<j<19 -> done on 100.000 numbers
 - If 20<j<29 -> done on 1.000.000 numbers
 - If 30<j<39 -> done on 10.000.000 numbers

#### How the time is calculated:
Scroll down till *calculate_merge_sort* (will take this as an example). Next to it there is a copy for each algorithm. (A template would've been a better idea). A (chrono) clock is starting just before the function merge_sort.   
After the sort function ended, we stop the clock, calculated the time between both of them and put it into the matrix.   
The beauty of this logic is that the clock is just for the function withing the whole code. Even if there are some distrubings due to other open programs , we shrinked our time bubble.

#### How we run each algorithm:
Now take a look at the *create_time_vectors*. Ultra_tester is a string array with the files from the tester. Sort Algorithms is a string array with those. 
     
I've added a progress bar for visual pruposes when the tests are run.   

Pseudo-Code :   

For each file (sorted, reversed, random):   
-->for each power(10^4,10^5, 10^6, 10^7):   
-->-->for each algorithm:    
-->-->-->read the array, calculate time, add to the time_array, delete the array.    

*Why?* -> the computer will not remember how to sort in one way (to make adjustments and improve itself) because each time we sort with a different algorithm.

#### How we print the results:
Take a look at the *statistic_final.txt*. Again, we will take as an example merge_sort. It has 3 big rectangles(Reversed.txt, sorted.txt, random.txt). Each of these has 4 lines starting with : 10^4, 10^5, 10^6, 10^6. On the wright side of them are some numbers which represents a test finished in x seconds. At the end of each line is an Averge after some tests.

#### What about that PowerPoint?
All of the results from the *statistic_final.txt* are represented on graph on the powerpoint. Furthermore, there are interesting facts about each sorting algortihm and more details about the invornment in which the tests were made.

#### Easter Egg:
There is one more [.txt](https://github.com/MihaiB-dev/Data_Structures/blob/main/tema1/final_comparati.txt) that we haven't talked about. Those results were made from just 10 test, so don't take them seriously. (The text is in Romanian)

## Final Thoughts:
I've learned so much during this project, from sorting to anaylze data. Thnaks for staying with me till this moment. Good day!


