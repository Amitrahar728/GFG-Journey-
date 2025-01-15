//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isFeasible(const vector<int>& stations, int k, double d) {
    int count = 0;
    for (int i = 0; i < stations.size() - 1; ++i) {
        count += floor((stations[i + 1] - stations[i]) / d);
    }
    return count <= k;
}

double findSmallestMaxDist(vector<int>& stations, int k) {
    double low = 0, high = *max_element(stations.begin() + 1, stations.end()) - stations[0];
    double result = high;
    while (high - low > 1e-6) {
        double mid = (low + high) / 2;
        if (isFeasible(stations, k, mid)) {
            result = mid;
            high = mid;
        } else {
            low = mid;
        }
    }
    return round(result * 100) / 100.0;
}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> stations(n);
        for (int i = 0; i < n; i++) {
            cin >> stations[i];
        }
        int k;
        cin >> k;
        Solution obj;
        cout << fixed << setprecision(2) << obj.findSmallestMaxDist(stations, k)
             << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends