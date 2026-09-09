class Solution {
public:

    string encode(vector<string>& strs) {

        string concat;

        for (const string& str: strs) {
            
            concat += str;
            // character in between input strings
            concat += "/esc/";
        }
        return concat;
    }

    vector<string> decode(string s) {
        
        // buffer to insert characters in to
        string buffer;
        vector<string> decodedList;

        for (int i = 0; i < s.size(); i++) {
            char character = s[i];

            // dump buffer into output list and skip escape characters
            if (character == '/' && s.substr(i, 5) == "/esc/") {
                decodedList.push_back(buffer);
                i += 4;
                buffer = "";
            
            // add characters to buffer if escape character not met
            } else {
                buffer += character;
            }
        }

        return decodedList;

    }
};
