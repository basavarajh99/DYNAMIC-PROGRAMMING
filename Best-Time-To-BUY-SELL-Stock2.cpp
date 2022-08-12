//for any index, I need to know whether I've bought or sold previously
//If I buy. Then ans is reduced by price on that day since i invested money and it got debted from my account
//if buy = 0, then u can't buy cuz u already bought and haven't sold yet
//if buy = 1, then u can buy cuz u already sold or haven't bought yet

//recursion
long f(int ind, int buy, long *val, int n)
{
  if(ind == n) return 0; //if all the days are exhausted and even if u  are holding stock then ur profit will be -ve since u have'nt sold it
  
  long profit = 0;
  if(buy)
    profit = max(-val[ind] + f(ind+1, 0, val, n), 0 + f(ind+1, 1, val, n));
    // -val[ind] + f(ind+1, 0, val, n) = you decide to buy that stock, so buy = 0 for next day
    // 0 + f(ind+1, 1, val, n) = you didn't buy that stock, so buy = 1
  else
    profit = max(val[ind] + f(ind+1, 1, val, n), 0 + f(ind+1, 0, val, n));
  
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
  if(ind == n) return 0; //if all the days are exhausted and even if u  are holding stock then ur profit will be -ve since u have'nt sold it
  
  if(dp[ind][buy] != -1) return dp[ind][buy];
  
  long profit = 0;
  if(buy)
    profit = max(-val[ind] + f(ind+1, 0, val, n, dp), 0 + f(ind+1, 1, val, n, dp));
    // -val[ind] + f(ind+1, 0, val, n) = you decide to buy that stock, so buy = 0 for next day
    // 0 + f(ind+1, 1, val, n) = you didn't buy that stock, so buy = 1
  else
    profit = max(val[ind] + f(ind+1, 1, val, n, dp), 0 + f(ind+1, 0, val, n, dp));
  
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
  vector<vector<int>> dp(n+1, vector<int>(2, 0));
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
        profit = max(val[ind] + dp[ind+1][1], 0 + dp[ind+1][0]);

      dp[ind][buy] = profit;
    }
  }
  
  return dp[0][1];
}

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Space Optimization
long maxprofit(long *val, int n)
{
  vector<int> ahead(2, 0), cur(2, 0);
  //if(ind == n) return 0; //if all the days are exhausted and even if u  are holding stock then ur profit will be -ve since u have'nt sold it
  ahead[0] = ahead[1] = 0;
  
  for(int ind = n-1; ind >= 0; ind++)
  {
    for(int buy = 0; buy <= 1; buy++)
    {
      long profit = 0;
      if(buy)
        profit = max(-val[ind] + ahead[0], 0 + ahead[1]);
        // -val[ind] + f(ind+1, 0, val, n) = you decide to buy that stock, so buy = 0 for next day
        // 0 + f(ind+1, 1, val, n) = you didn't buy that stock, so buy = 1
      else
        profit = max(val[ind] + ahead[1], 0 + ahead[0]);

      cur[buy] = profit;
    }
    ahead = cur;
  }
  
  return ahead[1];
}
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Space Optimization, same as previous bbut using 4 variablea to remove buy for loop
long maxprofit(long *val, int n)
{
  //vector<int> ahead(2, 0), cur(2, 0);
  long aheadnotbuy, aheadbuy, curnotbuy, curbuy;
  //if(ind == n) return 0; //if all the days are exhausted and even if u  are holding stock then ur profit will be -ve since u have'nt sold it
  //ahead[0] = ahead[1] = 0;
  aheadnotbuy = aheadbuy = 0;
  
  for(int ind = n-1; ind >= 0; ind++)
  {
    //for(int buy = 0; buy <= 1; buy++)
    //{
      long profit = 0;
      //else
        //profit = max(val[ind] + ahead[1], 0 + ahead[0]);
      curnotbuy = max(val[ind] + aheadbuy, 0 + aheadnotbuy);
     
    //if(buy)
        //profit = max(-val[ind] + ahead[0], 0 + ahead[1]);
      curbuy = max(-val[ind] + aheadnotbuy, 0 + aheadbuy);
        // -val[ind] + f(ind+1, 0, val, n) = you decide to buy that stock, so buy = 0 for next day
        // 0 + f(ind+1, 1, val, n) = you didn't buy that stock, so buy = 1
      
    
      //cur[buy] = profit;
    }
    aheadbuy = curbuy;
    aheadnotbuy = curnotbuy;
  }
  
  return aheadbuy;
}
