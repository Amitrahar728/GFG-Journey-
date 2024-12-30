//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool Search(vector<int>& arr, int k) {
        int low =0;
        int high = arr.size()-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if (arr[mid] == k) return true;
            if(arr[low] == arr[mid ] && arr[mid]== arr[high]){
                low = low+1;
                high = high -1;
                continue;
            }
            if (arr[low]<= arr[mid]){
                if (k>=arr[low] && k<arr[mid]) {
                        high=mid- 1;
                } 
                else{
                    low = mid + 1;
                }
            }
            else{
                if(k>arr[mid] && k<=arr[high]){
            low =mid+ 1;
                } 
                else{
                high=mid-1;}
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        bool res = obj.Search(arr, k);
        if (res)
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends