#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map <int, int> prev_seen;
        for (int i = 0; i < nums.size(); i++){

            int num = nums[i];
            int remainder = target - num;

            if (prev_seen.contains(remainder)){
                return {prev_seen[remainder], i};
            }

            prev_seen[num] = i;
        }

    }
};
