//ind = 0 means rod length = 1, therefore basecase if ind=0 then n*val[0];
//Recursion TC: >>>O(2^n) and SC: O(T) cuz we are stranded at the same index
int f(int ind, int len, vector<int>& val) //top-down
{
  if(ind == 0)
   return (len * val[0]); //total wt that i can take is maxwt/wt at 0th index and value of that quantity will be maxwt/wt * val
  
  
  int notTake = 0 + f(ind-1, len, val);
  int take = INT_MIN, rodlen = ind+1;
  if(rodlen <= len) take = val[ind]+(ind, len-val[ind], val);
  
  return max(notTake, take);
}

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
//memoization TC: O(N*T) SC: O(N*T)+O(T)
dp[len][len+1]={-1};
int f(int ind, int len, vector<int>& val) //top-down
{
   if(ind == 0)
   return (len * val[0]); //total wt that i can take is maxwt/wt at 0th index and value of that quantity will be maxwt/wt * val
  
  if(dp[ind][len]!=-1) return dp[ind][len];
  
  int notTake = 0 + f(ind-1, len, val);
  int take = INT_MIN, rodlen = ind+1;
  if(rodlen <= len) take = val[ind]+(ind, len-rodlen, val);
  
  return dp[ind][len]=max(notTake, take);
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Tabulation TC: O(N*T) SC: O(N*T)
dp[len][len+1]={0};
int f(int maxlen, vector<int>& val) //top-down
{
//   if(ind == 0)
//   {
//     if(T % coins[0] == 0) return T/coins[0];
//     return 1e9;
//   }
  
  for(int len = 0; len <= maxlen; len++)
  {
     dp[0][len] = len * val[0]; //total wt that i can take is maxwt/wt at 0th index and value of that quantity will be maxwt/wt * val
  }
  
  for(int ind = 1; ind < n; ind++)
  {
    for(int len = 0; len <= maxlen; len++)
    {
        int notTake = 0 + dp[ind-1][len];
        int take = INT_MIN, rodlen = ind+1;
        if(rodlen <= maxlen) take = val[ind]+dp[ind][maxlen-rodlen];
        dp[ind][len]=max(notTake, take);
    }
  }
  
  return dp[n-1][maxlen];
}
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Space OPtimization TC: O(N*T) SC: O(T)

int f(int maxlen, vector<int>& val) //top-down
{
  vector<int>prev(maxlen+1, 0), cur(maxlen+1, 0);
//   if(ind == 0)
//   {
//     if(T % coins[0] == 0) return T/coins[0];
//     return 1e9;
//   }
  
  for(int len = 0; len <= maxlen; len++)
  {
     prev[len] = len * val[0]; //total wt that i can take is maxwt/wt at 0th index and value of that quantity will be maxwt/wt * val
  }
  
  for(int ind = 1; ind < n; ind++)
  {
    for(int len = 0; len <= maxlen; len++)
    {
        int notTake = 0 + prev[len];
        int take = INT_MIN, rodlen = ind+1;
        if(rodlen <= maxlen) take = val[ind]+cur[maxlen-rodlen];
        cur[len]=max(notTake, take);
    }
    prev = cur
  }
  
  return prev[maxlen];
}
----------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Further Space Optimization with single row
  
//calling function
int f(int maxlen, vector<int>& val)
{
  vector<int> prev(maxlen+1, 0);
//   if(ind == 0)
//   {
//     if(wt[0] <= W) return val[0];
//     return 0;
//   }
 for(int len = 0; len <= maxlen; len++)
  {
     prev[len] = len * val[0]; //total wt that i can take is maxwt/wt at 0th index and value of that quantity will be maxwt/wt * val
  }
  
  for(int ind = 1; ind < n; ind++)
  {
    for(int len = 0; len <= maxlen; len++)
    {
        int notTake = 0 + prev[len];
        int take = INT_MIN, rodlen = ind+1;
        if(rodlen <= maxlen) take = val[ind]+prev[maxlen-rodlen];
        prev[len]=max(notTake, take);
    }
  }
  
  return prev[maxlen];
}                          
       
