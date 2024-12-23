//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    int maxSweetness(vector<int>& sweetness, int N, int K) {
        int low = 1;
        int high = accumulate(sweetness.begin(), sweetness.end(), 0); 
        int result = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canDivide(sweetness, N, K, mid)) {
                result = mid;
                low = mid + 1; 
            } else {
                high = mid - 1; 
            }
        }

        return result;
    }

private:
    bool canDivide(vector<int>& sweetness, int N, int K, int minSweetness) {
        int currentSum = 0, pieces = 0;

        for (int i = 0; i < N; i++) {
            currentSum += sweetness[i];
            if (currentSum >= minSweetness) {
                pieces++;
                currentSum = 0;
            }}
        return pieces >= K + 1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> sweetness(n);
        for (int i = 0; i < n; i++) {
            cin >> sweetness[i];
        }
          Solution ob;
          int res=ob.maxSweetness(sweetness, n, k);
        cout << res << endl;
    
cout << "~" << "\n";
}
}
// } Driver Code Ends