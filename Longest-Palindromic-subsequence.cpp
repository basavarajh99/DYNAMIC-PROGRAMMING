//just write string in reverse order and take LCS pf those two, it will be LPS
//recursion

int f(int i, int j, string& s, string& t)
{
   if(i<0 or j<0) return 0;
   
  if(s[i] == s[j]) 1+f(i-1, j-1, s, t); //match
  
  return 0+max(f(i-1, j, s, t), f(i, j-1, s, t)); //not-match
}

//calling function
int lps(string s)
{
  sting t = reverse(s);
  int n = s.size(), m = t.size();
  
  return f(n-1, m-1, s, t);
}

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
//memoization 
int f(int i, int j, string& s, string& t, vector<vector<int>>& dp)
{
   if(i<0 or j<0) return 0;
   if(dp[i][j]!=-1) return dp[i][j];
  
  if(s[i] == s[j]) dp[i][j] = 1+f(i-1, j-1, s, t, dp); //match
  
  return dp[i][j] = 0+max(f(i-1, j, s, t), f(i, j-1, s, t, dp)); //not-match
}

//calling function
int lps(string s)
{
   sting t = reverse(s);
  int n = s.size(), m = t.size();
  vector<vector<int>> dp(n, vector<int>(m, -1)); 
  return f(n-1, m-1, s, t, dp);
}

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Tabulation right shift of index, since base case is negative i.e. every i-1 is i and j-1 is j
//calling function
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
                       
   return dp[n][m];
}
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
//space optimization
//calling function
int lps(string s)
{
   sting t = reverse(s);
  int n = s.size(), m = t.size();
  vector<int> prev(m+1, 0), cur(m+1, 0); 
  
 //for(int i=0; i<=n; i++) dp[i][0] = 0;
  for(int j=0; j<=m; j++) prev[j] = 0;
  
  for(int i=1; i<=n; i++)
  {
    for(int j=1; j<=m; j++)
    {
      if(s[i-1] == t[j-1]) cur[j] = 1+prev[j-1]; //match
      else cur[j] = 0+max(prev[j], cur[j-1]; // not match
    }
    prev = cur;
  }
                       
   return prev[m];
}
