//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    pair<long,long> indexes(vector<long long> v, long long x)
    {
    long long n = v.size();
    long long left = -1, right = -1;
    long long low = 0, high = n - 1;
    while (low <= high) {
        long long mid = low + (high-low) / 2;
        if (v[mid] == x) {
            left = mid;         
            high = mid - 1;     
        } else if (v[mid] < x) {
            low = mid + 1;     
        } else {
            high = mid - 1;    
        }
    }

    low = 0, high = n - 1;
    while (low <= high) {
        long long mid = low+(high- low) /2;
        if (v[mid]==x){
            right = mid;        
            low = mid + 1;     
        } else if (v[mid] < x) {
            low = mid + 1;    
        } else {
            high = mid - 1;   
        }
    }

    if (left == -1) {
        return {-1, -1};
    }
    return {left, right};
    }
};

//{ Driver Code Starts.

int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        vector<long long>v;
        cin>>n;
        for(long long i=0;i<n;i++)
        {
            cin>>k;
            v.push_back(k);
        }
        long long x;
        cin>>x;
        Solution obj;
        pair<long,long> pair = obj.indexes(v, x);
        
        if(pair.first==pair.second and pair.first==-1)
        cout<< -1 <<endl;
        else
        cout<<pair.first<<" "<<pair.second<<endl;

    
cout << "~" << "\n";
}
	return 0;
}

// } Driver Code Ends