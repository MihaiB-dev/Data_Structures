#include <iostream>
#include <fstream>
#include <unordered_map>
using namespace std;

int main(){
    ifstream fin("pariuri.in"); ofstream fout("pariuri.out");
    short N,M;
    unordered_map<long, long> time_sum;
    long time;
    int sum;
    fin>>N;
    for(short i = 0; i < N; i ++)
    {
        fin>>M;
        for(short j = 0; j < M; j++)
        {
            fin >> time >> sum;
            if(time_sum.find(time) == time_sum.end())
            {
                time_sum[time] = sum;
            }
            else
            {
                time_sum[time] +=sum;
            }
        }
    }
    fout<<time_sum.size()<<endl;
    for (auto& it: time_sum) {
    fout << it.first << " "<<it.second << " ";
}
    return 0;
}