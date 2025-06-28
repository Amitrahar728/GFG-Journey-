class Solution {
  public:
    vector<int> countLessEq(vector<int>& a, vector<int>& b) {
        // code here
        vector<int> sorted(100001,0);
        for(int i =0; i<b.size(); i++){
            sorted[b[i]]++;
        }
        for(int i =1; i<100001; i++) sorted[i]+=sorted[i-1];
        vector<int> ans(a.size());
        for(int i =0; i<a.size(); i++){
            ans[i] = sorted[a[i]];
        }
        return ans;
    }
};