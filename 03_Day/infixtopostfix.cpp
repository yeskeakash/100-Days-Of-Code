#include <bits/stdc++.h>
using namespace std;

// checking if the character is operand or operator
int isOperand(char x) {
    if (x == '+' || x == '-' || x == '*' || x == '/')
        return 0;
    return 1;
}

// precedence of operator inside stack 
int prec(char x) {
    if (x == '+' || x == '-') return 1;
    else if (x == '*' || x == '/') return 2;
    else return 0;
}

char* convert(const char* infix) {
    stack<char> st;
    int len = strlen(infix);
    char* postfix = new char[len + 1];
    int i = 0, j = 0;
    while (infix[i] != '\0') {
        if (isOperand(infix[i])) {
            postfix[j++] = infix[i++];
        } else {
            while (!st.empty() && prec(infix[i]) <= prec(st.top())) {
                postfix[j++] = st.top();
                st.pop();
            }
            st.push(infix[i++]);
        }
    }
    while (!st.empty()) {
        postfix[j++] = st.top();
        st.pop();
    }
    postfix[j] = '\0';
    return postfix;
}

int main() {
    const char* infix = "a+b*c-d/e";
    char* postfix = convert(infix);
    cout << postfix << endl;
    delete[] postfix;
    return 0;
}