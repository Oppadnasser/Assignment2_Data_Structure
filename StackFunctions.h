#ifndef ASSIGNMENT2_DATA_STRUCTURE_STACKFUNCTIONS_H
#define ASSIGNMENT2_DATA_STRUCTURE_STACKFUNCTIONS_H

#include <bits/stdc++.h>
#include "Stack.h"
using namespace std;

int longestValidParentheses(string s) {
    int n = s.size();
    stack<int> stk;
    stk.push(-1);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            stk.push(i);
        } else {
            stk.pop();
            if (stk.empty()) {
                stk.push(i);
            } else {
                ans = max(ans, i - stk.top());
            }
        }
    }
    return ans;
}



int getPrecedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

string infixToPostfix(string infix) {
    string postfix;
    Stack<char> operatorStack(infix.length());

    for (char c : infix) {
        if (isalnum(c)) {
            postfix += c;
        }
        else if (c == '(') {
            operatorStack.push(c);
        }
        else if (c == ')') {
            while (!operatorStack.isEmpty() && operatorStack.top() != '(') {
                postfix += operatorStack.pop();
            }
            if (!operatorStack.isEmpty() && operatorStack.top() == '(') {
                operatorStack.pop();
            }
        }
        else {
            while (!operatorStack.isEmpty() && getPrecedence(operatorStack.top()) >= getPrecedence(c)) {
                postfix += operatorStack.pop();
            }
            operatorStack.push(c);
        }
    }

    while (!operatorStack.isEmpty()) {
        postfix += operatorStack.pop();
    }

    return postfix;
}


#endif //ASSIGNMENT2_DATA_STRUCTURE_STACKFUNCTIONS_H
