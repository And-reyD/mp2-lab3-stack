#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include "TStack.h"
using namespace std;

class TCalc {
private:
    string expr;
    string pstfix;
    TStack<char> st_char;
    TStack<double> st_d;

    int priority(char operation);
public:
    TCalc();
    ~TCalc();
    TCalc(const TCalc& other);

    TCalc& operator=(const TCalc& other);

    void set_expr(string _expr);
    string get_expr();
    string get_pstfix();
    bool check_expr();
    void convert_to_postfix();
    double calc();
};

int TCalc::priority(char operation) {
    switch (operation) {
    case '(': return 0;
    case '+': return 1;
    case '-': return 1;
    case '*': return 2;
    case '/': return 2;
    case '^': return 3;
    }
    return 0;
}

TCalc::TCalc() {
}

TCalc::~TCalc() {
}

TCalc::TCalc(const TCalc& other) {
    expr = other.expr;
    pstfix = other.pstfix;
}

TCalc& TCalc::operator=(const TCalc& other) {
    expr = other.expr;
    pstfix = other.pstfix;
    return *this;
}

void TCalc::set_expr(string _expr) {
    expr = _expr;
}

string TCalc::get_expr() {
    return expr;
}

string TCalc::get_pstfix() {
    return pstfix;
}

bool TCalc::check_expr() {
    for (int i = 0; i < expr.length(); i++) {
        if (expr[i] == '(') {
            st_char.push(expr[i]);
        }
        else if (expr[i] == ')') {
            if (st_char.empty()) {
                return false;
            }
            else {
                st_char.pop();
            }
        }
    }
    return st_char.empty();
}

void TCalc::convert_to_postfix() {
    string infix = "(" + expr + ")";
    pstfix = "";
    st_char.clear();
    for (int i = 0; i < infix.size(); i++) {
        if (isdigit(infix[i])) {
            pstfix += infix[i];
            pstfix += " ";
        }
        else if (infix[i] == '(') {
            st_char.push(infix[i]);
        }
        else if (infix[i] == ')') {
            while (st_char.top() != '(') {
                pstfix += st_char.pop();
                pstfix += " ";
            }
            st_char.pop();
        }
        else if (pstfix[i] == '+' || pstfix[i] == '-' || pstfix[i] == '*' || pstfix[i] == '/' || pstfix[i] == '^') {
            while (priority(infix[i]) <= priority(st_char.top())) {
                pstfix += st_char.pop();
                pstfix += " ";
            }
            st_char.push(infix[i]);
        }
    }

    if (pstfix[pstfix.size() - 1] == ' ') {
        pstfix.pop_back();
    }
}

double TCalc::calc() {
    for (int i = 0; i < pstfix.length(); i++) {
        if (isdigit(pstfix[i])) {
            st_d.push(stod(&pstfix[i]));
        }
        if (pstfix[i] == '+' || pstfix[i] == '-' || pstfix[i] == '*' || pstfix[i] == '/' || pstfix[i] == '^') {
            double second;
            double first;

            if (!(st_d.empty())) {
                second = st_d.pop();
            }
            else {
                throw "Exception: Too much operation in the postfix string";
            }

            if (!(st_d.empty())) {
                first = st_d.pop();
            }
            else {
                throw "Exception: Too much operation in the postfix string";
            }

            switch (pstfix[i]) {
            case '+':
                st_d.push(first + second);
                break;
            case '-':
                st_d.push(first - second);
                break;
            case '*':
                st_d.push(first * second);
                break;
            case '/':
                st_d.push(first / second);
                break;
            case '^':
                st_d.push(pow(first, second));
                break;
            }
        }
    }
    if (!(st_d.empty())) {
        double result = st_d.pop();
        if (!(st_d.empty())) {
            throw "Exception: Too many operands in the string";
        }
        return result;
    }
    else {
        throw "Exception: No operands in the string";
    }
}