#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:

    bool hasNextNode(int num, unordered_map<int, int>& filled_map) {
        if (filled_map.find(num + 1) == filled_map.end()) return false;
        return true;
    }


    int longestConsecutive(vector<int>& nums) {

        // create and fill maps that keep track of whether a node is part of a longer chain
        unordered_map<int, int> longest_chain_size;
        for (const int& num: nums) {
            longest_chain_size[num] = 1;
        }




        int max_length = 0;

        for (const auto num: nums) {

            if (longest_chain_size.find(num) == longest_chain_size.end()) continue;

            int node = num;
            int length = 1;
            // iterate through chained nodes till the chain breaks.
            while (hasNextNode(node, longest_chain_size)) {

                int next_node = node + 1;
                length += longest_chain_size[next_node];
                
                // if we've already calculated the size of the chain starting from a node
                // add them (done above) and break (because we've found the largest chain starting from said node)
                if (longest_chain_size[next_node] > 1) break;
                longest_chain_size.erase(node);

                node = next_node;

            }

            longest_chain_size[num] = length;
            if (length > max_length) max_length = length;
        }

        return max_length;
        
    }
};
