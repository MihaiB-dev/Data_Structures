# muzica

***Link: https://infoarena.ro/problema/muzica***   
Vasile found out that DJ Random will mix the playlist for the Freshmen's Ball of the Faculty of Mathematics and Informatics of the University of Bucharest. For simplicity, we will consider that each song can be encoded (using algorithms far too intelligent for Vasile) into 32-bit integers . Vasile also has a favorite playlist of his, and he is curious how many of the songs in his playlist are also in DJ Random's playlist.


DJ Random is quite lazy, and for this reason he will generate his songs in the following way: he chooses his first two songs R[ 1 ] = A and R[ 2 ] = B , and for the rest he will use the formula ***R[ i ] = (C * R[i - 1] + D * R[i - 2]) % E*** .

### Input data
The input file muzica.in will contain on the first line N , the number of songs from Vasile's playlist, and M , the number of songs from DJ Random's playlist. On the second line there are A , B , C , D and E , the constants with which DJ Random builds his playlist, and on the third line there are N numbers representing the songs in Vasile's playlist.

### Output data
In the output file muzica.out will be on the first line the number of songs from Vasile's playlist is also in D Random's playlist.

### limitation
- 3 ≤ N ≤ 10.000
- 3 ≤ M ≤ 10.000.000
- 1 ≤ A, B, C, D, E ≤ 1.000.000.000
- Every song has a 32-bit integer associated with it .
- It is guaranteed that Vasile is an original guy and has no two identical songs in his playlist.

### Example: 
muzica.in	   
3 4   
1 1 1 1 1000000000
1 2 7  
music.out:  
2

### Explanation
The songs in Vasile's playlist are: 1, 2, 7 , and those in DJ Random's playlist are: 1, 1, 2, 3 , so there are two songs that can be found in Vasile's playlist and in the playlist- DJ Random's, namely: 1 and 2 .