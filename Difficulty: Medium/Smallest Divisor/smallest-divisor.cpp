//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int computeSum(const vector<int>& arr, int divisor) {
    int sum = 0;
    for (int num : arr) {
        sum += (num + divisor - 1) / divisor; 
    }
    return sum;
}
    int smallestDivisor(vector<int>& arr, int k) {

        int left = 1, right = *max_element(arr.begin(), arr.end());
    int result = right;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        int sum = computeSum(arr, mid);

        if (sum <= k) {
            result = mid;
            right = mid - 1; 
        } else {
            left = mid + 1; }
    }

    return result;
    }
};


//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.smallestDivisor(arr, d);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends