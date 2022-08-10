//similar to subsetsum-k
//we can derive if every possible target between 1 and target is true/false
//no need to find all the subsets, just check s1 subset and last row of the dp array which tells whether the total sum can be achieved with given array subsets sum 
//combination and s2 is just s1 - dp of last row's every column  and return minimum of them as absolute minimum difference and loop until (total_sum)/2 only as after 
//that the absolute differnece repeats

//tabulation

//Tabulation
dp[n][k+1]
bool f(arr, k) //target=k
{
  int totalsum = 0;
  for(int i=0; i<n; i++) totalsum+=arr[i];
  k=totalsum; //new target
  //if(target==0) return true;
  for(int i=0; i<n; i++)
    dp[i][0] = true;
  //if(ind == 0) return arr[ind]==target;
   if(arr[0]<=k) dp[0][arr[0]] = true;
  
  for(int ind=1; ind<n; ind++)
  {
    for(int target=1; target<=k; target++)
    {
      bool take = false;
      if(arr[ind]<=target)
      take = dp[ind-1][target-arr[ind]];
      int not_take = dp[ind-1][target];

      dp[ind][target] = take | not_take;
    }
  }
  //return dp[n-1][k];
  //now dp[n-1][col=0 to totalsum] will have all the possible answers of the subsets and just get min of them
  int mini = 1e9;
  
  for(int s1=0; s1<totalsum; s1++) 
  {
    if(dp[n-1][s1] == true) //true for only those whose subset sum can be formed with given array elements
      mini = min(mini, abs((totalsum-s1) - s1)); //s1 = s1 and s2 = totalsum-s1
  }
  
  return mini;
}
