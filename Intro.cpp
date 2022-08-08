//Tabulation: Bottom-up
//Memoization: Top-bottom
//overlapping subproblems are not recomputed (unlike recursion) again if already computed.

//fibonacci
//Memoization TC: O(N) SC: O(N)+O(N)
int fib(int n, vector<int>& dp)
{
  if(n<=1) return n;
  
  if(dp[n]!=-1) return dp[n];
  
  return dp[n] = fib(n-1, dp)+fib(n-2, dp);
}

//Tabulation TC: O(N) SC: O(N) //no recursion stack space

int fib(int n, vector<int>& dp)
{
  // if(n<=1) return n; convert this case as
  dp[0] = 0, dp[1] = 1;  
  //prev     //prev2
  //return dp[n] = fib(n-1, dp)+fib(n-2, dp); convert this case as
  for(int i=2; i<=n; i++)
    dp[i] = dp[i-1] + dp[i-2];
  //cur     //prev    //prev2
  
  //prev2 = prev
  //prev = cur
  
  //SC:O(1)
  
  return dp[n-1];
  //return dp[prev]
}

