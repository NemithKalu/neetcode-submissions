#include <regex>
#include <cctype>

using namespace std;

class Solution {
public:

    string getCleanString(string original_text) {
        
        regex nonAlphanumeric("[^a-zA-Z0-9]");
        string clean_text = regex_replace(original_text, nonAlphanumeric, "");

        transform(clean_text.begin(), clean_text.end(), clean_text.begin(), [](unsigned char c) {
            return tolower(c);
        });
        return clean_text;
    }


    bool isPalindrome(string s) {

        string clean_string = getCleanString(s);
        int clean_length = clean_string.size();
        int midpoint = clean_length/2 + 1;

        for (int i = 0; i < midpoint; i++) {
            if (clean_string[i] != clean_string[clean_length - 1 - i]) {
                return false;
            }
        }
        return true;
    }
};
