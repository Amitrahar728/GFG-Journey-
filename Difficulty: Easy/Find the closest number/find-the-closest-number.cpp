//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int findClosest(vector<int>& arr, int k) {
    int n = arr.size();
    int l= 0, r =n-1;
    int c=arr[0];
    while(l<=r){
        int mid =l+(r-l)/2;

        if (abs(arr[mid]-k)<abs(c-k)||abs(arr[mid]-k)==abs(c-k)&& arr[mid]>c){
            c=arr[mid];}
        if(arr[mid]<k){
            l=mid+1;
        } 
        else{
            r=mid - 1;
        }
    }return c;
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.findClosest(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends