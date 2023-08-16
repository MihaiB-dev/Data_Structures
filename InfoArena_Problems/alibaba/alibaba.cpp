#include <iostream>
#include <fstream>
#include <stack>

using namespace std;
int main(){
    ifstream fin("alibaba.in");
    ofstream fout("alibaba.out");
    int N,K;
    string large_number;

    fin>>N>>K;
    fin>>large_number;
    stack<char> numbers; //important to be char ! (easy to compare and print out), without char (large_number[i]-'0') to compare and add.

    //idea: I will use a stack to put numbers in it. When the read number is greater than the element in stack, we pop.

    for(int i = 0; i < N; i++)
    {
        while((numbers.empty() == false) && large_number[i] > numbers.top() && K!=0)
        {
            numbers.pop();
            K--;

        }
        numbers.push(large_number[i]); // we make sure that in the stack are elements in decending order. 
    }

    while( K!= 0) // if we have same values e.g 99999999999999999
    {
        numbers.pop();
        K--;
    }

     char p[10001]; //important char!
    //we create the number from the stack;
    int i = 0;
    while(!numbers.empty()){
        p[i] = numbers.top();
        numbers.pop();
        i++;
    }
    for(int j = i-1; j >=0; j --)
    {
        fout<<p[j];
    }

    return 0;
}