//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    // Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string& s) {
        int arr[26] ={0};
        for(int  i =0; i<s.length(); i++){
            char ch = s[i];
            int number =0;
            if(ch>='a' && ch<='z'){
                number = ch-'a';
                
            }
            else {
                number = ch-'A';
                
            }
            arr[number]++;
            
        }
        int maxi = -1;
        int ans =0;
        for(int i =0; i<26; i++){
            if(maxi<arr[i]){
                ans =i;
                maxi = arr[i];
                
            }
        }
        char finalans = 'a'+ans;
        return finalans;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution obj;
        cout << obj.getMaxOccuringChar(str) << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends