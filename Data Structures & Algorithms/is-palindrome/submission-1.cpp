#include <regex>
#include <cctype>

using namespace std;

class Solution {
public:

    string getCleanString(string original_text) {
        string clean_text;
        
        // Reserve memory ahead of time to avoid multiple reallocations
        clean_text.reserve(original_text.size()); 

        for (const char& character : original_text) {
            // Check if the character is alphanumeric
            if (isalnum(static_cast<unsigned char>(character))) {
                clean_text += tolower(static_cast<unsigned char>(character)); // Append it to our clean string
            }
        }
    
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
