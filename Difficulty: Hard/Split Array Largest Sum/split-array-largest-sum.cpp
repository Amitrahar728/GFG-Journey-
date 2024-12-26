//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isValid(int arr[], int n, int k, int maxSum) {
    int subarrayCount = 1;
    int currentSum = 0;

    for (int i = 0; i < n; i++) {
        if (currentSum + arr[i] > maxSum){
            subarrayCount++;
            currentSum = arr[i];
            if (subarrayCount > k) {
                return false;
            }
        }
        else {
            currentSum += arr[i];
        }
    }

    return true;
    }
    int splitArray(int arr[] ,int N, int K) {
        int low = *max_element(arr, arr + N);
    int high = accumulate(arr, arr + N, 0); 
    int result = high;

    while (low <= high) {
        int mid=low+(high-low)/2;
        if (isValid(arr, N, K, mid)) {
            result=mid; 
            high=mid-1;
        } 
        else{
            low=mid+1;
        }
    }
    return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends