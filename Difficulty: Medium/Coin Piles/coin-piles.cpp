class Solution {
  public:
    int minimumCoins(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        sort(arr.begin() , arr.end());
        vector<int> pre(n);
        pre[0] = arr[0];
        //preorder sum generation for solving 
        for(int i =1; i<n; i++){
            pre[i] = arr[i]+pre[i-1];
        }
        
        int ans = INT_MAX;
        int prev = 0;
        for(int i =0;i<n; i++){
            if(i>0) prev = pre[i-1];
            int pos = upper_bound(arr.begin()+i, arr.end(), arr[i]+k)- arr.begin(); //vo position dega jaha jake arr[i]+k exceed kr jayega 
            int total = pos>0 ? pre[n-1] - pre[pos-1] :0;
            int extra = prev +  total -((n-pos)*(arr[i]+k));
            ans = min(ans, extra);
            
        }
        return ans;
        
    }
};
