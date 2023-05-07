#include <iostream>
#include <deque>
#include <fstream>

using namespace std;

class MinMax{
    int min;
    int max;
    

    void calculate_Min_max(deque<int>person){
        for(auto i = person.begin(); i != person.end(); i++)
        {
            if(*i<min){min = *i;}
            if(*i > max){max = *i;}
        }
    }

    public:
    MinMax(): min(30001), max(0){};
    int difference_min_max(deque<int>person){
        calculate_Min_max(person);
        return max-min;
    }
};
int main(){
    ifstream fin("vila2.in");
    ofstream fout("vila2.out");

    deque<int>person;
    int N,K,x,max=0; 
    // N = number of houses
    //K = the subdomains of the residence
    // x = each person.
    // max = the maximum differnece

    fin>>N>>K;

    for(int i = 0; i <= K; i++)
    {
        fin>>x;
        person.push_back(x);
    }
    for(int i = 0; i < (N-K); i++)
    {
        MinMax minmax;
        int diff = minmax.difference_min_max(person);
        if (diff > max)
        {
            max = diff;
        }
        fin>>x;
        person.pop_front();
        person.push_back(x);
    }

    //calculate for the last pair of numbers
    MinMax minmax;
    int diff = minmax.difference_min_max(person);
    if (diff > max)
    {
        max = diff;
    }


    fout << max;
}