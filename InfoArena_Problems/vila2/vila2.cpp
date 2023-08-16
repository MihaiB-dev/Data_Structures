#include <iostream>
#include <deque>
#include <fstream>
#include <vector>
using namespace std;

// class MinMax{
//     public:
//     deque<int> min;
//     deque<int> max;
    

//     void add_pop(vector<int>person, int i,int k){
//         while(!max.empty() && person[max.back()] < person[i])max.pop_back();//while we have numbers in queue smaller than original, we pop

//         while(!min.empty() && person[min.back()] > person[i])min.pop_back();//while we have numbers in quere grater than original, we pop

//         min.push_back(i); // the smallest number is in front
//         max.push_back(i); // the biggest number is in front

//         if(i >= k && max.front() <= i - k)max.pop_front();//each time after we pass the first k elements we pop

//         if(i >= k && min.front() <= i - k)min.pop_front();//each time after we pass the first k elements we pop


//     }   
// };
int main(){
    ifstream fin("vila2.in");
    ofstream fout("vila2.out");

    
    int N,K,diff = 0; 
    // N = number of houses
    //K = the subdomains of the residence
    // x = each person.
    // max = the maximum differnece

    fin>>N>>K;
    K = K + 1;
    vector<int> person(N);
    // MinMax minmax;
    deque<int> min;
    deque<int> max;
    
    for(int i = 0; i < N; i++) // add people in the vector
    {
        
        fin >> person[i]; // read the number
        while(!max.empty() && person[max.back()] < person[i])max.pop_back();//while we have numbers in queue smaller than original, we pop

        while(!min.empty() && person[min.back()] > person[i])min.pop_back();//while we have numbers in quere grater than original, we pop

        min.push_back(i); // the smallest number is in front
        max.push_back(i); // the biggest number is in front

        if(i >= K && max.front() <= i - K)max.pop_front();//each time after we pass the first k elements we pop

        if(i >= K && min.front() <= i - K)min.pop_front();//each time after we pass the first k elements we pop


            
        //minmax.add_pop(person,i,K); // add the person position in min max and make it stable.

        if(i >= K - 1)
        {
            int diff_temp = person[max.front()] -person[min.front()];
            if(diff_temp > diff)diff = diff_temp;
        }
    }
    
    fout << diff << endl;
    //calculate for the last pair of numbers


}