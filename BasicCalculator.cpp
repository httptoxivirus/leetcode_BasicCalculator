class Solution {
public:
    int calculate(string s) {
        int n=s.length();
        stack<int> st;
        stack<char> oper;
        for(int i=0; i<n; i++) {
            if(s[i] == ' ')
            continue;
            if(s[i] == '(')
            oper.push(s[i]);
            else if(s[i]-'0' <= 9 && s[i]-'0' >= 0) {
                int num = 0;
                while(i<n && (s[i]-'0' <= 9 && s[i]-'0' >= 0)) {
                    num = num*10 + (s[i]-'0');
                    i++;
                }
                i--;
                st.push(num);
            }
            else if(s[i] == '+' || s[i] == '-') {
                while(!oper.empty() && (oper.top() == '+' || oper.top() == '-')) {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                char op = oper.top();
                oper.pop();
                if(op == '+')
                st.push(a+b);
                else if(op == '-')
                st.push(a-b);
              }
              oper.push(s[i]);
            }
            else if(s[i] == ')') {
                while(!oper.empty() && oper.top() != '(') {
                    int b = st.top();
                    st.pop();
                    int a = st.top();
                    st.pop();
                    char op = oper.top();
                    oper.pop();
                    if(op == '+')
                    st.push(a+b);
                    else if(op == '-')
                    st.push(a-b);
                }
                oper.pop();
            }
        }
        while(!oper.empty()) {
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();
            char op = oper.top();
            oper.pop();
            if(op == '+')
            st.push(a+b);
            else if(op == '-') 
            st.push(a-b);
        }
        return st.top();
    }
};
