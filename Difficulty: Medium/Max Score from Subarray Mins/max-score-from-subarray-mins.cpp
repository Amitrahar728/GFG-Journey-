class Solution {
  public:
    int maxSum(vector<int> &arr) {
        // code here
         int n = arr.size();
        int ans = 0;
        for(int i=0;i<n-1;i++){
            int sum = arr[i]+arr[i+1];
            ans = max(ans,sum);
        }
        return ans;
    }
};