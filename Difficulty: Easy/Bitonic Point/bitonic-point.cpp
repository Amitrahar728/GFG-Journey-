//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int findMaximum(vector<int> &arr) {
        // code here
        int low = 0, high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Check if mid is the bitonic point
        if ((mid == 0 || arr[mid] > arr[mid - 1]) && 
            (mid == arr.size() - 1 || arr[mid] > arr[mid + 1])) {
            return arr[mid];
        }

        // Move to the side where the bitonic point could be
        if (mid < arr.size() - 1 && arr[mid] < arr[mid + 1]) {
            low = mid + 1; // Right half
        } else {
            high = mid - 1; // Left half
        }
    }
    return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        int value;

        // Read the entire line of integers
        string line;
        // cin.ignore(); // Ignore the newline after the test case input
        getline(cin, line);
        stringstream ss(line);

        // Parse integers and add them to the vector
        while (ss >> value) {
            arr.push_back(value);
        }

        Solution ob;
        auto ans = ob.findMaximum(arr);
        cout << ans << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends