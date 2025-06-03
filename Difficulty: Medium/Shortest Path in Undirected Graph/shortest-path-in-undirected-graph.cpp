class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        int n = adj.size();
        vector<int> dist(n, 1e9);
        dist[src] = 0;

        queue<int> q;
        q.push(src);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neighbor : adj[node]) {
                if (dist[node] + 1 < dist[neighbor]) {
                    dist[neighbor] = dist[node] + 1;
                    q.push(neighbor);
                }
            }
        }

        vector<int> ans(n, -1);
        for (int i = 0; i < n; i++) {
            if (dist[i] != 1e9) {
                ans[i] = dist[i];
            }
        }

        return ans;
    }
};
