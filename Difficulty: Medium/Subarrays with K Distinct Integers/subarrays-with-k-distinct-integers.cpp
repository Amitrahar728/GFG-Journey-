//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int atMostK(vector<int> &arr, int k) {
        int l = 0, r = 0, cnt = 0;
        unordered_map<int, int> mpp;

        while (r < arr.size()) {
            mpp[arr[r]]++;
            
            while (mpp.size() > k) {
                mpp[arr[l]]--;
                if (mpp[arr[l]] == 0) {
                    mpp.erase(arr[l]);
                }
                l++;
            }
            
            cnt += (r - l + 1);
            r++;
        }

        return cnt;
    }

    int exactlyK(vector<int> &arr, int k) {
        return atMostK(arr, k) - atMostK(arr, k - 1);
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        int k;
        cin >> k;
        cin.ignore();
        Solution obj;
        cout << obj.exactlyK(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends