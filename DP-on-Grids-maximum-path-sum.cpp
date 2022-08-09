//any cell can be start point
//recursion TC: O(3^n*m)  SC: O(n*m)+O(n)
f(i, j, matrix) //stat from last row any column
{
  if(j<0 or j>=col) return INT_MIN; //out of bound case
  if(i==0) return grid[0][j]; //first row any column
  
  int up = grid[i][j]+f(i-1, j, matrix);
  int left_diagonal = grid[i][j]+f(i-1, j-1, matrix);
  int right_diagonal = grid[i][j]+f(i-1, j+1, matrix);
  
  return max(up, max(left_diagonal, right_diagonal));
}
//in calling function call from last row

int maxi = -1e9;
for(j=0; j<col; j++)
  maxi = max(maxi, f(row-1, col, matrix));
return maxi;
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//memoization TC: O(n*m) SC: O(n*m)+O(n)
dp(row, col)
f(i, j) //stat from last row any column
{
  if(j<0 or j>=col) return INT_MIN; //out of bound case
  if(i==0) return grid[0][j]; //first row any column
  if(dp[i][j]!=-1) return dp[i][j];
  int up = grid[i][j]+f(i-1, j);
  int left_diagonal = grid[i][j]+f(i-1, j-1);
  int right_diagonal = grid[i][j]+f(i-1, j+1);
  
  return dp[i][j]=max(up, max(left_diagonal, right_diagonal));
}

//in calling function call from last row

int maxi = -1e9;
for(j=0; j<col; j++)
  maxi = max(maxi, f(row-1, col, matrix)); 
return maxi;

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Tabulation TC: O(n*m) SC: O(n*m)
dp(row, col)
f(i, j) //stat from last row any column
{
  //if(i==0) return grid[0][j]; //first row any column
  for(int j=0; j<col; j++) dp[0][j] = matrix[0][j];

  //if(dp[i][j]!=-1) return dp[i][j];
  
  for(int i=1; i<row; i++)
  {
    for(int j=0; j<col; j++)
    {
      int up = grid[i][j]+dp[i-1][j];
      int left_diagonal = grid[i][j];
      // if(j<0) return INT_MIN; //out of bound case
      if(j-1>0) left_diagonal += dp[i-1][j-1];
      else left_diagonal += -1e9;
      // if(j>=col) return INT_MIN; //out of bound case
      int right_diagonal = grid[i][j];
      if(j+1<col) right_diagonal += dp[i-1][j+1];
      else right_diagonal += -1e9;
      // return dp[i][j]=max(up, max(left_diagonal, right_diagonal));
      dp[i][j] = max(up, max(left_diagonal, right_diagonal));;
    }
  }
  
  int maxi = -1e9;
  
  for(int j=0; j<row; j++)
    maxi = max(maxi, dp[n-1][j]); //max of last row
  
  return maxi;
}
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Space Optimisation TC: O(n*m) SC: O(n)

f(i, j) //stat from last row any column
{
  vector<int> previous_row(col, 0), current_row(col, 0);
  //if(i==0) return grid[0][j]; //first row any column
  for(int j=0; j<col; j++) previous_row[j] = matrix[0][j];

  //if(dp[i][j]!=-1) return dp[i][j];
  
  for(int i=1; i<row; i++)
  {
    for(int j=0; j<col; j++)
    {
      int up = grid[i][j]+previous_row[j];
      int left_diagonal = grid[i][j];
      // if(j<0) return INT_MIN; //out of bound case
      if(j-1>0) left_diagonal += previous_row[j-1];
      else left_diagonal += -1e9;
      // if(j>=col) return INT_MIN; //out of bound case
      int right_diagonal = grid[i][j];
      if(j+1<col) right_diagonal += dp[i-1][j+1];
      else right_diagonal += -1e9;
      // return dp[i][j]=max(up, max(left_diagonal, right_diagonal));
      current_row[j] = max(up, max(left_diagonal, right_diagonal));;
    }
    
    previous_row=current_row;
  }
  
  int maxi = -1e9;
  
  for(int j=0; j<row; j++)
    maxi = max(maxi, previous[j]); //max of last row
  
  return maxi;
}
