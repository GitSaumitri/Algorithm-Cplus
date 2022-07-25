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
    8. Combination SUM 
    9. Combination SUM - unique combinations
    10. Subset SUM
    11. Unique Subsets
    12. Print all permutations of a string or array
    13. Print all permutations of a string or array
    14. N-Queens
    15. Sudoku solver
    16. M coloring problem
    17. Palindrome partitioning 
    18. Rat in a Maze
    19. Kth permutation sequence
*/

#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class recursionSeries{
    public:
    //6. Print subsequences
    void printSubsequences(int ind, vector<int>& ds, int arr[], int n);

    //7. Printing subsequences whose sum is K
    void printSubsequencesSUM(int ind, vector<int>& ds, int arr[], int n, int sum);
    void printSubsequencesSUM(int ind, vector<int>& ds, int arr[], int n, int sum, int s);
        // only one solution
    bool printSubsequencesSUM1(int ind, vector<int>& ds, int arr[], int n, int sum, int s);
        // only return count
    int printSubsequencesSUM2(int ind, vector<int>& ds, int arr[], int n, int sum, int s);

    //8. Combination SUM
    void findCombinations(int ind, int target, vector<int>& arr, vector<vector<int>>& ans, vector<int>& ds);
    vector<vector<int>> combinationSum(vector<int>& candidates, int target);

    //9. Combination SUM
    void findCombinations2(int ind, int target, vector<int>& arr, vector<vector<int>>& ans, vector<int>& ds);
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target);

    //10. Subset SUM
    void subsetSumUtils(int ind, int sum, vector<int>&arr, int len, vector<int>& sumSubset);
    vector<int> subsetSum(vector<int> arr, int len);

    //11. unique subsets
    void subsetUniqueUtils(int ind, vector<int>&nums, vector<int>& ds, vector<vector<int>>& subsets);
    vector<vector<int>> subsetUnique(vector<int> arr);

    //12. permutation - extra track space
    void recurPermute(vector<int>& ds, vector<int> &nums, vector<vector<int>>& ans, int freq[]);
    vector<vector<int>> permute(vector<int>& nums);

    //13 permutation - no exta space
    void recurPermute1(int index, vector<int> &nums, vector<vector<int>>& ans);
    vector<vector<int>> permute1(vector<int>& nums);

    //14. N queens
    bool isSafe(int row, int col, vector<string> board, int n);
    void solve(int col, vector<string>& board, vector<vector<string>>& ans, int n);
    vector<vector<string>> solveQueens(int n);

    //15. soduko solver
    bool isValid(vector<vector<char>>& board, int row, int col, char ch);
    bool solveSudoku(vector<vector<char>>& board);
    void sudokuSolver(vector<vector<char>>& board);

    //16. graph colouring
    bool isSafeToColor(int node, int color[], bool graph[5][5], int n, int col);
    bool solveMcolor(int node, int color[], int m, int n, bool graph[5][5]);
    bool graphColoring(bool graph[5][5], int m, int n);

    //17. palindrome partitioning
    bool isPalindrom(string s, int start, int end);
    void palindromPartitioningUtil(int index, string s, vector<string>& path, 
                                    vector<vector<string>>& res);
    vector<vector<string>> palindromPartitioning(string s);

    //19. Rate in a maze
    void solveFindPath(int i, int j, vector<vector<int>>& maze,int n,
                    vector<string>& ans, string move, vector<vector<int>>& vis);
    vector<string> findPath(vector<vector<int>>& maze, int n);
 
    // 18. Kth permutation
    string getPermutation(int n, int k);

};

int main(){
    recursionSeries ob;

    // 6. Printing subsequences
    int arr6[] = {3,2,1}; int n = 3; vector<int> ds6;
    cout<<"Print Subsequences"<<endl;
    ob.printSubsequences(0, ds6, arr6, n);

    //7. Printing subsequence whose sum is K
    int arr7[] = {1,2,1}; n = 3; int sum=2; vector<int> ds7;
    cout<<endl<<"Print Subsequences of SUM "<<sum<<" "<<endl;
    ob.printSubsequencesSUM(0, ds7, arr7, n, sum);
    cout<<endl<<"Print Subsequences of SUM "<<sum<<" "<<endl;
    ob.printSubsequencesSUM(0, ds7, arr7, n, sum, 0);
    cout<<endl<<"Print Subsequences of SUM "<<sum<<" first "<<endl;
    ob.printSubsequencesSUM1(0, ds7, arr7, n, sum, 0);
    cout<<endl<<"Count "<<ob.printSubsequencesSUM2(0, ds7, arr7, n, sum, 0)<<endl;

    //8. Combination SUM
    vector<int> arr8({2,3,6,7}); n = 4, sum=7; vector<int> ds8; vector<vector<int>> res8;
    res8 = ob.combinationSum(arr8, sum);
    cout<<"Combination SUM of "<<sum<<" "<<endl;
    for(int i=0; i<res8.size(); i++){
        cout<<"{ ";
        for(int j=0; j<res8[i].size(); j++){
            cout<<res8[i][j]<<" ";
        }
        cout<<"} ";
    }
    cout<<endl;

    //9. Combination SUM
    vector<int> arr9({2,5,2,1,2}); n = 5, sum=5; vector<int> ds9; vector<vector<int>> res9;
    res9 = ob.combinationSum2(arr9, sum);
    cout<<"Combination SUM of "<<sum<<" "<<endl;
    for(int i=0; i<res9.size(); i++){
        cout<<"{ ";
        for(int j=0; j<res9[i].size(); j++){
            cout<<res9[i][j]<<" ";
        }
        cout<<"} ";
    }
    cout<<endl;

    //10. Subset SUM
    vector<int> arr10({1,2,5}); n = 3; vector<int> res10;
    res10 = ob.subsetSum(arr10, n);
    cout<<"Subset sum "<<endl;
    for(int i=0; i<res10.size(); i++){
        cout<<res10[i]<<" ";
    }
    cout<<endl;

    //11. Subset SUM
    vector<int> arr11({1,2,2}); vector<vector<int>> res11;
    res11 = ob.subsetUnique(arr11);
    cout<<"Unique Subsets "<<endl;
    for(int i=0; i<res11.size(); i++){
        cout<<"{ ";
        for(int j=0; j<res11[i].size(); j++){
            cout<<res11[i][j]<<" ";
        }
        cout<<"}";
    }
    cout<<endl;
 
    //12. permutation
    vector<int> arr12({1,2,2}); vector<vector<int>> res12;
    res12 = ob.permute(arr12);
    cout<<"Permutations  "<<endl;
    for(int i=0; i<res12.size(); i++){
        cout<<"{ ";
        for(int j=0; j<res12[i].size(); j++){
            cout<<res12[i][j]<<" ";
        }
        cout<<"}";
    }
    cout<<endl;
 
    //13. permutation
    vector<int> arr13({1,2,2}); vector<vector<int>> res13;
    res13 = ob.permute1(arr13);
    cout<<"Permutations  "<<endl;
    for(int i=0; i<res13.size(); i++){
        cout<<"{ ";
        for(int j=0; j<res13[i].size(); j++){
            cout<<res13[i][j]<<" ";
        }
        cout<<"}";
    }
    cout<<endl;

    //14 N queens
    vector<vector<string>> ans14;
    n=4;
    ans14 = ob.solveQueens(4);
    cout<<"N Queens: "<<ans14.size()<<" "<<ans14[0].size()<<endl;
    for(int i=0; i<ans14.size(); i++){
        for(int k=0; k<ans14[0].size(); k++){
            cout<<ans14[i][k]<<endl;
        }
        cout<<endl;
    }
    cout<<endl;
 
    //15. sudoku solver
    vector<vector<char>> board = {{'5','3','.','.','7','.','.','.','.'},
                                    {'6','.','.','1','9','5','.','.','.'},
                                    {'.','9','8','.','.','.','.','6','.'},
                                    {'8','.','.','.','6','.','.','.','3'},
                                    {'4','.','.','8','.','3','.','.','1'},
                                    {'7','.','.','.','2','.','.','.','6'},
                                    {'.','6','.','.','.','.','2','8','.'},
                                    {'.','.','.','4','1','9','.','.','5'},
                                    {'.','.','.','.','8','.','.','7','9'}};
    cout<<"Solve sudoku "<<endl;
    ob.sudokuSolver(board);
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[i].size(); j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }

    // 16. M-coloring problem
    //bool graphColoring(bool graph[101][101], int m, int n){
    bool graph[5][5]={{0,0,0,0,0},
                    {0,0,1,1,0},
                    {0,0,0,1,0},
                    {0,0,0,0,1},
                    {0,1,0,0,0}}; 
    cout<<"Graph coloring "<<ob.graphColoring(graph,3,5);  

    //17. palindrome partitioning
    string s("aab");
    vector<vector<string>> res17;
    res17 = ob.palindromPartitioning(s);
    cout<<"Palindome partitioning: "<<endl;
    for(int i=0; i<res17.size(); i++){
        cout<<"{ ";
        for(int j=0; j<res17[i].size(); j++){
            cout<<res17[i][j]<<" ";
        }
        cout<<"} ";
    }
    cout<<endl;

    // 19. Rate in a maze
    vector<vector<int>> maze = {{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};
    vector<string> res19;
    res19 = ob.findPath(maze, maze.size());
    cout<<"Rate in a Maze paths:"<<endl;
    for(int i=0; i<res19.size(); i++){
        cout<<res19[i]<<" ";
    }
    cout<<endl;

    // 18. Kth permutation
    n = 4; 
    int k=17;
    string res18 = ob.getPermutation(n, k);
    cout<<"Kth permutation "<<res18;

    return 0;
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
    - print parametarised
    - how to print only one answer - not continue with recursion.
        - return true, if base condition if true then return
    - how to print only the counts of subsequence 
        - return 1 if get it else return 0 then add it all
*/
void recursionSeries::printSubsequencesSUM(int ind, vector<int>& ds, int arr[], int n, int sum){
    if(ind == n){
        if(sum == 0){
        cout<<"{ ";
        for(auto it: ds){
            cout<< it<<" ";
        }
        cout<<"} ";
        }
        return;
    }
    // take or pick the particular index into the subsequence
    ds.push_back(arr[ind]);
    printSubsequencesSUM(ind+1, ds, arr, n, sum - arr[ind]);
    ds.pop_back();

    //not pick or not take condition, this element is not added to your subsequence
    printSubsequencesSUM(ind+1, ds, arr, n, sum);
}

void recursionSeries::printSubsequencesSUM(int ind, vector<int>& ds, int arr[], int n, int sum, int s){
    if(ind == n){
        if(s == sum){
        cout<<"{ ";
        for(auto it: ds){
            cout<< it<<" ";
        }
        cout<<"} ";
        }
        return;
    }
    // take or pick the particular index into the subsequence
    ds.push_back(arr[ind]);
    s += arr[ind];

    printSubsequencesSUM(ind+1, ds, arr, n, sum, s);

    s -= arr[ind];
    ds.pop_back();

    //not pick or not take condition, this element is not added to your subsequence
    printSubsequencesSUM(ind+1, ds, arr, n, sum, s);
}

bool recursionSeries::printSubsequencesSUM1(int ind, vector<int>& ds, int arr[], int n, int sum, int s){
    if(ind == n){
        if(s == sum){
            cout<<"{ ";
            for(auto it: ds){
                cout<< it<<" ";
            }
            cout<<"} ";
            return true;
        }
        return false;
    }
    // take or pick the particular index into the subsequence
    ds.push_back(arr[ind]);
    s += arr[ind];

    if(printSubsequencesSUM1(ind+1, ds, arr, n, sum, s)==true)
        return true;

    s -= arr[ind];
    ds.pop_back();

    //not pick or not take condition, this element is not added to your subsequence
    if(printSubsequencesSUM1(ind+1, ds, arr, n, sum, s)==true)
        return true;

    //if non of the cases hit
    return false;
}

int recursionSeries::printSubsequencesSUM2(int ind, vector<int>& ds, int arr[], int n, int sum, int s){
    if(ind == n){
        if(s == sum){
            //cout<<"{ ";
            //for(auto it: ds){
            //    cout<< it<<" ";
            //}
            //cout<<"} ";
            return 1;
        }
        return 0;
    }
    // take or pick the particular index into the subsequence
    ds.push_back(arr[ind]);
    s += arr[ind];

    int l = printSubsequencesSUM2(ind+1, ds, arr, n, sum, s);

    s -= arr[ind];
    ds.pop_back();

    //not pick or not take condition, this element is not added to your subsequence
    int r = printSubsequencesSUM2(ind+1, ds, arr, n, sum, s);

    //if non of the cases hit
    return l+r;
}

/* 8. Combination SUM
   Given an array of distinct integers and a target integer, return a list of all unique
   combination of candidates where the chosen number sum to target. You may return the 
   candidate in any order.
   The same number may be chosen from candidates an unlimited number of times, two 
   combinations are unique, if the frequency of at least one of the chosen number is
   different.  
        - O(2^t)*O(k)
*/
void recursionSeries::findCombinations(int ind, int target, vector<int>& arr, vector<vector<int>>& ans, vector<int>& ds){
    if(ind == arr.size()){
        if(target == 0){
            ans.push_back(ds);
        }
        return;
    }
    //pick up the element
    if(arr[ind] <= target){
        ds.push_back(arr[ind]);
        findCombinations(ind, target-arr[ind], arr, ans, ds);
        ds.pop_back();
    }

    findCombinations(ind+1, target, arr, ans, ds);
}

vector<vector<int>> recursionSeries::combinationSum(vector<int>& candidates, int target){
    vector<vector<int>> ans;
    vector<int> ds;
    findCombinations(0, target, candidates, ans, ds);
    return ans;
}

/* 9. Combination SUM
   Given a collection of candidate numbers and a target number, find all unique combinations
   where the candidate number sum to target.
   Each number in candidates may only be used once in the combination.
   Note: solution set must not cotain duplicate numbers.
    - O(2^n)
*/
void recursionSeries::findCombinations2(int ind, int target, vector<int>& arr, vector<vector<int>>& ans, vector<int>& ds){
    if(target==0){
        ans.push_back(ds);
        return;
    }
    for(int i = ind; i<arr.size(); i++){
        if(i>ind && arr[i]==arr[i-1]) continue;
        if(arr[i] > target) break;
        ds.push_back(arr[i]);
        findCombinations2(i+1, target-arr[i], arr, ans, ds);
        ds.pop_back();
    }
}

vector<vector<int>> recursionSeries::combinationSum2(vector<int>& candidates, int target){
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ans;
    vector<int> ds;
    findCombinations2(0, target, candidates, ans, ds);
    return ans;
}

/* 10. Subset SUM
   Given a list of N integers, print sums of all subsets in it, output should be printed in 
   increasing order of sums.

*/
void recursionSeries::subsetSumUtils(int ind, int sum, vector<int>&arr, int len, vector<int>& sumSubset){
    if(ind==len){
        sumSubset.push_back(sum);
        return;
    }
    //pick the element
    subsetSumUtils(ind+1, sum+arr[ind], arr, len, sumSubset);

    //do-not pick the element
    subsetSumUtils(ind+1, sum, arr, len, sumSubset);
}
vector<int> recursionSeries::subsetSum(vector<int> arr, int len){
    vector<int> sumSubset;
    subsetSumUtils(0,0,arr,len,sumSubset);
    sort(sumSubset.begin(),sumSubset.end());
    return sumSubset;
}


/* 11. Subset SUM
   Given a list of N integers, that may contain duplicates, 
   return all possible subsets, no duplicate subset
*/
void recursionSeries::subsetUniqueUtils(int ind, vector<int>&nums, vector<int>& ds, vector<vector<int>>& subsets){
    subsets.push_back(ds);   //pick the element
    for(int i=ind; i<nums.size(); i++){
        if(i!=ind && nums[i]==nums[i-1]) continue;
        ds.push_back(nums[i]);
        subsetUniqueUtils(i+1, nums, ds, subsets);
        ds.pop_back();
    }
}
vector<vector<int>> recursionSeries::subsetUnique(vector<int> arr){
    vector<vector<int>> subsets;
    vector<int> ds;
    sort(arr.begin(),arr.end());
    subsetUniqueUtils(0,arr,ds,subsets);
    return subsets;
}

/* 12. permutation
 track for each element
    - O(n!)
*/ 
void recursionSeries::recurPermute(vector<int>& ds, vector<int> &nums, vector<vector<int>>& ans, int freq[]){
    if(ds.size() == nums.size()){
        ans.push_back(ds);
        return;
    }
    for(int i=0; i<nums.size(); i++){
        if(!freq[i]){
            ds.push_back(nums[i]);
            freq[i]=1;
            recurPermute(ds, nums, ans, freq);
            freq[i]=0;
            ds.pop_back();
        }
    }
}
vector<vector<int>> recursionSeries::permute(vector<int>& nums){
    vector<int> ds;
    vector<vector<int>> ans;
    int freq[nums.size()]={0};
    for(int i=0; i<nums.size();i++) freq[i]=0;
    recurPermute(ds, nums, ans, freq);
    return ans;
}

/* 13. permutation - space optimized
    swap each element
        - O(n!)*O(n)
    space is saved a lot as compared to previous approach
*/
void recursionSeries::recurPermute1(int index, vector<int> &nums, vector<vector<int>>& ans){
    if(index == nums.size()){
        ans.push_back(nums);
        return;
    }
    for(int i=index; i<nums.size(); i++){
        swap(nums[index],nums[i]);
        recurPermute1(index+1, nums, ans);
        swap(nums[index],nums[i]);
    }
}
vector<vector<int>> recursionSeries::permute1(vector<int>& nums){
    vector<vector<int>> ans;
    recurPermute1(0, nums, ans);
    return ans;
}

/*  N-Queens
    
*/
bool recursionSeries::isSafe(int row, int col, vector<string> board, int n){
    //check upper diagonal
    int drow = row;
    int dcol = col;

    while(row>=0 && col>=0){
        if(board[row][col]=='Q') return false;
        row--;
        col--;
    }

    col = dcol;
    row = drow;
    while(col>=0){
        if(board[row][col]=='Q') return false;
        col--;
    }

    row = drow;
    col = dcol;
    while(row<n && col>=0){
        if(board[row][col]=='Q') return false;
        row++;
        col--;
    }

    return true;
}

void recursionSeries::solve(int col, vector<string>& board, vector<vector<string>>& ans, int n){
    if(col == n){
        //cout<<"put board in"<<endl;
        ans.push_back(board);
        return;
    }

    for(int row=0; row<n; row++){
        if(isSafe(row, col, board, n)){
            board[row][col]='Q';
            solve(col+1, board, ans, n);
            board[row][col]='.';
        }
    }
}

vector<vector<string>> recursionSeries::recursionSeries::solveQueens(int n){
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n, '.');
    for(int i=0; i<n; i++){
        board[i]=s;
    }
    solve(0, board, ans, n);
    return ans;
}

/*
    Sudoko solver
        - check row cons col changes - entire row 
        - check col cons row changes - entire col
        - [3*(row/3)+i/3][3*(col/3)+i%3] - first divide/second modulo - in that cubical  
*/
bool recursionSeries::isValid(vector<vector<char>>& board, int row, int col, char ch){
    for(int i=0; i<9; i++){
        if(board[i][col]==ch)
            return false;
        if(board[row][i]==ch)
            return false;
        if(board[3*(row/3)+ i/3][3*(col/3)+ i%3]==ch)
            return false;
    }
    return true;
}
bool recursionSeries::solveSudoku(vector<vector<char>>& board){
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[0].size(); j++){
            if(board[i][j] == '.'){
                for(char c='1'; c <= '9'; c++){
                    if(isValid(board,i,j,c)){
                        board[i][j]=c;
                        if(solveSudoku(board)==true)
                            return true;
                        else
                            board[i][j]='.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void recursionSeries::sudokuSolver(vector<vector<char>>& board){
    solveSudoku(board);
}

/*  16. M coloring  //bi-pertite graph is 2-color problem
    Given an undirected graph and an integer M. Determine if the graph can be colored with
    at most M colors such that no two adjacent vertices of the graph are colored with the 
    same color. Here coloring of a graph means assigning of color to all vertices. Print 1
    if it is possible to colour vertices and 0 otherwise.
        - N nodes m colors - O(N to the power m) - space O(m)
*/
bool recursionSeries::isSafeToColor(int node, int color[], bool graph[5][5], int n, int col){
    for(int k=0; k<n; k++){
        if(k!=node && graph[k][node]==1 && color[k]==col){
            return false;
        }
    }
    return true;
}
bool recursionSeries::solveMcolor(int node, int color[], int m, int n, bool graph[5][5]){
    if(node==n)
        return true;
    for(int i=1; i<=m; i++){
        if(isSafeToColor(node, color, graph, n, i)){
            color[node]=i;
            if(solveMcolor(node+1,color,m,n,graph))
                return true;
            color[node]=0;
        }
    }
    return false;
}

bool recursionSeries::graphColoring(bool graph[5][5], int m, int n){
    int color[n] = {0};
    if(solveMcolor(0,color,m,n,graph))
        return true;
    return false;
}

/* 17. Palindrome partitioning
    Given a string a, partition s such that every substring of the partition is 
    a palindrom, return all possible palindrom partiotioning of s.
    A palindrom string is a string, that reads the same backward as forward.
*/ 
bool recursionSeries::isPalindrom(string s, int start, int end){
    while(start <= end){
        if(s[start++] !=s [end--])
            return false;
    }
    return true;
}
void recursionSeries::palindromPartitioningUtil(int index, string s, vector<string>& path, 
                                    vector<vector<string>>& res){
    if(index == s.size()){
        res.push_back(path);
        return;
    }
    for(int i=index; i<s.size(); ++i){
        if(isPalindrom(s, index, i)){
            path.push_back(s.substr(index, i-index+1));
            palindromPartitioningUtil(i+1, s, path, res);
            path.pop_back();
        }
    }
}
vector<vector<string>> recursionSeries::palindromPartitioning(string s){
    vector<vector<string>> res;
    vector<string> path;
    palindromPartitioningUtil(0,s,path,res);
    return res;
}

/* 19. Rate in a Maze - Backtracking
    A rat is placed at (0,0) in a square matrix of order n x n. It has to reach the 
    destination at (n-1,n-1). Find all possible paths that the rat can take to reach
    from source to destination. The directions the rate can move are U(up), D(Down)
    L(Left) and R (right). Value 0 at a cell in the matrix, represents that it is 
    blocked and rat can't move to it, while 1 at a cell in the matrix represents that
    rat can be travel through it. In a path, no cell can be visited more than one time.
        - lexicographicall - DLRU
        - all 4 direction - O(4^(nXm)) - space is auxillay space of recurssion - O(n*m)
*/

void recursionSeries::solveFindPath(int i, int j, vector<vector<int>>& maze,int n,
                    vector<string>& ans, string move, vector<vector<int>>& vis){
    
    if(i==n-1 && j==n-1){
        ans.push_back(move);
        return;
    }
    ///*
    string dir="DLRU";
    int di[4][2]={{1,0},{0,-1},{0,1},{-1,0}};
    for(int ind=0; ind<4; ind++){
        int nexti = i + di[ind][0];
        int nextj = j + di[ind][1];
        //cout<<"i "<<i<<"j "<<j<<" nexti "<<nexti<<" nextj"<<nextj<<endl;
        if(nexti>=0 && nextj>=0 && nexti<n && nextj<n &&
            !vis[nexti][nextj] && maze[nexti][nextj]==1){
                vis[i][j]=1;
                solveFindPath(nexti, nextj, maze, n, ans, move+dir[ind], vis);
                vis[i][j]=0;
        }
    }
    /*
    //downward
    if(i+1<n && !vis[i+1][j] && maze[i+1][j]==1){
        vis[i][j]=1;
        solveFindPath(i+1, j, maze, n, ans, move + 'D', vis);
        vis[i][j]=0;
    }
    //left
    if(j-1>=0 && !vis[i][j-1] && maze[i][j-1]==1){
        vis[i][j]=1;
        solveFindPath(i, j-1, maze, n, ans, move + 'L', vis);
        vis[i][j]=0;
    }
    //right
    if(j+1<n && !vis[i][j+1] && maze[i][j+1]==1){
        vis[i][j]=1;
        solveFindPath(i, j+1, maze, n, ans, move + 'R', vis);
        vis[i][j]=0;
    }
    //upward
    if(i-1>=0 && !vis[i-1][j] && maze[i-1][j]==1){
        vis[i][j]=1;
        solveFindPath(i-1, j, maze, n, ans, move + 'U', vis);
        vis[i][j]=0;
    }
    */
}

vector<string> recursionSeries::findPath(vector<vector<int>>& maze, int n){
    vector<string> ans;
    vector<vector<int>> vis(n, vector<int>(n,0));
    if(maze[0][0]==1) // you can't start if (0,0) is 0
        solveFindPath(0, 0, maze, n, ans, "", vis);
    return ans;
}

/* Kth permutation sequence
   The set {1,2,3,4,5,..n} contains a total of n! unique permutations.
   By listing and labeling all of the permuations in order, we get the following sequence 
   for n=3 -> "123" "132" "213" "231" "312" "321".
   Given n and k, return the kth permutation sequence.
        - recursion - find all then return k-1th - O(n!) * O(n) 
        - since we need only one number - so findout the position then calculate it
            - 4! = 4 * 3!
*/
string recursionSeries::getPermutation(int n, int k){
    int fact=1;
    vector<int> numbers;
    for(int i=1; i<n; i++){
        fact = fact * i;
        numbers.push_back(i);
    }
    numbers.push_back(n);
    string ans="";
    k = k-1;
    while(true){
        ans = ans + to_string(numbers[k/fact]);
        numbers.erase(numbers.begin()+k/fact);
        if(numbers.size()==0)
            break;
        k = k % fact;
        fact = fact/ numbers.size();
    }
    return ans;
}
