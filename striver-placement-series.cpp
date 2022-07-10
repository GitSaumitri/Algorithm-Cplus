/* Strivers Placement series  
    1. Two SUM
    2. Reverse pairs (appl: find inversion)
    3. Grid Unique path
       https://leetcode.com/problems/unique-paths/discuss/22954/C%2B%2B-DP
    4. sort an array of 0's 1's 2's without using extra space or sorting algo
    5. Find the duplicate number
    6. Find the repeating and missing 
       https://takeuforward.org/data-structure/find-the-repeating-and-missing-numbers/
    7. Merge two sorted array with O(1) extra space
       https://www.geeksforgeeks.org/efficiently-merging-two-sorted-arrays-with-o1-extra-space/
    8. Maximum Subarray
    9.
    10.
    11.
    12.

*/
#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#include <vector>

class placement{
    //2. Reverse pairs (appl: find inversion)
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
    //2. Reverse pairs (appl: find inversion)
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

    // 13. count Inversion
    int merge1(vector<int> nums, int low, int mid, int high){
        int inv=0;
        /*
        int j=mid+1;
        for(int i=low; i<=mid; i++){
            while((j<=high) && (nums[low] > nums[j])){
                j++;
            }
            inv += (j - (mid+1));
        }
        */
        int left = low;
        int right = mid+1;
        vector<int> temp;
        while(left <= mid && right <= high){
            if(nums[left] <= nums[right]){
                temp.push_back(nums[left++]);
            }else{
                temp.push_back(nums[right++]);
                inv = inv + (mid -left +1);
            }
        }
        while(left <= mid){
            temp.push_back(nums[left++]);
        }
        while(right <= high){
            temp.push_back(nums[right++]);
        }
        for(int i=low; i<high; i++){
            nums[i] = temp[i-low];
        }
        return inv;
    }
    // 13. count Inversion
    int merge_sort1(vector<int>& nums, int low, int high){
        if(low >= high)
            return 0;
        int mid = (low+high)/2;
        int inv = merge_sort1(nums, low, mid);
        inv += merge_sort1(nums, mid+1, high);
        inv += merge1(nums, low, mid, high);
        return inv;
    }

    public:

    //1. Two SUM
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

    /* 2. Reverse pairs (appl: find inversion)
    Given an array nums, we call (i,j) as important reverse pair if
    i < j and nums[i] > 2*nums[j]. Return the number of pairs.
    */
    int find_inversion(vector<int>& nums){
        return merge_sort(nums,0,nums.size()-1);
    }

    /* 3. Grid Unique path
       The robot is placed in top left corner, it can move either right or down.
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

    /* 4. sort an array of 0's 1's 2's without using extra space or sorting algo 
            1. sorting - O(nlogn)
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

    /* 5. Find the duplicate number 
        Given an array nums containing n+1 integers where each
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

    /* 6. Find the repeating and missing 
        Given as unsorted array of size n. Array elements are in the
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

    /* 7. Merge two sorted array with O(1) extra space
        We need to merge these two sorted arrays, such that the intial numbers
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
    
    /* 8. Maximum Subarray 
        Find the contiguous subarray (containing at least one number)
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
            2. Merge eachpair - O(nlogn) + O(n)    
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

   /* 10. set matrix zeros
        1. Bruteforce - for each zero set to -1 for all row/col then set 0 at the end
        2. reserve extra space for col n row - mark them based on zero
        3. For the exta space above - reserve the first row and col.
   */
    void setMatrixZeros(vector<vector<int>> & matrix){
        int col0=1;
        int rows = matrix.size();
        int cols = matrix[0].size();
        for(int i=0; i<rows; i++){
            if(matrix[i][0]==0) col0=0;
            for(int j=1; j<cols; j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }

        for(int i=rows-1; i>=0; i--){
            for(int j=cols-1; j>=0; j--){
                if(matrix[i][0]==0 || matrix[0][i]==0)
                    matrix[i][j]=0;
            }
            if(col0==0){
                matrix[i][0]=0;
            }
        }
        return;
    }

   /* 11. Pascal Triangle
    n       n
     C   =   P  / r!  = compute in O(n) = (n!) / ((r!) * (n-r)!)    
      r       r
   Manly three type of problem
            1. Given an non-negative integer, generate first n rows
                O(n*n)   space - O(n*n) 
            2. print the nth row of pascal triangle
                O(n)     space - O(n)
            3. print the nth row and mth column element - O(n) - O(1)
                                    r-1       4
    5th row 3rd column element =        C      C     =  (4*3)/(2*1) = 6
                                         c-1    2
    https://www.cuemath.com/ncr-formula/
   */   
    vector<vector<int>> pascal_traingle(int nrows){
        vector<vector<int>> r(nrows);
        for(int i=0; i<nrows; i++){
            r[i].resize(i+1);
            r[i][0] = r[i][i] = 1;

            for(int j = 1 ; j < i ; j++)
                r[i][j] = r[i-1][j-1] + r[i-1][j];
        }
        return r;
    } 

    /* 12. Next permutation
       Implement next permutation, which rearranges numbers into the lexicographically
       next greater permutation of numbers.
       If such arrangement is not possible, it much rearrange it as the lowest possible
       order (i.e sort in ascending order).
       The replacement must be in-place and use only constant extra memory.
            1. c++ inbuild next_permutation
            2. bruteforce - find all permutations
            3. lnear order -
    */
   void nextPermutation(vector<int>& nums){
       int i,j;
       int len = nums.size();
       for(i=len-2; i>=0; i--){
           if(nums[i] < nums[i+1])
                break;
       }
       if(i<0){
           reverse(nums.begin(), nums.end());
       } else {
           for(j=len-1; j>=0; j--){
               if(nums[j] > nums[i])
                    break;
           }
           swap(nums[j],nums[i]);
           reverse(nums.begin()+i+1,nums.end());
       }
   }

   /* 13. Count Inversions
      Two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j
        1. brute force - O(n*n) space - O(1)
        2. merge sort - O(nlogn) space - O(n)
   */
    int countInversions(vector<int> nums){
        return merge_sort1(nums, 0, nums.size()-1);
    }

    /* 14. Best time to buy and sell stock
            1. Brute force - O(n2)
            2. 
    */
   int maxProfitStocks(vector<int> stocks){
       int m = stocks[0];
       int profit = 0;
       for(int i=0; i<stocks.size(); i++){
           // profit for today is the price for today minus
           //the minimum seen till now
           profit = max(profit, stocks[i]-m);
           m = min(m,stocks[i]);
       }
       /*
        int profit = 0;
        int minPrice = INT_MIN;
        for(int i=0; i<stocks.size(); i++){
            minPrice = min(minPrice, stocks[i]);
            profit = max(profit, stocks[i]-minPrice); 
        }
       */
       return profit;
   }

    /* 15. Rotate Matrix
       You are given an n x n 2D matrix representing an image.
       Rotate an image by 90 degrees (clockwise)
            1. Using extra space - O(n*n) space - O(n*n)
            2. Transpose (colms into rows) + reverse 
    */
   void rotate_matrix(vector<vector<int>>& matrix){
       int rows = matrix.size();
       int cols = matrix[0].size();

       for(int i=0; i<rows; i++){
           for(int j=0; j<i; j++){
               swap(matrix[i][j],matrix[j][i]);
           }
       }

       for(int i=0; i<rows; i++){
           reverse(matrix[i].begin(), matrix[i].end());
       }
   }

   /* 16. Search a 2D matrix
      Write an efficient algorithm that searches for a value in an m x n matrix.
      The matrix has the following properties
      1- integer in each row are sorted from left to right.
      2- the first integer of each row is greater that the last integer of the previous row
    - GFG - variation of same - search in a row wise and colum wise sorted matrix   
      - here the 2nd condition might not be true.
            1. linear seach - O(n*m)  space - O(1)
            2. binary search on each row - O(nlogm)
            3. start from right top cornet - if small than move left else move down
            4. (with 2nd condition) binary search assuming a single sorted array  
   */
    bool search_2d(vector<vector<int>> nums, int val){
        if(!nums.size())
            return false;
        int rows = nums.size();
        int cols = nums[0].size();
        /* WHEN - 2D array is row wise and colm wise sorted 
        but not necessarily first integer of each is greater than the last
        integer of the previous row 
        int i=0, j=cols-1; //right top corner
        while(i < rows && j >= 0){
            if(nums[i][j]==val){
                cout<<"Found element at "<<i<<" "<<j<<endl;
                return true;
            }else if(nums[i][j] > val){
                j--;
            }else {
                i++;
            }
        }
        return false;
        */
       int low = 0;
       int high = (rows*cols - 1);
       while(low <= high){
           int mid = (low + (high - low)/2);
           if(nums[mid/cols][mid%cols]==val){
                cout<<"Found element at "<<mid/rows<<" "<<mid%cols<<endl;
                return true;
           }
           if(nums[mid/rows][mid%cols] < val){
               low = mid+1;
           }else {
               high = mid+1;
           }
       }
       return false;
    }

    /* 17. Power x to n
        n can be postive or negative - O(logn)
    //if n is positive
    int power(int x, int n){
        if(n <= 1){
            return x;
        }
        if(n%2==0){
            return power(x,n/2) * power(x,n/2);
        }else {
            return x * power(x, n-1); 
        }
    }*/
    double power(double x, int n){
        double ans = 1.0;
        long long nn = n; //taken long long so that while converting
                        //max negative to positive it shouldn't go out of bound
        if(nn<0) 
            nn = -1 * nn; 
        while(nn){
            if(nn%2){
                ans = ans * x;
                nn = nn - 1;
            } else {
                x = x * x;
                nn = nn/2;
            }
        }
        if(n<0) 
            ans = (double)(1.0)/(double)(ans);
        return ans;
    } 

    /* 18. Majority element
    Given an array of size n, The majority element is the element that appears more than
    floor of (n/2) times.
            1. Brute force - compare all O(n*n)
            2. using hash-map -  O(nlogn)
            3. Moore voting algorithm O(n)
    */
     int majority_element(vector<int> nums){
         int count= 0;
         int candidate = 0;
         for(int num: nums){
            if(count == 0){
                candidate = num;
            }
            if(num == candidate)
                count += 1;
            else
                count -= 1;
         }
         return candidate;
     }

    /* 19. Majority element
    Given an array of size n, The majority element is the element that appears more than
    floor of (n/3) times.
            1. Brute force - compare all O(n*n)
            2. using hash-map - O(n) if using frequency array - O(nlogn) with c++
            3. Moore voting algorithm O(n)
    */
    int majority_element1(vector<int> nums){
        return 0;
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
    vector<vector<int>> mat({{1,1,1,1},
    {1,0,1,1},
    {1,1,0,1},
    {0,0,0,1}});
    ob.setMatrixZeros(mat);
    for(int i=0; i<mat.size(); i++){
        for(int j=0; j<mat[0].size(); j++){
            cout<<" "<<mat[i][j];
        }
        cout<<endl;
    }

    //11. Pascal Triangle
    vector<vector<int>> r;
    r = ob.pascal_traingle(6);
    for(int i=0; i<r.size(); i++){
        for(int j=0; j<r[i].size(); j++){
            cout<<" "<<r[i][j];
        }
        cout<<endl;
    }

    //12. Next Permutation
    //vector<int> nums1({1,3,5,4,2});
    vector<int> nums1({5,4,3,2,1});
    cout<<"Number: ";
    for(int i=0; i<nums1.size(); i++){
        cout<<nums1[i]<<" ";
    }
    cout<<endl;
    ob.nextPermutation(nums1);
    cout<<"Next Permutation: ";  
    for(int i=0; i<nums1.size(); i++){
        cout<<nums1[i]<<" ";
    }
    cout<<endl;

    //13. Count inversions
    vector<int> nums2({5,4,3,2,1}); //10
    //vector<int> nums2({1,2,3,4,5}); //0
    cout<<"Inversion count = "<<ob.countInversions(nums2)<<endl;

    //14. Stock Buy and sell
    vector<int> stocks({7,1,5,3,6,4});
    cout<<"Max Profit = " <<ob.maxProfitStocks(stocks)<<endl;

    //15. Rotate Matrix
    vector<vector<int>> matrix({{1,2,3},{4,5,6},{7,8,9}});
    ob.rotate_matrix(matrix);
    for(int i=0; i<matrix.size(); i++){
        for(int j=0; j<matrix[0].size(); j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    //16. Search in 2D matrix
    vector<vector<int>> matrix1({{1,2,3},{4,5,6},{7,8,9}});
    cout<<"Search in 2D matrix: "<<ob.search_2d(matrix1,9)<<endl;
    
    //17. Pow x to n
    int x = 5;
    int n = -2;
    cout<<"Pow "<<x<<" to "<<n<<" = "<<ob.power(x,n)<<endl;

    //18. Majority element
    vector<int> input18({1,3,4,5,6,1,1,1,1,1});
    cout<<"Majority element: "<<ob.majority_element(input18)<<endl;

    //19. Majority element - II
    vector<int> input19({1,3,4,5,6,1,1,1,1,1});
    cout<<"Majority element: "<<ob.majority_element1(input19)<<endl;

    return 0;
}