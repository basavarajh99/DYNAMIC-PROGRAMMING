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
