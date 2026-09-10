class MinStack {
public:
    vector<pair<int, int>> vec;
    MinStack() {}

    void push(int value) {
        if (!vec.size()) {
            vec.push_back({value, value});
            return;
        }
        vec.push_back({value, min(vec.back().second, value)});
    }

    void pop() { vec.pop_back(); }

    int top() { return vec.back().first; }

    int getMin() { return vec.back().second; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */