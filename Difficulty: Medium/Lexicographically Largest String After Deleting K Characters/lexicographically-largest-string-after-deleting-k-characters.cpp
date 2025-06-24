class Solution {
  public:
    string maxSubseq(string& s, int k) {
        // code here
      std::vector<char> stack;
        for(char c: s) {
            while (k > 0 && stack.size() > 0 && stack.back() < c) {
                stack.pop_back();
                k--;
            }
            stack.push_back(c);
        }
        while(k > 0 && stack.size() > 1) {
            stack.pop_back();
            k--;
        }
        return std::string(stack.begin(), stack.end());
    }
};
