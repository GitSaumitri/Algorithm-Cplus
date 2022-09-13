#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:

/* 1. Minimum number of Jumps */
/* Given an array of N integers arr[] where each element represents 
the max length of the jump that can be made forward from that element. 
Find the minimum number of jumps to reach the end of the array 
(starting from the first element). If an element is 0, then you cannot 
move through that element.
Note: Return -1 if you can't reach the end of the array.
https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1?page=1&difficulty[]=1&company[]=Amazon&curated[]=1&sortBy=submissions
*/
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


/*    Kadane's Algorithm
Given an array Arr[] of N integers. Find the contiguous sub-array(containing at least one number) which has the maximum sum and return its sum.
https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1?page=1&difficulty[]=1&company[]=Amazon&curated[]=1&sortBy=submissions
*/
    long long max(long long a, long long b){
        if(a > b)
            return a;
        return b;
    }
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        
        // Your code here
        long long res=INT_MIN, sum=0;
        
        for(int i=0; i<n; i++){
            sum += arr[i];
            res = max(res, sum);
            sum = max(sum, 0);
        }
        return res;
        
    }

/* Kth smallest element
Given an array arr[] and an integer K where K is smaller than size of array, the task is to find the Kth smallest element in the given array. It is given that all array elements are distinct.
https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1?page=1&difficulty[]=1&company[]=Amazon&curated[]=1&sortBy=submissions
*/
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        //code here
        priority_queue <int> pq;
        for(int i=0; i<= r; i++){
            pq.push(arr[i]);
        }
        
        while(pq.size()>k){
            pq.pop();
        }
        return pq.top();
    }

    //O(n) - using partition algorith 
    // use random element as pivot then partition the array into two parts
    // https://takeuforward.org/data-structure/kth-largest-smallest-element-in-an-array/

/* Maximum of all subarrays of size k
Given an array arr[] of size N and an integer K. Find the maximum for each and every contiguous subarray of size K.
https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1?page=1&difficulty[]=1&company[]=Amazon&curated[]=1&sortBy=submissions
- set we can't store duplicate elements so we need to take a multiset
- 
*/
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        // your code here
        vector<int> res;
        multiset<int> ms;
        
        for(int i=0; i<n; i++){
            if(i<k-1){
                ms.insert(arr[i]);
            }else{
                ms.insert(arr[i]);
                res.push_back(*ms.rbegin());
                ms.erase(ms.find(arr[i-k+1]));
            }
        }
        
        return res;
    }

/* Zero sum subarrays
You are given an array arr[] of size n. Find the total count of sub-arrays having their sum equal to 0.
https://practice.geeksforgeeks.org/problems/zero-sum-subarrays1825/1?page=1&difficulty[]=1&company[]=Amazon&curated[]=1&sortBy=submissions

We have to calculate the number of subarrays with sum=0 in this array. 
We will make a hashmap (basically a frequency map) that will store the sum vs frequency of that sum. 
Also, initially when we are at index =-1 (hypothetically), the sum is 0. 
So, we already have sum 0-1 in the hashmap i.e. frequency of sum 0 is 1.
*/
typedef long long ll;
    //Function to count subarrays with sum equal to 0.
    ll findSubarray(vector<ll> arr, int n ) {
        //code here
        int count  = 0;
        unordered_map<ll,int> hmap;
        int i=-1;
        ll sum = 0;
        hmap[sum]=1;
        while(i < (n-1)) {
            i++;
            sum += arr[i];
            if(hmap.count(sum)) {
                //cout<<"-- "<<count<<"sum "<<sum<<endl;
                count += hmap[sum];
                hmap[sum] = hmap[sum]+1; 
            } else {  
                hmap[sum]=1;
            }
        }
        return count;
    }

/* Rotten oranges
Given a grid of dimension nxm where each cell in the grid can have values 0, 1 or 2 which has the following meaning:
0 : Empty cell
1 : Cells have fresh oranges
2 : Cells have rotten oranges

We have to determine what is the minimum time required to rot all oranges. A rotten orange at index [i,j] can rot other fresh orange at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit time. 
https://practice.geeksforgeeks.org/problems/rotten-oranges2536/1?page=2&difficulty[]=1&company[]=Amazon&curated[]=1&sortBy=submissions
*/
 //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int fresh=0;
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        int vis[m][n]={0};
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }else{
                    vis[i][j]=0;
                }   
                if(grid[i][j]==1)
                    fresh++;
            }
        }
        int tm=0;
        int cnt=0;
        vector<vector<int>>dir({{-1,0},{0,-1},{1,0},{0,1}});
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            tm = max(tm,t);
            for(int i=0; i<4; i++){
                int nr = r + dir[i][0];
                int nc = c + dir[i][1];
                if(nr>=0 && nr<m && nc>=0 && nc<n &&
                    grid[nr][nc]==1 && vis[nr][nc]!=2){
                    vis[nr][nc]=2;
                    q.push({{nr,nc},t+1});
                    cnt++;
                }
            }
        }
        if(cnt!=fresh)
            return -1;
        return tm;
    }

};





int main(){
    cout<<"Amazon practice in online IDE\n";
    return 0;
}