#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <iostream>
#include <string>
#include "Stack.h" // Assuming you have implemented your own Stack class
using namespace std;

class Calculator 
{
    string infix;
    char delimiter;
    bool isOperator(char c);
    int precedence(char op);
    bool isAlphanumeric(char c);
    void swap(char& a, char& b);
    string reverseString(string str);

public:
    string infixToPrefix();
    string infixToPostfix();
    int evaluatePostfix();
    int evaluatePrefix();
};

#endif // CALCULATOR_H
