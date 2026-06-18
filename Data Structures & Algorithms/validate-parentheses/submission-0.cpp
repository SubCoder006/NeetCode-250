class Solution {
   public:
    bool isValid(string s) {
        stack<char> st;
        for (auto p : s) {
            if (p == '(' || p == '{' || p == '[')
                st.push(p);
            else {
                if (st.empty()) return false;
                if ((st.top() == '(' && p == ')') || (st.top() == '{' && p == '}') ||
                    (st.top() == '[' && p == ']'))
                    st.pop();
                else {
                    return false;
                }
            }
        }
        return st.size() == 0;
    }
};
