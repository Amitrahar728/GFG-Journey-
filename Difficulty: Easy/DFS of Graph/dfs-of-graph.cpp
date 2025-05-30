class Solution {
  public:
    void func(vector<vector<int>> &adj , vector<int> &vis, int start , vector<int> &ans){
        vis[start ] =1;
        ans.push_back(start);
        for(auto it : adj[start]){
            if(!vis[it]){
                func(adj,vis,it, ans);
            }
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int>vis(n,0);
        int start =0;
        vector<int> ans;
        func(adj, vis,start,ans);
        return ans;
        
        
    }
};