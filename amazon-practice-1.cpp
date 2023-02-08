#include<bits/stdc++.h>
using namespace std;


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution{
  public:

/*
1. Biggest Island (easy)
2. 'K' Closest Points to the Origin (easy)
3. Right View of a Binary Tree (easy)
4. Number of Islands (Medium)
5. Merge 'K' Sorted Lists (medium)
6. Tasks Scheduling (medium)
7. Merge Intervals (medium)
8. Zigzag Traversal (medium)
9. Minimum Meeting Rooms (hard)
10. Alien Dictionary (hard)
*/

/* 1. Minimum number of Jumps */
    https://leetcode.com/problems/jump-game-ii/description/
/* Given an array of N integers arr[] where each element represents 
the max length of the jump that can be made forward from that element. 
Find the minimum number of jumps to reach the end of the array 
(starting from the first element). If an element is 0, then you cannot 
move through that element.
Note: Return -1 if you can't reach the end of the array.
https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1?page=1&difficulty[]=1&company[]=Amazon&curated[]=1&sortBy=submissions
-> try of the below example.
7
1 4 3 0 8 9 0
7
1 4 3 0 8 9 0
*/
  int max(int x, int y){
    return (x > y) ? x : y;
  }
  
  //public:
    int minJumps(int arr[], int n){
        // Your code here
        // The number of jumps needed to
        // reach the starting index is 0
        if (n <= 1)
            return 0;

        // Return -1 if not possible to jump
        if (arr[0] == 0)
            return -1;

        // initialization
        // stores all time the maximal
        // reachable index in the array.
        int maxReach = arr[0];

        // stores the number of steps
        // we can still take
        int step = arr[0];

        // stores the number of jumps
        // necessary to reach that maximal
        // reachable position.
        int jump = 1;

        // Start traversing array
        int i = 1;
        for (i = 1; i < n; i++) {
            // Check if we have reached the end of the array
            if (i == n - 1)
                return jump;

            // updating maxReach
            maxReach = max(maxReach, i + arr[i]);

            // we use a step to get to the current index
            step--;

            // If no further steps left
            if (step == 0) {
                // we must have used a jump
                jump++;

                // Check if the current index/position or lesser index
                // is the maximum reach point from the previous indexes
                if (i >= maxReach)
                    return -1;

                // re-initialize the steps to the amount
                // of steps to reach maxReach from position i.
                step = maxReach - i;
            }
        }
    return -1;
    }

/*    Kadane's Algorithm
Given an array Arr[] of N integers. Find the contiguous sub-array(containing at least one number) which has the maximum sum and return its sum.
https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1?page=1&difficulty[]=1&company[]=Amazon&curated[]=1&sortBy=submissions
*/
    /*
    long long max(long long a, long long b){
        if(a > b)
            return a;
        return b;
    }
    */

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

/* Trapping rain water 
Given an array arr[] of N non-negative integers representing the height of blocks. If width of each block is 1, compute how much water can be trapped between the blocks during the rainy season. 
https://practice.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1?page=1&difficulty[]=1&company[]=Amazon&curated[]=1&sortBy=submissions
*/
    long long trappingWater(int arr[], int n){
        // code here
        int left = 0;
        long long maxleft=0, maxright=0;
        int right = n-1;
        long long count=0;
        
        while(left <= right){
            if(arr[left] <= arr[right]){
                if(arr[left] >= maxleft){
                    maxleft = arr[left];
                }else{
                    count += maxleft - arr[left];
                }
                left++;
            }else{
                if(arr[right] >= maxright){
                    maxright = arr[right];   
                }else{
                    count += maxright - arr[right];
                }
                right--;
            }
        }
        return count;
    }

    /* Find whether path exist
    Given a grid of size n*n filled with 0, 1, 2, 3. Check whether there is a path possible from the source to destination. You can traverse up, down, right and left.
The description of cells is as follows:

A value of cell 1 means Source.
A value of cell 2 means Destination.
A value of cell 3 means Blank cell.
A value of cell 0 means Wall.
Note: There are only a single source and a single destination.
https://practice.geeksforgeeks.org/problems/find-whether-path-exist5238/1?page=2&difficulty[]=1&company[]=Amazon&curated[]=1&sortBy=submissions
    */
    bool bfs(vector<vector<int>>&grid, int i, int j){
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> dir({{-1,0},{0,-1},{0,1},{1,0}});
        q.push({i,j}); //cout<<"i "<<i<<" j "<<j<<endl;
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i=0; i<4; i++){
                int nr = r + dir[i][0];
                int nc = c + dir[i][1];
                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    if(grid[nr][nc]==2)
                        return true;
                    if(grid[nr][nc]==3){
                        grid[nr][nc] = 0;
                        q.push({nr,nc});
                        //cout<<"i "<<nr<<" j "<<nc<<endl;
                    }
                }
            }
        }
        return false;
    }
    //public:
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) 
    {
        //code here
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1){
                    //start from the source
                    grid[i][j]=0;
                    if(bfs(grid,i,j))
                        return true;
                    else
                        return false;
                }
            }
        }
        return false;
    }

/* Next greater element 
Given an array arr[ ] of size N having elements, the task is to find the next greater element for each element of the array in order of their appearance in the array.
Next greater element of an element in the array is the nearest element on the right which is greater than the current element.
If there does not exist next greater of current element, then next greater element for current element is -1. For example, next greater of the last element is always -1.
https://practice.geeksforgeeks.org/problems/next-larger-element-1587115620/1?page=3&difficulty[]=1&company[]=Amazon&curated[]=1&sortBy=submissions
*/
   //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        //int n = arr.size();
        vector<long long> result(n, -1);
        // create an empty stack
        stack<int> s;
 
        // do for each element
        for (int i = 0; i < n; i++){
        // loop till we have a greater element on top or stack becomes empty.
 
            // Keep popping elements from the stack smaller than the current
            // element, and set their next greater element to the current element
            while (!s.empty() && arr[s.top()] < arr[i]){
                result[s.top()] = arr[i];
                s.pop();
            }
 
            // push current "index" into the stack
            s.push(i);
        }
        return result;
    }

/* Rate in a maze
Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell.
https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1?page=2&difficulty[]=1&company[]=Amazon&curated[]=1&sortBy=submissions
*/    
    void solve(int i, int j, 
        vector<vector<int>>& a, int n, 
        vector<string>& ans, string move,
        vector<vector<int>>& vis, int di[], int dj[]) {
    
        if (i == n-1 && j == n-1) {
            ans.push_back(move);
            return;
        }
        string dir = "DLRU";
        for (int ind = 0; ind < 4; ind++) {
        int nexti = i + di[ind];
        int nextj = j + dj[ind];
            if (nexti >= 0 && nextj >= 0 && nexti < n && nextj < n 
                && !vis[nexti][nextj] && a[nexti][nextj] == 1) {
                vis[i][j] = 1;
                solve(nexti, nextj, a, n, ans, move + dir[ind], vis, di, dj);
                vis[i][j] = 0;
            }
        }
    }
  //public:
    vector<string> findPath(vector < vector < int >> & m, int n) {
      vector<string> ans;
      vector<vector<int>> vis(n, vector<int> (n, 0));
      int di[] = {+1,0,0,-1};
      int dj[] = { 0,-1,1,0};
      if (m[0][0] == 1) 
        solve(0, 0, m, n, ans, "", vis, di, dj);
      return ans;
    }

/* Detect cycle in an undirected Graph
*/ 
bool isCycleUtils(int v, vector<bool>& vis, 
        vector<int> adj[], int parent ){
        vis[v] = true;            
        for(int i=0; i<adj[v].size(); i++){
            //- be careful about below condition - after if there is a ifelse
            // so don't combine the first if's vis and isCycle.
            //if adjacent vertex is not visited
            if(!vis[adj[v][i]]) {
                if(isCycleUtils(adj[v][i], vis, adj, v))
                    return true;  
            } 
            // If an adjacent vertex is visited and
            // is not parent of current vertex,
            // then there exists a cycle in the graph.    
            else if(adj[v][i] != parent)
                return true;
        }
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
       vector<bool> vis(V,false);  
       for(int i=0; i<V; i++){
            // not visited if there is a cycle
           if(!vis[i] && isCycleUtils(i, vis, adj, -1))    
                return true;
       }
       return false;
    }
/*
We can't use the same algorithm: The algorithm above simply explores all connected components of the graph. If you encounter an already marked vertex, there must be two different paths to reach it, and in an undirected graph there must be a cycle. 
If not, you can continue with the next connected component - no need to clean up the component you just finished.
On the other hand, if you have a directed graph, two different paths to the same vertex don't make a cycle. So you need a different algorithm (for example, you may need to clean up any steps you back track.)
*/

/* Detect cycle in a directed Graph 
Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.
https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1?page=4&difficulty[]=1&company[]=Amazon&curated[]=1&sortBy=submissions
Depth First Traversal can be used to detect a cycle in a Graph. 
DFS for a connected graph produces a tree. There is a cycle in 
a graph only if there is a back edge present in the graph. 
A back edge is an edge that is from a node to itself (self-loop) 
or one of its ancestors in the tree produced by DFS.
*/
     bool isCycleUtils1(int v, vector<bool>& vis, 
                vector<bool>& rec, vector<int> adj[] ){
        if(vis[v]==false){
            vis[v] = true;
            rec[v] = true;
            for(int i=0; i<adj[v].size(); i++){
                if(!vis[adj[v][i]] && isCycleUtils1(adj[v][i], vis, rec, adj))
                    return true;
                else if(rec[adj[v][i]])
                    return true;
            }
        }   
        rec[v] = false;
        return false;
    }
  //public:
    // Function to detect cycle in a directed graph.
    bool isCyclic1(int V, vector<int> adj[]) {
        // code here
       vector<bool> vis(V,false);
       vector<bool> rec(V,false);
       
       for(int i=0; i<V; i++){
           if(!vis[i] && isCycleUtils1(i, vis, rec, adj))    
            return true;
       }
       return false;
    }

/* Find the number of Islands
Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid) consisting of '0's (Water) and '1's(Land). Find the number of islands.
Note: An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.

https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1?page=4&difficulty[]=1&company[]=Amazon&curated[]=1&sortBy=submissions
*/
    void bfs(int r, int c, vector<vector<char>>& grid,
        vector<vector<int>>& vis){
            int n = grid.size();
            int m = grid[0].size();
            queue<pair<int,int>> q;
            vis[r][c]=1;
            q.push({r,c});
            while(!q.empty()){
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                //search in all directions
                for(int i=-1; i<=1; i++){
                    for(int j=-1; j<=1; j++){
                        int nr = row + i;
                        int nc = col + j;
                        if(nr>=0 && nr<n && nc>=0 && nc<m &&
                            grid[nr][nc]=='1' && !vis[nr][nc]){
                                vis[nr][nc]=1;
                                q.push({nr,nc});
                        }
                    }
                }
            }
        }
  //public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        int cnt=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                //not visied and it's land
                if(!vis[i][j] && grid[i][j]=='1'){
                    cnt++;
                    bfs(i,j,grid,vis);
                }
            }
        }
        return cnt;
    }

/*
Given an array of integers. Find the Inversion Count in the array. 

Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If array is already sorted then the inversion count is 0. If an array is sorted in the reverse order then the inversion count is the maximum. 
Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.

https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1?page=1&difficulty[]=1&company[]=Amazon&curated[]=1&sortBy=submissions
*/
//take extra care about the return types and what you are passing - took 5 times to check this
    long long int merge(long long arr[], long long start, long long mid, long long end){
        long long left = start;
        long long  right = mid+1;
        vector<long long> temp;
        long long int inv=0;
        while(left <= mid && right <= end){
            if(arr[left] <= arr[right]){
                temp.push_back(arr[left++]);
            }else{
                temp.push_back(arr[right++]);
                inv += (mid-left+1);
            }
        }
        while(left <= mid){
            temp.push_back(arr[left++]);
        }
        while(right <= end){
            temp.push_back(arr[right++]);
        }
        for(int i=start; i<=end; i++){
            arr[i] = temp[i-start];
        }
        return inv;
    }
    
    long long int mergesort(long long arr[], long long start, long long end){
        long long int inv=0;
        long long mid;
        if(end > start){
            mid = (start+end)/2;
            inv += mergesort(arr,start,mid);
            inv += mergesort(arr,mid+1,end);
            inv += merge(arr,start,mid,end);
        }
        return inv;
    }
  //public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        return mergesort(arr,0,N-1);
    }

/* merge intervals
   make sure and be careful on how you handle the 2d vector
   https://practice.geeksforgeeks.org/problems/8a644e94faaa94968d8665ba9e0a80d1ae3e0a2d/1?page=1&difficulty[]=1&company[]=Amazon&curated[]=1&sortBy=submissions
*/
vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
         // Code here
       vector<vector<int>> result;
       if(intervals.size()==0){
           return result;
       }
       
       sort(intervals.begin(), intervals.end());
       vector<int> interval = intervals[0];

       for(auto it: intervals){
           if(it[0] <= interval[1]){
               interval[1] = max(interval[1],it[1]);
           }else{
               result.push_back(interval);
               interval = it;
           }
       }
       result.push_back(interval);
       return result;
    }
/*
Given the root of a binary tree, calculate the vertical order traversal of the binary tree.
For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).
The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column. There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.
Return the vertical order traversal of the binary tree.
https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/  (987. Vertical Order Traversal of a Binary Tree)
*/
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        queue<pair<TreeNode*,pair<int,int>>> q;
        map<int, map<int, multiset<int>>> ms;
        
        q.push({root,{0,0}});
        while(!q.empty()){
            auto e = q.front();
            q.pop();
            TreeNode * node = e.first;
            int x = e.second.first;
            int y = e.second.second;
            ms[x][y].insert(node->val);
            if(node->left){
                q.push({node->left,{x-1,y+1}});
            }
            if(node->right){
                q.push({node->right,{x+1,y+1}});
            }
        }
        
        for(auto p: ms){
            vector<int> a;
            for(auto q: p.second){
                a.insert(a.end(),q.second.begin(),q.second.end());
            }
            res.push_back(a);
        }
        
        return res;
    }

/* 
    We are given an array of money in each house A and we need to return the maximum amount we can rob without robbing from any two adjacent houses.
    nice -> https://leetcode.com/problems/house-robber/discuss/1605797/C%2B%2BPython-4-Simple-Solutions-w-Explanation-or-Optimization-from-Brute-Force-to-DP
    nice -> https://leetcode.com/problems/house-robber/discuss/156523/From-good-to-great.-How-to-approach-most-of-DP-problems.
    https://leetcode.com/problems/house-robber/  - 198. House Robber 
    Find recursive relation
    Recursive (top-down)
    Recursive + memo (top-down)
    Iterative + memo (bottom-up)
    Iterative + N variables (bottom-up)
*/
    //Recursive (top-down)
    int robHouse(vector<int>&nums, int i){
        if(i < 0 || i>=nums.size())
            return 0;
        return max(robHouse(nums,i+1), nums[i]+robHouse(nums,i+2));
    }
    //public:
    int rob(vector<int>& nums) {
        return robHouse(nums,0);
    }

    //Recursive + memo (top-down)
    int robHouse1(vector<int>&nums, int i, vector<int>&memo){
        if(i < 0 || i>=nums.size())
            return 0;
        if(memo[i]!=-1)
            return memo[i];
        return (memo[i] = max(robHouse1(nums, i+1, memo), nums[i]+robHouse1(nums, i+2, memo)));
    }
    //public:
    int rob1(vector<int>& nums) {
        vector<int>memo(nums.size(),-1);
        return robHouse1(nums,0,memo);
    }
    // Iterative + Memo
    int rob2(vector<int>& nums) {
        int len = nums.size(), i;
        vector<int>memo(len+1,-1);
        memo[0]=0;
        memo[1]=nums[0];
        for(i=1; i < len; i++){
            memo[i+1] = max(memo[i], memo[i-1]+nums[i]);
        }
        return memo[len];
    }
    // Iterative + variable
    // take the maximum of previously calculated and current element or calculate till current  
    int rob3(vector<int>& nums) {
        int len = nums.size();
        int pre = 0, cur = 0;
        for (int i = 0; i < len; i++) {
            int temp = max(pre + nums[i], cur); 
            pre = cur;
            cur = temp;
        }
        return cur;
    }
/*
https://leetcode.com/problems/house-robber-ii/ (213. House Robber II)
https://leetcode.com/problems/house-robber-ii/discuss/59921/9-lines-0ms-O(1)-Space-C%2B%2B-solution
*/
    int robberyHouse(vector<int>&nums, int l, int r){
        int pre=0, curr=0;
        for(int i=l; i<=r; i++){
            int temp = max(pre + nums[i], curr);
            pre = curr;
            curr = temp;
        }
        return curr;
    }
    //public:
    int robbery(vector<int>& nums) {
        int n = nums.size();
        if(n==0)
            return 0;
        if(n==1)
            return nums[0];
        
        return max(robberyHouse(nums,0,n-2), robberyHouse(nums,1,n-1));
    }

/* https://leetcode.com/problems/house-robber-iii/ (337. House Robber III)
nice - https://leetcode.com/problems/house-robber-iii/discuss/79330/Step-by-step-tackling-of-the-problem
*/


/* Minimum platforms - GFG
Given arrival and departure times of all trains that reach a railway station. Find the minimum number of platforms required for the railway station so that no train is kept waiting.
Consider that all the trains arrive on the same day and leave on the same day. Arrival and departure time can never be the same for a train but we can have arrival time of one train equal to departure time of the other. At any given instance of time, same platform can not be used for both departure of a train and arrival of another train. In such cases, we need different platforms.
https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1?page=1&difficulty[]=1&company[]=Amazon&curated[]=1&sortBy=submissions    
*/
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	sort(arr,arr+n);
    	sort(dep,dep+n);
    	
    	int minp = 1;
    	int res = 1;
    	int i=1, j=0;
    	while(i < n && j < n){
    	    if(arr[i] <= dep[j]){
    	        minp++;
    	        i++;
    	    }
    	    else if(arr[i] > dep[j]){
    	        minp--;
    	        j++;
    	    }
    	    if(res < minp){
    	       res = minp;
    	    }
    	}
    	return res;
    }

/* Coin change
    Given an integer array coins[ ] of size N representing different denominations of currency and an integer sum, find the number of ways you can make sum by using different combinations from coins[ ].  
Note: Assume that you have an infinite supply of each type of coin. 
https://practice.geeksforgeeks.org/problems/coin-change2448/1?page=1&difficulty[]=1&company[]=Amazon&curated[]=1&sortBy=submissions

*/
    // either take the nth coin or don't take
    long long int count(int coins[], int N, int sum) {
        // code here.
        if(sum == 0)
            return 1;
        
        if(sum < 0)
            return 0;
        
        if(N <= 0)
            return 0;
        
        return count(coins, N-1, sum) + 
                count(coins, N, sum-coins[N-1]);
    }

    //dp
    long long int coinChange(int coins[], int s, int n, 
                        vector<vector<long long int>>& dp){
        if (s == 0)
            return dp[n][s] = 1;
        if (n == 0)
            return 0;
        if (dp[n][s] != -1)
            return dp[n][s];
        if (coins[n - 1] <= s) {
            // Either Pick this coin or not
            return dp[n][s] = coinChange(coins, s - coins[n - 1], n, dp)
                          + coinChange(coins, s, n - 1, dp);
        }
        else // We have no option but to leave this coin
            return dp[n][s] = coinChange(coins, s, n - 1, dp);                        
    }

  public:
    long long int count1(int coins[], int n, int s) {

        vector<vector<long long int>>dp(n+1, vector<long long int>(s+1,-1));
        return coinChange(coins, s, n, dp);
    }

    // optimise
    long long int count2(int coins[], int n, int sum) {
        // table[i] will be storing the number of solutions for
        // value i. We need sum+1 rows as the table is constructed
        // in bottom up manner using the base case (sum = 0)
        long long int table[sum + 1];
   
        // Initialize all table values as 0
        memset(table, 0, sizeof(table));
   
        // Base case (If given value is 0)
        table[0] = 1;
   
        // Pick all coins one by one and update the table[]
        // values after the index greater than or equal to the
        // value of the picked coin
        for (int i = 0; i < n; i++)
            for (int j = coins[i]; j <= sum; j++)
                table[j] += table[j - coins[i]];
        return table[sum];
    }

/* Merge sort
Given an array arr[], its starting position l and its ending position r. Sort the array using merge sort algorithm.
https://practice.geeksforgeeks.org/problems/merge-sort/1?page=1&difficulty[]=1&company[]=Amazon&curated[]=1&sortBy=submissions
*/
    void merge(int arr[], int l, int m, int r)
    {
         // Your code here
        int temp[r-l+1];
        int i = l;
        int j = m+1;
        int k = 0;
        while(i <= m && j <= r){
            if(arr[i] <= arr[j]){
                temp[k++] = arr[i++];
            }else{
                temp[k++] = arr[j++];
            }
        }
        while(i <= m){
            temp[k++] = arr[i++];
        }
        while(j <= r){
            temp[k++] = arr[j++];
        }
        for(k=l; k<=r; k++){
            arr[k] = temp[k-l];
        }
    }
    //public:
    void mergeSort(int arr[], int l, int r)
    {
        //code here
        if(l < r){
            int mid = (r+l)/2;
            mergeSort(arr, l, mid);
            mergeSort(arr, mid+1, r);
            merge(arr, l, mid, r);
        }
    }




};

int main(){
    cout<<"Amazon practice in online IDE\n";
    return 0;
}
