class Solution {
  public:
    string findOrder(vector<string> &words) {
        unordered_map<char, set<char>> graph;
        unordered_map<char, int> indegree;

        // Initialize graph
        for (string word : words) {
            for (char c : word) {
                graph[c];
            }
        }

        // Build the graph from adjacent word pairs
        for (int i = 0; i < words.size() - 1; i++) {
            string w1 = words[i];
            string w2 = words[i + 1];
            int len = min(w1.size(), w2.size());
            bool found = false;

            for (int j = 0; j < len; j++) {
                if (w1[j] != w2[j]) {
                    char u = w1[j], v = w2[j];
                    if (!graph[u].count(v)) {
                        graph[u].insert(v);
                        indegree[v]++;
                    }
                    found = true;
                    break;
                }
            }

            if (!found && w1.size() > w2.size()) return "";
        }

        // Topological sort (Kahn's algorithm)
        queue<char> q;
        for (auto it = graph.begin(); it != graph.end(); ++it) {
            char c = it->first;
            if (indegree[c] == 0) {
                q.push(c);
            }
        }

        string result;
        while (!q.empty()) {
            char curr = q.front(); q.pop();
            result += curr;

            for (char neighbor : graph[curr]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        if (result.size() != graph.size()) return "";
        return result;
    }
};
