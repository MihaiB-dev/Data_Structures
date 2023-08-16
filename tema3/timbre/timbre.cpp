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
    vector<pair<int, int>> timbre_intervale(M); //aici se afla toate intervalele de tip {margine_superioara, pret}
    for(short i = 0; i < M; i ++)
    {   
        fin>>mi>>ci;
        //timbre_intervale[i] = {mi,ci};
        timbre_intervale[i].first = mi;
        timbre_intervale[i].second = ci;
    }//adaugam intrvalele in vector sub forma de tuple

    while(N > 0)//cat timp mai avem timbre de pus in clasor
    {   
        short max_price = 10000;
        short val = 0;
        for(short i = 0; i < M; i++)//trecem prin fiecare interval
            if(timbre_intervale[i].first >= N && timbre_intervale[i].second < max_price)
            {
                max_price = timbre_intervale[i].second;
                val = i;
            }

        N -= K;
        sum += max_price; // max price este acum cel mai mic numar mai mare e cat N (succesor)
        timbre_intervale[val].first = 0; //scoatem din considerare valoarea efectuata deoarece putem lua o singura data dintr-un interval

    }
    fout << sum;
}