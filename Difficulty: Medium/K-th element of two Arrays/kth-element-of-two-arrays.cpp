//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        int n = a.size();
        int m = b.size();
        if (m < n) return kthElement(b, a,  k);


    int left = k;

   
    int low = max(0, k - n), high = min(k, m);
    while (low <= high) {
        int mid1 = (low + high) >> 1;
        int mid2 = left - mid1;
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;
        l1 = (mid1 == 0) ? INT_MIN : b[mid1 - 1];
        r1 = (mid1 == m) ? INT_MAX : b[mid1];
        l2 = (mid2 == 0) ? INT_MIN : a[mid2 - 1];
         r2 = (mid2 == n) ? INT_MAX : a[mid2];


        if (l1 <= r2 && l2 <= r1) {
            return max(l1, l2);
        }

        else if (l1 > r2) high = mid1 - 1;
        else low = mid1 + 1;
    }
    return -1;
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> a, b;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            b.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(a, b, k) << endl << "~\n";
    }
    return 0;
}
// } Driver Code Ends