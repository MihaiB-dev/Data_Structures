#include <iostream>
#include <fstream>
#include <vector>
#include <utility>

using namespace std;

int main()
{
    ifstream fin("timbre.in"); ofstream fout("timbre.out");
    
    short N,M,K,sum = 0;
    int mi, ci;

    fin>>N>>M>>K;
    vector<pair<int, int>> postage_interval(M); //here there are all intervals of type: {top margin, price}
    for(short i = 0; i < M; i ++)
    {   
        fin>>mi>>ci;
        //postage_interval[i] = {mi,ci};
        postage_interval[i].first = mi;
        postage_interval[i].second = ci;
    }//add new intervals into vector as a tuple

    while(N > 0)//cat timp mai avem timbre de pus in clasor
    {   
        short max_price = 10000;
        short val = 0;
        for(short i = 0; i < M; i++)//goes throw each interval
            if(postage_interval[i].first >= N && postage_interval[i].second < max_price)
            {
                max_price = postage_interval[i].second;
                val = i;
            }

        N -= K; 
        sum += max_price; //Now max price is the smaller number bigger than N (succesor)
        timbre_intervale[val].first = 0; //get rid of top margin as we can get only one time an interval
        
    }
    fout << sum;
}