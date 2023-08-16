#include <iostream>
#include <fstream>
using namespace std;
const int maxel = 100001;
const int log = 17; //log(max)
int rmq[maxel][log]; //cream matricea pentru rmq

int query(int st, int dr){
  int lungime = dr-st + 1;
  int k = 0;
  while(1 << (k+1) <= lungime)k++;
  //exemplu lungime = 17
  //alege cea mai mare putere a lui 2 pana in 17
  // 1, 2, 4, 8, 16
  //=> k = 4 (2^4)
  return min(rmq[st][k], rmq[dr - (1<<k) + 1][k]);
  //nu este o problema daca avem "overlap"
  //0 1 2 3 4 5 6 7 8 9 10
  //    |---------| avem st = 2 dr = 7 k = 4
  //    |-----|     m[st][k]
  //        |-----| m[dr - (1<<k) + 1][k]
}

int main(){
    ifstream fin("rmq.in");
    ofstream fout("rmq.out");

    int N,M;// N = nr elemente, M = interogari
    int st,dr;//[st,dr] = intervalul din care cautam minimul la interogari
    
    fin >> N >> M;

    for(int i = 0; i < N; i ++)fin >> rmq[i][0]; //punem toate elementele in matrice

    for(int j = 1; j < log; j ++)
      for(int i = 0; i <= N - (1<<j); i++)
        rmq[i][j] = min(rmq[i][j-1], rmq[i+ (1<<(j-1))][j-1]);//atunci cand calcuam pentru bucket-uri mai mari, vedem minimul din cele mai mici.
    //0 1 2 3 4 5 6 7 8 9 10 11 12
    //      |-----|
    //              |------|
    //      |--------------|
    //cand calculam minimul pentru index(3) la log(8)= 3
    //facem minimul din ultimele 2, ca sa nu pierdem timp

    for(int i = 0; i < M; i++)
    {
      fin >> st >> dr;
      st--;
      dr--;
      fout << query(st,dr) << endl;
    }
}