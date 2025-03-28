//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool place (vector<int> arr , int mid , int k  ){
    int cnt = 1;
    int last = arr[0];
    for(int i =1; i<arr.size(); i++){
        if((arr[i]-last)>=mid){
            cnt ++;
            last = arr[i];
        }

    }
    if(cnt >=k){
        return true;
    }
    else return false;
    }


    int aggressiveCows(vector<int> &stalls, int k) {
// --------------------------------------BRUTE APPROACH(LINEAR SEARCH)--------------------------------------------------

        sort(stalls.begin(), stalls.end());
        int n = stalls.size();
        int low =0;
        int high = stalls[n-1]-stalls[0];
        // int ans = 1;
        while(low<=high){
             int mid = (low+high)/2;
             if (place(stalls, mid, k)) {
                // ans = mid;
                low = mid + 1;
             }
              else
                high = mid - 1;
         }
         return high ;
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string in;
        getline(cin, in);
        stringstream sss(in);
        int num;
        while (sss >> num) {
            k = num;
        }
        Solution ob;
        int ans = ob.aggressiveCows(arr, k);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends