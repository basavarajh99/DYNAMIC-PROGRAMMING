//Tabulation right shift of index, since base case is negative i.e. every i-1 is i and j-1 is j
//calling function
int lcs(string s, sting t)
{
  int n = s.size(), m = t.size();
  vector<vector<int>> dp(n+1, vector<int>(m+1, 0)); 
  
  for(int i=0; i<=n; i++) dp[i][0] = 0;
  for(int j=0; j<=m; j++) dp[0][j] = 0;
  
  int ans = 0;
  for(int i=1; i<=n; i++)
  {
    for(int j=1; j<=m; j++)
    {
      if(s[i-1] == t[j-1])
      {
        dp[i][j] = 1+dp[i-1][j-1]; //match
        ans = max(ans, dp[i][j]);
      }
      else dp[i][j] = 0; // max(dp[i-1][j], dp[i][j-1]; // not match then put 0, since it should be consecative, cuz its substring
    }
  }
                       
   return ans;
}

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
//space optimization
//calling function
int lcs(string s, sting t)
{
  int n = s.size(), m = t.size();
  vector<int> prev(m+1, 0), cur(m+1, 0); 
  
 //for(int i=0; i<=n; i++) dp[i][0] = 0;
  for(int j=0; j<=m; j++) prev[j] = 0;
  
   int ans = 0;
  for(int i=1; i<=n; i++)
  {
    for(int j=1; j<=m; j++)
    {
      if(s[i-1] == t[j-1])
      {
        cur[j] = 1+prev[j-1]; //match
        ans = max(ans, cur[j]);
      }
      else cur[j] = 0; // max(dp[i-1][j], dp[i][j-1]; // not match then put 0, since it should be consecative, cuz its substring
    }
    prev = cur;
  }
                       
   return ans;
}
