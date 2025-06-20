#include <vector>
#include <map>
#include <algorithm>

class Solution {
public:
    bool validgroup(std::vector<int> &arr, int k) {
        if (arr.size() % k != 0) {
            return false;
        }

        std::map<int, int> freqMap;
        for (int num : arr) {
            freqMap[num]++;
        }

        // Changed loop syntax for C++11/14 compatibility
        for (auto const& entry : freqMap) {
            int current_val = entry.first;
            int count = entry.second;

            if (count == 0) {
                continue;
            }

            int num_groups_to_form_starting_here = count;

            for (int i = 0; i < k; ++i) {
                int required_consecutive_num = current_val + i;

                if (freqMap.find(required_consecutive_num) == freqMap.end() ||
                    freqMap[required_consecutive_num] < num_groups_to_form_starting_here) {
                    return false;
                }

                freqMap[required_consecutive_num] -= num_groups_to_form_starting_here;
            }
        }
        return true;
    }
};