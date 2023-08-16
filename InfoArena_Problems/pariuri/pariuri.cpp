#include <iostream>
#include <fstream>
#include <unordered_map>
using namespace std;

int main(){
    ifstream fin("pariuri.in"); ofstream fout("pariuri.out");
    short N,M;
    unordered_map<long, long> timp_sume;
    long timp;
    int suma;
    fin>>N;
    for(short i = 0; i < N; i ++)
    {
        fin>>M;
        for(short j = 0; j < M; j++)
        {
            fin >> timp >> suma;
            if(timp_sume.find(timp) == timp_sume.end())
            {
                timp_sume[timp] = suma;
            }
            else
            {
                timp_sume[timp] +=suma;
            }
        }
    }
    fout<<timp_sume.size()<<endl;
    for (auto& it: timp_sume) {
    fout << it.first << " "<<it.second << " ";
}
    return 0;
}