#include<bits/stdc++.h>
using namespace std;

int isBalanced(char *exp){
    stack<int> s;

    for(int i=0; exp[i]!='\0'; i++){
        if(exp[i] == '('){
            s.push(exp[i]);
        }
        else if(exp[i] == ')'){
            if(s.empty()) return false;
            s.pop();
        }
    }
    return s.empty() ? true : false;
}

int main(){
    char s[] = "((((a+b)*(c-d))))";
    if(isBalanced(s)){
        cout << "The expression is balanced." << endl;
    } else {
        cout << "The expression is not balanced." << endl;
    }
    return 0;
}