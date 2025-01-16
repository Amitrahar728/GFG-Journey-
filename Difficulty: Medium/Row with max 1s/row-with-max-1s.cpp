//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int search (vector<int> arr , int n ){
    int low =0;
    int high = n-1;
    int ans = n ;
    while (low <=high){
        int mid = (low +high)/2;
        if (arr[mid] == 1) {
          ans = mid;
          high = mid - 1;
        } else
          low = mid + 1;
    }
    return ans;
}
    int rowWithMax1s(vector<vector<int>> &arr) {
        int cnt =  arr[1].size();
        int n = arr.size();
        int m = cnt;
        int ind = -1;
        for(int i =0; i<n ; i++){
        int cnt1 = search(arr[i], m );
        if(cnt1 < cnt ){
            cnt = cnt1;
            ind = i;
        }
    }
    return ind;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after the integer input
    while (t--) {
        string input;
        getline(cin, input);
        vector<vector<int>> mat;
        string innerArray;
        bool isInsideArray = false;

        for (char c : input) {
            if (c == '[') {
                if (isInsideArray) {
                    innerArray.clear();
                }
                isInsideArray = true;
            } else if (c == ']') {
                if (isInsideArray && !innerArray.empty()) {
                    vector<int> row;
                    stringstream ss(innerArray);
                    int num;

                    while (ss >> num) {
                        row.push_back(num);
                        if (ss.peek() == ',')
                            ss.ignore();
                        while (isspace(ss.peek()))
                            ss.ignore();
                    }

                    mat.push_back(row);
                    innerArray.clear();
                }
                isInsideArray = false;
            } else if (isInsideArray) {
                if (!isspace(c)) {
                    innerArray += c;
                }
            }
        }

        Solution obj;
        cout << obj.rowWithMax1s(mat);
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends