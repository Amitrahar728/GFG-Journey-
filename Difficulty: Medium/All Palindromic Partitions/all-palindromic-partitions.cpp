class Solution {
public:
    bool isPalindrome(const std::string& s) {
        int left = 0;
        int right = s.length() - 1;
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    void backtrack(const std::string& s, int start, std::vector<std::string>& currentPartition, std::vector<std::vector<std::string>>& result) {
        if (start == s.length()) {
            result.push_back(currentPartition);
            return;
        }

        for (int i = start; i < s.length(); ++i) {
            std::string sub = s.substr(start, i - start + 1);
            if (isPalindrome(sub)) {
                currentPartition.push_back(sub);
                backtrack(s, i + 1, currentPartition, result);
                currentPartition.pop_back();
            }
        }
    }

    std::vector<std::vector<std::string>> palinParts(std::string &s) {
        std::vector<std::vector<std::string>> result;
        std::vector<std::string> currentPartition;
        backtrack(s, 0, currentPartition, result);
        return result;
    }
};