#include <stack>
#include <string>

using namespace std;

class Solution {
public:

    bool isOperator(string token) {
        vector<string> operators = {"+", "-", "*", "/"};
        for (auto& elem : operators) {
            if (token == elem) return true;
        }
        return false;
    }

    string evaluate(string left, string op, string right){
        
        int l = stoi(left);
        int r = stoi(right);
        
        switch (op[0]) {
            case '+':
                return to_string(l + r);
                break;

            case '-':
                return to_string(l - r);
                break;

            case '*':
                return to_string(l * r);
                break;

            case '/':
                if (r != 0) {
                    return to_string(l / r);
                } else {
                    return ""; 
                }
                break;
        }
    }


    int evalRPN(vector<string>& tokens) {

        stack <string> operands;

        for (const auto& token : tokens) {
            if (isOperator(token)) {
                string right = operands.top();
                operands.pop();

                string left = operands.top();
                operands.pop();

                operands.push(evaluate(left, token, right));
                
            } else {
                operands.push(token);
            }
        }

        return stoi(operands.top());
        
    }
};
