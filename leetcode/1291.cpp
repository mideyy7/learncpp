
#include "include.h"

class Solution {
public:
/*

Note that start is limited by lengtth
the length limits where the start positin can begin from so it does not go out of bounds
if length is 2: start goes from 0-7 inclusive
if kength is 3: start goes from 0-6 inclusive

*/
    vector<int> sequentialDigits(int low, int high) {
        std::string digits = "123456789";
        vector<int> result;
        for (int length = 2; length <= 9; length++) {
            for (int start = 0; start <= 9 - length; start++) {
                int digit = stoi(digits.substr(start, length));
                if (digit >= low && digit <= high) {
                    result.push_back(digit);
                }

            }
        }
        return result;
        
    }
};