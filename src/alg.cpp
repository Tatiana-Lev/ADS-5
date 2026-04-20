// Copyright 2025 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int getPrecedence(char op) {
    if (op == '+' || op == '_') {
        return 1;
    }
    if (op == '*' || op == '/') {
        return 2;
    }
    return 0;
}
std::string infx2pstfx(const std::string& inf) {
    TStack<char, 100> st;
    std::ostringstream post;

    for (size_t i = 0; i < inf.size(); ++i) {
        char c = inf[i];
        if (c == ' ')continue;
        if (std::isdigit(c)) {
            while (i < inf.size() && std::isdigit(inf[i])) {
                post << inf[i];
                ++i;
            }
            post << ' ';
            --i;
        }else if (c == '('){
            st.push(c);
        }else if (c == ')'){
            while (!st.empty() && st.top() != '(') {
                post << st.top() << ' ';
                st.pop();
            }
            st.pop();
        }else if (isOperator(c)){
            while (!st.empty() && st.top() != '(' && 
                getPrecedence(st.top()) >= getPrecedence(c)) {
                post << st.top() << ' ';
                st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty()) {
        post << st.top() << ' ';
        st.pop();
    }
    std::string result = post.str();
    if (!result.empty() && result.back() == ' ') {
        result.pop_back();
    }
    return result;
}
  return std::string("");
}

int eval(const std::string& pref) {
    TStack<int, 100> st;
    std::istringstream iss(post);
    std::string token;

    while (iss >> token) {
        if (std::isdigit(token[0])) {
            st.push(std::stoi(token));
        }else{
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();

            if (token == "+") {
                st.push(a + b);
            }else if (token == "-"){
                st.push(a - b);
            }else if (token == "*"){
                st.push(a * b);
            }else if (token == "/"){
                st.push(a / b);
            }
        }
    }
    return st.top();
}
