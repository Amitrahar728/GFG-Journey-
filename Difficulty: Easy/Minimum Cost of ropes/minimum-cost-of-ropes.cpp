//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int minCost(vector<int>& arr) {
        priority_queue<long long , vector<long long > , greater<long long >> pq;
        for(int i =0; i<arr.size(); i++){
            pq.push(arr[i]);
        }
        
        long long cost =0;
        while(pq.size()>1){
            long long a = pq.top();
            pq.pop();
            long long b = pq.top();
            pq.pop();
            long long sum = a+b;
            cost+=sum;
            pq.push(sum);
        }
        return cost;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> a;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        cout << ob.minCost(a) << endl;
        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends