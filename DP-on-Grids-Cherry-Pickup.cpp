//3D DP
//fixed start and variable end
//single i for row, since bob and alice will move simultaneously down but coulumns may vary
// there are 9 combination of next paths i.e. for every path alice takes bob has 3 choices and vice versa

//recursion TC: O(3^n * 3^n) SC: O(n)

int f(i, j1, j2, r, c, grid) // j1 = alice and j2 = bob
{
  if(j1<0 or j2<0 or j1>c or j2>c)
    return -1e8;
  
  if(i==r-1) 
  {
    if(j1 == j2) return grid[i][j1]; //if both of them end up in same cell, consider only one person's value
    else return grid[i][j1]+grid[i][j2]; //if both end up in different cell, consider only both values
  }
  
  int maxi = -1e8;
  
  for(int dj1=-1; dj1<=1; dj1++)// for alice, from left-diagonal -> down -> right-diagonal
  {
    for(int dj2=-1; dj2<=1; dj2++)// for bob, for each move of alice bob can go left-diagonal -> down -> right-diagonal
    {
        int value = 0;// number of chocolates collected
        if(j1 == j2) value = grid[i][j1]; //only one person's value
        else value = grid[i][j1]+grid[i][j2];
        value += f(i+1, j1+dj+1, j2+dj2, r, c, grid);
        maxi = maxi(maxi, values); //maximum of each row, since there can be 9 possible values
    }
  }
  
  return maxi;
}

//in calling function
return f(0, 0, c-1, r, c, grid);

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
//memoization TC: O(n*m)*9 SC: O(n*m)+o(n)
dp(row, col1, col2)
int f(i, j1, j2, r, c, grid, dp) // j1 = alice and j2 = bob
{
  if(j1<0 or j2<0 or j1>c or j2>c)
    return -1e8;
  
  if(i==r-1) 
  {
    if(j1 == j2) return grid[i][j1]; //if both of them end up in same cell, consider only one person's value
    else return grid[i][j1]+grid[i][j2]; //if both end up in different cell, consider only both values
  }
  
  if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
  
  int maxi = -1e8;
  
  for(int dj1=-1; dj1<=1; dj1++)// for alice, from left-diagonal -> down -> right-diagonal
  {
    for(int dj2=-1; dj2<=1; dj2++)// for bob, for each move of alice bob can go left-diagonal -> down -> right-diagonal
    {
        int value = 0;// number of chocolates collected
        if(j1 == j2) value = grid[i][j1]; //only one person's value
        else value = grid[i][j1]+grid[i][j2];
        value += f(i+1, j1+dj+1, j2+dj2, r, c, grid);
        maxi = maxi(maxi, values); //maximum of each row, since there can be 9 possible values
    }
  }
  
  return dp[i][j1][j2]=maxi;
}

//in calling function
return f(0, 0, c-1, r, c, grid);

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Tabulation TC: O(n*m)*9 SC: O(n*m)
  
int maximumChocoloates(int r, int c, vector<vector<int>> &grid)
{
  //3D dp
  vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, 0)));
  
  for(int j1=0; j1<c; j1++)
  {
    for(int j2=0; j2<c; j2++)
    {
      if(j1==j2) dp[r-1][j1][j2] = grid[r-1][j1]; //landing in same cell, then only one is considered
      else dp[r-1][j1][j2] = grid[r-1][j1]+grid[r-1][j2];;
    }
  }
  
  for(int i=n-2; i>=0; i--)
  {
    for(int j1=0; j1<c; j1++)
    {
      for(int j2=0; j2<c; j2++)
      {
        int maxi = -1e8;
  
        for(int dj1=-1; dj1<=1; dj1++)// for alice, from left-diagonal -> down -> right-diagonal
        {
          for(int dj2=-1; dj2<=1; dj2++)// for bob, for each move of alice bob can go left-diagonal -> down -> right-diagonal
          {
              int value = 0;// number of chocolates collected
              if(j1 == j2) value = grid[i][j1]; //only one person's value
              else value = grid[i][j1]+grid[i][j2];
              if(j1+dj1 >= 0 and j1+dj1 < c and j2+dj2 >=0 and j2+dj2 < c)
              value += dp[i+1][j1+dj1][j2+dj2];
              maxi = maxi(maxi, values); //maximum of each row, since there can be 9 possible values
          }
        }
        dp[i][j1][j2]=maxi;
      }
    }
  }
  
  return dp[0][0][c-1];
}

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Spcae optimization TC: O(n*m)*9 SC: O(n)
  // to 2d dp
int maximumChocoloates(int r, int c, vector<vector<int>> &grid)
{
  //3D dp
  vector<vector<int>> front_row(c, vector<int>(c, 0));
  vector<vector<int>> current_row(c, vector<int>(c, 0));
  
  for(int j1=0; j1<c; j1++)
  {
    for(int j2=0; j2<c; j2++)
    {
      if(j1==j2) front_row[j1][j2] = grid[r-1][j1]; //landing in same cell, then only one is considered
      else front_row[j1][j2] = grid[r-1][j1]+grid[r-1][j2];;
    }
  }
  
  for(int i=n-2; i>=0; i--)
  {
    for(int j1=0; j1<c; j1++)
    {
      for(int j2=0; j2<c; j2++)
      {
        int maxi = -1e8;
  
        for(int dj1=-1; dj1<=1; dj1++)// for alice, from left-diagonal -> down -> right-diagonal
        {
          for(int dj2=-1; dj2<=1; dj2++)// for bob, for each move of alice bob can go left-diagonal -> down -> right-diagonal
          {
              int value = 0;// number of chocolates collected
              if(j1 == j2) value = grid[i][j1]; //only one person's value
              else value = grid[i][j1]+grid[i][j2];
              if(j1+dj1 >= 0 and j1+dj1 < c and j2+dj2 >=0 and j2+dj2 < c)
              value += front_row[j1+dj1][j2+dj2];
              maxi = maxi(maxi, values); //maximum of each row, since there can be 9 possible values
          }
        }
        current_row[j1][j2]=maxi;
      }
    }
    front_row = current_row;
  }
  
  return front_row[0][c-1];
}
