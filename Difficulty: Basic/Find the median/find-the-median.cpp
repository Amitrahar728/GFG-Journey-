//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int findMedian(vector<int> &arr) {
       sort(arr.begin(), arr.end());

    int n = arr.size();

    // Check for even or odd length
    if (n % 2 == 1) {
        return arr[n / 2]; // Middle element for odd size
    } else {
        // Floor of the average for even size
        return (arr[n / 2 - 1] + arr[n / 2]) / 2;
    }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        vector<int> arr;
        while (ss >> num)
            arr.push_back(num);

        Solution ob;
        cout << ob.findMedian(arr) << endl;
    }
}

// } Driver Code Ends