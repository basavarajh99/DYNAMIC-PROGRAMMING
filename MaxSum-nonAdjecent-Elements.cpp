//recursion
f(ind, arr)
{
  if(ind==0) return arr[0];
  if(ind<0) return 0;
  
  pick = arr[ind]+f(ind-2, arr);
  nopick = 0+f(ind-1, arr);
  
  return max(pick, nopick);
}

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// memoization
f(ind, arr, dp)
{
  if(ind==0) return arr[0];
  if(ind<0) return 0;
  if(dp[ind]!=-1) return dp[ind];
  pick = arr[ind]+f(ind-2, arr, dp);
  nopick = 0+f(ind-1, arr, dp);
  
  return dp[ind]=max(pick, nopick);
}

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 //tabulation
 f(arr, dp)
{
  //if(ind==0) return arr[0];
  dp[0] = arr[0];
  //if(ind<0) return 0;
  int neg = 0;
  //if(dp[ind]!=-1) return dp[ind];
  for(int i=1; i<n; i++)
  {
    //pick = arr[ind]+f(ind-2, arr, dp);
    pick = arr[i]; if(i>1) take+=dp[i-2];
    nopick = 0+dp[i-1];
    //return dp[ind]=max(pick, nopick);
    dp[i] = max(pick, nopick);
  }
  //return dp[ind]=max(pick, nopick);
  return dp[n];
}
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
  //space optimization
f(arr)
{
  //if(ind==0) return arr[0];
  //dp[0] = arr[0];
  int prev = arr[0];
  //if(ind<0) return 0;
  //int neg = 0;
  //if(dp[ind]!=-1) return dp[ind];
  int prev2 = 0;
  for(int i=1; i<n; i++)
  {
    //pick = arr[ind]+f(ind-2, arr, dp);
    pick = arr[i]; if(i>1) take+=prev2;
    nopick = 0+prev1;
    //return dp[ind]=max(pick, nopick);
    int cur = max(pick, nopick);
    prev2 = prev;
    prev = cur;
  }
  //return dp[ind]=max(pick, nopick);
  //return dp[n];
  return prev;
}
