//how many times s2 occurs in s1
//for not matching u should reduce s1
//for match first take character and reduce and other case can be without taking the character and reducing the s1 and finding occurance of that character in reduced s1

//recursion
int f(int i, int j, string s1, string s2) // i = s1.size()-1, j = s2.size()-1
{
  if(j < 0) return 1; //matched s2 in s1
  if(i < 0) return 0; //s2 characters remaining and s1 exhausted, so all characters did'nt match
  
  if(s[i] == s[j])//match
    return f(i-1, j-1) + f(i-1, j); //f(i-1, j-1) reducing both s1 and s2 by taking character in s1, f(i-1, j) reducing s1 only without taking character in s1
  return f(i-1, j);//not matching
}

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Memoization
dp(n , m);
int f(int i, int j, string s1, string s2) // i = s1.size()-1, j = s2.size()-1
{
  if(j < 0) return 1; //matched s2 in s1
  if(i < 0) return 0; //s2 characters remaining and s1 exhausted, so all characters did'nt match
  
  if(dp[i][j] != -1) return dp[i][j];
  
  if(s[i] == s[j])//match
    return dp[i][j] = f(i-1, j-1) + f(i-1, j); //f(i-1, j-1) reducing both s1 and s2 by taking character in s1, f(i-1, j) reducing s1 only without taking character in s1
  return dp[i][j] = f(i-1, j);//not matching
}

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Tabulation, right shift of index cuz -ve index

int f(int i, int j, string s1, string s2) // i = s1.size()-1, j = s2.size()-1
{
  int n = s1.size(), m = s2.size();
  vector<vector<double>> dp(n+1, vector<double>(m+1,0))
  //if(j < 0) return 1; //matched s2 in s1
  for(int i=0; i<=n; i++)
    dp[i][0] = 1;
  //if(i < 0) return 0; //s2 characters remaining and s1 exhausted, so all characters did'nt match
  for(int j=1; j<=m; j++)
    dp[0][j] = 0;
  
  for(int i = 1; i <= n; i++)
  {
    for(int j = 1; j <= m; j++)
    {
       if(s[i] == s[j])//match
        dp[i][j] = dp[i-1][j-1] + dp[i-1][j]; //f(i-1, j-1) reducing both s1 and s2 by taking character in s1, f(i-1, j) reducing s1 only without taking character in s1
      else dp[i][j] = dp[i-1][j];//not matching
    }
  }
 return (int)dp[n][m];
}

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
//spcae optimization 

int f(int i, int j, string s1, string s2) // i = s1.size()-1, j = s2.size()-1
{
  int n = s1.size(), m = s2.size();
  vector<double>prev(m+1,0), cur(m+1, 0);
  
  //if(j < 0) return 1; //matched s2 in s1
  //for(int i=0; i<=n; i++)
    //dp[i][0] = 1;
  prev[0] = cur[0] = 1;
  
  for(int i = 1; i <= n; i++)
  {
    for(int j = 1; j <= m; j++)
    {
       if(s[i] == s[j])//match
        cur[j] = prev[j-1] + prev[j]; //f(i-1, j-1) reducing both s1 and s2 by taking character in s1, f(i-1, j) reducing s1 only without taking character in s1
      else cur[j] = prev[j];//not matching
    }
    prev = cur;
  }
 return (int)prev[m];
}

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Further spcae optimization 

int f(int i, int j, string s1, string s2) // i = s1.size()-1, j = s2.size()-1
{
  int n = s1.size(), m = s2.size();
  vector<double>prev(m+1,0);
  
  //if(j < 0) return 1; //matched s2 in s1
  //for(int i=0; i<=n; i++)
    //dp[i][0] = 1;
  prev[0] = 1;
  
  for(int i = 1; i <= n; i++)
  {
    for(int j = m; j >= 1; j--)
       if(s[i] == s[j])//match
        prev[j] = prev[j-1] + prev[j]; //f(i-1, j-1) reducing both s1 and s2 by taking character in s1, f(i-1, j) reducing s1 only without taking character in s1
  }
 return (int)prev[m];
}
