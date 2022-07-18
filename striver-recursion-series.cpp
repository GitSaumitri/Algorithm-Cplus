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
    4a. Find the reverse of an array (functional recursion) 
    4b. check if the string is a palindrom (functional recursion)
    5a. fibonacci series (multiple recursion)
    6. Print subsequences
      - maintain order of elements / otherwise it's a subarray
      - alternative way is through powerset
    7. Printing subsequences whose sum is K
        - 
*/


#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class recursionSeries{
    public:
    void printSubsequences(int ind, vector<int>& ds, int arr[], int n);

};

int main(){
    recursionSeries ob;

    // 6. Printing subsequences
    int arr[] = {3,2,1}; int n = 3; vector<int> ds;
    cout<<"Print Subsequences"<<endl;
    ob.printSubsequences(0, ds, arr, n);

}

/* 6. Printing subsequence
        -  take/pick (index) | not-take/not-pick (index)
        - take call -> remove that element -> not-take call
        - for every index two options - O(2 ^ n) X to print O(n)
        - space - O(n) - max calls in recurssion is maximum 3
*/
void recursionSeries::printSubsequences(int ind, vector<int>& ds, int arr[], int n){
    if(ind == n){
        cout<<"{ ";
        for(auto it: ds){
            cout<< it<<" ";
        }
        cout<<"} ";
        return;
    }
    // take or pick the particular index into the subsequence
    ds.push_back(arr[ind]);
    printSubsequences(ind+1, ds, arr, n);
    ds.pop_back();

    //not pick or not take condition, this element is not added to your subsequence
    printSubsequences(ind+1, ds, arr, n);
}

/* 7. Printing subsequences whose SUM is K
    - 
*/