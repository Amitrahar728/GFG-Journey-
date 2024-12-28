//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User-function template for C++

// Complete the function
// n: Input n
// Return True if the given number is a lucky number else return False

class Solution{
public:
    bool isLucky(int n) {
        vector<int> numbers;
    for (int i = 1; i <= n; i++) {
        numbers.push_back(i);
    }

    int i = 2; 
    while (i <= numbers.size()) {
        vector<int> temp;
        for (int j = 0; j < numbers.size(); j++) {
            if ((j + 1) % i != 0) { 
                temp.push_back(numbers[j]);
            }
        }
        numbers = temp;  i++;
    }
    for (int num : numbers) {
        if (num == n) {
            return 1;
        }
    }
    return 0;
    }
};

//{ Driver Code Starts.
signed main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        Solution obj;
        //calling isLucky() function
        if(obj.isLucky(n))
            cout<<"1\n";//printing "1" if isLucky() returns true
        else
            cout<<"0\n";//printing "0" if isLucky() returns false
    
cout << "~" << "\n";
}
    
}
// } Driver Code Ends