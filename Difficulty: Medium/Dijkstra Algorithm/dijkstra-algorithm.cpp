// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int, int>>> adj(V);
        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w}); 
        }

        set<pair<int,int>> st;
        vector<int> dist(V,1e9); // pura dist vector ko infinite value assign krdi 
        
        st.insert({0,src});// pehli value add krdi set m 
        dist[src] = 0;// yaha enter krliya src node ka distance 
        
        while(!st.empty()){
            auto it = *(st.begin()); // we will get the value the pointer is pointing to.
            int node = it.second; // node value fetch krli 
            int dis = it.first; // distance value fetch krli top element ki jo sbse chota hai distance m 
            st.erase(it); // fir usko remove krdiya vaha se
            
            for(auto &it : adj[node]){ // uss particular node jo top pr thi uske saare neighbours k pass jana hai and uke nodes ki value leni hai 
                int adjnode = it.first;
                int edg = it.second;
                
                if(dis+edg <dist[adjnode]) {
                    // agar chota distance mil jaye jo pehle se h usko erase kro and isko add kro 
                    if(dist[adjnode] != 1e9)
                            st.erase({dist[adjnode], adjnode});
                            
                    dist[adjnode] = dis +edg;
                    st.insert({dist[adjnode], adjnode});
                }
            }
        }
        return dist ;
    }
};