class Solution {
public:
    int catchThieves(vector<char>& arr, int k) {
        int n = arr.size();
        vector<int> p;
        vector<int> t;

        for(int i =0; i< n; i++){
            if(arr[i] =='P'){
                p.push_back(i);
            } else if (arr[i] == 'T') {
                t.push_back(i);
            }
        }

        int cnt = 0;
        int cntp= 0;
        int cntt = 0;

        while(cntp<p.size() && cntt<t.size()){
            if(abs(p[cntp] - t[cntt])<=k){
                cnt++;
                cntp++;
                cntt++;
            } 
            else if(p[cntp]< t[cntt]){
                cntp++;
            } else {
                cntt++;
            }
        }
        return cnt;
    }
};