//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string baseEquiv(int n, int m){
        for (int base = 2; base <= 32; ++base){
            
        int digits = 0, temp = n;
        while (temp>0){
            temp/=base;
            ++digits;}
        if(digits==m){
            return "Yes";
            
        }}
        
        return "No";
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        Solution ob;
        cout<<ob.baseEquiv(n,m)<<endl;
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends