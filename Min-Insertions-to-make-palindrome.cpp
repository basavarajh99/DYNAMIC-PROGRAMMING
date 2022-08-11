//ma xwill be length of string
//keep the lps intact and add mismatched characters
//i.e Min-Insertions-to-make-palindrome = Length of the string - LPS

int lps(string s)
{
   sting t = reverse(s);
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
                       
   return s.size() - dp[n][m];
}
