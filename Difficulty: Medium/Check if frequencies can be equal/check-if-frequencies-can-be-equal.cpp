#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool sameFreq(string& s) {
        unordered_map<char, int> mpp;
        for(char c : s) {
            mpp[c]++;
        }
        
        map<int, int> freqCount;
        for(auto& it : mpp) {
            freqCount[it.second]++;
        }
        
        if(freqCount.size() == 1) {
            return true; // All frequencies are already equal
        }
        if(freqCount.size() > 2) {
            return false; // Need to remove more than one character
        }
        
        auto it = freqCount.begin();
        int firstFreq = it->first;
        int firstCount = it->second;
        int secondFreq = (++it)->first;
        int secondCount = it->second;
        
        // Case 1: One of the frequencies is 1 and occurs only once
        if((firstFreq == 1 && firstCount == 1) || (secondFreq == 1 && secondCount == 1)) {
            return true;
        }
        
        if(abs(firstFreq - secondFreq) == 1 && 
           ((firstFreq > secondFreq && firstCount == 1) || 
            (secondFreq > firstFreq && secondCount == 1))) {
            return true;
        }
        
        return false;
    }
};