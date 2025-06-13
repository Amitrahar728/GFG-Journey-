class Solution {
  public:
    int kokoEat(vector<int>& arr, int k) {
        int low = 1;
        int high = *max_element(arr.begin(), arr.end());
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long hoursNeeded = 0;

            for (int bananas : arr) {
                hoursNeeded += (bananas + mid - 1) / mid;  }

            if (hoursNeeded <= k) {
                ans = mid;         
                high = mid - 1;
            } else {
                low = mid + 1;      
            }
        }

        return ans;
    }
};
