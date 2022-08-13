//recursion
int f(int i, int j, vector<int>& cuts)
{
  if(i > j) return 0; //no more cuts
  
  int mini = INT_MAX;
  
  for(int ind = i; ind <= j; ind++)
  {
    int cost = cuts[j+1]-cuts[i-1]  + f(i, ind-1, cuts) + f(ind+1, j, cuts); //cost of cut = length of stick, i.e. (j+1) - (i-1)
    mini = min(mini, cost);
  }
  return mini;
}

//calling function

int cost(int n, int c, vector<int>& cuts)
{
  cuts.push_back(n); //initial right most cut
  cuts.insert(cuts.begin(), 0); //initial left most cut
  sort(cuts.begin(), cuts.end()); //to solve two sub problems independently, array needs to sorted
  return f(1, c, cuts); //i=1, j=c
}

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Memoization TC: O(N^3) SC: O(N^2)+O(N)
int f(int i, int j, vector<int>& cuts, vector<vector<int>>& dp)
{
  if(i > j) return 0; //no more cuts
  
  if(dp[i][j] != -1) return dp[i][j];
  
  int mini = INT_MAX;
  
  for(int ind = i; ind <= j; ind++)
  {
    int cost = cuts[j+1]-cuts[i-1]  + f(i, ind-1, cuts, dp) + f(ind+1, j, cuts, dp); //cost of cut = length of stick, i.e. (j+1) - (i-1)
    mini = min(mini, cost);
  }
  return dp[i][j] = mini;
}

//calling function

int cost(int n, int c, vector<int>& cuts)
{
  cuts.push_back(n); //initial right most cut
  cuts.insert(cuts.begin(), 0); //initial left most cut
  sort(cuts.begin(), cuts.end()); //to solve two sub problems independently, array needs to sorted
  vector<vector<int>> dp(c+1, vector<int>(c+1, -1));
  return f(1, c, cuts, dp); //i=1, j=c
}
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Tabulation TC: O(N^3) SC: O(N^2)

int cost(int n, int c, vector<int>& cuts) //n = size of cut and c = length of stick
{
  cuts.push_back(n); //initial right most cut
  cuts.insert(cuts.begin(), 0); //initial left most cut
  sort(cuts.begin(), cuts.end()); //to solve two sub problems independently, array needs to sorted
  vector<vector<int>> dp(c+2, vector<int>(c+2, 0));
  
  for(int i = c; i >= 1; i--)
  {
    for(int j = 1; j <= c; j++)
    {
      if(i > j) continue; //no more cuts
  
      int mini = INT_MAX;

      for(int ind = i; ind <= j; ind++)
      {
        int cost = cuts[j+1]-cuts[i-1]  + dp[i][ind-1] + dp[ind+1][j]; //cost of cut = length of stick, i.e. (j+1) - (i-1)
        mini = min(mini, cost);
      }
     dp[i][j] = mini;
    }
    
    return dp[1][c];
}
