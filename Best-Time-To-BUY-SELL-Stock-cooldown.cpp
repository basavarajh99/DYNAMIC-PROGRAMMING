//can't buy right after sell
// just increment by 2, cuz consecative is not allowed and this ristriction is only for sell, not for buy

//recursion
long f(int ind, int buy, long *val, int n)
{
  if(ind >= n) return 0; //if all the days are exhausted and even if u  are holding stock then ur profit will be -ve since u have'nt sold it
  
  long profit = 0;
  if(buy)
    profit = max(-val[ind] + f(ind+1, 0, val, n), 0 + f(ind+1, 1, val, n));
    // -val[ind] + f(ind+1, 0, val, n) = you decide to buy that stock, so buy = 0 for next day
    // 0 + f(ind+1, 1, val, n) = you didn't buy that stock, so buy = 1
  else
    profit = max(val[ind] + f(ind+2, 1, val, n), 0 + f(ind+1, 0, val, n)); //changed
  
  return profit;
}

//calling function
long maxprofit(long *val, int n)
{
  return f(0, 1, val, n);
}

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
//memoization
long f(int ind, int buy, long *val, int n, vector<vector<int>>& dp)
{
  if(ind >= n) return 0; //if all the days are exhausted and even if u  are holding stock then ur profit will be -ve since u have'nt sold it
  
  if(dp[ind][buy] != -1) return dp[ind][buy];
  
  long profit = 0;
  if(buy)
    profit = max(-val[ind] + f(ind+1, 0, val, n, dp), 0 + f(ind+1, 1, val, n, dp));
    // -val[ind] + f(ind+1, 0, val, n) = you decide to buy that stock, so buy = 0 for next day
    // 0 + f(ind+1, 1, val, n) = you didn't buy that stock, so buy = 1
  else
    profit = max(val[ind] + f(ind+2, 1, val, n, dp), 0 + f(ind+1, 0, val, n, dp));
  
  return dp[ind][buy] = profit;
}

//calling function
long maxprofit(long *val, int n)
{
  vector<vector<int>> dp(n, vector<int>(2, -1));
  return f(0, 1, val, n, dp);
}

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Tabulation
long maxprofit(long *val, int n)
{
  vector<vector<int>> dp(n+, vector<int>(2, 0));
  //if(ind == n) return 0; //if all the days are exhausted and even if u  are holding stock then ur profit will be -ve since u have'nt sold it
  dp[n][0] = dp[n][1] = 0;
  
  for(int ind = n-1; ind >= 0; ind++)
  {
    for(int buy = 0; buy <= 1; buy++)
    {
      long profit = 0;
      if(buy)
        profit = max(-val[ind] + dp[ind+1][0], 0 + dp[ind+1][1]);
        // -val[ind] + f(ind+1, 0, val, n) = you decide to buy that stock, so buy = 0 for next day
        // 0 + f(ind+1, 1, val, n) = you didn't buy that stock, so buy = 1
      else
        profit = max(val[ind] + dp[ind+2][1], 0 + dp[ind+1][0]);

      dp[ind][buy] = profit;
    }
  }
  
  return dp[0][1];
}

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Tabulation optimized
long maxprofit(long *val, int n)
{
  vector<int> front2(2, 0));
  vector<int> front1(2, 0));
  vector<int> cur(2, 0));
  //if(ind == n) return 0; //if all the days are exhausted and even if u  are holding stock then ur profit will be -ve since u have'nt sold it
  
  for(int ind = n-1; ind >= 0; ind++)
  {
        cur[1] = max(-val[ind] + front1[0], 0 + front1[1]);
        // -val[ind] + f(ind+1, 0, val, n) = you decide to buy that stock, so buy = 0 for next day
        // 0 + f(ind+1, 1, val, n) = you didn't buy that stock, so buy = 1
     
        cur[0] = max(val[ind] + front2[1], 0 + front1[0]);
    
    front2 = front1;
    front1 = cur;
  }
  
  return cur[1];
}
