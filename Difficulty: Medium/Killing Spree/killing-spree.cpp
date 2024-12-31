//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    long long int killinSpree(long long int n)
    {
        int count = 0;
    long long i = 1;

    while(n >= i * i) {
        n -= i * i;
        count++;
        i++;
    }

    return count;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int n; cin>>n;
        Solution obj;
        long long int ans = obj.killinSpree(n);
        cout<<ans<<"\n";
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends