//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
  public:
    vector<int> farNumber(int N,vector<int> Arr){
    vector<int> minRight(N);
    minRight[N - 1] = Arr[N - 1];
    for (int i = N - 2; i >= 0; --i){
        minRight[i] = min(minRight[i + 1], Arr[i]);
    }
    vector<int> result(N, -1);
    for (int i = 0; i < N; ++i) {
        int low = i + 1, high = N - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (minRight[mid] < Arr[i]) {
                result[i] = mid; 
                low = mid + 1;  
            } else {
                high = mid - 1;
            }
        }
    }

    return result;
    }
};

//{ Driver Code Starts.
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        vector<int> Arr(N);
        for(int i=0;i<N;i++)
            cin>>Arr[i];
        Solution obj;
        vector<int> answer=obj.farNumber(N,Arr);
        for(auto i:answer)
            cout<<i<<" ";
        cout<<endl;
  
cout << "~" << "\n";
}
}
// } Driver Code Ends