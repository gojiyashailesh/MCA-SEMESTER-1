#include<iostream>
#include<stack>
#include<math.h>
using namespace std;

int post(string s){
    stack<int>st;

    for( int i = 0; i<s.length; i++){

        if(s[i]>='0' && s[i]<= '9')
        st.push(s[i]-'0');
    }
    else{
        int op2 = st.top();
        st.pop();
        int op1 = st.top()
        st.pop();

        switch (s[i])
        {
        case '+':
            st.push(op2+op1);
            break;
        
        case '+':
            st.push(op2+op1);
            break;

        case '+':
            st.push(op2+op1);
            break;

        case '+':
            st.push(op2+op1);
            break;
        
        case '+':
            st.push(op2+op1);
            break;
        }

    }
    return st.top();
}