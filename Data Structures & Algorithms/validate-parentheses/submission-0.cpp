#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:

    bool isValid(string s) {

    // key : value --> opening bracket : closing bracket
    unordered_map<char, char> get_closing_bracket = {{')', '('}, {'}', '{'}, {']', '['}};
    stack<char> opener_stack;

    for (const char& bracket : s) {

        bool is_opening_bracket = !get_closing_bracket.contains(bracket);
        
        if (is_opening_bracket) {
            opener_stack.push(bracket);
        } else if (!is_opening_bracket && opener_stack.empty()) {
            return false;
        } else {
            if (opener_stack.top() != get_closing_bracket[bracket]) {
                return false;
            } else {
                opener_stack.pop();
            }
        }
    }

    if (opener_stack.empty()) {
        return true;
    } else {
        return false;
    }

    }
};
