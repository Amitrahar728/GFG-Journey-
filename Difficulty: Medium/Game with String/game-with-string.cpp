#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <numeric>

class Solution {
public:
    int minValue(string &s, int k) {
       unordered_map<char, int> M;
        for (char c : s) {
            M[c]++;
        }

        priority_queue<int> pq;
        for (auto it: M) {
            pq.push(it.second);
        }

        while (k > 0 && !pq.empty()) {
            int top_freq = pq.top();
            pq.pop();
            top_freq--;
            if (top_freq > 0) {
                pq.push(top_freq);
            }
            k--;
        }

        int ans = 0;
        while (!pq.empty()) {
            int freq = pq.top();
            pq.pop();
            ans += freq * freq;
        }
        return ans;
    }
};