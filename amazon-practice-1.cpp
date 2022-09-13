#include<bits/stdc++.h>
using namespace std;
/* 1. Minimum number of Jumps */
/* Given an array of N integers arr[] where each element represents 
the max length of the jump that can be made forward from that element. 
Find the minimum number of jumps to reach the end of the array 
(starting from the first element). If an element is 0, then you cannot 
move through that element.
Note: Return -1 if you can't reach the end of the array.
https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1?page=1&difficulty[]=1&company[]=Amazon&curated[]=1&sortBy=submissions
*/

class Solution{
  public:
    int minJumps(int arr[], int n){
        // Your code here
        if(n==1)
            return 0;
        if(arr[0]==0)
            return -1;
        
        int hault=0, jump =0, maxi=0;
        for(int i=0; i<n; i++){
            if(arr[i]==0)
                return -1;
            maxi = max(maxi,i+arr[i]);
            if(maxi>=n-1){
                jump++;
                return jump;
            }
            if(i==hault){
                hault=maxi;
                jump++;
            }
        }    
        
        if(hault>=n-1)
            return jump;
        return -1;
    }
};


int main(){
    cout<<"Amazon practice in online IDE\n";
    return 0;
}