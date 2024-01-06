#include<iostream>
#include<stack>
using namespace std;

int precedence(char c){
    if ( c == '^'){
        return 4;
    }
    else if(c =='%'){
        return 3;
    }
    else if ( c == '/' || c == '*'){
        return 2;
    }
    else if ( c == '+' || c == '-'){
        return 1;
    }
    else {
        return -1;
    }
}

string infixtopostfix(string s){
    stack<char>st;
    string result;

    for(int i = o; i<s.length; i++)
}