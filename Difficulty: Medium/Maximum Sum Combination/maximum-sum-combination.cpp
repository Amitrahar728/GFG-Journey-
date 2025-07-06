#include <vector>
#include <algorithm>
#include <queue>
#include <set>

class Solution {
public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        vector<int> arr;

        int n = a.size();
        int m = b.size();

        if (k <= 0 || n == 0 || m == 0) {
            return arr;
        }

        priority_queue<pair<int, pair<int, int>>> pq;

        set<pair<int, int>> visited_pairs;

        pq.push({a[n - 1] + b[m - 1], {n - 1, m - 1}});
        visited_pairs.insert({n - 1, m - 1});

        while (k > 0 && !pq.empty()) {
            pair<int, pair<int, int>> current = pq.top();
            pq.pop();

            arr.push_back(current.first);
            k--;

            int i = current.second.first;
            int j = current.second.second;

            if (i > 0 && visited_pairs.find({i - 1, j}) == visited_pairs.end()) {
                pq.push({a[i - 1] + b[j], {i - 1, j}});
                visited_pairs.insert({i - 1, j});
            }

            if (j > 0 && visited_pairs.find({i, j - 1}) == visited_pairs.end()) {
                pq.push({a[i] + b[j - 1], {i, j - 1}});
                visited_pairs.insert({i, j - 1});
            }
        }

        return arr;
    }
};