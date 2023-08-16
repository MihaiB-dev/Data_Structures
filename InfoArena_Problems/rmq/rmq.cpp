#include <iostream>
#include <fstream>
using namespace std;
const int maxel = 100001;
const int log = 17; //log(max)
int rmq[maxel][log]; //create a matrix for RMQ

int query(int left, int right){
  int length = right-left + 1;
  int k = 0;
  while(1 << (k+1) <= length)k++; //other way to say log(length) but safer

  return min(rmq[left][k], rmq[right - (1<<k) + 1][k]);
  //it's not a problem if we have overlap
  //Example for the formula:
  //0 1 2 3 4 5 6 7 8 9 10
  //    |---------| we have left = 2 right = 7 k = 4 (return the min. in the range 2 to 7)
  //    |-----|     m[left][k]  (min from 2 - 5 (k blocks)(starting from left index))
  //        |-----| m[dr - (1<<k) + 1][k] (min from 4-7 (k blocks)(goes from the right side to left for k blocks))
}

int main(){
    ifstream fin("rmq.in");
    ofstream fout("rmq.out");

    int N,M;// N = number of elements, M = interogations
    int st,dr;//[st,dr] = intervalul din care cautam minimul la interogations
    
    fin >> N >> M;

    for(int i = 0; i < N; i ++)fin >> rmq[i][0]; //put all the elements in the matrix

    for(int j = 1; j < log; j ++)
      for(int i = 0; i <= N - (1<<j); i++)
        //when we calculate for th bigger buckets, we will in fact look the the minimums of the smaller ones.
        rmq[i][j] = min(rmq[i][j-1], rmq[i+ (1<<(j-1))][j-1]);

    //0 1 2 3 4 5 6 7 8 9 10 11 12
    //      |-----|
    //              |------|
    //      |--------------|
    //Calculate the minimum for index(3) (i = 3) for log(8) = 3
    //we make the minimum for the last 2, for less redundency

    for(int i = 0; i < M; i++)
    {
      fin >> st >> dr;
      st--;
      dr--;
      fout << query(st,dr) << endl;
    }
}