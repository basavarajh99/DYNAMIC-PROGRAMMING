//recursion
f(ind)
{
  if(ind == 0) return 0;
  
  int left = f(ind-1)+abs(arr[ind]-arr[ind-1]);
  int right = INT_MAX;
  if(ind>1)
  right = f(ind-2)+abs(arr[ind]-arr[ind-2]);
  
  return min(left, right);
}

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//memoization TC: O(N) SC: O(N)+O(N)
  
f(ind, arr, dp)
{
  if(ind == 0) return 0;
  if(dp[n]!=-1) return dp[n];
  int left = f(ind-1, arr, dp)+abs(arr[ind]-arr[ind-1]);
  int right = INT_MAX;
  if(ind>1)
  right = f(ind-2, arr, dp)+abs(arr[ind]-arr[ind-2]);
  
  return dp[n]=min(left, right);
}

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Tabulation TC: O(N) SC: O(N)
f(ind, arr, dp)
{
  //if(ind == 0) return 0;
  dp[0] = 0;
  
  //if(dp[n]!=-1) return dp[n];
  for(int i=1; i<n; i++)
  {
    //int left = f(ind-1, arr, dp)+abs(arr[ind]-arr[ind-1]);
    int fs = dp[i-1]+abs(arr[i]-arr[i-1]);
    //int right = INT_MAX;
    int ss = INT_MAX
    //if(ind>1)
      if(i>1)
    //right = f(ind-2, arr, dp)+abs(arr[ind]-arr[ind-2]);
    int ss = dp[i-2]+abs(arr[i]-arr[i-2]);
    
    //return dp[n]=min(left, right);
    dp[i] = min(fs, ss);
  }  
  
  return dp[n-1];
}  
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
  //space optimized O(1)
f(ind, arr)
{
  //if(ind == 0) return 0;
  //dp[0] = 0;
  int prev = 0, prev2=0;
  //if(dp[n]!=-1) return dp[n];
  for(int i=1; i<n; i++)
  {
    //int left = f(ind-1, arr, dp)+abs(arr[ind]-arr[ind-1]);
    //int fs = dp[i-1]+abs(arr[i]-arr[i-1]);
    int fs = prev + abs(arr[i]-arr[i-1]);
    //int right = INT_MAX;
    int ss = INT_MAX
    //if(ind>1)
      if(i>1)
    //right = f(ind-2, arr, dp)+abs(arr[ind]-arr[ind-2]);
   // int ss = dp[i-2]+abs(arr[i]-arr[i-2]);
    int ss = prev2 + abs(arr[i]-arr[i-2]);
    //return dp[n]=min(left, right);
    //dp[i] = min(fs, ss);
    int cur = min(fs, ss);;
    prev2 = prev;
    prev = cur;
  }  
  
  //return dp[n-1];
  return prev;
}  
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
 //follow up instead of 1 or 2 jumps if it's k jumps
  
f(ind, arr)
{
  if(ind==0) return 0;
  
  min_steps = INT_MAX;
  
  for(j=1; j<=k; j++)
  {
    int jmp = f(ind-j)+abs(arr[ind]-arr[ind-j]);
    min_steps = min(min_steps, jmp);
  }
  
  return min_steps;
}  
