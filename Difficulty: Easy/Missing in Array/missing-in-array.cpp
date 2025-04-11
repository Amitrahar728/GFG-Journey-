//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
//   bool find(vector<int> arr, int x){
//       for(int  i =0; i<arr.size(); i++){
//           if(x == arr[i]){
//               return false ;
//           }
//       }
//       return true;
//   }
    int missingNumber(vector<int>& arr) {
      long long n = arr.size() + 1;
    long long total = n * (n + 1) / 2;
    long long sum = 0;
    for (int num : arr) sum += num;
    return (int)(total - sum);

    }
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
        cout << obj.missingNumber(a) << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends