//s1-s2 = d
//s1>s2
//s1 can be written as s1 = totalsum-s2
// therfore s1-s2 = d can be written as totalsum-s2-s2 = d
//therefore s2 = (totalsum-d)/2
//therefore the problem reduced to count subsets having sum as (totalsum-d)/2
//constraints: totalsum-d has to be >= 0 and it should be even

//similar to subset sum k, here target = sum
//recursion from n-1 to 0
int f(ind, target, arr)
{
  if(target==0) return 1; //if there are 0's in the arr then remove this condition and change below condition as follow
  if(ind == 0) return arr[ind]==target; // this should be changed as 
//   if(ind == 0)
//   {
//     if(target == 0 and arr[0] == 0) return 2; //cuz take and not take case both will return same ans and both need to be counted
//     if(sum == 0 or sum == arr[0]) return 1; //single array element case
//     return 0;
//   } change this in memoization, tabulation, space-optimization as well for all the problems related to this
  
  int take = 0;
  if(arr[ind]<=target)
  take = f(ind-1, target-arr[ind], arr);
  
  int not_take = f(ind-1, target, arr);
  
  return take+not_take;
}

//in calling function
int countpartition(int n, int d, vector<int> &arr)
{
  int totalsum = 0;
  for(auto &it : arr) totalsum+=it;
  if(totalsum-d < 0 or (totalsum-d)%2) return false;
  return f(n, (totalsum-d)/2, arr);
}
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Memoization 
dp[n][target+1];
int f(ind, target, arr)
{
  if(target==0) return 1;
  if(ind == 0) return arr[ind]==target;
  if(dp[ind][target]!=-1) return dp[ind][target];
  bool take = 0;
  if(arr[ind]<=target)
  take = f(ind-1, target-arr[ind], arr);
  
  int not_take = f(ind-1, target, arr);
  
  return dp[ind][target] = take + not_take;
}
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Tabulation
dp[n][k+1]
int f(arr, k) //target=k
{
  //if(target==0) return true;
  //for(int i=0; i<n; i++)
    //dp[i][0] = 1; remove this for array elements having 0
  
  if(arr[0] == 0) dp[0][0]=2; //i.e. if ind = 0, sum = 0 and number = 0, then 2 cases pick/notpick
  else dp[0][0]=1; //i.e. if ind = 0, sum = 0 and number != 0, then 1 case notpick
  
  //if(ind == 0) return arr[ind]==target;
   if(arr[0]!=0 and arr[0]<=k) dp[0][arr[0]] = 1;
  
  for(int ind=1; ind<n; ind++)
  {
    for(int target=1; target<=k; target++)
    {
      bool take = 0;
      if(arr[ind]<=target)
      take = dp[ind-1][target-arr[ind]];
      int not_take = dp[ind-1][target];

      dp[ind][target] = take + not_take;
    }
  }
  
  return dp[n-1][k];
}
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
//space optimization
int f(arr, k) //target=k
{
  prev(k+1, 0), cur(k+1, 0);
 
  //if(target==0) return true;
  //for(int i=0; i<n; i++)
    //prev[0] = 1; remove this for array elements having 0
  
  if(arr[0] == 0) prev[0]=2; //i.e. if ind = 0, sum = 0 and number = 0, then 2 cases pick/notpick
  else prev[0]=1; //i.e. if ind = 0, sum = 0 and number != 0, then 1 case notpick
  
  //if(ind == 0) return arr[ind]==target;
   if(arr[0]!=0 and arr[0]<=k) prev[arr[0]] = 1;
  
  for(int ind=1; ind<n; ind++)
  {
    for(int target=1; target<=k; target++)
    {
      bool take = 0;
      if(arr[ind]<=target)
      take = prev[target-arr[ind]];
      int not_take = prev[target];

      cur[target] = take + not_take;
    }
    prev=cur;
  }
  
  return prev[k];
}
