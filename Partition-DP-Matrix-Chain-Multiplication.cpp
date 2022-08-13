//two matrices of dimension r1, c1 and r2, c2 then
//it should satisfy c1 == r2 and No. of operations = r1*c1*c2 
//for any i'th matrix i'th = A[i-1]*A[i]

//recursion
int f(int i, int j, vector<int>& arr)
{
  if(i==j) return 0; //no multiplications for single element matrix
  
  int mini = 1e9;
  
  for(int k = i; k < j; k++) //different partitions from i to k and k+1 to j
  {
    int steps = arr[i-1] * arr[k] * arr[j] + f(i, k, arr) + f(k+1, j, arr);
    
    mini = min(mini, steps);
  }
  
  return mini;
}

//calling function
int mcm(vector<int> &arr, int N)
{
  return (1, N-1, arr);
}

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Memoization TC: O(N*N*N) SC: O(N*N) + O(N)
int f(int i, int j, vector<int>& arr, vector<vector<int>>& dp)
{
  if(i==j) return 0; //no multiplications for single element matrix
  
  if(dp[i][j] != -1) return dp[i][j];
  
  int mini = 1e9;
  
  for(int k = i; k < j; k++) //different partitions from i to k and k+1 to j
  {
    int steps = arr[i-1] * arr[k] * arr[j] + f(i, k, arr, dp) + f(k+1, j, arr, dp);
    
    mini = min(mini, steps);
  }
  
  return dp[i][j] = mini;
}

//calling function
int mcm(vector<int> &arr, int N)
{
  vector<vector<int>> dp(N, vector<int>(N, -1));
  return (1, N-1, arr, dp);
}

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Tabulation TC: O(N*N*N) SC: O(N*N)

int mcm(vector<int> &arr, int N)
{
  vector<vector<int>> dp(N, vector<int>(N, 0));
  
  //if(i==j) return 0; //no multiplications for single element matrix
  for(int i = 1; i < N; i++) dp[i][i] = 0;
  
  for(int i = N-1; i >= 1; i--)
  {
    for(int j = i+1; i< N; j++)
    {
      int mini = 1e9;
  
      for(int k = i; k < j; k++) //different partitions from i to k and k+1 to j
      {
        int steps = arr[i-1] * arr[k] * arr[j] + dp[i][k] + dp[k+1][j];
        mini = min(mini, steps);
      }

      dp[i][j] = mini;      
    }
  }
  
  return dp[1][N-1];
}
