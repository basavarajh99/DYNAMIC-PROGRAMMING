//front partition

//memoization TC: O(N^2) SC: O(N) + O(N)
bool isPalindrome(int i, int j, string s, vector<int> &dp)
{
  while(i < j)
  {
    if(s[i] != s[j])
      return false;
    i++, j--;
  }
  
  return true;
}

int f(int i, int n, string &s)
{
  if(i == n) return 0;
  
  if(dp[i] != -1) return dp[i];
  
  int cuts = 0, mincuts = INT_MAX;
  
  for(int j = i; j < n; j++)
  {
    if(isPalindrome(i, j, s))
    {
      cuts = 1 + f(j+1, n, s, dp);// consider for cut only if it's a palindrome and move to next character after present palindrome
      mincuts = min(mincuts, cuts); 
    }
  }
  
  return dp[i] = min;
}

//calling function
int palindromepartition(string s)
{
  int n = s.size();
  vector<int> dp(n, -1);
  return f(0, n, s, dp)-1; //since we are doing partition at the end too
}
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Tabulation TC: O(N^2) SC: O(N)
bool isPalindrome(int i, int j, string s, vector<int> &dp)
{
  while(i < j)
  {
    if(s[i] != s[j])
      return false;
    i++, j--;
  }
  
  return true;
}
int palindromepartition(string s)
{
  int n = s.size();
  vector<int> dp(n+1, 0);
  
  dp[n] = 0;
  
  for(int i = n-1; i >= 0; i--)
  {
    int cuts = 0, mincuts = INT_MAX;

    for(int j = i; j < n; j++)
    {
      if(isPalindrome(i, j, s))
      {
        cuts = 1 + dp[j+1];// consider for cut only if it's a palindrome and move to next character after present palindrome
        mincuts = min(mincuts, cuts); 
      }
    }
    dp[i] = min;
  }
  
  return dp[0]-1; //since we are doing partition at the end too
}
