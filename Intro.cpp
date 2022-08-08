//Tabulation: Bottom-up
//Memoization: Top-bottom
//overlapping subproblems are not recomputed (unlike recursion) again if already computed.

//fibonacci

int fib(int n, vector<int>& dp)
{
  if(n<=1) return n;
  
  if(dp[n]!=-1) return dp[n];
  
  return dp[n] = fib(n-1, dp)+fib(n-2, dp);
}
