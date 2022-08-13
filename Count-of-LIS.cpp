vector<int> LIS(vector<int> arr, int n)
{
  vector<int> dp(n, 1), cnt(n, 1); //from left view
  int maxi = 1;
  for(int ind = 0; ind < n; ind++)
  {
    for(int prev = 0; prev < ind; prev++)
    {
      if(arr[prev] < arr[ind] and 1+dp[prev] > dp[ind])
      {
        dp[ind] = 1+dp[prev];
        cnt[ind] = cnt[prev]; //since the length is increasing this is new LIS, so count remains same
      }
      
      else if(arr[prev] < arr[ind] and 1+dp[prev] == dp[ind])
       cnt[ind] += cnt[prev]; //since the length is same for different elements count will increase stating that LIS of same length with different elements can be formed
    }
    maxi = max(maxi, dp[ind]);
  }
  
  int cntlis = 0;
  
  for(int i = 0; i < n; i++)
    if(dp[i] == maxi) cntlis += cnt[i]; //sumup of all the LIS cnt
  
  return cntlis;  
}
