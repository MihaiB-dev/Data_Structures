#include <iostream>

using namespace std;

int main(){
    int length; //legnth <= 10^5
    string memory;
    cin>>length;
    cin>>memory;
    int camera[10]={0};
    for(int i = 0; i < length; i ++)
    {
        if (memory[i] == 'L'){
            for(int stanga = 0; stanga< 10; stanga ++)
            {
                if(camera[stanga] == 0){
                    camera[stanga] = 1; break;
                }
            }
        }
        else
        if(memory[i] == 'R'){
            for(int dreapta = 9; dreapta>=0; dreapta--)
            {
                if(camera[dreapta] == 0){
                    camera[dreapta] = 1;break;
                }
            }
        }
        else
        if(memory[i]>='0' && memory[i]<='9')
        {
            camera[memory[i]-'0'] = 0;
        }
    }

    for(int i = 0; i< 10; i++)
    {
        cout<<camera[i];
    }

    return 0;
}