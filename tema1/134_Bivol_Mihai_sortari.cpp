# include <iostream>
#include <fstream>
#include <chrono> //for clock
#include <string>
#include <cmath>//for heap sort
#include "progressbar.hpp" //progress bar
using namespace std;

#define TEST_INPUT_NUMBER 3 // cate fisiere de inputuri vrei sa puneti (default 3)
#define SORT_NUMBER 5 //need to be 5
#define NUMBER_TESTS 1 //cate teste vreti sa se faca pentru fiecare sortare
#define POWER_10 3 //starts from 10^4 and goes to 10^4*(10^3)
//global arrays for each sort algorithm
float V_merge[TEST_INPUT_NUMBER][NUMBER_TESTS*POWER_10];
float V_shell[TEST_INPUT_NUMBER][NUMBER_TESTS*POWER_10];
float V_insertion[TEST_INPUT_NUMBER][NUMBER_TESTS*POWER_10];
float V_heap[TEST_INPUT_NUMBER][NUMBER_TESTS*POWER_10];
float V_radix[TEST_INPUT_NUMBER][NUMBER_TESTS*POWER_10];

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

void insertion_sort(long n,long v[])
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

//heap_sort -------------------------
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
//end heap_sort ----------------------
int Max(long v[], long n){
    int max = v[0];
    for(int i = 0;i<n; i++) if (v[i]> max) max = v[i];
    return max;
    }
void countSort(long n, long v[], long poz)
{
    int max = 10;
    int bucket[n], count[max] ={0};

    for(int i = 0; i < n; i++) count[(v[i]/poz)%10]++; //calculam un contor pentru elemente

    for(int i = 1; i < max; i++) count[i] += count[i-1]; 

    for(int i = n - 1; i>= 0; i--) //punem elementele in ordinea buna, descrescator
    {
        bucket[count[(v[i]/poz)%10] - 1] = v[i];
        count[(v[i]/poz)%10]--;
    }

    for(int i = 0; i < n; i++) v[i]= bucket[i];
}
void radix_sort(long n, long v[])
{  
    long max = Max(v,n);
    for (int poz = 1; max/poz > 0; poz*=10) countSort(n,v,poz);
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
void calculate_heap_sort(int i, int j, long SIZE, long v[])
{
    auto begin = std::chrono::high_resolution_clock::now();
    heap_sort(SIZE,v);

    //end the clock
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

    V_heap[i][j] = elapsed.count()* 1e-9;
}
void calculate_radix_sort(int i, int j, long SIZE, long v[])
{
    auto begin = std::chrono::high_resolution_clock::now();
    radix_sort(SIZE,v);

    //end the clock
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

    V_radix[i][j] = elapsed.count()* 1e-9;
}

void create_time_vectors(string ultra_tester[], string sort_algorithm[]){
    progressbar bar(TEST_INPUT_NUMBER*POWER_10*NUMBER_TESTS*SORT_NUMBER);
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
                        else if(sort_algorithm[sort] == "insertion_sort" && SIZE < 1000000)
                            {calculate_insertion_sort(i,j,SIZE,v);}
                        else if(sort_algorithm[sort] == "heap_sort")
                            {calculate_heap_sort(i,j,SIZE,v);}
                        else if(sort_algorithm[sort] == "radix_sort")
                            {calculate_radix_sort(i,j,SIZE,v);}
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

void template_write_vector(float v[][NUMBER_TESTS*POWER_10],string ultra_tester[],ofstream& fout)
{ 
    for(int a = 0; a < TEST_INPUT_NUMBER; a++)
                    {   fout << ultra_tester[a] << ": "<<endl;
                        for(int input = 0; input < POWER_10; input ++)
                            {   float sum = 0;
                                fout << pow(10.0,POWER_10) * pow(10.0,input)<< ": ";
                                for(int number=input * NUMBER_TESTS; number < input * NUMBER_TESTS + NUMBER_TESTS; number++ )
                                {
                                    sum += v[a][number];
                                    fout << v[a][number] << " ";
                                }
                                fout << "Avg: " << sum/NUMBER_TESTS << endl;
                            }
                        fout<<endl;
                        
                    }
    fout << endl;
}
void write_time_vectors(string ultra_tester[], string sort_algorithm[])
{   ofstream fout("statistic.txt");
    progressbar vbar(TEST_INPUT_NUMBER*NUMBER_TESTS*POWER_10);
    for(int sort = 0; sort< SORT_NUMBER; sort++)
        {
            fout<<sort_algorithm[sort]<<":"<<endl<<endl;
            // if (sort_algorithm[sort] == "merge_sort") 
            //     {template_write_vector(V_merge,ultra_tester,fout);}
            // else if (sort_algorithm[sort] == "shell_sort") 
                {template_write_vector(V_shell,ultra_tester,fout);}
             if(sort_algorithm[sort] == "insertion_sort")
                {template_write_vector(V_insertion,ultra_tester,fout);}
            else if(sort_algorithm[sort] == "heap_sort")
                {template_write_vector(V_heap,ultra_tester,fout);}
            else if(sort_algorithm[sort] == "radix_sort")
                {template_write_vector(V_radix,ultra_tester,fout);}
            // {for(int j = 0; j< NUMBER_TESTS*POWER_10; j++)
            //     {
            //         vbar.update();
            //         fout<<V_merge[i][j]<<" ";
            //     }
            
        fout<<endl;
        }
}
int main(){
    string ultra_tester[TEST_INPUT_NUMBER] = {"reversed.txt","sorted.txt","random.txt"}; //puteti sa adaugati cate input-uri doriti, sa aveti grija sa sa aiba size-ul respectiv lui 10^4*10^POWER_10 numere. si sa se schimbe test_input_number respectiv la cate imput-uri aveti. 
    string sort_algorithm[SORT_NUMBER] = {"merge_sort","shell_sort","insertion_sort","heap_sort","radix_sort"};
    
    create_time_vectors(ultra_tester, sort_algorithm); //aceasat functie va popula vectorii globali cu timpurile de la fiecare algoritm de sortare.
    
    write_time_vectors(ultra_tester,sort_algorithm);

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
    
    //Compar Insertion sort cu Heap sort si radix sort pentru n^5 si n^4 la elementele sortate
    // i = 1 (pentru cele sortate)
    // ofstream fout("comparari.txt");
    // int i = 1;
    // for(int input = 0; input < 2; input++)//inseamna ca merge pentru n^4 si n^5
    // {   float V_a_b[NUMBER_TESTS];
    //     float V_c_d[NUMBER_TESTS];
    //     int p = 0;
    //     int u = 0;
    //     for(int number=input * NUMBER_TESTS; number < input * NUMBER_TESTS + NUMBER_TESTS; number++ )
    //     {
    //         V_a_b[p++] = V_heap[i][number]/V_insertion[i][number];
    //         V_c_d[u++] = V_radix[i][number]/V_insertion[i][number];
    //     }

    //     float mult_a = 1;
    //     float mult_c = 1;
    //     for(int i = 0; i < NUMBER_TESTS;i++)
    //     {
    //         mult_a *= V_a_b[i];
    //         mult_c *= V_c_d[i];

    //     }
    //     mult_a = pow(mult_a,1.0/NUMBER_TESTS);
    //     mult_c = pow(mult_c,1.0/NUMBER_TESTS);
    //     fout << "Insertion este de: " << mult_a << "ori mai bun de cat heap sort pentru " << pow(10.0,4) * pow(10.0,input)<<" numere"<<endl;
    //     fout << "Insertion este de: " << mult_c << "ori mai bun de cat radix sort pentru " << pow(10.0,4) * pow(10.0,input)<<" numere"<<endl;
    //     fout<<endl;
    // }

    // for(int s = 0; s < 3; s++)
    // {
    //     float V_a_b[NUMBER_TESTS];

    //     int p = 0;

    //     for(int number=3 * NUMBER_TESTS; number < 3 * NUMBER_TESTS + NUMBER_TESTS; number++ )
    //     {
    //         V_a_b[p++] = V_merge[s][number]/V_heap[s][number];
    //     }

    //     float mult_a = 1;

    //     for(int i = 0; i < NUMBER_TESTS;i++)
    //     {
    //         mult_a *= V_a_b[i];


    //     }
    //     mult_a = pow(mult_a,1.0/NUMBER_TESTS);

    //     fout << ultra_tester[s]<<": Heap_sort este de: " << mult_a << "ori mai bun de cat merge sort pentru " << 10000000 <<" numere"<<endl;

    //     fout<<endl;
    //}
    
}