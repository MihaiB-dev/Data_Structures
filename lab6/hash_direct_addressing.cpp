#include <iostream>
#include <fstream>
#include <climits>
#define P 666013

using namespace std;
int main(){
    ifstream fin("date.in");
    ofstream fout("date.out");
    int v[P] = {0};
    int x;
    while(fin>>x){
        int division = x%P;
        if(v[division] == 0)//inseamna ca nu se afla nimic in acea casuta
        {v[x%P] = x;}
        else
        {
            while(v[division] != 0)
            {
                division++;
                if(division > 666013){division = 0;}
            }
            v[division] = x;
        }

    }
    for(int i = 0; i < 10; i++){
        fout << v[i]<<endl;
    }
    return 0;

}