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
    11. Subset SUM
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
