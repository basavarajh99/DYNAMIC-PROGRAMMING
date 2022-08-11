//min no. of insert/remove/replace to convert s1 to s2

//Recursion

int f(int i, int j, string s1, string s2)
{
  if(i<0) return j+1; //if s1 exhausted then j+1 characters need to be inserted to convert s1 to s2
  if(j<0) return i+1; //if s2 exhausted then i+1 characters need to be deleted to convert s1 to s2
  
  if(s1[i] == s2[j]) return f(i-1, j-1, s1, s2); //if they match then no operations are performed
  
  return 1+min(f(i-1, j), min(f(i, j-1), f(i-1, j-1))); 
  //f(i-1, j) :- //delete mismatch character from s1, and look for matching character from s2 in shriked s1
  //f(i, j-1) :- insert matching character at end of s1, so i don't change and s2 shrinks                                               
  //f(i-1, j-1) :- replace the mismatch character with matching character and shrink both s1 and s2, and take min of all these three operations and add 1 since we did one of these operations
}

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 //Memoization
dp(n, m)
int f(int i, int j, string s1, string s2)
{
  if(i<0) return j+1; //if s1 exhausted then j+1 characters need to be inserted to convert s1 to s2
  if(j<0) return i+1; //if s2 exhausted then i+1 characters need to be deleted to convert s1 to s2
  
  if(dp[i][j]!=-1) return dp[i][j];
  
  if(s1[i] == s2[j]) return dp[i][j] = f(i-1, j-1, s1, s2); //if they match then no operations are performed
  
  return dp[i][j] = 1+min(f(i-1, j), min(f(i, j-1), f(i-1, j-1))); 
  //f(i-1, j) :- //delete mismatch character from s1, and look for matching character from s2 in shriked s1
  //f(i, j-1) :- insert matching character at end of s1, so i don't change and s2 shrinks                                               
  //f(i-1, j-1) :- replace the mismatch character with matching character and shrink both s1 and s2, and take min of all these three operations and add 1 since we did one of these operations
}
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 //Tabulation, right shift index
dp(n+1, m+1)
int f(int i, int j, string s1, string s2)
{
  int n = s1.size(), m = s2.size();
  //if(i<0) return j+1; //if s1 exhausted then j+1 characters need to be inserted to convert s1 to s2
  for(int i=0; i<=n; i++)
    dp[i][0] = i;
  //if(j<0) return i+1; //if s2 exhausted then i+1 characters need to be deleted to convert s1 to s2
  for(int j=0; j<m; j++)
    dp[0][j] = j;
  
  for(int i=1; i<=n; i++)
  {
    for(int j=1; j<=m; j++)
    {
       if(s1[i] == s2[j]) return dp[i][j] = dp[i-1][j-1]; //if they match then no operations are performed
       else dp[i][j] = 1+min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])); 
      //f(i-1, j) :- //delete mismatch character from s1, and look for matching character from s2 in shriked s1
      //f(i, j-1) :- insert matching character at end of s1, so i don't change and s2 shrinks                                               
      //f(i-1, j-1) :- replace the mismatch character with matching character and shrink both s1 and s2, and take min of all these three operations and add 1 since we did one of these operations
    }
  }
  
  return dp[n][m];
 }
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 //Space Optimization
int f(int i, int j, string s1, string s2)
{
  
  int n = s1.size(), m = s2.size();
  vector<int> prev(m+1, 0), cur(m+1, 0);
  //if(i<0) return j+1; //if s1 exhausted then j+1 characters need to be inserted to convert s1 to s2
  //for(int i=0; i<=n; i++)
    //dp[i][0] = i; //this means for first col, its that index number 
  //if(j<0) return i+1; //if s2 exhausted then i+1 characters need to be deleted to convert s1 to s2
  for(int j=0; j<m; j++)
    prev[j] = j;
  
  for(int i=1; i<=n; i++)
  {
    for(int j=1; j<=m; j++)
    {
      cur[0] = i; //every time each row's first col has index as value, that is first column 
       if(s1[i] == s2[j]) return cur[j] = prev[j-1]; //if they match then no operations are performed
       else cur[j] = 1+min(prev[j], min(cur[j-1], prev[j-1])); 
      //f(i-1, j) :- //delete mismatch character from s1, and look for matching character from s2 in shriked s1
      //f(i, j-1) :- insert matching character at end of s1, so i don't change and s2 shrinks                                               
      //f(i-1, j-1) :- replace the mismatch character with matching character and shrink both s1 and s2, and take min of all these three operations and add 1 since we did one of these operations
    }
    prev = cur;
  }
  
  return prev[m];
 }
