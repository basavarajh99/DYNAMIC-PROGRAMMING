//Recursion TC: >>>O(2^n) and SC: O(T) cuz we are stranded at the same index
int f(int ind, int W, vector<int>& val, vector<int>& wt) //top-down
{
  if(ind == 0)
   return ((int)(W/wt[0) * val[0]); //total wt that i can take is maxwt/wt at 0th index and value of that quantity will be maxwt/wt * val
  
  
  int notTake = 0 + f(ind-1, W, val, wt);
  int take = 0;
  if(wt[ind] <= W) take = val[ind]+(ind, W-wt[ind], val, wt);
  
  return min(notTake, take);
}

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
//memoization TC: O(N*T) SC: O(N*T)+O(T)
dp[N][W+1]={-1};
int f(int ind, int W, vector<int>& val, vector<int>& wt) //top-down
{
  if(ind == 0)
   return ((int)(W/wt[0) * val[0]); //total wt that i can take is maxwt/wt at 0th index and value of that quantity will be maxwt/wt * val
  
  if(dp[ind][W]!=-1) return dp[ind][W];
  
  int notTake = 0 + f(ind-1, W, val, wt);
  int take = 0;
  if(wt[ind] <= W) take = val[ind]+(ind, W-wt[ind], val, wt);
  
  return dp[ind][W]=min(notTake, take);
}
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Tabulation TC: O(N*T) SC: O(N*T)
dp[N][maxW+1]={0};
int f(int n, int maxW, vector<int>& val, vector<int>& wt) //top-down
{
//   if(ind == 0)
//   {
//     if(T % coins[0] == 0) return T/coins[0];
//     return 1e9;
//   }
  
  for(int W = 0; W <= maxW; W++)
  {
     if(ind == 0)
      dp[0][W] = ((int)(W/wt[0) * val[0]); //total wt that i can take is maxwt/wt at 0th index and value of that quantity will be maxwt/wt * val
  }
  
  for(int ind = 1; ind < n; ind++)
  {
    for(int W = 0; W <= maxW; W++)
    {
       int notTake = 0 + dp[ind-1][W];
       int take = 0;
       if(wt[ind] <= W) take = val[ind]+dp[ind][W-wt[ind]];
       dp[ind][W]=min(notTake, take);
    }
  }
  
  return dp[n-1][W];
}
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Space OPtimization TC: O(N*T) SC: O(T)

int f(int n, int maxW, vector<int>& val, vector<int>& wt) //top-down
{
  vector<int>prev(maxW+1, 0), cur(maxW+1, 0);
//   if(ind == 0)
//   {
//     if(T % coins[0] == 0) return T/coins[0];
//     return 1e9;
//   }
  
  for(int W = 0; W <= maxW; W++)
  {
     if(ind == 0)
      prev[W] = ((int)(W/wt[0) * val[0]); //total wt that i can take is maxwt/wt at 0th index and value of that quantity will be maxwt/wt * val
  }
  
  for(int ind = 1; ind < n; ind++)
  {
    for(int W = maxW; W >= 0; W--)
    {
       int notTake = 0 + prev[W];
       int take = 0;
       if(wt[ind] <= W) take = val[ind]+cur[W-wt[ind]];
       cur[W]=min(notTake, take);
    }
    prev=cur;
  }
  
  return prev[W];
}
----------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Further Space Optimization with single row
  
//calling function
int knapsack(int n, int maxW, vector<int>& val, vector<int>& wt)
{
  vector<int> prev(maxW+1, 0);
//   if(ind == 0)
//   {
//     if(wt[0] <= W) return val[0];
//     return 0;
//   }
 for(int W = 0; W <= maxW; W++)
  {
     if(ind == 0)
      prev[W] = ((int)(W/wt[0) * val[0]); //total wt that i can take is maxwt/wt at 0th index and value of that quantity will be maxwt/wt * val
  }
  
  for(int ind = 1; ind < n; ind++)
  {
    for(int W = 0; W <= maxW; W++)
    {
        int notTake = 0+prev[W];
        int take = 0;
        if(wt[ind] <= W)
          take = val[ind] + prev[W-wt[ind]];
        prev[W]=max(take, notTake);    
    }
  }
  
  return prev[maxW];
}                          
                            
                            
