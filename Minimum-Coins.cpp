//infinite supply or multiple use, then in take case stay at same index and reduce the target

//Recursion TC: >>>O(2^n) and SC: O(T) cuz we are stranded at the same index
int f(int ind, int T, vector<int>& coins) //top-down
{
  if(ind == 0)
  {
    if(T % coins[0] == 0) return T/coins[0];
    return 1e9;
  }
  
  int notTake = 0 + f(ind-1, T. coins);
  int take = INT_MAX;
  if(coins[ind] <= T) take = 1+(ind, T-coins[ind], coins);
  
  return min(notTake, take);
}

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//memoization TC: O(N*T) SC: O(N*T)+O(T)
dp[N][T+1]={-1};
int f(int ind, int T, vector<int>& coins) //top-down
{
  if(ind == 0)
  {
    if(T % coins[0] == 0) return T/coins[0];
    return 1e9;
  }
  
  if(dp[ind][T]!=-1) return dp[ind][T];
  
  int notTake = 0 + f(ind-1, T. coins);
  int take = INT_MAX;
  if(coins[ind] <= T) take = 1+(ind, T-coins[ind], coins);
  
  return dp[ind][T]=min(notTake, take);
}
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Tabulation TC: O(N*T) SC: O(N*T)
dp[N][T+1]={0};
int f(int n, int target, vector<int>& coins) //top-down
{
//   if(ind == 0)
//   {
//     if(T % coins[0] == 0) return T/coins[0];
//     return 1e9;
//   }
  
  for(int T = 0; T <= target; T++)
  {
    if(T % coins[0] == 0) dp[0][T] = T/coins[0];
    dp[0][T] = 1e9;
  }
  
  for(int ind = 1; ind < n; ind++)
  {
    for(int T = 0; T <= target; T++)
    {
      int notTake = 0 + dp[ind-1][T];
      int take = INT_MAX;
      if(coins[ind] <= T) take = 1+dp[ind][T-coins[ind]];
      dp[ind][T]=min(notTake, take);
    }
  }
  
  return dp[n-1][target];
}
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Space OPtimization TC: O(N*T) SC: O(T)

int f(int n, int target, vector<int>& coins) //top-down
{
  vector<int>prev(target+1, 0), cur(target+1, 0);
//   if(ind == 0)
//   {
//     if(T % coins[0] == 0) return T/coins[0];
//     return 1e9;
//   }
  
  for(int T = 0; T <= target; T++)
  {
    if(T % coins[0] == 0) prev[T] = T/coins[0];
    prev[T] = 1e9;
  }
  
  for(int ind = 1; ind < n; ind++)
  {
    for(int T = 0; T <= target; T++)
    {
      int notTake = 0 + prev[T];
      int take = INT_MAX;
      if(coins[ind] <= T) take = 1+cur[T-coins[ind]];
      cur[T]=min(notTake, take);
    }
    prev=cur;
  }
  
  return prev[target];
}
