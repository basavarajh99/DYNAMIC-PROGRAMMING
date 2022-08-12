//substract fee either at buy or sell
//Space Optimization, same as previous bbut using 4 variablea to remove buy for loop
long maxprofit(long *val, int n, int fee)
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
      curnotbuy = max(val[ind] - fee + aheadbuy, 0 + aheadnotbuy);
     
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
