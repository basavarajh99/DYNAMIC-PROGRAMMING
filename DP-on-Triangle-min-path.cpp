//recursion TC: O(2^sum(N)) SC: O(N)
//starts from (0,0) to last row

f(i, j)
{
  if(i == n-1) return triangle[n-1][j]; //any column element in the last row
  
  int down = triangle[i][j]+f(i+1, j);
  int diagonal = triangle[i][j]+f(i+1, j+1);
  
  return min(down, diagonal);
}

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Memoization TC: O(n*n) SC: O(n)+O(n*n)
dp(n, n)
f(i, j)
{
  if(i == n-1) return triangle[n-1][j]; //any column element in the last row
  if(dp[i][j]!=-1) return dp[i][j];
  int down = triangle[i][j]+f(i+1, j);
  int diagonal = triangle[i][j]+f(i+1, j+1);
  
  return dp[i][j]=min(down, diagonal);
}

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Tabulation TC: O(n*n) SC: O(n*n)
  //reverse of recursion
dp(n, n)
f(i, j)
{
  //if(i == n-1) return triangle[n-1][j]; //any column element in the last row
  for(int j=0; j<n; j++) dp[n-1][j] = triangle[n-1][j];
  //if(dp[i][j]!=-1) return dp[i][j];
  for(int i=n-2; i>=0; i--)
  {
    for(int j=i; j>=0; j--)
    {
       //int down = triangle[i][j]+f(i+1, j);
       int down = triangle[i][j]+dp[i+1][j];
      //int diagonal = triangle[i][j]+f(i+1, j+1);
       int diagonal = triangle[i][j]+dp[i+1][j+1];
      //return dp[i][j]=min(down, diagonal);
       dp[i][j]=min(down, diagonal);
    }
  }
 return dp[0][0];
}

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Space optimization TC: O(n*n) SC: O(n)
f(i, j)
{
  front_row[n]={0},  cur_row[n]={0};
  //if(i == n-1) return triangle[n-1][j]; //any column element in the last row
  //for(int j=0; j<n; j++) dp[n-1][j] = triangle[n-1][j];
  for(int j=0; j<n; j++)  front_row[j] = triangle[n-1][j];
  //if(dp[i][j]!=-1) return dp[i][j];
  for(int i=n-2; i>=0; i--)
  {
    for(int j=i; j>=0; j--)
    {
       //int down = triangle[i][j]+f(i+1, j);
       //int down = triangle[i][j]+dp[i+1][j];
       int down = triangle[i][j]+front_row[j];
      //int diagonal = triangle[i][j]+f(i+1, j+1);
       //int diagonal = triangle[i][j]+dp[i+1][j+1];
      int diagonal = triangle[i][j]+front_row[j+1];
      //return dp[i][j]=min(down, diagonal);
       cur_row[j]=min(down, diagonal);
    }
    front = cur;
  }
 return front[0];
}
