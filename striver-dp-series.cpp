/* Steivers Dynamic Programming playlist 
    1. Introduction
    2. Climbing Stairs
    3. Frog Jump
    4. Frog Jump with K distance
    5. Maximum sum of non-adjacent elements
    6. House Robber 2
    7. Ninja's training
    8. Grid Unique Paths
    9. Unique Paths 2
    10. Minimum path sum in grid
    11. Triangle, Fixed starting point and variable ending
    12. Minimum/Maximum falling path sum
    13. Cherry Pickup II / 3D DP
    14. Subset sum equals to target
    15. Partition equals to subset sum
    16. Partition a set into two subset with min abs sum diff
    17. Count subsets with sum K
    18. Count partition with given diff
    19. 0/1 knapsack
    20. Minimum coins
    21. Target Sum
    22. Coin change 2
    23. Unbounded knapsack
    24. Rod cutting problem
    25. Longest common subsequence
    26. Print LCS
    27. Longest common substring
    28. Longest Palindromic subsequence
    29. Minimum insertion to make string palindrom
    30. Minimum insertion/deletion to convert string a to b
    31. Shortest common supersequence
    32. Distinct subsequences
    33. Edit distance
    34. Wild card matching
    35. Best time to buy and sell stocks
    36. Buy and sell stock - II
    37. Buy and sell stock - III
    38. Buy and sell stock - IV
    39. Buy and sell stock with cooldown
    40. Buy and sell stock with transaction fee
    41. Longest increasing subsequence
    42. printing LIS
    43. Longest increasing subsequence - bs
    44. Largest divisible subset
    45. Longest string chain
    46. Longest Bitonic subsequence
    47. Number of longest increasing subsequence
    48. Matrix chain multiplication - partition DP
    49. MCM - bottom up - tabulation
    50. Minimum cost to cut sticks
    51. Burst Balloons
    52. Evaluate boolean expression to true
    53. Palindrome partitioning - II // front parition
    54. Partition array for maximum sum 
    55. Maximum rectange area with all 1's
    56. Count submatrices with all ones - DP on rectanges
*/


/*
1. Introduction

- recurssion
- memoization [top->down] 
- tabulation [bottom->up]

fabonacci series - f(n) = f(n-1) + f(n-2)

- overlapping subproblems
same subprobem is need to be computed multiple times

- memoization 
store the value of subproblems in some table/map to reuse

- tabulation
calculate the values from base value to the result

- Recurssion to DP
  1. DP array [max space needed to store all subproblems], store the base value
  2. while solving, if the subproblem is previously solved (or base case), return value dp value stored 
  3. otherwise solve the subproblem and store it in dp.

recurssion: O(2^n)
int f(int n){
    if(n<=1)
        return n;
    return f(n-1) + f(n-2);
}

memoziation: O(n) + O(n)
int f(int n, vector<int>&dp){
    if(n<=1)
        return n;
    if(dp[n]!=-1)
        return dp[n];
    return dp[n] = f(n-1, dp) + f(n-2, dp);
}

tabulation: O(n) - O(n)
int f(int n){
   int dp[n+1];
   dp[0]=0;
   dp[1]=1;
   for(int i=2; i<=n; i++){
       dp[i] = dp[i-2]+dp[i-1];
   }
   return dp[n];
}
optimize above further: O(n) - O(1)
int f(int n){
   int prev1=0;
   int prev2=1;
   for(int i=2; i<=n; i++){
       int curr = prev1 + prev2;
       prev2 = prev1;
       prev1 = curr; 
   }
   return prev1;
}
*/

/* 3. Frog Jump
Can jump only 1 or 2 steps
Find the minimum steps to reach from 1 to n.
- all possible ways 
- express in terms of index
- do all possible for that index
- take the min of all possible


Recurssion to DP
memoziation - look at the parameters changing
*/

int f(int ind, vector<int>& heights){
    if(n==0) 
        return n;

    int first = f(ind-1,heights,dp) + abs(heights[ind]-heights[ind-1]);
    int second = INT_MAX;
    if(ind>1) 
        second = f(ind-2,heights,dp) + abs(heights[ind]-heights[ind-2]);
    return min(left,right);
}

int f1(int ind, vector<int>& heights, vector<int>&dp){
    if(n==0) 
        return n;
    if(dp[ind]!=-1) 
        return dp[ind];
    int first = f(ind-1,heights,dp) + abs(heights[ind]-heights[ind-1]);
    int second = INT_MAX;
    if(ind>1) 
        second = f(ind-2,heights,dp) + abs(heights[ind]-heights[ind-2])
    return dp[ind] = min(left,right);
}

int frogJump(int n, vector<int>& heights){
    
    //return f(n-1, heights);

    vector<int>dp(n+1,-1);
    //return f1(n-1, heights, dp);

    dp[0] = 0;
    for(int ind=1; i<n; i++){
    	int first = dp[ind-1] + abs(heights[ind]-heights[ind-1]);
    	int second = INT_MAX;
    	if(ind > 1) 
        	second = dp[ind-2] + abs(heights[ind]-heights[ind-2])
        dp[ind] = min(first,second);
    }
    return dp[n-1];
    //can optimize the space further
}


