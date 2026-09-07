#include <unordered_map>


class Solution {
public:

    void appendList(vector<int>& list1, const vector<int>& list2){
        // Optimize performance by pre-allocating memory
        list1.reserve(list1.size() + list2.size());
        // Append highest frequency list to kMostElements
        list1.insert(list1.end(), list2.begin(), list2.end());
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        // variable containing the highest frequency count
        int maxFrequency = 0;

        
        // Create (number => frequency) map
        std::unordered_map<int, int> numberFrequencyMap;
        for(const auto& num: nums) {
            // increment frequency everytime you meet num in input nums array
            numberFrequencyMap[num] += 1;
            // update highest frequency count
            if(numberFrequencyMap[num] > maxFrequency) {
                maxFrequency = numberFrequencyMap[num];
            }
        }
        
        // Create (frequency => numbers (list)) map
        std::unordered_map<int, vector<int>> frequencyNumberMap;
        for (const auto& [num, frequency]: numberFrequencyMap) {
            frequencyNumberMap[frequency].push_back(num);
        }


        vector<int> kMostElements;
        int currentFrequency = maxFrequency;

        // Find highest frequency elements and append them to kMostElements till it contains k elements
        while (kMostElements.size() != k) {
            appendList(kMostElements, frequencyNumberMap[currentFrequency]);
            // Decrease freq till we find the next highest frequency
            currentFrequency -= 1;
        }

        return kMostElements;
    }
};
