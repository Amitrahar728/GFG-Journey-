//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    // Function to find maximum product subarray
    int maxProduct(vector<int> &arr) {
        int n = arr.size();
// -------------------BRUTE FORCE APPROACH--------------------------------------------------------------
        // int res = arr[0];
        // for (int i =0; i<n ; i++){
        //     int pro =1;
        //     for(int j =i; j<n; j++){
        //         pro*=arr[j];
        //         if(pro > res){
        //             res = pro;
        //         }
        //     }
        // }
        // return res ;
        
// ------------------------OPTIMAL APPROACH ----------------------------------------------------
    //   --> Two cases :
    //   1.) if arr[i] == 0 (Reset the product to zero )
    //   2.) if arr[i] == any negative number (therefore maintain a and b )
       
       
        int a = arr[0];
        int b = arr[0];
        int c = arr[0];
        for(int i = 1;i<n; i++){
            
        // a = max({arr[i], arr[i]*b, arr[i]*a});
        // b = min({arr[i], arr[i]*b , arr[i]*a});
        // int t = a;
        // c = max(c, t );
        
        // }
        // return c;
        
        
        if (arr[i]<0) {
            swap(a, b);
        }
        a = max(arr[i],arr[i]*a);
        b = min(arr[i],arr[i]*b);

        c = max(c, a);
        }
        return c;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // int n, i;
        // cin >> n;
        // vector<int> arr(n);
        // for (i = 0; i < n; i++) {
        //     cin >> arr[i];
        // }

        vector<int> arr;
        string input;

        // Read array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        auto ans = ob.maxProduct(arr);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends