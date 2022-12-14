/* Steivers Dynamic Programming playlist 
    1. Introduction
    2.
    3. Frog Jump - 1DP
    4. 

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
