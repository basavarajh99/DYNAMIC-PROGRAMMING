//tabulation
string lcs(string s, sting t)
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
 int len = dp[n][m]; //length of lcs 
 string ans = "";
 for(int i=0; i<len; i++)
      ans+='$';
   
 int index = len-1; //filling ans from end
  int i = n, j = m;
   while(i>0 and j>0)
    {
      if(s[i-1] == s[j-1]) //move diagonally up 
      {
        ans[index] = s[i-1];
        i--, j--;
      }
      
      else if(dp[i-1][j] > dp[i][j-1]) //move up
        i--;
      else
        j--; // move left
    }       
  return ans;
}
