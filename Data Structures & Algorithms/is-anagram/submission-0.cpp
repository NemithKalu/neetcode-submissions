#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> string_count;

        for(char ch: s){
            if (!string_count.contains(ch)){
                string_count[ch] = 1;
            }else{
                string_count[ch] += 1;
            }
        }

        for (char ch: t){
            if (!string_count.contains(ch)){
                return false;
            }else{
                string_count[ch] -= 1;
            }
        }

        for (const auto& [_, count] : string_count){
            if(count != 0){
                return false;
            }
        }

        return true;    
    }
};
