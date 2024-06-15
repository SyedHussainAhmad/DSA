#include <string>
#include "Stack.h"

bool isValid(const string& s) 
{
    Stack<char> stack; 

    for (char c : s) 
    {
        if (c == '(' || c == '[' || c == '{') 
        {
            stack.push(c);
        }

        else if (c == ')' || c == ']' || c == '}') 
        {
            if (stack.isEmpty()) 
            {
                return false;
            }
            char top = stack.top(); 
            stack.pop();
            if ((c == ')' && top != '(') || (c == ']' && top != '[') || (c == '}' && top != '{')) 
            {
                return false; 
            }
        }
    }
    return stack.isEmpty();
}

//int main() 
//{
//    string s1 = "{({()})[]}";
//    string s2 = "{[()]";
//    string s3 = "{{))";
//
//    cout << "isValid(\"" << s1 << "\"): " << (isValid(s1) ? "valid" : "not valid") << endl;
//    cout << "isValid(\"" << s2 << "\"): " << (isValid(s2) ? "valid" : "not valid") << endl;
//    cout << "isValid(\"" << s3 << "\"): " << (isValid(s3) ? "valid" : "not valid") << endl;
//
//    return 0;
//}
