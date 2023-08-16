#include <iostream>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int main(){
ifstream fin("proc2.in");
ofstream fout("proc2.out");
priority_queue <long, vector<long>, greater<long> > min_heap;
priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > used_proc;

int N,M;
long start, end;
fin>>N>>M;
for(int i = 1; i <= N; i++)
{
    min_heap.push(i);
}
for(int i = 0; i < M; i++)
{
    fin>>start>>end;
    while(!used_proc.empty() && used_proc.top().first <= start)//when we found in the root a processor that is free
    {
        min_heap.push(used_proc.top().second);//we put back to our min heap of free processors
        used_proc.pop();
    }
    used_proc.push({start+end, min_heap.top()}); //add the top processor in used processors
    fout << min_heap.top()<<endl;

    min_heap.pop();
}
}