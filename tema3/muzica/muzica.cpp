#include <iostream>
#include <unordered_map>
#include <fstream>
#include <vector>
using namespace std;
#define P 666013
int main()
{
    ifstream fin("muzica.in");
    ofstream fout("muzica.out");


    unordered_map<int,vector<long>> muzica_vasile;
    //when found we change the umber to -1
    int N,M;
    long A,B,C,D,E;
    long X;
    fin>>N>>M>>A>>B>>C>>D>>E;

    //punem in hash valorile melodiile
    for(int i = 0; i < N; i++)
    {
        fin>>X;
        muzica_vasile[X%P].push_back(X);
    }
    long counter = 0;
    //solve foor the first 2 elements
    //R[0] = A
    int R_first = A;
    int R_second = B;

    auto it = muzica_vasile.find(R_first%P);
    if(it != muzica_vasile.end())
        for(auto& v : it->second)//for the first element
        {
            if(v == R_first)
            {
                v = -1;
                counter++;
                break;
            }
        }

    it = muzica_vasile.find(R_second%P);
    if(it != muzica_vasile.end())
        for( auto& v : it->second)//for the first element
        {
            if(v == R_second)
            {
                v = -1;
                counter++;
                break;
            }
        }
    
    int R_now;
    for(int i = 3; i <= M; i++)//for the rest of the elements
    {
        R_now = (C* R_second + D* R_first)%E;
        it = muzica_vasile.find(R_now%P);
        if(it != muzica_vasile.end())
            for( auto& v : it->second)
            {
                if(v == R_now)
                {
                    v = -1;
                    counter++;
                    break;
                }
            }
        R_first = R_second;
        R_second = R_now;
    }

    fout << counter;
}