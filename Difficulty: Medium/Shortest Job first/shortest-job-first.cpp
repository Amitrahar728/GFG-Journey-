// User function Template for C++

//Back-end complete function Template for C++

class Solution {
  public:
    long long solve(vector<int>& bt) {
        int n = bt.size();
        sort(bt.begin(), bt.end());
        int sum =0;
        int total=0;
        for(int i =0; i<bt.size()-1; i++){
            sum+=bt[i];
            total+=sum;
        }
        return total/n;
        
    }
};