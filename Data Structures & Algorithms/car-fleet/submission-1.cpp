#include <unordered_map>
#include <algorithm>
#include <stack>

using namespace std;

class Solution {
public:

    float getTime(int target, int position, int speed){
        return (static_cast<float>(target - position) / speed);
    }


    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        // map speeds to positions so they don't get lost when position is sorted
        unordered_map<int, int> getSpeed;
        for (int i = 0; i < position.size(); i++) {
            getSpeed[position[i]] = speed[i];
        }

        // reverse sort positions
        sort(position.begin(), position.end(), greater<int>());

        // get unrestricted finish times (only taking finish speed and distance to target into account)
        vector<float> unrestricted_time;
        for (auto& pos : position) {
            unrestricted_time.push_back(getTime(target, pos, getSpeed[pos]));
        }

        // create max_stack :- if vehicle in front is blocking, then go at that speed
        stack<float> real_time;
        for (auto& time : unrestricted_time) {
            if (real_time.empty() || real_time.top() < time) {
                real_time.push(time);
            } else {
                real_time.push(real_time.top());
            }
        }

        // check how many different end times are there
        int fleets = 1;
        float previous_time = real_time.top();
        while (!real_time.empty()) {
            if (real_time.top() != previous_time) {
                fleets += 1;
                previous_time = real_time.top();
            }
            real_time.pop();
        }

        return fleets;
    }
};
