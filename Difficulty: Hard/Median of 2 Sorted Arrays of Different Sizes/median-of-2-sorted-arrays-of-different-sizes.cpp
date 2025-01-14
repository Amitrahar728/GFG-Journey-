//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    double medianOf2(vector<int>& a, vector<int>& b) {
        if (a.size() > b.size()) {
            return medianOf2(b, a);
        }
        
        int m = a.size();
        int n = b.size();
        int low = 0, high = m;
        
        while (low <= high) {
            int i = (low + high) / 2;
            int j = (m + n + 1) / 2 - i;

            int aLeft = (i == 0) ? INT_MIN : a[i - 1];
            int aRight = (i == m) ? INT_MAX : a[i];
            int bLeft = (j == 0) ? INT_MIN : b[j - 1];
            int bRight = (j == n) ? INT_MAX : b[j];

            if (aLeft <= bRight && bLeft <= aRight) {
                if ((m + n) % 2 == 0) {
                    return (max(aLeft, bLeft) + min(aRight, bRight)) / 2.0;
                } else {
                    return max(aLeft, bLeft);
                }
            } else if (aLeft > bRight) {
                high = i - 1;
            } else {
                low = i + 1;
            }
        }
        
        return 0.0;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline after reading `t`

    while (t--) {
        // Read the first array
        string line1;
        getline(cin, line1);
        stringstream ss1(line1);

        vector<int> array1;
        int num;
        while (ss1 >> num) {
            array1.push_back(num);
        }

        // Read the second array
        string line2;
        getline(cin, line2);
        stringstream ss2(line2);

        vector<int> array2;
        while (ss2 >> num) {
            array2.push_back(num);
        }

        // Create a Solution object and calculate the median
        Solution ob;
        if (array2.size() == 1 && array2[0] == 0) {
            array2.pop_back();
        }

        double ans = ob.medianOf2(array1, array2);
        if (ans == (int)ans) {
            cout << (int)ans << endl;
        } else {
            cout << ans << endl;
        }

        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends