#include <iostream>
#include <fstream>

#include <cmath>//for heap sort
#define NUMBER 100000
using namespace std;
void merge_function(long inceput, long sfarsit,long mid, long v[]){
    long i = inceput, j = mid+1, k = 0;
    long *temp = new long[sfarsit-inceput+1];

    while(i<=mid && j <=sfarsit) if(v[i] < v[j]){temp[k++] = v[i++];} else{temp[k++] = v[j++];}

    while(i <= mid)temp[k++] = v[i++];

    while(j <= sfarsit)temp[k++] = v[j++];

    for(i = inceput,k = 0; i < sfarsit, k < sfarsit-inceput+1; k++, i++) v[i] = temp[k];

    delete [] temp;
}
void merge_sort(long inceput,long sfarsit,long v[]){
    if (inceput < sfarsit)
    {
        long mijloc = (sfarsit-inceput)/2 + inceput;
        merge_sort(inceput, mijloc, v);
        merge_sort(mijloc+1, sfarsit, v);

        merge_function(inceput,sfarsit,mijloc, v);
    }
}

void shell_sort(long n,long v[])
{
    for(long gap = n/2;gap > 0; gap/=2)
        for(long i = gap; i<n;i++)
            for(long j=i-gap;j>=0 && v[j]>v[j+gap];j-=gap)
                swap(v[j],v[j+gap]);
}

void insertion(long n,long v[])
{   long j;
    for(long i = 1; i < n; i++)
    {
        long key = v[i];
        j = i -1;
        while(j>=0 && key < v[j])
        {
            v[j+1]=v[j];
            j--;  
        }
        v[j+1] = key;
    }
}


void swap(long from, long to,long v[])
{
    long tmp = v[from];
    v[from] = v[to];
    v[to] = tmp;
}

void trickle_up(long position,long v[])
{ 
    if (position == 0) return;
    long parent = floor((position-1)/2);
    if (v[position] > v[parent]){
        swap(position,parent,v);
        trickle_up(parent,v);
    }
}
void trickle_down(long parent,long last_position, long v[])
{
    long left = 2*parent+1;
    long right = 2*parent+2;

    if(left == last_position && v[parent] < v[left])
    {
        swap(parent,left,v);
        return;
    }
    if(right == last_position && v[parent] < v[right])
    {
        swap(parent,right,v);
        return;
    }
    if(left >= last_position || right >= last_position)return;

    if(v[left] > v[right] && v[parent]<v[left])
    {
        swap(parent,left,v);
        trickle_down(left,last_position,v);
    }
    else if(v[left] < v[right])
    {
        swap(parent,right,v);
        trickle_down(right,last_position,v);
    }
}

void create_max_heap(long last_position,long v[]){
    long solved = 0;
    for(long i=last_position; i> solved++; i --)trickle_up(i,v);
}
void remove(long last_position, long v[])
{
    // long tmp = v[0];
    swap(0,last_position--,v);
    trickle_down(0,last_position,v);

}

void heap_sort(long n, long v[])
{   n--;
    create_max_heap(n,v);
    long i = 0;
    while(n>=0)
    {
        remove(n--,v);
    }
}
int main(){
    ifstream fin("tester/random_10000000.txt");
    long v[NUMBER],p;
    for(p = 0; p < NUMBER; p++)fin >> v[p]; //citirea array-ului

    //add sort algorithm
    //merge_sort(0,99,v);
    //shell_sort(NUMBER,v);
    insertion(NUMBER,v);
    //heap_sort(NUMBER,v);
    //for(p = 0; p < NUMBER; p++)cout<< v[p]<<" ";
    return 0;
}