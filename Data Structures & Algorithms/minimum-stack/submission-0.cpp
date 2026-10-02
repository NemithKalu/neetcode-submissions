class MinStack {

private:
    vector<pair<int, int>> _stack;

public:

    MinStack() {
    }
    
    void push(int val) {
        if (_stack.size() == 0) {
            _stack.push_back({val, val});
        } else {

            int previous_min = _stack[_stack.size() - 1].second;
            if (previous_min < val) {
                _stack.push_back({val, previous_min});                
            } else {
                _stack.push_back({val, val});
            }
        }
    }
    
    void pop() {
        if (_stack.size() != 0) {
            _stack.pop_back();
        }
    }
    
    int top() {
        if (_stack.size() != 0) {
            return _stack[_stack.size() - 1].first;
        }
    }
    
    int getMin() {
        if (_stack.size() != 0) {
            return _stack[_stack.size() - 1].second;
        }
    }
};
