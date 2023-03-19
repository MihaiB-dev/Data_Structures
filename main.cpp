# include <iostream>
#include <fstream>
#include <chrono> //for clock
#include <string>
#include "progressbar.hpp" //progress bar
using namespace std;

#define TEST_INPUT_NUMBER 3
#define SORT_NUMBER 3 //need to be 5
#define NUMBER_TESTS 10
#define POWER_10 4 //starts from 10^4 and goes to 10^4*(10^3)
//global arrays for each sort algorithm
float V_merge[TEST_INPUT_NUMBER][NUMBER_TESTS*POWER_10];
float V_shell[TEST_INPUT_NUMBER][NUMBER_TESTS*POWER_10];
float V_insertion[TEST_INPUT_NUMBER][NUMBER_TESTS*POWER_10];

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
//create an array for each sorting algorithm 


void calculate_merge_sort(int i, int j, long SIZE, long v[]){   
    //start the clock
    auto begin = std::chrono::high_resolution_clock::now();
    merge_sort(0,SIZE-1,v);

    //end the clock
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

    V_merge[i][j] = elapsed.count()* 1e-9;
    }
void calculate_shell_sort(int i, int j, long SIZE, long v[])
{
    auto begin = std::chrono::high_resolution_clock::now();
    shell_sort(SIZE,v);

    //end the clock
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

    V_shell[i][j] = elapsed.count()* 1e-9;
}
void calculate_insertion_sort(int i, int j, long SIZE,long v[])
{
    auto begin = std::chrono::high_resolution_clock::now();
    insertion_sort(SIZE,v);

    //end the clock
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

    V_insertion[i][j] = elapsed.count()* 1e-9;
}

void create_time_vectors(string ultra_tester[], string sort_algorithm[]){
    progressbar bar(TEST_INPUT_NUMBER*4*10*SORT_NUMBER);
    int i = 0, j = 0; //vor ajuta la punerea valorilor in array-urile de sortari

    for (int poz = 0; poz < TEST_INPUT_NUMBER; poz ++) //merge prin fiecare tester 
    {   
        ifstream fin("tester/"+ultra_tester[poz]); //change which tester to make
        //ofstream fout("tester/"+long_tester[poz]+"solved.txt");
        long SIZE = 10000;
        for (int u = 0; u < POWER_10; u ++){ //for each 10^4 10^15 10^16 10^7
            for (int each_test = 0; each_test < NUMBER_TESTS; each_test++) 
                {
                for (int sort = 0; sort < SORT_NUMBER; sort++) //merge prin fiecare sortare
                    {  
                        long *v = new long[SIZE];
                        for(long p = 0; p < SIZE; p++)fin >> v[p]; //citirea array-ului
                        bar.update(); 
                        if (sort_algorithm[sort] == "merge_sort") 
                            {calculate_merge_sort(i,j,SIZE,v);}
                        else if (sort_algorithm[sort] == "shell_sort") 
                            {calculate_shell_sort(i,j,SIZE,v);}
                        else if(sort_algorithm[sort] == "insertion_sort" && SIZE < 10000000)
                            {calculate_insertion_sort(i,j,SIZE,v);}

                        delete [] v;
                        //cout << "Test " << each_test << ", time for " +  sort_algorithm[sort] + " using " + ultra_tester[poz] + " is : "<< elapsed.count()* 1e-9 << " seconds"<<endl;
                    }
                j++;
                }
             // a trecut prin fiecare sortare si merge la urmatorul test
            SIZE *=10; // first time 10000, next 100000 and than 1000000...
        }  
        //cout << endl;
        fin.close();
        j = 0; //resetam val lui j
        i++;
    }
}
int main(){
    
    string ultra_tester[TEST_INPUT_NUMBER] = {"reversed_10000000.txt","sorted_10000000.txt","random_10000000.txt"};
    string sort_algorithm[SORT_NUMBER] = {"merge_sort","shell_sort","insertion_sort"};
    
    create_time_vectors(ultra_tester, sort_algorithm); //aceasat functie va popula vectorii globali cu timpurile de la fiecare algoritm de sortare.
    //Vectori: V_merge , 
    //Explicatie:
    
    //avem o matrice cu 3 lini si 30 col ce semifica:
    // test_input|  10.000  100.000  1.000.000  10.000.000
    //------------------------------------------------
    //i=0 Reversed [0,...9,10,...19,20,...,29,30,...,39] 
    //i=1 Sorted   [----------//-----------------------]
    //i=2 Random   [----------//-----------------------] 
    //Fiecare pozitie v[i][j] semnifica testul j%10 pentru test_input i
    // daca 0<j<9 -> facut pe 10.000 de numere
    // daca 10<j<19 -> facut pe 100.000 de numere
    // daca 20<j<29 -> facut pe 1.000.000 de numere
    // daca 30<j<39 -> facut pe 10.000.000 de numere

    for(int i = 0; i< TEST_INPUT_NUMBER; i++)
        {for(int j = 0; j< NUMBER_TESTS*POWER_10; j++)
            cout<<V_merge[i][j]<<" ";
        cout<<endl;}
}