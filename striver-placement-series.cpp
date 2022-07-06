#include<iostream>
using namespace std;
#include<vector>
#include<map>

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
        return grid_recurssive_paths(0,0,m,n);
        /* DP */
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

    //3. grid Unique path
    //https://leetcode.com/problems/unique-paths/discuss/22954/C%2B%2B-DP
    cout<<"Number of Unique paths "<<ob.unique_paths(3,7)<<endl;



    return 0;
}