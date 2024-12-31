//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
        int trailingZeroes(int x) {
        int count = 0;
        int factor = 5;
        while (x >= factor) {
            count += x / factor;
            factor *= 5;
        }
    return count;
    }
        int findNum(int n)
        {
            if (n == 0) return 0;
        int low = 0, high = 5 * n;
        int result = 0;
    
        while (low < high) {
            int mid = low + (high - low) / 2; 
            if (trailingZeroes(mid) >= n) {
                 high = mid; 
        } 
            else {
                low = mid + 1; 
        }
    }
    
    return low; 
    }
};

//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Solution ob;
        cout <<ob.findNum(n) << endl;
    
cout << "~" << "\n";
}
return 0;
}
// } Driver Code Ends