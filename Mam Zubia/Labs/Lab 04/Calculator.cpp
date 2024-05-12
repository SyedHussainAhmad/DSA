#include "Calculator.h"
bool Calculator::isOperator(char c) 
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int Calculator::precedence(char op) 
{
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    return 0;
}

bool Calculator::isAlphanumeric(char c) 
{
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
}

string Calculator::infixToPostfix() 
{
    string postfix;
    Stack<char> stack;
    for (char& c : infix) 
    {
        if (isAlphanumeric(c))
            postfix += c;
        else if (c == '(')
            stack.push(c);
        else if (c == ')') 
        {
            while (!stack.isEmpty() && stack.top() != '(') 
            {
                postfix += stack.top();
                stack.pop();
            }
            stack.pop();
        }
        else 
        {
            while (!stack.isEmpty() && precedence(c) <= precedence(stack.top())) 
            {
                postfix += stack.top();
                stack.pop();
            }
            stack.push(c);
        }
    }
    while (!stack.isEmpty())
    {
        postfix += stack.top();
        stack.pop();
    }
    return postfix;
}

void Calculator::swap(char& a, char& b) 
{
    char temp = a;
    a = b;
    b = temp;
}

string Calculator::reverseString(string str) 
{
    int left = 0;
    int right = str.size() - 1;
    while (left < right) 
    {
        swap(str[left], str[right]);
        ++left;
        --right;
    }
    return str;
}

string Calculator::infixToPrefix() 
{
    string reversedInfix = reverseString(infix);
    for (char& c : reversedInfix) 
    {
        if (c == '(')
            c = ')';
        else if (c == ')')
            c = '(';
    }
    return reverseString(infixToPostfix());
}

int Calculator::evaluatePostfix() {
    string postfix = infixToPostfix();
    Stack<int> stack;
    for (int i = 0; i < postfix.size(); i++)
    {
        char c = postfix[i];
        if (isdigit(c))
            stack.push(c - '0');
        else 
        {
            int operand2 = stack.top();
            stack.pop();
            int operand1 = stack.top();
            stack.pop();
            switch (c) 
            {
            case '+':
                stack.push(operand1 + operand2);
                break;
            case '-':
                stack.push(operand1 - operand2);
                break;
            case '*':
                stack.push(operand1 * operand2);
                break;
            case '/':
                stack.push(operand1 / operand2);
                break;
            }
        }
    }
    return stack.top();
}

int Calculator::evaluatePrefix() 
{
    string prefix = reverseString(infix);
    Stack<int> stack;
    for (int i = 0; i < prefix.size(); i++)
    {
        char c = prefix[i];
        if (isdigit(c))
            stack.push(c - '0');
        else 
        {
            int operand1 = stack.top();
            stack.pop();
            int operand2 = stack.top();
            stack.pop();
            switch (c) 
            {
            case '+':
                stack.push(operand1 + operand2);
                break;
            case '-':
                stack.push(operand1 - operand2);
                break;
            case '*':
                stack.push(operand1 * operand2);
                break;
            case '/':
                stack.push(operand1 / operand2);
                break;
            }
        }
    }
    return stack.top();
}
