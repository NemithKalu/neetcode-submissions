#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:

    string getSortedString(string str){
        sort(str.begin(), str.end());
        return str;
    }


    vector<string> getAnagramVector(vector<int> indexes, vector<string>& strs) {
        vector<string> anagrams;
        for (const auto& index: indexes) {
            anagrams.push_back(strs[index]);
        }
        return anagrams;
    }


    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<int>> anagram_to_index;

        // created the hashmap (sortedString => index vector)
        for (int i = 0; i < strs.size(); i++){
            string sortedString = getSortedString(strs[i]);
            anagram_to_index[sortedString].push_back(i);
        }

        vector<vector<string>> out_vector;

        // create grouped anagram vector
        for (const auto& pair: anagram_to_index) {
            out_vector.push_back(getAnagramVector(pair.second, strs));
        }

        return out_vector;
    }
};
