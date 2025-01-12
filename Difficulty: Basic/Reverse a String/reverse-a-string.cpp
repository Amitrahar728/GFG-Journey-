//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string reverseString(string& s) {
        string reversed = s;
        
        reverse(reversed.begin(), reversed.end());
        return reversed;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.reverseString(s) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends