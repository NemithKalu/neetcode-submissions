#include <unordered_map>

using namespace std;

class Solution {
public:

    bool isValidSection(vector<char>& section) {
        unordered_map<char, bool> prevSeen;

        for (const char& character: section) {
            if (character != '.' && prevSeen[character]) {
                return false;
            } else {
                prevSeen[character] = true;
            }
        }
        return true;
    }


    bool isValidSudoku(vector<vector<char>>& board) {

        vector<vector<char>> rows(9);
        vector<vector<char>> columns(9);
        vector<vector<char>> blocks(9);

        // fill in the 3 seperate data structs
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                
                char character = board[i][j];

                rows[i].push_back(character);
                columns[j].push_back(character);
                blocks[(i/3) + (j/3) * 3].push_back(character);                
            }
        }
        
        for ( auto& row: rows) {
            if (!isValidSection(row)){
                return false;
            }
        }

        for ( auto& column: columns) {
            if (!isValidSection(column)){
                return false;
            }
        }

        for ( auto& block: blocks) {
            if (!isValidSection(block)){
                return false;
            }
        }

        return true;
    }
};
