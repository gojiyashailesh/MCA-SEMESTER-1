#include<iostream>
#include<stack>

using namespace std;

int precedence(char c) {
    if (c == '^') {
        return 6;
    } else if (c == '%') {
        return 5;
    } else if (c == '/') {
        return 4;
    } else if (c == '*') {
        return 3;
    } else if (c == '+') {
        return 2;
    } else if (c == '-') {
        return 1;
    } else {
        return -1;
    }
}
   
string infixtopost(string s) {
    stack<char> st;
    string result;

    for (int i = 0; i < s.length(); i++) {

        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
            result += s[i];
        } else if (s[i] == '(') {
            st.push(s[i]);
        } else if (s[i] == ')') {
            while (!st.empty() && st.top() != '(') {
                result += st.top();
                st.pop();
            }
            if (!st.empty()) {
                st.pop();
            }
        } else {
            while (!st.empty() && precedence(st.top()) >= precedence(s[i])) {
                result += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
    return result;
}

int   main() {
    string infix;
    cout << "Enter the expression: ";
    cin >> infix;
    string postfix = infixtopost(infix);
    cout << "Postfix expression: " << postfix << endl;
    return 0;
}
