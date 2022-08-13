//similar to matrix chain multiplication
//start from bottom 

//memoization TC: O(N^3) SC: O(N^2) + O(N)
int f(int i, int j, vector<int>& a, vector<vector<int>>& dp)
{
  if(i>j) return 0;
  
  if(dp[i][j] != -1) return dp[i][j];
  
  int maxi = INT_MIN;
  
  for(int ind = i; ind <= j; ind++) //start can be from any one between i and j
  {
    int cost = a[i-1] * a[ind] * a[j+1] + f(i, ind-1, a) + f(ind+1, j, a);
    
    maxi = max(maxi, cost);
  }
  
  return dp[i][j] = maxi;
}

//calling function
int maxCoins(vector<int>& a)
{
  int n = a.size();
  a.push_back(1);//initial right most coin
  a.insert(a.begin(), 1);//initial left most coin
  vector<vector<int>> dp(n+1, vector<int>(n+1, -1))
  return f(1, n, a, dp);
}

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Tabulation  TC: O(N^3) SC: O(N^2)
int maxCoins(vector<int>& a)
{
  int n = a.size();
  a.push_back(1);//initial right most coin
  a.insert(a.begin(), 1);//initial left most coin
  vector<vector<int>> dp(n+2, vector<int>(n+2, 0))
  
  for(int i = n; i >= 1; i--)
  {
    for(int j = 1; j <= n; j++)
    {
        if(i>j) continue;

        int maxi = INT_MIN;

        for(int ind = i; ind <= j; ind++) //start can be from any one between i and j
        {
          int cost = a[i-1] * a[ind] * a[j+1] + dp[i][ind-1] + dp[ind+1][j];

          maxi = max(maxi, cost);
        }

       dp[i][j] = maxi; 
    }
  }
  
  return dp[1][n];    
}
  
  
  
