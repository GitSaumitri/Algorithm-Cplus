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
    9. Merge Intervals
    10. set matrix zeros
    11. Pascal Triangle
    12. Next permutation
    13. Count Inversions
    14. Best time to buy and sell stock
    15. Rotate Matrix
    16. Search a 2D matrix
    17. Power x to n
    18. Majority element
    19. Majority element
    20. Four SUM
    21. Largest subarray with zero sum
    22. Longest consecutive sequence
    23. Count Subarrays with XOR as K
    24. Longest sub string without repeat character
    25. Reverse a linked list 
    26. Middle of the linked list
    27. Merge two sorted lists
    28. Remove the nth node from end of the linkedlist
    29. Delete node in a linkedlist
    30. Add two numbers given as linked list
    31. Intersection point of two linked list
    32. Delete a cycle in a linked list
    33. Reverse nodes in K-groups
    34. Check for palindrom linked list
    35. Find the starting point of a cycle
    36. Flattening of a linkedlist
    37. Rotate a linked list
    38. Clone a linked list with next and random pointer
    39. 3 SUM
    40. Trapping rain water
    41. Remove duplicates from a sorted array
    42. Max consecutive ones
    43. N meetings in one room.
    44. Minimum platforms
    45. Job sequencing problem
    46. Minimum coins
    47. Fractional knapsack
    48. Subset sum -1  (recursion series)
    49. Subset sum -2  (recursion series)
    50. Print all permutation of a string/array - 1 (recursion series)
    51. Print all permutation of a string/array - 2 (recursion series)
    52. Combination sum (recursion series)
    53. Combination sum-2 (recursion series)
    54. Palindrom partitioning (recursion series)
    55. Kth permuation sequence (recursion series)
    56. N queen (recursion series)
    57. Sudoku solver (recursion series)
    58. M coloring problem (recursion series)
    59. Rate in a Maze (recursion series)
    60. Nth root of a number using binary search
    61. find element appear once in a sorted array (all other twice)
    62. search element in a rotated array
    63. Median of row wise sorted matrix (nested binary search)
    64. Median of two sorted array (binary search)
    65. kth element of two sorted array
    66. Power set - Print all subsequences
    67. Implenetation stack using array
    68. Allocate minimum number of pages - binary search
    69. Aggressive cows - binary search
    70. Queue implementation using array
    71. Stack imeplentation using single queue
    72. Queue implemenation using stack
    73. Valid parentheses
    74. Next greater element
    75. Implement LRU cache
    76. Implement LRU cache
    77. Implement LFU cache
    78. Implement LFU cache
    79. Largest rectange in histogram
    80. Largest rectange in histogram
    81. Sliding window maximum
    82. Rottange Oranges
*/

using namespace std;
#include<iostream>
#include<bits/stdc++.h>
#include <stdlib.h>

/* typical linklist node */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/* linklist node with a bottom pointer */
struct ListNode1 {
    int val;
    ListNode1 *next;
    ListNode1 *bottom;
    ListNode1() : val(0), next(NULL), bottom(NULL) {}
    ListNode1(int x) : val(x), next(NULL), bottom(NULL) {}
    //ListNode1(int x, ListNode1 *next) : val(x), next(next) {}
    //ListNode1(int x, ListNode1 *bottom) : val(x), bottom(bottom) {}
};

/* linklist node with random pointer can point to any of the node */
struct ListNode2 {
    int val;
    ListNode2 *next;
    ListNode2 *random;
    ListNode2() : val(0), next(NULL), random(NULL) {}
    ListNode2(int x) : val(x), next(NULL), random(NULL) {}
    //ListNode2(int x, ListNode1 *next) : val(x), next(next) {}
    //ListNode2(int x, ListNode1 *random) : val(x), random(bottom) {}
};

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
       /*
       int sum=0;
       int maxs=0;
       for(auto it: arr){
            sum = max(arr[i], sum+arr[i]);
            maxs = max(maxs, sum);
       }
       return maxs;
       */
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
            for(int j=cols-1; j>0; j--){
                if(matrix[i][0]==0 || matrix[0][j]==0)
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

    //ceil(x) : Returns the smallest integer that is greater than or equal to x 
    //(i.e : rounds up the nearest integer).
    //floor(x) : Returns the largest integer that is smaller than or equal to x 
    //(i.e : rounds downs the nearest integer).

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
         /* majority element has to appear in the input more than 
         non-majority elements */
         return candidate;
     }

    /* 19. Majority element
    Given an array of size n, The majority element is the element that appears more than
    floor of (n/3) times.
            1. Brute force - compare all O(n*n)
            2. using hash-map - O(n) if using frequency array - O(nlogn) with c++
            3. Moore voting algorithm O(n) - space O(1) find the two majority elemets
    */
    vector<int> majority_element1(vector<int> nums){
        int count1 = 0;
        int candidate1 = -1;
        int count2 = 0;
        int candidate2 = -1;
        int len = nums.size();
        vector<int> res;
        for(int i=0; i<len; i++){
            if(nums[i]==candidate1){
                count1++;
            }else if(nums[i]==candidate2){
                count2++;
            }else if(count1 == 0){
                candidate1 = nums[i];
                count1++;
            }else if(count2 == 0){
                candidate2 = nums[i];
                count1++;
            }else {
                count1--;
                count2--;
            }
        }
        count1 = count2 = 0;
        for(int i=0; i<len; i++){
            if(nums[i]==candidate1)
                count1++;
            else if(nums[i]==candidate2){
                count2++;
            }
        }
        if(count1 > (len/3))
            res.push_back(candidate1);
        if(count2 > (len/3))
            res.push_back(candidate2);

        return res;
    }

    /* 20. Four sum
        use two sum with a for loop
    */
    vector<vector<int>> fourSum(vector<int>& nums, int target){
        vector<vector<int>> res;
        if(nums.empty())
            return res;
        int n = nums.size();
        sort(nums.begin(),nums.end());

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int target2 = target - nums[i] - nums[j];
                int front = j+1;
                int back = n-1;

                while(front < back){
                    int two_sum = nums[front] + nums[back];
                    if(two_sum < target2) front++;
                    else if(two_sum > target2) back--;
                    else {
                        vector<int> quadruplet(4,0);
                        quadruplet[0]=nums[i];
                        quadruplet[1]=nums[j];
                        quadruplet[2]=nums[front];
                        quadruplet[3]=nums[back];
                        res.push_back(quadruplet);

                        //processing the duplicates of 4th number
                        while(front < back && nums[front] == quadruplet[2]) ++front;

                        //processing the duplicates of 3rd number
                        while(front < back && nums[back] == quadruplet[3]) --back;
                    }
                }

                //processing the duplication of 2nd number
                while(j+1 < n && nums[j+1] == nums[j]) ++j;
            }

            //processing the duplication of 1st number
            while(i+1 < n && nums[i+1] == nums[i]) ++i;
        }
        return res;
    }

    /* 21. Largest subarray with zero sum
        Given an array having both positive and negative integers. The task
        is to compute the length of the largest subarray with sum 0.
            - Bruteforce approach - O(n*n)
            - prefix sum - O(nlogn) - logn for hashmap
    */
   int LargestSubArraySum0(vector<int> arr){
       map<int,int> prefixSum;
       int sum=0, maxlen=0;
       for(int i=0; i<arr.size(); i++){
           sum += arr[i];
           if(sum == 0){
               maxlen = i + 1;
           } else {
               if(prefixSum.find(sum) != prefixSum.end()){
                    maxlen = max(maxlen, i - prefixSum[sum]);
               }else{
                   prefixSum[sum] = i;
               }
           }
       }
       return maxlen;
   }

   /* 22. Longest consecutive sequence
   Given an unsorted array of integers find the length of the longest
   consecutive elements sequence. run in O(n).
        - sorting then find sequence - O(nlogn) + O(n)
        - hash set - O(n) + O(n) + O(n)
    */
   int longestConsecutive(vector<int>& nums){
       set<int> hashSet;
       for(int num: nums){
           hashSet.insert(num);
       }
       int longestSteak = 0;
       for(int num: nums){
           if(!hashSet.count(num-1)){
               int currentNum = num;
               int currentSteak = 1;

               while(hashSet.count(currentNum+1)){
                   currentNum += 1;
                   currentSteak +=1 ;
               }

               longestSteak = max(longestSteak, currentSteak);
           }
       }
       return longestSteak;
   }

    /* 23. Count the number of subarrays having a given XOR as K
    Given an array of integers and a number m, count the number of subarrays having XOR
    of their elements as m.
        - find out all subarrays then xOR - O(n*n*n) optimise it to-> O(n*n)
        - Use the same method as prefix sum in problem#21
        -
    */  
   int countSubarrayXOR(vector<int> arr, int M){
       map<int, int> freq;
       int cnt = 0;
       int xorr = 0;
       for(auto it: arr){
            xorr = xorr ^ it;
            if(xorr == M){
                cnt++;
            }

            if(freq.find(xorr ^ M) != freq.end()){
                cnt += freq[xorr ^ M];
            }

            freq[xorr] += 1;
       }
       return cnt;
   }

   //24. Longest sub string without repeat character
   int lengthOfLongestSubstring(string s){
       vector<int> mpp(256,-1);
       int left = 0, right=0;
       int n = s.size();
       int len = 0;
       while(right < n){
           if(mpp[s[right]] != -1)
               left = max(mpp[s[right]]+1, left);
            mpp[s[right]] = right;
            len = max(len, right - left + 1);
            right++;
       }
       return len;
   }

    //25. Reverse a linked list
    ListNode * reverseList(ListNode * head){
        ListNode *temp = nullptr;
        ListNode *next = head;
        while(head!=nullptr){
            next = head->next;
            head->next = temp;
            temp = head;
            head = next;
        }
        return temp;
    }

    /* 26. Middle of the linked list
        if there are two middle nodes, return the second middle node
            1. count the number of nodes
            2. tortoise method
    */
   ListNode * listMiddleNode(ListNode *head){
       ListNode *slow = head;
       ListNode *fast = head;
       while(fast!=nullptr && fast->next!=nullptr){
           slow = slow->next;
           fast = fast->next->next;
       }
       return slow;
   }

    /* 27. Merge two sorted linked list
            - inplace.
    */
   ListNode * mergeTwoSortedList(ListNode *l1, ListNode *l2){
       if(l1==nullptr) return l2;
       if(l2==nullptr) return l1;
       if(l1->val > l2->val){
           ListNode *temp=l2;
           l2 = l1;
           l1 = temp;
       }
       ListNode *res = l1;
       while(l1!=nullptr && l2!=nullptr){
           ListNode *temp = nullptr;
           while(l1!=nullptr && l1->val <= l2->val){
               temp = l1;
               l1 = l1->next;
           }
           temp->next = l2;

           //swap
           ListNode * tmp=l1;
           l1 = l2;
           l2 = tmp;
       }
       return res;
       /*
       ListNode result;
       ListNode *res = &result;
       while(l1!=nullptr && l2!=nullptr){
           if(l1->val < l2->val){
               res->next = l1;
               l1 = l1->next;
           }else{
               res->next = l2;
               l2 = l2->next;
           }
           res = res->next;
       }
       if(l1!=nullptr){
           res->next = l1;
       }
       if(l2!=nullptr){
           res->next = l2;
       }
       return result.next;
       */
   }

    /* 28.Remove nth node from end of the linked list 
            - O(n) 
    */
    ListNode * removeNthNode(ListNode *head, int n){
        ListNode *start = new ListNode();
        start->next = head;
        ListNode *fast = start;
        ListNode *slow = start;

        for(int i=1; i<=n; i++){
            fast = fast->next;
        }

        while(fast->next!=nullptr){
            fast = fast->next;
            slow = slow->next;
        }
        //ListNode * del=slow->next;
        slow->next = slow->next->next;
        //delete(del);
        //head = start->next;
        //delete(start);
        //return head;
        return start->next;
    }

    /* 29. Delete node in a linked list
       it is guarnteed that the node to be deleted is not a tail node in the list.
        - O(1)
    */
    void deleteThisNode(ListNode *node){
        ListNode *d = node->next;
        node->val = node->next->val;
        node->next = node->next->next;
        free(d);
        return;
    }

    /* 30. Add two numbers as linked list
       You are given two non-empty linked lists represting two non-negative integers.
       The digits are stored in reverse order and each of their nodes contains a single 
       digit. Add the two numbers and return the sum as a linked list.
       You may assume the two numbers do not contain any leading zero, 
       except the number 0 itself. 
    */
    ListNode * addTwoNumbersList(ListNode *l1, ListNode *l2){
        ListNode *head=nullptr,*node,*temp;
        int sum=0, carry=0;
        while(l1!=nullptr || l2!=nullptr || carry==1){
            sum = (l1!=nullptr?l1->val:0) +
                        (l2!=nullptr?l2->val:0) + carry;
            if(l1) l1=l1->next;
            if(l2) l2=l2->next;
            carry = sum/10;
            sum = sum%10;
            node = new ListNode(sum);
            if(head==nullptr){
                head = node;
                temp = node;
            }else{
                temp->next = node;
                temp=temp->next;
            }
        }
        return head;
    }

    /* 31. Intersection of two linked list
       Find the node at which the intersection of two singly linked list begins.
        1. each one ll and compare with all nodes of other - O(n*n)
        2. use a hash - store all node adds - O(n+n) - assuming hasing works with O(1)
        3. find both ll length - find diff - longer travel the diff - then travel till it collide
        4. just like above, but traverse till end, then go to next ll till collide
    */
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){
        if(headA == nullptr || headB == nullptr)
            return nullptr;
        ListNode *a = headA;
        ListNode *b = headB;

        //if a and b have different length, then we will stop the loop after second iteration
        while( a != b ){
            //for the end of first iteration, we just reset the pointer to the head of another ll
            a = (a == nullptr? headB : a->next);
            b = (b == nullptr? headA : b->next);
        }
        return a;
    }

    /* 32. Deletct a cycle in a linked list
            1. put all nodes in hash while travelling - O(n)
            2. tortoise method
    */
    bool isCycle(ListNode *head){
        if(head==nullptr || head->next==nullptr)
            return false;

        ListNode* fast = head;
        ListNode* slow = head;

        while(fast!=nullptr && fast->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow){
                return true;
            }
        } 
        return false;
    }

    /* 33. Reverse nodes in K groups
        - O(n) + O(n) - space - O(1)
    */
    ListNode * reverseKGroup(ListNode *head, int k){
        if(head == nullptr || k==1) return head;

        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *curr = dummy, *next = dummy, *pre = dummy;
        int count=0;

        while(curr->next!=nullptr){
            curr = curr->next;
            count++;
        }

        while(count >= k){
            curr = pre->next;
            next = curr->next;
            for(int i=1; i<k ; i++){
                curr->next = next->next;
                next->next = pre->next;
                pre->next = next;
                next = curr->next;
            }
            pre = curr;
            count -= k;
        }
        return dummy->next;
    }

    /* 34. check if linkedlist is palindrom
        - find values in list and check palindrom
        - reverse the right half of the ll
    */
    bool isPalindrom(ListNode* head){
        if(head==nullptr || head->next==nullptr)
            return true;
        ListNode *slow = head;
        ListNode *fast = head;

        while(fast->next!=nullptr && fast->next->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        slow->next = reverseList(slow->next);
        slow=slow->next;

        while(slow!=nullptr){
            if(head->val!=slow->val)
                return false;
            head = head->next;
            slow = slow->next;
        }
        return true;
    }

    /* 35. Find the stating point of the cycle
        - bruit force - hash
        - find the collision point - then starting point
        - intuition - 2 (L1 + L2) = L1 + L2 + Nc 
                    -> L1 = Nc - L2 
    */
    ListNode* detectCycle(ListNode *head){
        if(head==nullptr || head->next==nullptr)
            return nullptr;
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *entry = head;

        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast){ //there is a cycle
                while(entry!=slow){ //find the entry location
                    entry=entry->next;
                    slow=slow->next;
                }
                return entry;
            }
        }
        return nullptr;
    }

    /* 36. Flattening a linked list
        Given a linked list of size N, where everynode represents a linkedlist and 
        two pointer of it's type
        (i) a new pointer to the next node
        (ii) a bottom pointer to the linked list where this node is head
        The flattened list will be printed using the bottom pointer instead of next pointer.
    */
    ListNode1* mergeTwoLinkedlists(ListNode1 *a, ListNode1 *b){
        ListNode1 *temp = new ListNode1(0);
        ListNode1 *res = temp;
        while(a!=NULL && b!=NULL){
            if(a->val < b->val){
                temp->bottom = a;
                temp=temp->bottom;
                a=a->bottom;
            } else {
                temp->bottom = b;
                temp=temp->bottom;
                b=b->bottom;
            }
        }
        if(a) temp->bottom=a;
        else temp->bottom=b;
        
        return res->bottom;
    }
    ListNode1* flatten(ListNode1* root){
        if(root==NULL || root->next==NULL)
            return root;
        // recur for list on right
        root->next = flatten(root->next);
        //now merge
        root = mergeTwoLinkedlists(root,root->next);
        //return the root, it is merged with the left
        return root;
    }

    /* 37. Rotate a linkedlist K times
        - k can be more than the length of linkedlist
        - put the last one in first - O(k*n)
        - One k is n it rotate to itself, k = n%k
        - point the last node to first then number of rotated node first first points to null
        - O(n) + O(n-n%k) = O(n)
    */
    ListNode * rotateRight(ListNode* head, int k){
        //edge case
        if(!head || !head->next || k==0)
            return head;
        //compute the length
        ListNode *curr = head;
        int len = 1;
        while(curr->next && ++len)
            curr = curr->next;
        
        //go till that node
        curr->next = head;
        k = k % len;
        k = len - k;
        while(k--) curr=curr->next;

        //make the node head and break connection
        head = curr->next;
        curr->next=NULL;

        return head;
    }

    /* 38. Clone a linkedlist with next and random pointer
        - hash - for each node create a deep copy = {original node, deepcopy}
        - than travel the node and copy the deepcopy based on originla node - O(N) - space - O(N)
        - two pointer approach -  
    */
    ListNode2* copyRandomList(ListNode2* head){
        ListNode2* iter = head;
        ListNode2* front = head;

        /* First round: make copy of each node, and link them 
        together side by side in a single list */
        while(iter != NULL){
            front = iter->next;
            ListNode2* copy = new ListNode2(iter->val);
            iter->next = copy;
            copy->next = front;
            iter = front;
        }

        // second round: assign random pointer for the copy node
        iter = head;
        while(iter != NULL){
            if(iter->random != NULL){
                iter->next->random = iter->random->next;
            }
            iter = iter->next->next;
        }

        /* third round: restore the original list and 
            extract the copy list */
        iter = head;
        ListNode2 * newhead = new ListNode2(0);
        ListNode2 * copy = newhead;

        while(iter!=NULL){
            front = iter->next->next;

            //extract the copy 
            copy->next = iter->next;

            //restore the original list
            iter->next = front;

            copy = copy->next;
            iter = front;
        }
        return newhead->next;
    }

    /* 39. 3SUM
       Given an array nums of n integers, are there elements a,b,c in nums
       such that a+b+c=0? Find all unique triplets in the array which gives
       the sum of 0.
        - three loops - O(n3logn)
        - optimised - O(n*n)
    */
    vector<vector<int>> threeSum(vector<int>& nums){

        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        for(int i=0; i<nums.size()-2; i++){

            if(i==0 || (i>0 && nums[i]!=nums[i-1])){

                int lo = i+1, hi = nums.size()-1, sum=0-nums[i];

                while(lo < hi){
                    if(nums[lo]+nums[hi]==sum){
                        vector<int> temp;
                        temp.push_back(nums[lo]);
                        temp.push_back(nums[hi]);
                        temp.push_back(nums[i]);
                        res.push_back(temp);

                        while(lo<hi && nums[lo] == nums[hi]) lo++;
                        while(lo<hi && nums[hi] == nums[hi-1]) hi--;

                        lo++;hi--;
                    }
                    else if(nums[lo]+nums[hi] < sum) lo++;
                    else    hi--;
                }
            }
        }
        return res;
    }


    /* 40. Trapping rainwater
        - double loop
        - use prefix sum from left right and right side
        - two pointer approach
    */    
    int trap(vector<int>& height){
        int n = height.size();
        int left = 0;
        int right = n-1;
        int res = 0;
        int maxleft = 0, maxright=0;

        while(left <= right){
            if(height[left] <= height[right]){
                if(height[left]>=maxleft)
                    maxleft = height[left];
                else    
                    res += maxleft-height[left];
                left++;
            } else {
                if(height[right]>=maxright)
                    maxright = height[right];
                else    
                    res += maxright-height[right];
                right--;
            }
        }
        return res;
    }

    /* 41. remove duplicates from sorted array and 
        return the size of result array */
    /*  - can use a hash set - O(n)
        - two pointer 
    */
    int removeDuplicates(vector<int>& nums){
        if(nums.size()==0)
            return 0;
        int i=0;
        for(int j=1; j < nums.size(); j++){
            if(nums[j] != nums[i]){
                i++;
                nums[i] = nums[j];
            }
        }

        return i+1;
    }

    /* 42. Max consecutive 1's */
    int findMaxConsecutiveOnes(vector<int>& nums){
        int cnt=0;
        int maxi=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==1)
                cnt++;
            else
                cnt=0;
            maxi = max(maxi, cnt);
        }
        return maxi;
    }

    /* 43. N meeting in one Room  - Greedy - GFG
       There is one meeting room in a firm. There are n meeting in the form of (S[i],F[i]) where S[i] is start time of meeting and F[i] is finish time of meeting i.
       What is the maximum number of meetings that can be accomodated in the meeting room? 
       Also note that start time of one choosen meeting can't be equal to the end time of the other chosen meeting. 
        
        - first meeting start time should be greater than the last meeting end time
        - sort based on end time the start from beginning - O(nlogn)
    */

// WHY comparator function passed to sort STL has to be static ?????
    struct meeting {
        int start;
        int end;
        int pos;
    };

    static bool comparator1(struct meeting m1, struct meeting m2){
        if(m1.end < m2.end)
            return true;
        else if(m1.end > m2.end)
            return false;
        else if(m1.pos < m2.pos)
            return true;
        else    
            return false;
    }

    void maxMeetings(int s[], int e[], int n){
        struct meeting meet[n];
        for(int i=0; i<n; i++){
            meet[i].start = s[i]; meet[i].end = e[i]; meet[i].pos = i+1;
        }

        sort(meet, meet+n, comparator1);

        vector<int> ans;
        int limit = meet[0].end;
        ans.push_back(meet[0].pos);

        for(int i=1; i<n; i++){
            if(meet[i].start >= limit){
                limit = meet[i].end;
                ans.push_back(meet[i].pos);
            }
        }
        for(int i=0; i<ans.size(); i++){
            cout<< ans[i] << " "; 
        }
    }

    /* 44. Minimum number of platforms required for a railway station - Greedy - GFG
       Given arrival and departure times of all trains that reach a railway station. Find the minimum number of platforms required for the railway station so that no train is kept waiting.
       Consider that all trains arrive on the same day and leave on the same day. Arrival and departure time can never be the same for a train but
       we can have arrival time of one train equal to departure time of other. At any given instance of time, same platform can't be used for both
       departure of a train and arrival of another train. In such cases,  we need different platform. 
       - two pointer approach
    */
    int findPlatform(int arr[], int dep[], int n){
        
        sort(arr,arr+n);
        sort(dep,dep+n);

        int plat_needed = 1, result = 1;
        int i=1, j=0;

        while(i < n && j < n){
            if(arr[i] <= dep[j]){
                plat_needed++;
                i++;
            }
            else if(arr[i] > dep[j]){
                plat_needed--;
                j++;
            }
            if(plat_needed > result){
                result = plat_needed;
            }
        }
        return result;
    }

    /* 45. Job sequencing Problem - Greedy - GFG
       Given a set of N jobs where each job i has a deadline and profit associated to it.
       Each job takes 1 unit of time to complete and only one job can be scheduled at at time.
       We earn the profit if and only if the job is completed by its deadline. 
       The task is to find the maximum profit and the number of jobs done.
       Job will be given in the form (Jobid, deadline, Profit) assiciated to that job. 
    */

    typedef struct job{
        int profit;
        int dead;
    }Job;
    
    static bool comparison(Job a, Job b){
        return (a.profit > b.profit);
    }

    pair<int,int> JobScheduling(Job arr[], int n){

        sort(arr, arr+n, comparison);
        int maxi = arr[0].dead;
        
        for(int i=1; i<n; i++){
            maxi = max(maxi, arr[i].dead);
        }

        vector<int>slot(maxi + 1,-1);
        int countJobs = 0;
        int jobProfits = 0;

        for(int i=0; i<n; i++){
            for(int j=arr[i].dead; j>0; j--){
    /*
    We can use disjoint set to remove the check from last day to first day. 
    However we can solve CoLORFUL ARRAY from SPOJ to understand how to solve this in O(NlongN) 
    */

                if(slot[j]==-1){
                    slot[j]=i;
                    countJobs++;
                    jobProfits += arr[i].profit;
                    break;
                }
            }
        }
        return make_pair(countJobs, jobProfits);
    }

    /* 46. Minimum Coins - Greedy - GFG
    Given a value V, if we want to make a change for V Rs and we have an infinite supply
    of each of the denominations in {1,2,5,10,20,50,100,500,1000} valued coins. 
    What is the minimum number of coins and/or notes to be added to make the change?
    */
    /*
    Greedy works here as the any two coint sum is less than the other coin present in the set.
    however for a example - {1,5,6,9} - greedy won't work - for 11 with below method - 9 + 1 +
                                                            but actual answer - 5 + 6
    */
    void findMin(int V){
        int deno[]={1, 2, 5, 10, 20, 50, 100, 500, 1000};
        int n = 9;
        vector<int> ans;

        for(int i = n-1; i >= 0; i--){
            //find denominaiton
            while(V >= deno[i]){
                V -= deno[i];
                ans.push_back(deno[i]);
            }
        }

        for(int i=0; i<ans.size(); i++){
            cout << ans[i] << " ";
        }
    }

    /* 47. Fractional knapsack - Greedy - GFG 
    Given weights and values of N items, we need to put these items in a knapsack of capacity
    W to get the maximum total value in the kanpsack.
        - make sure to use double to make use of fraction  
        - sort the item on value
        - pick if can be taken full - oterwise fraction 
    */
    typedef struct item{
        int value;
        int weight;
    }Item;

    static bool comp(Item a, Item b){
        double r1 = (double)a.value / (double)a.weight;
        double r2 = (double)b.value / (double)b.weight;
        return r1 > r2;
    };
    double fractionalKnapsack(int W, Item arr[], int n){
        
        sort(arr, arr+n, comp);

        int currWeight = 0;
        double finalvalue = 0.0;
        for(int i=0; i<n; i++){
            if(currWeight + arr[i].weight <= W){
                currWeight += arr[i].weight;
                finalvalue += arr[i].value;
            } else {
                int remain = W - currWeight;
                finalvalue += (arr[i].value / (double)arr[i].weight) * (double)remain;
                break;
            }
        }

        return finalvalue;
    }

    /* 48-59 check in recursion series */

    /* 60. Nth root of a number 
        - binary search can be used for any monotonically increasing sequence
        - search space - log2(Mx10 to the power d)
        - time - N * log2(M*10 to the power d)
    */
    double multiply(double number, int n){
        double ans = 1.0;
        for(int i=1; i<=n; i++){
            ans = ans * number;
        }
        return ans;
    }

    double getNthRoot(int n, int m){
        double low = 1;
        double high = m;
        double eps = 1e-6;

        while((high-low) > eps){
            double mid = (low + high)/2.0;
            if(multiply(mid,n) < m){
                low = mid;
            } else {
                high = mid;
            }
        }

        cout<< low << " "<< high << endl;

        //just to check
        cout<< pow(m, (double)(1.0/(double)n));
    }

    /* 61. Single element in an sorted array - leetcode
        - xor of the same number gives zero so zeroing at the end will give the element
        - optimization  - if elements are present twice and only one element present once
                        - that means if initially two elements are present start odd then even
                        - once the one element comes, start will be in even then odd
                        - as the one lement will be must be in odd index
    */
    // in order to check for the left half
    // 1st instance - even index
    // 2nd instance - odd index, check on the left if the instance of that number is there or not
    int singleNonDuplicate(vector<int>&nums){
        int low =  0;
        int high = nums.size()-2; // the one elemt can be at the end
        while( low <= high){
            int mid = (low + high) >> 1;
            if(nums[mid] == nums[mid^1]){ //get immediate left index 
                low = mid+1;
            }else {
                high = mid-1;
            }
        }
        return nums[low];
    }

    /* 62. leetcode 33. Search in rotated sorted array
        Given the array nums after the rotation and an integer target, if it is nums, or -1 if it is not in nums.
        - O(log) time.
        https://leetcode.com/problems/search-in-rotated-sorted-array-ii/discuss/1890199/C%2B%2B-oror-Algorithm-oror-Binary-Search
    */
    int rotateSearch(vector<int>&a, int target){
        int low = 0, high = a.size()-1;
        while(low <= high){
            int mid = (low + high) >> 1;
            if(a[mid] == target) 
                return mid;
            //the left side sorted
            if(a[low] <= a[mid]){
                if(target >= a[low] && target <= a[mid]){
                    high = mid-1;
                } else {
                    low = mid+1;
                }
            } else {
                //right half is sorted
                if(target >= a[mid] && target <= a[high]){
                    low = mid+1;
                } else {
                    high = mid-1;
                }
            }
        }
        return -1;
    }

    //if duplicates are allowed in the above case
        bool search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while(low <= high){
            while(low < high && nums[low] == nums[low + 1]){
                low++;
            }
            while(low < high && nums[high] == nums[high - 1]){
                high--;
            }
            int mid = low + (high - low)/2;
            if(nums[mid] == target){
                return true;
            }
            if(nums[low] <= nums[mid]){
                if(target >= nums[low] && target <= nums[mid]){
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }
            else{
                if(target >= nums[mid] && target <= nums[high]){
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
        }
        return false;
    }

    /* 63. Median of row wise sorted matrix
        - middle index is median of matrix
        - brute force is to convert it into an array and sort it - O(m*nlog(m*n)) find the middle
        - effiecint - binary search - can assume the numbers in the matrix are between 1 to 10 to the power 9.
        -  e.g -    1,  3,  6
                    2,  6,  9
                    3,  6,  9
        1 ) Why we are taking no of elements  <= mid ? 
                Because if no of elements <= mid is equal to reqd count then 
                it is sure that this mid is not going to be the answer. 
                becoz either that mid is not part of matrix or 
                that mid is part of matrix but has only 3 elements lesser than it 
                (acc to this problem). So to discard this mid we consider count to be <= mid.
        2 ) Why we take last low as answer?  becoz for the element at that low position , 
            we have made sure that no of elements lesser than it are greater than reqd count. 
            We can n't take any element greater than that because obviously 
            it will have greater count. But there is chance that if we eliminate count of elements 
            equal to it from that count,  we can have count = required count. 
            for ex in this case 6 was answer for which we got count =7 and 
            if we elminate all 6's from that 7 no's we will get exactly  4 no's less than 6.
        3) We can even set the low = min value in matrix, high = max value in matrix
            but we needn't waste O(n) time for that - 0th and m-1 the index row contains them.

    */
    int countSmallerThanEqualToMid(vector<int> row, int mid){
        int l=0, h = row.size() - 1;
        while(l <= h){
            int md = (l + h) >> 1;
            if(row[md] <= mid){
                l = md + 1;
            } else {
                h = md - 1;        
            }
        }
        return l;
    }

    int findMedian(vector<vector<int>>& A){
        int low = 1;
        int high = 1e9;
        int n = A.size();
        int m = A[0].size();
        while(low <= high){
            int mid = (low + high) >> 1;
            int cnt = 0;
            for(int i=0; i<n; i++){
                cnt += countSmallerThanEqualToMid(A[i], mid);
                /* int l=0, h = A[i].size() - 1;
                while(l <= h){
                    int md = (l + h) >> 1;
                    if(A[i][md] <= mid){
                        l = md + 1;
                    } else {
                        h = md - 1;   
                    }     
                }
                cnt += l; */
            }
            if(cnt <= (n*m)/2) 
                low = mid + 1;
            else 
                high = mid - 1;
        }
        return low;
    }

    /* 64. Median of two sorted array of different size
        - sort them into a third array, find median - time - O(n+m) - space - O(n+m)
        - no need to take extra space, find out the position of element - O(n+m) - space O(1)
        - use binary search
    */
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
        if(nums2.size() < nums1.size())
            // binary search on smaller search space
            return findMedianSortedArrays(nums2,nums1);
        int n1 = nums1.size();
        int n2 = nums2.size();
        int low = 0, high = n1;

        while(low <= high){
            int cut1 = (low+high) >> 1;
            int cut2 = (n1 + n2 +1)/2 - cut1;

            int left1 = cut1 == 0 ? INT_MIN : nums1[cut1-1];
            int left2 = cut2 == 0 ? INT_MIN : nums2[cut2-1];

            int right1 = cut1 == n1 ? INT_MAX : nums1[cut1];
            int right2 = cut2 == n2 ? INT_MAX : nums2[cut2];

            if(left1 <= right2 && left2 <= right1){
                if( (n1+n2) % 2 == 0)
                    return (max(left1, left2) + min(right1,right2)/2.0);
                else    
                    return max(left1, left2);
            } else if(left1 > right2) {
                high = cut1 - 1 ;    
            } else {
                low = cut1 + 1;
            }
        }
        return 0.0;
    }
    /* 65. Kth element of two sorted array - GFG - binary search
        - brute force - two pointers pointing to two arrays - O(K) - space - O(1)
        - divide n concure - O(logN+logM) - O(logN)
        - binary search - O(log(min(M,N))) - O(1)  
    */
    int kthElement(int arr1[], int arr2[], int n, int m, int k){
        if(n > m)
            //binary search on smaller search space
            return kthElement(arr2, arr1, m, n, k);
        
        int low = max(0,k-m), high = min(k,n);

        while(low <= high){
            int cut1 = (low+high) >> 1;
            int cut2 = k - cut1;

            int l1 = cut1 == 0 ? INT_MIN : arr1[cut1 - 1];
            int l2 = cut2 == 0 ? INT_MIN : arr2[cut2 - 1];
            int r1 = cut1 == n ? INT_MAX : arr1[cut1];
            int r2 = cut2 == m ? INT_MAX : arr2[cut2];

            if(l1 <= r2 && l2 <= r1){
                return max(l1, l2);
            } else if(l1 > r2){
                high = cut1 - 1;
            } else {
                low = cut1 + 1;
            }
        }
        return 1;
    }
    
   /* leetcode. 4. Median of two sorted arrays
	Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).
		*/
   double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        
        if(len1 > len2){
            return findMedianSortedArrays(nums2,nums1);
        }
        int low = 0;int high=len1;
        int combinedlen = len1+len2;
        
        while(low <= high){
            int partition1 = low + (high-low)/2;
            int left1 = (partition1==0?INT_MIN:nums1[partition1-1]);
            int right1 = (partition1==len1?INT_MAX:nums1[partition1]);
            
            int partition2 = (combinedlen+1)/2 - partition1;
            int left2 = (partition2==0?INT_MIN:nums2[partition2-1]);
            int right2 = (partition2==len2?INT_MAX:nums2[partition2]);
            
            if(left1 <= right2 && right1 >= left2){
                if(combinedlen%2==0){
                    return (max(left1,left2)+min(right1,right2))/2.0;
                }
                return max(left1,left2);
            }
            if(left1 > right2){
                high = partition1-1;
            }else{
                low = partition1+1;
            }
        }
        return -1;
    }

	
    /* 66. Power set - Print all subsequences 
        https://takeuforward.org/data-structure/power-set-print-all-the-possible-subsequences-of-the-string/
        - O(2 to the powe n * n)
    */
    vector<string> AllPossibleStrings(string s) {
	    int n = s.length();
	    vector<string>ans;
	    for (int num = 0; num < (1 << n); num++) {
		    string sub = "";
		    for (int i = 0; i < n; i++) {
			    //check if the ith bit is set or not
			    if (num & (1 << i)) {
				    sub += s[i];
			    }
		    }
		    if (sub.length() > 0) {
			    ans.push_back(sub);
		    }
	    }
	    sort(ans.begin(), ans.end());
	    return ans;
    }

    /* 68. Allocate minimum number of pages  - recursion/dp - binary search
        - A book will be allocated to one student 
        - Each student must get a minimum of 1 book
        - Allotment should be in contiguous order
        - Maximum number of pages allocated is minimum 
        - logn*O(n)
    */
    int isPossible(vector<int>&A, int pages, int students){
        // check allocation of books among given students is possible
        int cnt = 0;
        int sumAllocated = 0;
        for(int i=0; i<A.size(); i++){
            if(sumAllocated + A[i] > pages){
                cnt++;
                sumAllocated = A[i];
                if(sumAllocated > pages)
                    return false;
            } else {
                sumAllocated += A[i];
            }
        }
        if( cnt < students)
            return true;
        return false;
    }
    int allocateMinPages(vector<int>& A, int B){
        if(B > A.size())
            return -1;
        int low = A[0];
        int high = 0;
        //minimize the search space 
        for(int i=0; i<A.size(); i++){
            high = high + A[i];
            low = min(A[i],low);
        }
        //binary search
        while(low <= high){
            int mid = (low + high) >> 1;
            if(isPossible(A, mid, B)){
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }

    /* 69. Aggressive cows (SPOJ)
        - place the cows in such a way that the minimum distance between cows will be largest
        - longest minimum distance between cows - 
    */
    bool isPossibleCows(vector<int>& A, int n, int cows, int mind){
        int cntCows = 1;
        int lastPlacedCow = A[0];
        for(int i=1; i<n; i++){
            if(A[i] - lastPlacedCow >= mind){
                cntCows++;
                lastPlacedCow = A[i];
            }
        }
        if(cntCows >= cows)
            return true;
        return false;
    }
    int aggressiveCows(vector<int>& A, int cows){
        int n = A.size();
        sort(A.begin(), A.end());
        int low = 1;
        int high = A[n-1] - A[0];
        while(low <= high){
            int mid = (low + high) >> 1;
            if(isPossibleCows(A, n, cows, mid)){
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return high;
    }

    /* 73. Valid parenthesis - three type of brackets [{()}]
        - O(n) - space O(n) for stack
    */
    bool isValidParenthesis(vector<char>& A){
        stack<char> s;
        for(char ch: A){
            if(ch == '(' || ch == '[' || ch == '{'){
                s.push(ch);
            } else {
                if(s.empty())
                    return false;
                if((s.top()=='(' && ch==')')||
                    (s.top()=='[' && ch==']') ||
                    (s.top()=='{' && ch=='}')){
                        s.pop();
                } else {
                    return false;
                }
            }
            if(!s.empty())
                return false;
            return true;
        }
    }

    /* 74. Next Greater element

    */
    vector<int> nextGreaterElement(vector<int> arr){
        int n = arr.size();
        vector<int> ans(n,-1);
        stack<int> s;
        if(n <= 1)
            return ans;

        s.push(0);
        for(int i=1; i < n; i++){
            while(!s.empty() && (arr[i] > arr[s.top()])){
                ans[s.top()] = arr[i];
                s.pop();
            }
            s.push(i);
        }
        return ans;
    }

    /* variation of above question if it is a circular array - that means for last search from beginning */
    vector<int> nextGreaterElements(vector<int>& nums){
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> st;
        for(int i=2*n-1; i>=0; i++){
            while(!st.empty() && st.top() <= nums[i%n]){
                st.pop();
            }
            if(i < n){
                if(!st.empty()){
                    ans[i] = st.top();
                }
            }
            st.push(nums[i%n]);
        }
        return ans;
    }

    //helper functions.
    /* create a linked list */
    ListNode * createAlist(vector<int> nums){
        ListNode *head = new ListNode(nums[0]);
        int len = nums.size();
        ListNode *node = head;
        for(int i=1; i<len; i++){
            node->next = new ListNode(nums[i]);
            node=node->next;
        }
        return head;
    }

    /* display linked list */
    void displayList(ListNode *head){
        if(head==nullptr){
            cout<<"No elements in the list"<<endl;
            return;
        }
        while(head){
            cout<<head->val<<"->";
            head=head->next;
        }
        cout<<"null";
        cout<<endl;
    }

    /* display random list */
    void displayRandomList(ListNode2 *head){
        ListNode2* iter = head;
        while(iter != NULL){
            cout<<iter->val<<"R(";
            if(iter->random!=NULL)
                cout<<iter->random->val<<")"<<"->";
            else
                cout<<"null)->";
            iter = iter->next;
        }
        cout<<"null"<<endl;
    }

    void displayArr(vector<int> arr){
        cout<<"{";
        for(int i=0; i<arr.size(); i++){
            cout<<arr[i]<<" ";
        }
        cout<<"}";
        cout<<endl;
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
    vector<int> input19({2,2,2,2,5,6,1,1,1,1,1});
    vector<int> res19;
    res19 = ob.majority_element1(input19);
    cout<<"Majority element: ";
    for(int i=0; i<res19.size(); i++){
        cout<<res19[i]<<" ";
    }
    cout<<endl;

    //20. Four SUM
    vector<int> input20({4,3,3,4,4,2,1,2,1,1});
    vector<vector<int>> res20;
    res20 = ob.fourSum(input20,7);
    cout<<"Four SUM"<<endl;
    for(int i=0; i<res20.size(); i++){
        for(int j=0; j<res20[0].size(); j++){
            cout<<res20[i][j]<<" ";
        }
        cout<<endl;
    }

    //21. Largest subarray with SUM zero
    vector<int> array21({1,-1,3,2,-2,-8,1,7,10,23});
    cout<<"Largest sub-array sum zero length: "<<ob.LargestSubArraySum0(array21)<<endl;

    //22. Longest consecutive sequence
    vector<int> array22({102,4,100,1,101,3,2});
    cout<<"Longest sequence length: "<<ob.longestConsecutive(array22)<<endl;
   
    //23. Count the number of subarrays having a given XOR as K
    vector<int> array23({4,2,2,6,4});
    int var23 = 6;
    cout<<"Number of subarray with XOR as "<<var23<<" is: ";
    cout<<ob.countSubarrayXOR(array23,var23)<<endl;

    //24. Longest substring withour repeating characters
    string str24="abcaabcdba";
    cout<<"Length of longest substring: "<<ob.lengthOfLongestSubstring(str24)<<endl;
   
    // 25. Reverse the linked list
    vector<int> arr25({1,2,3,4,5,6});
    ListNode *head = ob.createAlist(arr25);
    ob.displayList(head);
    head = ob.reverseList(head);
    cout<<"Reversed linked list: "<<endl;
    ob.displayList(head);

    // 26. Find the middle of the list
    ListNode * node = ob.listMiddleNode(head);
    cout<<"Middle node of the list: "<<node->val<<endl;

    // 27. Merge of the two sorted list
    vector<int> arr27({7,8,9});
    ListNode *head1 = ob.createAlist(arr25);
    ListNode *head2 = ob.createAlist(arr27);
    head = ob.mergeTwoSortedList(head1,head2);
    ob.displayList(head);

    // 28. Remove nth node
    head = ob.removeNthNode(head, 1);
    cout<<"After removing nth node: "<<endl;
    ob.displayList(head);

    // 29. Delete this node
    ListNode* del29 = head->next->next;
    cout<<"After deleting this "<<del29->val<<" node:"<<endl;
    ob.deleteThisNode(del29);
    ob.displayList(head);

    // 30. Add two numbers given in linked list
    vector<int> arr301({2,4,3});
    ListNode *node1 = ob.createAlist(arr301);
    vector<int> arr302({5,6,7,9});
    ListNode *node2 = ob.createAlist(arr302);
    /*
    ListNode* node1 = new ListNode(2);
    node1->next = new ListNode(4);
    node1->next->next = new ListNode(3);
    ListNode* node2 = new ListNode(5);
    node2->next = new ListNode(6);
    node2->next->next = new ListNode(7);
    node2->next->next->next = new ListNode(9); 
    */
    ob.displayList(node1);
    ob.displayList(node2);
    cout<<"After Adding this two numbers:"<<endl;
    ListNode * node3 = ob.addTwoNumbersList(node1,node2);
    ob.displayList(node3);

    // 31. Intersection node of two linkedlist
    node1 = new ListNode(1);
    node2 = new ListNode(11);
    node1->next = new ListNode(2);
    node2->next = node1->next;
    node2->next->next = new ListNode(3);
    node3 = ob.getIntersectionNode(node1, node2);
    cout<<"Intersection node "<<node3->val<<endl;

    // 32. detect a cycle in a linkedlist
    node1 = new ListNode(1);
    node1->next = new ListNode(2);
    node1->next->next = new ListNode(3);
    node1->next->next->next = node1->next;
    cout<<"Is cycle "<<ob.isCycle(node1)<<endl;

    //33. Reverse a linkedlist in groups of size K
    vector<int> arr33({1,2,3,4,5});
    node1 = ob.createAlist(arr33);
    ob.displayList(node1);
    /*
    node1 = new ListNode(1);
    node1->next = new ListNode(2);
    node1->next->next = new ListNode(3);
    node1->next->next->next = new ListNode(4);
    node1->next->next->next->next = new ListNode(5); */
    cout<<"Reverse K groups "<<endl;
    head = ob.reverseKGroup(node1,3);
    ob.displayList(head);

    //34. is palindrom
    vector<int> arr34({1,2,3,2,1});
    node1 = ob.createAlist(arr34);
    ob.displayList(node1);
    /*
    node1 = new ListNode(1);
    node1->next = new ListNode(2);
    node1->next->next = new ListNode(3);
    node1->next->next->next = new ListNode(2);
    node1->next->next->next->next = new ListNode(1);
    */
    cout<<"Is Palindrom "<<ob.isPalindrom(node1)<<endl;

    //35. find the starting point
    node1 = new ListNode(1);
    node1->next = new ListNode(2);
    node1->next->next = new ListNode(3);
    node1->next->next->next = node1->next;
    cout<<"Cycle starting point "<<ob.detectCycle(node1)->val<<endl;
   
    // 36. Flattening a ll
    ListNode1* node36 = new ListNode1(1);
    node36->bottom = new ListNode1(18);
    node36->next = new ListNode1(5);
    node36->next->bottom = new ListNode1(12);
    ListNode1* res36 = ob.flatten(node36);
    cout<<"Flatten a list with two pointers"<<endl;
    while(res36!=NULL){
        cout<<res36->val<<" "; 
        res36 = res36->bottom;
    }
    cout<<endl;

    // 37. Rotate a ll
    vector<int> arr37({1,2,3,4});
    node1 = ob.createAlist(arr37);
    ob.displayList(node1);
    node1 = ob.rotateRight(node1, 2);
    cout<<"Rotate list 2 times: ";
    ob.displayList(node1);

    // 38. random ll copy
    ListNode2 * node38 = new ListNode2(1);
    node38->next = new ListNode2(2);
    node38->next->next = new ListNode2(3);
    node38->next->next->next = new ListNode2(4);
    node38->random = node38->next->next->next;
    node38->next->random = node38;
    node38->next->next->random = NULL;
    node38->next->next->next->random = node38->next;   
    ob.displayRandomList(node38);
    cout<<"Copy random list:";
    ListNode2* copy = ob.copyRandomList(node38);
    ob.displayRandomList(copy);

    // 39. 3SUM
    vector<int> arr39({-1,0,1,2,-1,-1});
    vector<vector<int>> res39 = ob.threeSum(arr39);
    cout<<"Three SUM"<<endl;
    for(auto a: res39){
        ob.displayArr(a);
    }

    //40. Trapping rainwater

    return 0;
}
