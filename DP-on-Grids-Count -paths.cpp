//Count paths
//Count paths with obstacles
//max path sum
//min path sum
//Triangle
//2 start points

//Recursion TC: O(2^n*m) SC: O(m-1+n-1) i.e. path length

f(i, j) //we start from last cell n-1, m-1
{
  if(i==0 and j==0) return 1; //reached destination
  if(i<0 or j<0) return 0;
  
  int up = f(i-1, j);
  int left = f(i, j-1);
  
  return up+left;
}

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Memoization TC: O(N*M) SC: O(n-1+m-1)+O(N*M)
dp(m*n);
f(i, j) //we start from last cell n-1, m-1
{
  if(i==0 and j==0) return 1;
  if(i<0 or j<0) return 0;
  if(dp[i][j]!=-1) return dp[i][j];
  int up = f(i-1, j, dp);
  int left = f(i, j-1, dp);
  
  return dp[i][j]=up+left;
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
    if(i==0 and j==0) dp[i][j]=1;
    else
    {
      int up = 0, left = 0;
      if(i>0) up = dp[i-1][j];
      if(j>0) left = dp[i][j-1];
      dp[i][j] = up+left;
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
    if(i==0 and j==0) cur_row[j]=1;
    else
    {
      int up = 0, left = 0;
      if(i>0) up = prev_row[j];
      if(j>0) left = cur_row[j-1];
      cur_row[j] = up+left;
    }
  }
   prev_row = cur_row;
 } 
   return prev_row[col-1];
 }
