#include "include.h"

class Solution {
public:
    int count_bits(int val) {
        int result = 0;
        while (val) {
            result += val & 1; // set selected bits to 0 without affectinmg other bits.. 0000001 makes the rest of the bits 0 apart from the last 1 which reflects if it is 0 or 1
            val >>= 1;  // shift right by 1 drops the last bit as we have counted it
        }
        return result;

    }
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> result;
        for (int h = 0; h < 12; h++) {
            for (int m = 0; m < 60; m++) {
                if (count_bits(h) + count_bits(m) == turnedOn) {
                    string temp = to_string(h) + ":";
                    if (m < 10) temp += "0";
                    temp += to_string(m);
                    result.push_back(temp);
                }
            }
        }
        return result;
    }
    
};