//Similar To Matrix Chain Multiplication

//memoization

#define long long ll
int mod = 1000000007;

ll f(int i, int j, int isTrue, string &exp, vector<vector<vector<ll>>> &dp) (0 to n-1)
{
  if(i > j) return 0;
  
  if(i == j) //single T or F
  {
    if(isTrue) //if isTrue = 1 and single element is true then return true else false
      return isTrue == 'T';
    else
      return isTrue == 'F'; //if isTrue = 0 and single element is false then return true else false
  }
  
   if(dp[i][j][isTrue] != -1) return dp[i][j][isTrue];
  
  ll ways = 0;
  
  for(int ind = i; ind <= j-1; ind+=2)
  {
    ll LT = f(i, ind-1, 1, exp, dp); // left expression as true
    ll LF = f(i, ind-1, 0, exp, dp); // left expression as false
    ll RT = f(ind+1, j, 1, exp, dp); // right expression as true
    ll RF = f(ind+1, j, 0, exp, dp); // right expression as false
    
    if(exp[ind] == '&')  
    {
      // true for & = T & T
      // false for & = T & F, F & T, F & F
      
      if(istrue) ways = (ways + (LT * RT) % mod) % mod; // If I'm looking for true then total ways of & to be true  
      else ways = (ways + (LT * RF) % mod + (LF * RT) % mod + (LF * RF) % mod) % mod; // If I'm looking for false then total ways of & to be false
    }
    
    else if(exp[ind] == '|')
    {
      // true for | = T | T, T | F, F | T
      // false for | = F | F
      if(isTrue) ways = (ways + (LT * RT) % mod + (LT * RF) % mod + (LF * RT) % mod) % mod; // If I'm looking for true then total ways of | to be true
      else ways = (ways + (LF * RF) % mod) % mod; // If I'm looking for false then total ways of | to be false
    }
    
    else //exp[ind] == '^'
    {
       // true for ^ = T ^ F, F ^ T
      // false for ^ = T ^ T, F ^ F
      if(isTrue) ways = (ways + (LT * RF) % mod + (LF * RT) % mod) % mod; //If I'm looking for true then total ways of ^ to be true
      else ways = (ways + (LT * RT) % mod + (LF * RF) % mod) % mod; // If I'm looking for false then total ways of ^ to be false
    }
  }
  
  return dp[i][j][isTrue] = ways;
}

// calling function
int evaluate(string &exp)
{
  int n = exp.size();
  vector<vector<vector<ll>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));
  return f(0, exp.size()-1, 1, exp, dp);
}
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Tabulation
#define long long ll
int mod = 1000000007;

int evaluate(string &exp)
{
  int n = exp.size();
  vector<vector<vector<ll>>> dp(n, vector<vector<int>>(n, vector<int>(2, 0)));
  
  for(int i = n-1; i >= 0; i--)
  {
    for(int j = i; j < n; j++)
    {
//         if(i == j) //single T or F
//         {
//           if(isTrue) //if isTrue = 1 and single element is true then return true else false
//             return isTrue == 'T';
//           else
//             return isTrue == 'F'; //if isTrue = 0 and single element is false then return true else false
//         }
        if(i == j)
        {
          dp[i][j][0] = (exp[i] == 'F');
          dp[i][j][1] = (exp[i] == 'T');
        }

         //if(dp[i][j][isTrue] != -1) return dp[i][j][isTrue];

        ll ways = 0;

        for(int ind = i; ind <= j-1; ind+=2)
        {
          ll LT = dp[i][ind-1][1]; // left expression as true
          ll LF = dp[i][ind-1][0]; // left expression as false
          ll RT = dp[ind+1][j][1]; // right expression as true
          ll RF = dp[ind+1][j][0]; // right expression as false

          if(exp[ind] == '&')  
          {
            // true for & = T & T
            // false for & = T & F, F & T, F & F
            dp[i][j][0] = (dp[i][j][0] + (LT * RF) % mod + (LF * RT) % mod + (LF * RF) % mod) % mod; // If I'm looking for false then total ways of & to be false
            dp[i][j][1] = (dp[i][j][1] + (LT * RT) % mod) % mod; // If I'm looking for true then total ways of & to be true  
          }

          else if(exp[ind] == '|')
          {
            // true for | = T | T, T | F, F | T
            // false for | = F | F
            dp[i][j][0] = (dp[i][j][0] + (LF * RF) % mod) % mod; // If I'm looking for false then total ways of | to be false
            dp[i][j][1] = (dp[i][j][1] + (LT * RT) % mod + (LT * RF) % mod + (LF * RT) % mod) % mod; // If I'm looking for true then total ways of | to be true
          }

          else //exp[ind] == '^'
          {
             // true for ^ = T ^ F, F ^ T
            // false for ^ = T ^ T, F ^ F
            dp[i][j][0] = (dp[i][j][0] + (LT * RT) % mod + (LF * RF) % mod) % mod; // If I'm looking for false then total ways of ^ to be false
            dp[i][j][1] = (dp[i][j][1] + (LT * RF) % mod + (LF * RT) % mod) % mod; //If I'm looking for true then total ways of ^ to be true
          }
        }
    }
  }
  
  return dp[0][n-1][1];
}
