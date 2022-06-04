// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"
int pref(char t) {
    switch (t) {
    case '(': return 0;
    case ')': return 1;
    case '-': return 2;
    case '+': return 2;
    case '*': return 3;
    case '/': return 3;
    case ' ': return 4;
    default: return 4;
    }
}
std::string infx2pstfx(std::string inf) {
    TStack <char, 100> stack;
    std::string tmp;
    int p;
    for (int t = 0; t < inf.size(); t++) {
        p= pref(inf[t]);
        if (p == 4) {
            tmp.push_back(inf[t]);
            tmp.push_back(' ');
        } else {
            if (((p == 0) || stack.isEmpty())) 
            {
              stack.push(inf[t]);
            } else if ((p > pref(stack.get()))) 
            {
                stack.push(inf[t]);
            } else if (p == 1) {
                while (stack.get() != '(') 
                {
                    tmp.push_back(stack.get());
                    tmp.push_back(' ');
                    stack.pop();
                }
                stack.pop();
            } else if (inf[t] != ' ') {
                int i = pref(stack.get());
                while ((i >= pref(inf[t])) && (!stack.isEmpty()))
                {
                    tmp.push_back(stack.get());
                    tmp.push_back(' ');
                    stack.pop();
                }
                stack.push(inf[t]);
            }
        }
    }
    while (!stack.isEmpty()) 
    {
        tmp.push_back(stack.get());
        tmp.push_back(' ');
        stack.pop();
    }
    if (tmp[tmp.size() - 1] == ' ') 
    {
        tmp.erase(tmp.size() - 1);
    }
    return tmp;}

int calk(char sum, int x, int y)
{
    switch (sum)
    {case '+': return x + y;
    case '-': return x - y;
    case '/':
       if (y != 0) return x / y;
    case '*': return x * y;
    default:
     return 0;
        break;
    }
}
int eval(std::string p) {
    TStack <int, 100> stack;
    int x, y;
    for (int t = 0; t < p.size(); t++) {
        if (pref(p[t]) < 4) {
            y = stack.get();
            stack.pop();
            x = stack.get();
            stack.pop();
            stack.push(calk(p[t], x, y));
        } else if (pref(p[t]) == 4 && p[t] != ' ') {
            stack.push(p[t] - '0');
        }
    }
    return stack.get();
}
