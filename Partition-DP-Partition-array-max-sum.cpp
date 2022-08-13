//at max k partitions
//similar to palindrome partition

//memoization TC: O(N*K) SC: O(N) + O(N)
int f(int ind, vector<int>& nums, int k, vector<int>& dp)
{
  if(ind == nums.size()) return 0;
  
  if(dp[ind] != -1) dp[ind];
  
  int maxi = INT_MIN, maxAns = INT_MIN, len = 0;
  
  for(int j = ind; j < min(len+k, nums.size()); j++) //go till k or n whichever is within bound
  {
    len++;
    maxi = max(maxi, nums[j]);
    int sum = len * maxi + f(j+1, nums, k, dp);
    maxAns = max(maxAns, sum);
  }
  
  return dp[ind] = maxAns;
}

// calling function
int maxsum(int k, vector<int>& nums)
{
  int n = nums.size();
  vector<int> dp(n ,-1);
  return f(0, nums, k, dp);
}
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Tabulation TC: O(N*K) SC: O(N) 
int maxsum(int k, vector<int>& nums)
{
  int n = nums.size();
  vector<int> dp(n+1, 0);
  
  for(int ind = n-1; ind >= 0; ind--)
  {
     int maxi = INT_MIN, maxAns = INT_MIN, len = 0;
  
      for(int j = ind; j < min(len+k, nums.size()); j++) //go till k or n whichever is within bound
      {
        len++;
        maxi = max(maxi, nums[j]);
        int sum = len * maxi + dp[j+1];
        maxAns = max(maxAns, sum);
      }

        dp[ind] = maxAns;
  }
  
  return dp[0];
 }
