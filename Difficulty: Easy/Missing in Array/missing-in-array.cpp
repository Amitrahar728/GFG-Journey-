//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int missingNum(vector<int>& arr) {
       int n = arr.size() + 1; // size is n-1
    long long total_sum = 1LL * n * (n + 1) / 2; // use long long to prevent overflow
    long long array_sum = 0;
    for (int num : arr) {
        array_sum += num;
    }
    return (int)(total_sum - array_sum);}
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.missingNum(a) << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends