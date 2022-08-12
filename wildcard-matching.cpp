//recursion
bool f(int i, int j, string& pattern, string& text)
{
  if(i<0 and j<0) return true; //both pattern and text to be matched are exhausted
  if(i<0 and j>=0) return false; //if text to be matched has some character's left and pattern is exhausted then there is nothing left in pattern to be matched
  if(j<0 and i>=0)
  {
    //if pattern has some characters left and text to be matched is exhausted then, All the characters in the pattern has to be '*' to match with an empty string "", 
    //since text to be matched is exhausted it falls to the case of matching empty string with pattern
    for(int i1=0; i1<=i; i1++)
      if(pattern[i1] != '*') return false;
    return true;
  }
  
  if(pattern[i] == text[j] or pattern[i] == '?')
    return f(i-1, j-1, pattern, text); //since they match with each other or pattern has '?' which matches with any character
  
  if(pattern[i] == '*')
    return f(i-1, j, pattern, text) | f(i, j-1, pattern, text); 
  //f(i-1, j, pattern, text) :- case where '*' is considered as empty i.e, "" and matching the text with remaining pattern
  //f(i, j-1, pattern, text) :- case where '*' is considered to be matching character with text and matching the text with pattern without shrinking pattern with remaining text
  
  return false; //if not of abouve two case then two characters are not matching
}

//calling function
bool wildcad(string pattern, string text)
{
  int n = pattern.size();
  int m = text.size();
  return f(n-1, m-1, pattern, text);
}

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//memoization
bool f(int i, int j, string& pattern, string& text, vector<vector<int>>& dp )
{
  if(i<0 and j<0) return true; //both pattern and text to be matched are exhausted
  if(i<0 and j>=0) return false; //if text to be matched has some character's left and pattern is exhausted then there is nothing left in pattern to be matched
  if(j<0 and i>=0)
  {
    //if pattern has some characters left and text to be matched is exhausted then, All the characters in the pattern has to be '*' to match with an empty string "", 
    //since text to be matched is exhausted it falls to the case of matching empty string with pattern
    for(int i1=0; i1<=i; i1++)
      if(pattern[i1] != '*') return false;
    return true;
  }
  
  if(dp[i][j]!=-1) return dp[i][j];
  
  if(pattern[i] == text[j] or pattern[i] == '?')
    return dp[i][j] = f(i-1, j-1, pattern, text, dp); //since they match with each other or pattern has '?' which matches with any character
  
  if(pattern[i] == '*')
    return dp[i][j] = f(i-1, j, pattern, text, dp) | f(i, j-1, pattern, text, dp); 
  //f(i-1, j, pattern, text) :- case where '*' is considered as empty i.e, "" and matching the text with remaining pattern
  //f(i, j-1, pattern, text) :- case where '*' is considered to be matching character with text and matching the text with pattern without shrinking pattern with remaining text
  
  return dp[i][j] = false; //if not of abouve two case then two characters are not matching
}

//calling function
bool wildcad(string pattern, string text)
{
  int n = pattern.size();
  int m = text.size();
  vector<vector<int>> dp(n, vector<int>(m, -1));
  return f(n-1, m-1, pattern, text, dp);
}

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Tabulation
bool wildcad(string pattern, string text)
{
  int n = pattern.size();
  int m = text.size();
  vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
  
  //if(i<0 and j<0) return true; //both pattern and text to be matched are exhausted
  dp[0][0] = true;
  
  //if(i<0 and j>=0) return false; //if text to be matched has some character's left and pattern is exhausted then there is nothing left in pattern to be matched
  for(int j=1; j<=m; j++)
    dp[0][j] = false;
  
//    if(j<0 and i>=0)
//   {
//     //if pattern has some characters left and text to be matched is exhausted then, All the characters in the pattern has to be '*' to match with an empty string "", 
//     //since text to be matched is exhausted it falls to the case of matching empty string with pattern
//     for(int i1=0; i1<=i; i1++)
//       if(pattern[i1] != '*') return false;
//     return true;
//   }
  for(i=1; i<=n; i++)
  {
    bool flag = true;
    for(int i1=1; i1<=i; i1++)
    {
      if(pattern[i1] != '*') 
       {
          flag = false;
          break;
       }
    }
     dp[i][0] = flag;
  }
  
  for(int i=1; i<=n; i++)
  {
    for(int j=1; j<=m; j++)
    {
      if(pattern[i] == text[j] or pattern[i] == '?')
       dp[i][j] = dp[i-1][j-1]; //since they match with each other or pattern has '?' which matches with any character

      else if(pattern[i] == '*')
        dp[i][j] = dp[i-1][j] | dp[i][j-1]; 
      //f(i-1, j, pattern, text) :- case where '*' is considered as empty i.e, "" and matching the text with remaining pattern
      //f(i, j-1, pattern, text) :- case where '*' is considered to be matching character with text and matching the text with pattern without shrinking pattern with remaining text

      else dp[i][j] = false; //if not of abouve two case then two characters are not matching
     }
  }
  
  return dp[n][m];
}

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Space Optimization
bool wildcad(string pattern, string text)
{
  int n = pattern.size();
  int m = text.size();
  vector<bool>prev(m+1, false), cur(m+1, false);
  
  //if(i<0 and j<0) return true; //both pattern and text to be matched are exhausted
  prev[0] = true;
  
  //if(i<0 and j>=0) return false; //if text to be matched has some character's left and pattern is exhausted then there is nothing left in pattern to be matched
  for(int j=1; j<=m; j++)
    prev[j] = false;
  
//    if(j<0 and i>=0)
//   {
//     //if pattern has some characters left and text to be matched is exhausted then, All the characters in the pattern has to be '*' to match with an empty string "", 
//     //since text to be matched is exhausted it falls to the case of matching empty string with pattern
//     for(int i1=0; i1<=i; i1++)
//       if(pattern[i1] != '*') return false;
//     return true;
//   }
//   for(i=1; i<=n; i++)
//   {
//     bool flag = true;
//     for(int i1=1; i1<=i; i1++)
//     {
//       if(pattern[i1] != '*') 
//        {
//           flag = false;
//           break;
//        }
//     }
//     //here for every row, we are assigning 0th column value
//      dp[i][0] = flag;
//   }
  
  for(int i=1; i<=n; i++)
  {
    //cur is the current row's value and that cur's 0th column value has to be assigned everytime. 
    
    bool flag = true;
    for(int i1=1; i1<=i; i1++)
    {
      if(pattern[i1] != '*') 
       {
          flag = false;
          break;
       }
    }
    //here for every row, we are assigning 0th column value
     cur[0] = flag;
    
    for(int j=1; j<=m; j++)
    {
      if(pattern[i] == text[j] or pattern[i] == '?')
       cur[j] = prev[j-1]; //since they match with each other or pattern has '?' which matches with any character

      else if(pattern[i] == '*')
        cur[j] = prev[j] | cur[j-1]; 
      //f(i-1, j, pattern, text) :- case where '*' is considered as empty i.e, "" and matching the text with remaining pattern
      //f(i, j-1, pattern, text) :- case where '*' is considered to be matching character with text and matching the text with pattern without shrinking pattern with remaining text

      else cur[j] = false; //if not of abouve two case then two characters are not matching
     }
    
    prev = cur;
  }
  
  return prev[m];
}
  
  
  
