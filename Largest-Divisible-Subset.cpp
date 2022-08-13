//sort array
//if arr[i] is divisible by arr[i-1] then arr[i] is divisible by all the elements before arr[i-1]
//similar to LIS, just sort array and change arr[prev] < arr[ind] to arr[ind]%arr[prev] == 0
vector<int> LIS(int arr[], int n)
{
  sort(arr, arr+n);
  vector<int> dp(n, 1), hash(n); //hash array tells who is previous one
  int maxi = 1, lastindex = 0;
  
  for(int ind = 0; ind < n; ind++)
  {
    for(int prev = 0; prev < ind; prev++)
    {
      if(arr[ind]%arr[prev] == 0 and 1+dp[prev] > dp[ind])
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
