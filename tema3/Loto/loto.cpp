#include <iostream>
#include <fstream>
#include <unordered_map>
using namespace std;

// Idee :
//Facem un hash cu toate sumele posibile din cele N numere. (le punem 3 cate 3)
//Atunci cand punem in hash fiecare suma verficiam daca adunat cu o alta suma din trecut daca suma S. 
//Daca de afisam.
int main()
{
    ifstream fin("loto.in");
    ofstream fout("loto.out");
    short N;
    int S;
    unordered_map<int,int[3]> sume;
    bool gasit = false; //daca gasim o suma buna atunci gasit = true si printam rez
    fin>>N>>S;
    int nr[101];
    for(short i = 0; i < N; i++){fin>>nr[i];}

    for(short i = 0; i < N && !gasit; i++)
        for(short j = 0; j < N && !gasit; j++)
            for(short p = 0; p < N && !gasit; p++)
                {   
                    sume[nr[i]+nr[j]+nr[p]][0]= nr[i];
                    sume[nr[i]+nr[j]+nr[p]][1]= nr[j];
                    sume[nr[i]+nr[j]+nr[p]][2]= nr[p];
                    int difference = S -(nr[i]+nr[j]+nr[p]);
                    if(sume.find(difference)!= sume.end())//am gasit o rezolvare
                    {
                        fout << nr[i] <<" " << nr[j] << " " << nr[p] << " " << sume[difference][0] << " " << sume[difference][1] << " " << sume[difference][2];
                        gasit = true;
                    }
                }
    if(!gasit)fout<<-1;

    return 0;
}