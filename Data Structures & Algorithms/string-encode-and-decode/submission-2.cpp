class Solution {
public:

    string encode(vector<string>& strs) {

        string concat;

        for (const string& str: strs) {
            for (const char& character: str) {
                concat += character;
            }
            concat += "/esc/";
        }
        return concat;
    }

    vector<string> decode(string s) {

        string buffer;
        vector<string> decodedList;

        for (int i = 0; i < s.size(); i++) {
            char character = s[i];
            if (character == '/' && s.substr(i, 5) == "/esc/") {
                decodedList.push_back(buffer);
                i += 4;
                buffer = "";
            } else {
                buffer += character;
            }
        }

        return decodedList;

    }
};
