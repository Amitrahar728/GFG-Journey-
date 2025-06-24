class Solution {
public:
    class DisjointSet {
    public:
        vector<int> rank, parent, size;
        DisjointSet(int n) {
            rank.resize(n, 0);
            parent.resize(n);
            size.resize(n);
            for (int i = 0; i < n; i++) {
                parent[i] = i;
                size[i] = 1;
            }
        }

        int findUPar(int node) {
            if (node == parent[node])
                return node;
            return parent[node] = findUPar(parent[node]);
        }

        void unionByRank(int u, int v) {
            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);
            if (ulp_u == ulp_v) return;
            if (rank[ulp_u] < rank[ulp_v]) {
                parent[ulp_u] = ulp_v;
            }
            else if (rank[ulp_v] < rank[ulp_u]) {
                parent[ulp_v] = ulp_u;
            }
            else {
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }
        }

        void unionBySize(int u, int v) {
            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);
            if (ulp_u == ulp_v) return;
            if (size[ulp_u] < size[ulp_v]) {
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }
            else {
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
    };

private:
    bool isvalid(int newr, int newc, int n) {
        return newr >= 0 && newr < n && newc >= 0 && newc < n;
    }

public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) continue;

                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, -1, 0, 1};

                for (int k = 0; k < 4; k++) {
                    int newr = i + dr[k];
                    int newc = j + dc[k];

                    if (isvalid(newr, newc, n) && grid[newr][newc] == 1) {
                        int nodeno = i * n + j;
                        int adjnodeno = newr * n + newc;
                        ds.unionBySize(nodeno, adjnodeno);
                    }
                }
            }
        }

        int mx = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) continue;

                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, -1, 0, 1};
                set<int> components;

                for (int k = 0; k < 4; k++) {
                    int newr = i + dr[k];
                    int newc = j + dc[k];

                    if (isvalid(newr, newc, n)) {
                        if (grid[newr][newc] == 1) {
                            components.insert(ds.findUPar(newr * n + newc));
                        }
                    }
                }
                int sizetotal = 0;
                for (auto it : components) {
                    sizetotal += ds.size[it];
                }
                mx = max(mx, sizetotal + 1);
            }
        }
        
        if (mx == 0 && n > 0) {
            for (int cellno = 0; cellno < n * n; cellno++) {
                mx = max(mx, ds.size[ds.findUPar(cellno)]);
            }
        }

        return mx;
    }
};