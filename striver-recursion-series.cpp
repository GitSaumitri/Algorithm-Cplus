/* strivers recursion/backtracking series 
    - When a function calls itself - recursion.
    - non completed or yet to be called functions are in - stack space
    - calling a function itself infinite times leads stack overflow
    - condition to stop recursion - boundary condition
    - recursion tree - visualize/practice
    - statements after the function call are excuted in reverse so backtracking <-
    - parametarised recursion - result is carring with paramters to recurssive call
        f(i, res+i)
    - functional recursion - result is the return value of the recursion function 
        return res + f(...)
    // 4a. Find the reverse of an array (functional recursion) 
    // 4b. check if the string is a palindrom (functional recursion)
    // 5a. fibonacci series (multiple recursion)
    // 6. Print subsequences
        - maintain order of elements / otherwise it's a subarray
        - alternative way is through powerset
    // 7. 
*/


#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class recursionSeries{
    public:

};

int main(){
    recursionSeries ob;

}

/* 6. Printing subsequence
        -  take (index) | not-take (index)
        - take -> remove -> take
*/