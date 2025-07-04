class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        int n = arr.size();
        // simple 2 pointer vali approach hai  
        map<int, int> mp;  
        int ans = 0;       
        int prev = 0;      

        for (int i = 0; i < n; ++i) {
            mp[arr[i]]++; 
            if (mp.size() <= k) {
                int cnt = i - prev + 1;  
                ans += cnt;
            }
            while (mp.size() > k) {
                mp[arr[prev]]--;        
                if (mp[arr[prev]] == 0) 
                    mp.erase(arr[prev]);
                prev++;                
                
                
                if (mp.size() <= k) {
                    int cnt= i-prev+1; 
                    ans += cnt;
                }
            }
        }
        return ans;
    }
};