class Solution {
public:
    bool func(const std::vector<int>& arr, int k, int x) {
        long long sum = 0;
        for (int val : arr) {
            sum += (val + x - 1) / x;
        }
        return sum <= k;
    }

    int smallestDivisor(std::vector<int>& arr, int k) {
        int low = 1;
        int high = 0;
        for (int num : arr) {
            if (num > high) {
                high = num;
            }
        }

        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (func(arr, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};