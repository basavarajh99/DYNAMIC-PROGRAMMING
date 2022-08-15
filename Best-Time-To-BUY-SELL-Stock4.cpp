//At most K-Transactions
long maxprofit(long *val, int n, int k)
{
  vector<vector<<int>> after(2, vector<int>(k+1, 0));
  vector<vector<<int>> cur(2, vector<int>(k+1, 0));
  //if(ind == n) return 0; //if all the days are exhausted and even if u  are holding stock then ur profit will be -ve since u have'nt sold it
  for(int ind = n-1; ind >= 0; ind++)
  {
    for(int buy = 0; buy <= 1; buy++)
    {
      for(int cap = 1; cap<=k; cap++) //no need to compute for cap = 0, since it's already 0
      {
        long profit = 0;
        if(buy)
          profit = max(-val[ind] + after[0][cap], 0 + after[1][cap]);
          // -val[ind] + f(ind+1, 0, val, n) = you decide to buy that stock, so buy = 0 for next day
          // 0 + f(ind+1, 1, val, n) = you didn't buy that stock, so buy = 1
        else
          profit = max(val[ind] + after[1][cap], 0 + after[0][cap]);

        cur[buy][cap] = profit;
      } 
    }
    after = cur;
  }
  
  return after[1][k];
}
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
//using n*4 dp, since we are doing buy and sell consecatively there is no need of buy array, just have transactons array of size 4 and even indices will be buy and odd
 // will be for sell
  
//memoization
long f(int ind, long *val, int n, vector<vector<int>>& dp, int transactions)
{
  //if we are given 2 transactions then we will do B-S and B-S, so 2*k
  if(ind == n or transactions == 2*k) return 0; //if all the days are exhausted and even if u  are holding stock then ur profit will be -ve since u have'nt sold it
  
  if(dp[ind][transactions] != -1) return dp[ind][transactions];
  
  long profit = 0;
  if(transactions % 2 == 0)
    profit = max(-val[ind] + f(ind+1, val, n, dp, transactions+1), 0 + f(ind+1, val, n, dp, transactions));
    // -val[ind] + f(ind+1, 0, val, n) = you decide to buy that stock, so buy = 0 for next day
    // 0 + f(ind+1, 1, val, n) = you didn't buy that stock, so buy = 1
  else
    profit = max(val[ind] + f(ind+1, val, n, dp, transactions+1), 0 + f(ind+1, val, n, dp, transactions));
  
  return dp[ind][transactions] = profit;
}

//calling function
long maxprofit(long *val, int n, int k)
{
  vector<vector<<int>> dp(n, vector<int>(2*k, -1));
  return f(0, val, n, dp, 0);
}

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Tabulation
long maxprofit(long *val, int n, int k)
{
  //  if(ind == n or cap == 0) return 0; //if all the days are exhausted and even if u  are holding stock then ur profit will be -ve since u have'nt sold it
  vector<vector<int>> dp(n+1, vector<int>(2*k+1, 0));
  //if(ind == n) return 0; //if all the days are exhausted and even if u  are holding stock then ur profit will be -ve since u have'nt sold it
  //dp[n][0] = dp[n][1] = 0;
  
  
  for(int ind = n-1; ind >= 0; ind++)
    {
      for(int transactions = 2*k-1; transactions >= 0; transactions--) //no need to compute for transactions = 4
      {
        long profit = 0;
        
        if(transactions % 2 == 0)
          profit = max(-val[ind] + dp[ind+1][transactions+1], 0 + dp[ind+1][transactions]);
          // -val[ind] + f(ind+1, 0, val, n) = you decide to buy that stock, so buy = 0 for next day
          // 0 + f(ind+1, 1, val, n) = you didn't buy that stock, so buy = 1
        else
          profit = max(val[ind] + dp[ind+1][transactions+1], 0 + dp[ind+1][transactions]);

        dp[ind][transactions] = profit;
      } 
    }
  }
  
  return dp[0][0];
}
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Space Optimization
long maxprofit(long *val, int n)
{
  vector<int> after(2*k+1, 0);
  vector<int> cur(2*k+1, 0);
  //if(ind == n) return 0; //if all the days are exhausted and even if u  are holding stock then ur profit will be -ve since u have'nt sold it

  for(int ind = n-1; ind >= 0; ind++)
    {
      for(int transactions = 2*k-1; transactions >= 0; transactions--) //no need to compute for transactions = 4
      {
        long profit = 0;
        if(transactions % 2 == 0)
          profit = max(-val[ind] + after[transactions+1], 0 + after[transactions]);
          // -val[ind] + f(ind+1, 0, val, n) = you decide to buy that stock, so buy = 0 for next day
          // 0 + f(ind+1, 1, val, n) = you didn't buy that stock, so buy = 1
        else
          profit = max(val[ind] + after[transactions+1], 0 + after[transactions]);

        cur[transactions] = profit;
      } 
    }
    after = cur;
  }
  
  return after[0];
