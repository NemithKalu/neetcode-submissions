#include <algorithm>

using namespace std;

class Solution {
public:

    int getNextIndex(int current_index, int increment, vector<int>& sorted_nums){
        
        int next_index = current_index;
        // iterate through similar values to avoid having duplicate entries     
        do{
            next_index += increment;

            // catch going out of bounds
            if (next_index == 0 || next_index == sorted_nums.size()) return next_index;
        } while (sorted_nums[next_index] == sorted_nums[current_index]);

        return next_index;

    }


    vector<vector<int>> getNegatingPairs(int current_index, vector<int>& sorted_nums) {

        // initialize 2 pointers at index + 1 and the end of the sorted array
        // don't traverse the whole array as you will get duplicates
        int left = current_index + 1;
        int right = sorted_nums.size() - 1;
        
        int target = 0 - sorted_nums[current_index];
        vector<vector<int>> negating_pairs;

        while (left < right) {

            // decrement right pointer (decrease value) if sum > target
            if (sorted_nums[left] + sorted_nums[right] > target) {
                right = getNextIndex(right, -1, sorted_nums);
            // increment left pointer (increase value) if sum < target
            }else if (sorted_nums[left] + sorted_nums[right] < target) {
                left = getNextIndex(left, 1, sorted_nums);
            // add pair as a vector
            }else if (sorted_nums[left] + sorted_nums[right] == target) {
                negating_pairs.push_back({sorted_nums[left], sorted_nums[right]});
                left = getNextIndex(left, 1, sorted_nums);
                right = getNextIndex(right, -1, sorted_nums);
            }
        }
        return negating_pairs;
    }


    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        vector<vector<int>> three_sum_triplets;

        // go through the list skipping duplicate values
        for (int i = 0; i < nums.size(); i = getNextIndex(i, 1, nums)) {
            vector<vector<int>> negating_pairs = getNegatingPairs(i, nums);
            for(vector<int> &neg_pair : negating_pairs) {
                neg_pair.push_back(nums[i]);
            }
            three_sum_triplets.insert(three_sum_triplets.end(), negating_pairs.begin(), negating_pairs.end());
        }

        return three_sum_triplets;
    }
};
