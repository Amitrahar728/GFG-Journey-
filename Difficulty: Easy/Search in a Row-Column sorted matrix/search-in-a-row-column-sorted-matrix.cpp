//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    bool matSearch(vector<vector<int>> &mat, int x) {
-----------------------------------BINARY
        // int n   = mat.size(); int m = mat[0].size();
        // if (n == 0) return false;
        // if (m == 0) return false;
        // long long low =0; long long high = n*m-1;
        // while(low<=high){
        //     long long mid = low +(high - low)/2;
        //     int row = mid/m;
        //     int col = mid%m;
        //     if(mat[row][col] == x) return true;
        //     else if(mat[row][col]< x) low = mid+1;
        //     else high = mid -1;
        // }
        // return  false ;
        
         int n = mat.size();
        if (n == 0) return false; 
        int m = mat[0].size();
        if (m == 0) return false; 

        
        int row = 0, col = m - 1;

        while (row < n && col >= 0) {
            if (mat[row][col] == x) {
                return true; 
            } else if (mat[row][col] < x) {
                row++;
            } else {
                col--;
            }
        }

        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c, 0));
        int x;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }
        cin >> x;
        Solution ob;
        bool an = ob.matSearch(matrix, x);
        if (an)
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends