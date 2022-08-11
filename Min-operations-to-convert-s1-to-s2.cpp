//operations delete/add
//deletions = length of s1 - len(LCS)
//insertions = length of s2 - len(LCS)
// total = deletions + insertions

int lcs(string s, sting t)
{
  int n = s.size(), m = t.size();
  vector<vector<int>> dp(n+1, vector<int>(m+1, 0)); 
  
  for(int i=0; i<=n; i++) dp[i][0] = 0;
  for(int j=0; j<=m; j++) dp[0][j] = 0;
  
  for(int i=1; i<=n; i++)
  {
    for(int j=1; j<=m; j++)
    {
      if(s[i-1] == t[j-1])dp[i][j] = 1+dp[i-1][j-1]; //match
      else dp[i][j] = 0+max(dp[i-1][j], dp[i][j-1]; // not match
    }
  }
                       
   return dp[n][m];
}
// calling function
int operations(string& s, string& t)
{
  int n = s.size(), m = t.size();
  int len = lcs(s, t);
  return n+m-2*len;
}
