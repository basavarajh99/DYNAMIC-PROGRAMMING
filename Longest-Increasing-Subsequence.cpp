//recursion
int f(int ind, int prev_ind, int arr[], int n)
{
  if(ind == n) return 0;
  
  //not take
  int len = 0 + f(ind+1, prev_ind, arr, n);
  
  //take
  if(prev_ind == -1 or arr[ind] > arr[prev_ind])
    len = max(len, 1+f(ind+1, ind, arr, n));
  
  return len;
}

//in calling function
int LIS(int arr[], int n)
{
  return f(0, -1, arr, n);
}

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Memoization
int f(int ind, int prev_ind, int arr[], int n, vector<vector<int>>& dp)
{
  if(ind == n) return 0;
  
  if(dp[ind][prev_ind]!=-1) return dp[ind][prev_ind];
  //not take
  int len = 0 + f(ind+1, prev_ind, arr, n, dp);
  
  //take
  if(prev_ind == -1 or arr[ind] > arr[prev_ind])
    len = max(len, 1+f(ind+1, ind, arr, n, dp));
  
  return dp[ind][prev_ind] = len;
}

//in calling function
int LIS(int arr[], int n)
{
  vector<vector<int>> dp(n, vector<int>(n+1, -1));
  return f(0, -1, arr, n, dp);
}
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Tabulation
int LIS(int arr[], int n)
{
  vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
  
  for(int ind = n-1; ind >= 0; ind--)
  {
    for(int prev_ind = ind-1; prev_ind >= -1; prev_ind--)
    {
       //not take
      int len = 0 + dp[ind+1][prev_ind+1]; //right shife prev_ind

      //take
      if(prev_ind == -1 or arr[ind] > arr[prev_ind])
        len = max(len, 1+dp[ind+1][ind+1]);

       dp[ind][prev_ind+1] = len;
    }
  }
  
  return dp[0][-1+1];
}
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Space Optimization
int LIS(int arr[], int n)
{
  vector<int> next(n+1, 0), cur(n+1, 0);
  
  for(int ind = n-1; ind >= 0; ind--)
  {
    for(int prev_ind = ind-1; prev_ind >= -1; prev_ind--)
    {
       //not take
      int len = 0 + next[prev_ind+1]; //right shife prev_ind

      //take
      if(prev_ind == -1 or arr[ind] > arr[prev_ind])
        len = max(len, 1+next[ind+1]);

       cur[prev_ind+1] = len;
    }
    next = cur;
  }
  
  return next[-1+1];
}
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//dp[i] = the LIS that ends at index i
int LIS(int arr[], int n)
{
  vector<int> dp(n, 1);
  int maxi = 1;
  
  for(int ind = 0; ind < n; ind++)
  {
    for(int prev = 0; prev < ind; prev++)
    {
      if(arr[prev] < arr[ind])
        dp[ind] = max(dp[ind], 1+dp[prev]); 
    }
    maxi = max(maxi, dp[ind]);
  }
 return maxi;
}
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Using Binary Search Lower bound
int LIS(int arr[], int n)
{
  vector<int> v;
  v.push_back(arr[0]);
  
  for(int i=1; i<n; i++)
  {
    if(arr[i] > v.back())
      v.push_back(arr[i]);
    
    else
    {
      int ind = lower_bound(v.begin(), v.end(), arr[i])-v.begin();
      v[ind] = arr[i];
    }
  }
  
 return v.size();
}
