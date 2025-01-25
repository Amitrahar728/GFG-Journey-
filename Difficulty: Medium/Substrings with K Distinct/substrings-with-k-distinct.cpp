//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
  int mostK(const string& s, int k) {
    unordered_map<char, int> freq;
    int l= 0,cnt= 0;

    for (int r = 0; r< s.length(); ++r){
        freq[s[r]]++;

        while (freq.size()> k) {
            freq[s[l]]--;
            if (freq[s[l]] == 0) {
                freq.erase(s[l]);
            }
            l++;
        }
        cnt+=(r -l+ 1);
    }

    return cnt;
}
    int countSubstr(string& s, int k) {
        return mostK(s, k)-mostK(s, k - 1);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.countSubstr(s, k) << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends