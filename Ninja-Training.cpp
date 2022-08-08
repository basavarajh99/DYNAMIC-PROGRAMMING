//recursion
//initially day = n-1
f(day, previous_task)
{
  if(day==0)
  {
    int maxi = 0;
    //if the present task is not the last task that i performed on the previous day then take maximum of all the remaining task
    for(int i=0; i<2; i++)
      if(i!=previous_task)
        maxi = max(maxi, task[0][i]);
    return maxi;
  }
  
  int maxi = 0;
  for(int i=0; i<2; i++)
  {
    if(i!=previous_task)
    {
      points += task[day][i]+f(day-1, i); //if it's not the previous task that I'm doing now then pass the task and next day to new call
      maxi = max(maxi, points);
    }
  }
  return maxi;
}

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
 //memoization TC: O(N*4)*3 SC: O(N)+O(N*4)
  //initially day = n-1
 // dp[n][4] = {-1, -1}
f(day, previous_task, dp)
{
  if(day==0)
  {
    int maxi = 0;
    //if the present task is not the last task that i performed on the previous day then take maximum of all the remaining task
    for(int i=0; i<3; i++)
      if(i!=previous_task)
        maxi = max(maxi, task[0][i]);
    return maxi;
  }
  
  if(dp[day][previous_task]!=-1) return dp[day][previous_task];
  
  int maxi = 0;
  for(int i=0; i<3; i++)
  {
    if(i!=previous_task)
    {
      points += task[day][i]+f(day-1, i); //if it's not the previous task that I'm doing now then pass the task and next day to new call
      maxi = max(maxi, points);
    }
  }
  return dp[day][previous_task]=maxi;
}

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
//tabulation TC: O(N*4*3) SC: O(N*4)
  
int ninja(vector<vector<int>>& points, int n)
{
  vector<vector<int>>dp(n, vector<int>(4, -1));
//    if(day==0)
//   {
//     int maxi = 0;
//     //if the present task is not the last task that i performed on the previous day then take maximum of all the remaining task
//     for(int i=0; i<3; i++)
//       if(i!=previous_task)
//         maxi = max(maxi, task[0][i]);
//     return maxi;
//   }
  dp[0][0] = max(points[0][1], points[0][2]);
  dp[0][1] = max(points[0][0], points[0][2]);
  dp[0][2] = max(points[0][0], points[0][1]);
  dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));
  
  for(int day=0; day<n; day++)
  {
    for(int previous_task = 0; previous_task<4; previous_task++)
    {
      dp[day][previous_task] = 0;
      for(int task = 0; task<3; task++)
      {
        if(task != previous_task)
        {
          int point = points[day][task]+dp[day-1][task];
          dp[day][previous_task] = max(dp[day][previous_task], point);
        }
      }
    }
  }
  return dp[n-1][3];
}

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
//space optimization TC: O(N*4*3) SC: O(N*4)
  
int ninja(vector<vector<int>>& points, int n)
{
  vector<int>prev(4, -1);
//    if(day==0)
//   {
//     int maxi = 0;
//     //if the present task is not the last task that i performed on the previous day then take maximum of all the remaining task
//     for(int i=0; i<3; i++)
//       if(i!=previous_task)
//         maxi = max(maxi, task[0][i]);
//     return maxi;
//   }
  prev[0] = max(points[0][1], points[0][2]);
  prev[1] = max(points[0][0], points[0][2]);
  prev[2] = max(points[0][0], points[0][1]);
  prev[3] = max(points[0][0], max(points[0][1], points[0][2]));
  
  for(int day=0; day<n; day++)
  {
    vector<int> temp(4, -1);
    for(int previous_task = 0; previous_task<4; previous_task++)
    {
      dp[day][previous_task] = 0;
      for(int task = 0; task<3; task++)
        if(task != previous_task)
          temp[previous_task] = max(temp[previous_task], points[day][task]+prev[task];);
    }
    prev = temp;
  }
  return prev[3];
}
  
