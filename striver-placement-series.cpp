/* Strivers Placement series  
    //1. Two SUM
    //2. find inversion
    //3. Grid Unique path
    //https://leetcode.com/problems/unique-paths/discuss/22954/C%2B%2B-DP
    //4. sort an array of 0's 1's 2's without using extra space or sorting algo
    //5. Find the duplicate number
    //6. Find the repeating and missing 
    //https://takeuforward.org/data-structure/find-the-repeating-and-missing-numbers/
    //7. Merge two sorted array with O(1) extra space
    //https://www.geeksforgeeks.org/efficiently-merging-two-sorted-arrays-with-o1-extra-space/
    //8. Maximum Subarray
    
*/
#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class placement{

    int merge(vector<int>& nums, int low, int mid, int high){
        int cnt=0;
        int j=mid+1;
        for(int i=low; i<=mid; i++){
            /* Below (2 * nums[j]) can occure in "integer overflow"
               so either type cast them to long to avoid that  
               ((long)nums[i] > (long)2*nums[j]))
               or use 2L so that it can auto type cast to long.
               */
            while((j<=high) && (nums[i] > 2L *nums[j])){
                j++;
            }
            cnt += (j - (mid+1));
        }

        vector<int> arr;
        int left =low;
        int right=mid+1;
        while(left <= mid && right <= high){
            if(nums[left]<= nums[right]){
                arr.push_back(nums[left++]);
            }else{
                arr.push_back(nums[right++]);
            }
        }
        while(left <= mid){
            arr.push_back(nums[left++]);
        }
        while(right <= high){
            arr.push_back(nums[right++]);
        }
        for(int i=low; i<=high; i++){
            nums[i] = arr[i-low];
        }
        return cnt;
    }
    int merge_sort(vector<int>& nums, int low, int high){
        if(low>=high) return 0;
        int mid = (low+high)/2;
        int inv = merge_sort(nums, low, mid);
        inv += merge_sort(nums, mid+1, high);
        inv += merge(nums, low, mid, high);
        return inv;
    }

    int grid_recurssive_paths(int i, int j, int m, int n){
        if(i==m-1 && j==n-1)
            return 1;
        if(i>=m || j>=n)
            return 0;
        else
            return (grid_recurssive_paths(i+1,j,m,n)+grid_recurssive_paths(i,j+1,m,n));
    }
    public:

    vector<int> twoSum(vector<int>&arr, int sum){
        /* Return the indices of the two numbers such that they add upto the target.
           Don't use same element twice, exactly one solution */
        vector<int> res;
        map<int,int> m;

        for(int i=0; i<arr.size(); i++){
            if(m.find(sum - arr[i])!=m.end()){
                return {i,m[sum-arr[i]]};
            }
            m[arr[i]]=i;
        }
        return {-1,-1};
    }

    /*
    Given an array nums, we call (i,j) as important reverse pair if
    i < j and nums[i] > 2*nums[j]. Return the number of pairs.
    */
    int find_inversion(vector<int>& nums){
        return merge_sort(nums,0,nums.size()-1);
    }

    /* The robot is placed in top left corner, it can move either right or down.
       The robot is trying to reach the bottom right corner of the grid.
       How many possible unique paths are there.
    */
    int unique_paths(int m, int n){
        /* recurssive solution */
        //return grid_recurssive_paths(0,0,m,n);
        /* DP */
        vector<vector<int>> dp(m, vector<int>(n,1));
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }

    /* 1. sorting - O(nlogn)
       2. couting number of 0,1,2 than replaying - O(n)+O(n)
       3. this - Dutch National Flag algorithm
    */
    void sort_0_1_2(vector<int> &arr){
        int start=0;
        int mid=0;
        int end=arr.size()-1;
        while(mid<=end){
            //if the element is 0
            if(arr[mid]==0){
                swap(arr[start++],arr[mid++]);
                /*swap
                int temp = arr[start];
                arr[start] = arr[mid];
                arr[mid] = temp;
                start++;mid++;
                */
            //if the element is 1
            }else if(arr[mid]==1){
                mid++;
            //if the element is 2
            }else{
                swap(arr[mid],arr[end--]);
                /*
                int temp = arr[mid];
                arr[mid] = arr[end];
                arr[end] = temp;
                end--;
                */
            }
        }
        return;
    }

    /* Given an array nums containing n+1 integers where each
    integer is between 1 to n, inclusive. Assuming that there 
    is only one duplicate number, find the duplicate one.
        1. sorting - O(nlogn) space - O(1)
        2. Hashing - O(n) space - O(n)
        3. linked list cycle method + tortoise method
        4. Math - calculate sum
    */
    int findDuplicate(vector<int> arr){
        int slow = arr[0];
        int fast = arr[0];
        do{
            slow = arr[slow];
            fast = arr[arr[fast]];
        }while(slow!=fast);

        fast = arr[0];
        while(slow !=fast){
            slow = arr[slow];
            fast = arr[fast];
        }
        return slow;
        /* Calculate SUM
        int len = arr.size();
        int sum1 = ((len-1)*len)/2;
        int sum2 = 0;
        for(int i=0; i<len; i++){
            sum2 += arr[i];
        }
        return sum2-sum1;
        */
    }

    /* Given as unsorted array of size n. Array elements are in the
    range from 1 to n. One number from set {1,2,..n} is missing and 
    one number occurs twice in the array. Find these two numbers
            1. Hashing - O(2n) - space - O(n)
            2. Math
            3. XOR
    */
   vector<int> findMissingRepeating(vector<int> arr){
       vector<int> res(2,0);

       return res;
   }

    /* We need to merge these two sorted arrays, such that the intial numbers
    (after complete sorting) are in the first array and the remaining numbers
    are in the second array.
        1. Using a third array - O(nlogn) + space - O(n)
        2. insertion sort - O(m*n) space - O(1)
        3. GAP O((n+m)log(n+m)
        4. other methods in hard part of GfG
    */
   void mergeSortedArray(vector<int>& arr1, vector<int>& arr2){
       int len1 = arr1.size();
       int len2 = arr2.size();
       int i=0, j=0;

       for(int i=0; i<len1; i++){
           if(arr1[i] > arr2[0]){
               swap(arr1[i],arr2[0]);
               /* after above step, second array
               became unsorted so sort it */
               int felement = arr2[0];
               int k;
               for(k=1; k<len2 && arr2[k]<felement; k++){
                   arr2[k-1] = arr2[k];
               }
               arr2[k-1] = felement;
           }
       }
       return;
   }
    
    /* Find the contiguous subarray (containing at least one number)
    which has the largest sum and return it.
        1. Iterate over all elements - O(n*n*n) -> O(n*n)
        2. Kadane's Algorithm - O(n) - space O(1)
    */
   int MaxSubarraySum(vector<int> arr){
       int sum=0;
       int maxs = INT_MIN;
       for(auto it: arr){
           sum += it;
           maxs = max(sum, maxs);
           if(sum < 0) sum=0;
       }
       return maxs;
   }

    /* 9. Merge Intervals
     -> ask if the intervals are in sorted order?
            1. Bruteforce - O(nlogn) + O(n*n)
            2. 
    */
   vector<vector<int>> mergeIntervals(vector<vector<int>> intervals){
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
};

int main(){
    placement ob;
    
    //1. Two SUM
    vector<int> arr({2,3,5,7,9,4,6});
    int sum=8;
    vector<int> res = ob.twoSum(arr,sum);
    cout<<"Two sum for "<<sum<<" is "<<arr[res[0]]<<" "<<arr[res[1]]<<endl;

    //2. find inversion
    vector<int> arr1({2,4,3,5,1});
    cout<<"Number of inversions "<<ob.find_inversion(arr1)<<endl;

    //3. Grid Unique path
    //https://leetcode.com/problems/unique-paths/discuss/22954/C%2B%2B-DP
    cout<<"Number of Unique paths "<<ob.unique_paths(3,7)<<endl;

    //4. sort an array of 0's 1's 2's without using extra space or sorting algo
    vector<int> arr2({2,1,0,2,1,0});
    ob.sort_0_1_2(arr2);
    for(int i=0; i<arr2.size(); i++){
        cout<<arr2[i]<<" ";
    }
    cout<<endl;

    //5. Find the duplicate number
    vector<int> arr3({2,5,9,6,9,3,8,4,7,1});
    cout<<"Duplicate number: "<<ob.findDuplicate(arr3)<<endl;

    //6. Find the repeating and missing 
    //https://takeuforward.org/data-structure/find-the-repeating-and-missing-numbers/
    vector<int> arr4({3,1,2,5,4,6,7,5});
    res = ob.findMissingRepeating(arr4);
    cout<<"Missing&Repating: "<<res[0]<<" "<<res[1]<<endl;

    //7. Merge two sorted array with O(1) extra space
    //https://www.geeksforgeeks.org/efficiently-merging-two-sorted-arrays-with-o1-extra-space/
    vector<int> arr5({1,5,9,10,15,20});
    vector<int> arr6({2,3,8,12});
    ob.mergeSortedArray(arr5,arr6);
    for(int i=0; i<arr5.size(); i++){
        cout<<arr5[i]<<" ";
    }
    cout<<endl;
    for(int i=0; i<arr6.size(); i++){
        cout<<arr6[i]<<" ";
    }
    cout<<endl;

    //8. Maximum Subarray
    vector<int> arr7({-2,-3,4,-1,-2,1,5,-3});
    cout<<"Subarray Sum: "<<ob.MaxSubarraySum(arr7)<<endl;

    //9. Merge Intervals
    vector<vector<int>> res1;
    vector<vector<int>> arr8({{1,3},{2,4},{2,6},{8,9},{8,10},{9,11},{15,18},{16,17}});
    res1 = ob.mergeIntervals(arr8);
    for(auto it: res1){
        cout<<"{"<<it[0]<<" "<<it[1]<<"} ";
    }
    cout<<endl;

    //10. set matrix zeros
    return 0;
}