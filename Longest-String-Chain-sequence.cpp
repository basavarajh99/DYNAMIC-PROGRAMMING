//difference of 1 char
//sort according to length
//similar to LIS, just change arr[prev] < arr[ind] to compare(arr[prev], arr[ind]), and write compare function
bool compare(string& s1, string& s2)
{
  if(s1.size() != s2.size()+1) return false;
  int first = 0, second = 0;
  while(first < s1.size()) //the larger string
  {
    if(second < s2.size() and s1[first] == s2[second])
    {
      first++;
      second++;
    }
    
    else
      first++;
  }
  
  if(first == s1.size() and second == s2.size()) return true;
  
  return false;
}

static bool comp(string& s1, string& s2)
{
  return s1.size() < s2.size();
}

int LIS(vector<int>& arr)
{
  sort(arr.begin(), arr.end(), comp); //sorting according to length
  vector<int> dp(n, 1); //hash array tells who is previous one
  int maxi = 1;
  
  for(int ind = 0; ind < n; ind++)
  {
    for(int prev = 0; prev < ind; prev++)
    {
      if(compare(arr[ind], arr[prev]) and 1+dp[prev] > dp[ind])
        dp[ind] = 1+dp[prev];
    }
    if(dp[ind] > maxi)
    {
      maxi = dp[ind];
    }
  }
  
  return maxi;
}
