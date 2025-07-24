class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int maxi = *max_element(arr.begin(), arr.end());
        int sec =-1;
        for(int i =0; i<arr.size(); i++){
            if(arr[i]>sec && arr[i]!= maxi){
                sec = arr[i];
            }
        }
        return sec;
    }
};