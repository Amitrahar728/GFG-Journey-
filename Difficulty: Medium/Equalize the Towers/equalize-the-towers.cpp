#include <vector>
#include <algorithm>
#include <climits> 

struct T {
    int h;
    int c;

    bool operator<(const T& o) const {
        return h < o.h;
    }
};

class Solution {
public:
    long long minCost(vector<int>& heights, vector<int>& costs) {
        int n = heights.size();
        
        vector<T> towers(n);
        for (int i = 0; i < n; ++i) {
            towers[i] = {heights[i], costs[i]};
        }

        sort(towers.begin(), towers.end());

        vector<long long> pc(n);
        vector<long long> pwh(n);

        pc[0] = towers[0].c;
        pwh[0] = (long long)towers[0].h * towers[0].c;

        for (int i = 1; i < n; ++i) {
            pc[i] = pc[i-1] + towers[i].c;
            pwh[i] = pwh[i-1] + (long long)towers[i].h * towers[i].c;
        }

        long long tc = pc[n-1];
        long long twh = pwh[n-1];

        long long minC = LLONG_MAX;

        for (int i = 0; i < n; ++i) {
            int currentH = towers[i].h;

            long long cL = 0;
            if (i > 0) {
                cL = (long long)currentH * pc[i-1] - pwh[i-1];
            }

            long long cR = 0;
            if (i < n - 1) {
                long long rC = tc - pc[i]; 
                long long rWH = twh - pwh[i]; 
                
                cR = rWH - (long long)currentH * rC;
            }
            
            minC = min(minC, cL + cR);
        }

        return minC;
    }
};