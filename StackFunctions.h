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

#endif //ASSIGNMENT2_DATA_STRUCTURE_STACKFUNCTIONS_H
