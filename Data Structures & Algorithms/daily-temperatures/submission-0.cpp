#include <stack>

using namespace std;

class Solution {
public:

    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> colder_indexes;
        vector<int> result(temperatures.size(), 0);

        colder_indexes.push(0);

        for (int i = 1; i < temperatures.size(); i++) {
            
            int current_temp = temperatures[i];
            int stack_top_temp = temperatures[colder_indexes.top()];

            while (current_temp > stack_top_temp) {
                result[colder_indexes.top()] = i - colder_indexes.top();
                colder_indexes.pop();
                if (colder_indexes.empty()) {
                    break;
                }
                stack_top_temp = temperatures[colder_indexes.top()];
            }
            colder_indexes.push(i);
        }

        return result;
    }
};
