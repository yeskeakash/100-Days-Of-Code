#include <bits/stdc++.h>
using namespace std;

// checking if the character is operand or operator
bool isOperand(char x) {
    return isalnum(x);
}

// precedence of operator inside stack 
int prec(char x) {
    if (x == '+' || x == '-') return 1;
    else if (x == '*' || x == '/') return 2;
    else if (x == '^') return 3; // Exponentiation has higher precedence
    return 0;
}

// function to check if the operator is right associative
bool isRightAssociative(char x) {
    return x == '^';
}

char* convert(const char* infix) {
    stack<char> st;
    int len = strlen(infix);
    char* postfix = new char[len + 1];
    int i = 0, j = 0;
    while (infix[i] != '\0') {
        if (isOperand(infix[i])) {
            postfix[j++] = infix[i++];
        } else if (infix[i] == '(') {
            st.push(infix[i++]);
        } else if (infix[i] == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix[j++] = st.top();
                st.pop();
            }
            if (!st.empty() && st.top() == '(') {
                st.pop();
            }
            i++;
        } else {
            while (!st.empty() && prec(infix[i]) <= prec(st.top()) && !isRightAssociative(infix[i])) {
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
    const char* infix = "(a+b)*c-d^e^f";
    char* postfix = convert(infix);
    cout << postfix << endl;
    delete[] postfix;
    return 0;
}