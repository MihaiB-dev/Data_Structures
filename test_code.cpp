#include <iostream>
#include <fstream>
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
{   int j;
    for(int i = 1; i < n; i++)
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
int main(){
    ifstream fin("tester/reversed_10000000.txt");
    long v[NUMBER],p;
    for(p = 0; p < NUMBER; p++)fin >> v[p]; //citirea array-ului

    //add sort algorithm
    //merge_sort(0,99,v);
    //shell_sort(NUMBER,v);
    //insertion(NUMBER,v);
    for(p = 0; p < NUMBER; p++)cout<< v[p]<<" ";
}