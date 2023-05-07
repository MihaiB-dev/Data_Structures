#include <iostream>
#include <deque>
#include <algorithm>
#include <fstream>
using namespace std;

long calculate_min(deque<long> deque){
    long min = *deque.begin();
    for(auto p = deque.begin(); p != deque.end(); ++p){
        if(*p < min){min = *p;}
    }
    return min;
}
int main(){
    deque<long> deque;
    int N,K; // N <= 5.000.000, 1 <= K <= N
    long sum = 0;
    ifstream fin("deque.in");
    ofstream fout("deque.out");

    fin>>N>>K;
    long x;
    //K = elements in deque, N = total numbers
    for(int i = 0; i < K; i++){ // first , we put numbers in deque

        fin>>x;
        deque.push_back(x);
    }
    //then, for the other numbers N-K, we calculate the min , pop first and push next
    long min = calculate_min(deque);
    cout<<min<< " ";
    sum+=min;
    int i = 0;
    do{
        deque.pop_front();
        fin>>x;
        if(x < min){min = x;}
        deque.push_back(x);
        sum+=min;
        cout<<min<< " ";
        i++;
    }while(i < (N-K));
    // for(int i = 0; i < N-K;i++){
        
       
    // }

    sum+=min;
    cout<<min<< " ";
    fout<<sum;

    return 0;
}