//Bitonic: first increase and then decrease or just increase or just decrease
//similar to LIS, just find LIS from begining and from end, then bitonic[] = begin+end-1 //cuz common element is removed 
//dp[i] = the LIS that ends at index i
vector<int> LIS(int arr[], int n)
{
  vector<int> dp1(n, 1); //from left view
  
  for(int ind = 0; ind < n; ind++)
  {
    for(int prev = 0; prev < ind; prev++)
    {
      if(compare(arr[ind], arr[prev]) and 1+dp1[prev] > dp1[ind])
        dp1[ind] = 1+dp1[prev];
    }
  }
  
  vector<int> dp2(n, 1); //from right view
  int maxi = 0;
  for(int ind = n-1; ind >= 0 ; ind--)
  {
    for(int prev = n-1; prev > ind; prev--)
    {
      if(compare(arr[ind], arr[prev]) and 1+dp2[prev] > dp2[ind])
        dp2[ind] = 1+dp2[prev];
    }
    maxi = max(maxi, dp1[i]+dp2[i]-1);
  }    
  
  return maxi;
}
