//Recursion TC: O(2^n*m) SC: O(m-1+n-1) i.e. path length

f(i, j) //we start from last cell n-1, m-1
{
  if(i==0 and j==0) return grid[0][0]; //reached destination and grid[0][0] will be part of path
  if(i<0 or j<0) return INT_MAX; //makes sure it becomes maximum path for not accepting case
  
  int up = grid[i][j]+f(i-1, j);
  int left = grid[i][j]+f(i, j-1);
  
  return min(up, left);
}

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Memoization TC: O(N*M) SC: O(n-1+m-1)+O(N*M)
dp(m*n);
f(i, j) //we start from last cell n-1, m-1
{
  if(i==0 and j==0) return grid[0][0]; //reached destination and grid[0][0] will be part of path
  if(i<0 or j<0) return INT_MAX; //makes sure it becomes maximum path for not accepting case
  if(dp[i][j]!=-1) return dp[i][j];
  
  int up = grid[i][j]+f(i-1, j);
  int left = grid[i][j]+f(i, j-1);
  
  return dp[i][j]=min(up, left);
}
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Tabulation TC: O(N*M) SC: O(N*M)
dp(m*n);
f(i, j) //we start from last cell n-1, m-1
{
  //if(i==0 and j==0) return 1;
 for(int i=0; i<row; i++)
 {
  for(int j=0; j<col; j++)
  {
    if(i==0 and j==0) dp[i][j]=grid[i][j];
    else
    {
      int up = grid[i][j], left = grid[i][j];
      if(i>0) up += dp[i-1][j];
      // if(i<0 or j<0) return INT_MAX; //makes sure it becomes maximum path for not accepting case
      else up += 1e9;
      if(j>0) left += dp[i][j-1];
      // if(i<0 or j<0) return INT_MAX; //makes sure it becomes maximum path for not accepting case
      else left += 1e9;
      dp[i][j]=min(up, left);
    }
  }
 }  
   return dp[row-1][col-1];
 }
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------  
 //Space optimization TC: O(N*M) SC: O(N)
prev_row(row, 0);
f(i, j) //we start from last cell n-1, m-1
{
  //if(i==0 and j==0) return 1;
 for(int i=0; i<row; i++)
 {
   cur_row(row, 0);
  for(int j=0; j<col; j++)
  {
    if(i==0 and j==0) cur_row[j]=grid[i][j];
    else
    {
      int up = grid[i][j], left = grid[i][j];
      //requiring previous row's j column
      if(i>0) up += prev_row[j];
       // if(i<0 or j<0) return INT_MAX; //makes sure it becomes maximum path for not accepting case
      else up += 1e9;
      //requiring current row's j column
      if(j>0) left += cur_row[j-1];
       // if(i<0 or j<0) return INT_MAX; //makes sure it becomes maximum path for not accepting case
      else left += 1e9;
      cur_row[j] = min(up, left);
    }
  }
   prev_row = cur_row;
 } 
   return prev_row[col-1];
 }
