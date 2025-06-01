// User function template for C++
class Solution {
  public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr) {
        int n = arr.size();
        int max = INT_MIN;
        for(int i =0; i<n; i++){
            if(arr[i]>max){
                max = arr[i];
            }
        }
        int b = INT_MIN;
        for(int i =0; i<n; i++){
            if(arr[i]>b  && arr[i]!=max){
                b = arr[i];
            }
        }
        if(b == INT_MIN)return -1;
        else return b;
    }
    //     sort(arr.begin(),arr.end());
    //     int a = arr[n-1];
    //     for(int i = n-2; i>=0; i--){
    //         if(arr[i] != a){
    //             return arr[i];
    //             break;
    //         }
            
    //     }
    //     return -1;
    // }
};