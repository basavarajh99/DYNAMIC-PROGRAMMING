int maxprofit(vector<int>& val)
{
  int mini = val[0];
  int maxi = 0;
  int n = val.size();
  
  for(int i=1; i<n; i++)
  {
    int cost = val[i] - mini;
    maxi = max(maxi, cost);
    mini = min(mini, val[i]);
  }
  
  return maxi;
}
