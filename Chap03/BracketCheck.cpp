#include <iostream>
#include <stack>

using namespace std;

bool isValid(string s)
{
    stack<char> sta;
    char c, b;
    int l = s.length();
    for (int i = 0; i < l; i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            sta.push(s[i]);
        }
        else if (s[i] == ')')
        {
            if (sta.empty())
                return false;
            else if (c = sta.top(), c == '(')
                sta.pop();
            else
                return false;
        }
        else if (s[i] == ']')
        {
            if (sta.empty())
                return false;
            else if (c = sta.top(), c == '[')
                sta.pop();
            else
                return false;
        }
        else if (s[i] == '}')
        {
            if (sta.empty())
                return false;
            else if (c = sta.top(), c == '{')
                sta.pop();
            else
                return false;
        }
    }
    if (sta.empty())
        return true;
    else
        return false;
}
int main()
{
    string s = "{{[[()]]}";
    bool b = true;
    ;

    b = isValid(s);
    if (b == true)
        cout << "true";
    else
        cout << "false";
    return 0;
}
