#include <iostream>
#include <stack>
#include <fstream>
#include <cstring>
#include <vector>
using namespace std;

int main(){
    
    ifstream fin("paranteze.in");
    ofstream fout("paranteze.out");
    int nr;
    fin>>nr;

    if(nr == 0){fout<<0;return 0;}//verify if it's vid

    string brackets;
    stack<int> stack; //create the stack
    vector<int> vec; // create a vector
    vec.resize(nr); //length of the vector is now equal to the length of the brackets string
    //idea : we go for each bracket in brackets and verify the requirments. Then, we will add 1's to the positions of the brackets where were good
    //after that, the max is the line with the most 1's consecutive.
    fin>>brackets;

    for(int i = 0; i < nr; i++)
    {
        if(brackets[i] == '(' || brackets[i] == '[' || brackets[i] == '{') // if it's an open bracket
        {stack.push(i);} // we add the closing bracket to the stack
        else
        if(stack.empty() == false) //if it is something in the stack, we make sure that if it's the stack empty , we don't compile stack.top()
        {
            if((brackets[i] == ')' && brackets[stack.top()] == '(') || (brackets[i] == ']' && brackets[stack.top()] == '[') || (brackets[i] == '}' && brackets[stack.top()] == '{')) // if it's a closing bracket
            {
                vec[i] = 1; // we have 1 on the closed bracket
                vec[stack.top()] = 1; // we have 1 on the open bracket
                stack.pop(); // now we remove the open bracket from the stack
            }else{stack.push(i);}
        }
    }
    int max = 0;
    int current = 0;
    for(int i = 0; i < nr; i++)//we make the second for to go for each elem in vector which is equal to 1
    {
        if(vec[i] == 1){
            current++;
            if (current > max){
                max = current;
            }
        }else{
            current = 0;
        }
    }
    fout << max;

    //other idea: we put in stack ( [ { , and when we find one, we pop it, if we have a good array of brackets != 0, we put in stack 'p' so that we know that there we did something with brackets. 
    //if we enounter next to it another number of good brackets we will make if we have this "p" before. If we have it we will sum the 2 lengths of those, and so on.
    //if we don't have p, we know that in the past it's someting wrong, so now we have a new set of good brackets.

    // int count = 0;
    // int count_past = 0;
    // int max = 0;
    // char const* start = "s";
    // fin>>brackets; //read the string of brackets

    // stack.push(*start);

    // stack.push(brackets[0]);
    // for(int i = 1;i < nr; i++)
    // {
    //     string sym(1, stack.top());
    //     const char* top = sym.c_str();

    //     if(strcmp(top,"s") == 0){stack.push(brackets[i]);}//if the stack is empty
    //     else{// for { } brackets

    //         string sym2(1, brackets[i]);
    //         const char* bracket = sym2.c_str();
            
    //         if(strcmp(bracket,"}") == 0){

    //             if(strcmp(top,"{")==0){count+=2;stack.pop();} //add to count and remove { from stack.
    //                 else{
    //                     count_past = count;
    //                     count=0;
    //                     stack.push(brackets[i]);
    //                     }//verify the count with max, make the count 0 and push the bracket

    //         }else if(strcmp(bracket,"]") == 0){

    //             if(strcmp(top,"[")==0){count+=2;stack.pop();} //add to count and remove { from stack.
    //                 else{
    //                     count_past = count;
    //                     count=0;
    //                     stack.push(brackets[i]);
    //                     }//verify the count with max, make the count 0 and push the bracket

    //         }else if(strcmp(bracket,")") == 0){

    //             if(strcmp(top,"(")==0){count+=2;stack.pop();} //add to count and remove { from stack.
    //                 else{
    //                     count_past = count;
    //                     count=0;
    //                     stack.push(brackets[i]);
    //                     }//verify the count with max, make the count 0 and push the bracket

    //         }else {
    //             if(strcmp(top,"p")==0){
    //                 if(count != 0){
    //                     stack.pop();
    //                     if(count_past == max){max = count + max; count_past = max;}
    //                     else{count_past += count;}
    //                 }
    //             }
    //             else if(count > max){max = count;}
            
    //             //case : count_past = count; daca merge mai sus
    //             //case : count_past = 0; daca nu sunt unele langa altele
    //             if(count!=0){
    //                 count_past = count;
    //                 count=0;
    //                 char const* p = "p";
    //                 stack.push(*p);
    //             }
    //             stack.push(brackets[i]);
    //             }
    //      }    
            
    // }

    // string sym(1, stack.top());
    // const char* top = sym.c_str();
    // if(strcmp(top, "p") == 0){
    //     max = count + max;
    // }
    return 0;
    }