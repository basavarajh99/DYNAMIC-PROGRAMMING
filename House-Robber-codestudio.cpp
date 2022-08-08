//similar to max sum of non adjecent, except we can't take first and last elements
f(arr)
{
  //if(ind==0) return arr[0];
  //dp[0] = arr[0];
  int prev = arr[0];
  //if(ind<0) return 0;
  //int neg = 0;
  //if(dp[ind]!=-1) return dp[ind];
  int prev2 = 0;
  for(int i=1; i<n; i++)
  {
    //pick = arr[ind]+f(ind-2, arr, dp);
    pick = arr[i]; if(i>1) take+=prev2;
    nopick = 0+prev1;
    //return dp[ind]=max(pick, nopick);
    int cur = max(pick, nopick);
    prev2 = prev;
    prev = cur;
  }
  //return dp[ind]=max(pick, nopick);
  //return dp[n];
  return prev;
}

int rob(vector<int>& val)
{
  int n = val.size();
  if(n==1) return val[0]; 
  vector<int> temp1, temp2;
  
  for(int i=0; i<n; i++)
  {
    if(i!=0) temp1.push_back(val[i]);// excluding first elem
    if(i!=n-1) temp2.push_back(val[i]);// excluding last elem
  }
  
  return max(f(temp1), f(temp2));
}
