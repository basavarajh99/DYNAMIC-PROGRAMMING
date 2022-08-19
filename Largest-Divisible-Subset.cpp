//sort array
//if arr[i] is divisible by arr[i-1] then arr[i] is divisible by all the elements before arr[i-1]
//similar to LIS, just sort array and change arr[prev] < arr[ind] to arr[ind]%arr[prev] == 0
vector<int> LDS(int arr[])
{
 //similar to LIS, see github
        int n = arr.size();
      sort(arr.begin(), arr.end());
      vector<int> dp(n, 1), hash(n); //hash array tells who is previous one
      int maxi = 1, lastindex = 0;

      for(int ind = 0; ind < n; ind++)
      {
          hash[ind] = ind; //initial everyone will have their own index
        for(int prev = 0; prev < ind; prev++)
        {
          if(arr[ind] % arr[prev] == 0 and 1+dp[prev] > dp[ind])
          {
            dp[ind] = 1+dp[prev];
            hash[ind] = prev; //LIS till index i              
          }
        }
        if(dp[ind] > maxi) //update only if subsequence of greater length is found
        {
          maxi = dp[ind]; //max of LIS
          lastindex = ind; //Max LIS index
        }
      }

      vector<int> v;
      v.push_back(arr[lastindex]);

      while(hash[lastindex] != lastindex) //trace_back till index = hash[index]
      {
        lastindex = hash[lastindex];
        v.push_back(arr[lastindex]);
      }

      reverse(v.begin(), v.end());

      return v;
}
