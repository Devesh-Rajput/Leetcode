class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        int result = 0;
        for (char ch : s) {
            if (ch == '(')
                st.push(0);
            if (ch == ')') {
                if (st.top() == 0) {
                    st.pop();
                    st.push(1);
                } else {
                    int sum = 0;
                    while (st.top() != 0) {
                        sum += st.top();
                        st.pop();
                    }
                    st.pop();
                    st.push(sum * 2);
                }
            }
        }
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        return result;
    }
};