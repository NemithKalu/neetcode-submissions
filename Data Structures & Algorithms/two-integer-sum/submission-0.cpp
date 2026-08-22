#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map <int, int> prev_seen;
        int first_index;
        int second_index;

        for (int i = 0; i < nums.size(); i++){

            int num = nums[i];
            int remainder = target - num;

            if (prev_seen.contains(remainder)){
                second_index = i;
                first_index = prev_seen[remainder];
                return {first_index, second_index};
            }

            prev_seen[num] = i;
        }

    }
};
