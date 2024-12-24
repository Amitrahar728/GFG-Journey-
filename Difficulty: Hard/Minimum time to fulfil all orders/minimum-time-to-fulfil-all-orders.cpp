//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    
    bool isPossible(int p, vector<int>& cook, int n, int mid)
{
    int cnt = 0;
    for (int i = 0; i < n; i++) {

        int c = 0;
        int time = mid;
 
        
        int perpratas = cook[i];
        while (time > 0) {
            time = time - perpratas;
            if (time >= 0) {
                c += 1;
                perpratas += cook[i];
            }
        }
        cnt += c;
        if (cnt >= p)
            return true;
    }
 
    return false;
}
    int findMinTime(int N, vector<int>&A, int L){
        int s = 0, e = 10000007;
    int mid, ans = -1;
 

    while (s <= e) {
        mid = (s + e) / 2;
        if (isPossible(N, A, L, mid)) {
            ans = mid;
            e = mid - 1;
        }
        else {
            s=mid+1;
        }
    }
 
    return ans;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    int l;
	    cin >> l;
	    vector<int>arr(l);
	    for(int i = 0; i < l; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    int ans = ob.findMinTime(n, arr, l);
	    cout << ans <<endl;
	
cout << "~" << "\n";
}
	return 0;
}

// } Driver Code Ends