//dp[i] = the LIS that ends at index i
vector<int> LIS(int arr[], int n)
{
  vector<int> dp(n, 1), hash(n); //hash array tells who is previous one
  int maxi = 1, lastindex = 0;
  
  for(int ind = 0; ind < n; ind++)
  {
    for(int prev = 0; prev < ind; prev++)
    {
      if(arr[prev] < arr[ind] and 1+dp[prev] > dp[ind])
        dp[ind] = 1+dp[prev];
        hash[ind] = prev;
    }
    if(dp[ind] > maxi)
    {
      maxi = dp[ind];
      lastindex = ind;
    }
  }
 
  vector<int> v;
  v.push_back(lastindex);
  
  while(hash[lastindex] != lastindex)
  {
    lastindex = hash[lastindex];
    v.push_back(arr[lastindex]);
  }
  
  reverse(v.begin(), v.end());
  
  return v;
}
