class Solution {
public:
    void floydWarshall(std::vector<std::vector<int>> &dist) {
        int n = dist.size();

       

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][k] != (int)1e8 && dist[k][j] != (int) 1e8){
                        dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        
    }
};