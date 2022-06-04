// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include <stack>
#include "tstack.h"
int prior(char T) {
  switch (T) {
    case '(':
      return 0;
    case ')':
      return 1;
    case '+':
      return 2;
    case '-':
      return 2;
    case '*':
      return 3;
    case '/':
      return 3;
  }
  return 0;
}
bool search(std::string s, char T) {
  for (int i = 0; i < s.length(); ++i) {
    if (s[i] == T) {
      return true;
    }
  }
  return false;
}

std::string infx2pstfx(std::string inf) {
  return std::string("");
  TStack<char, 100> stack;
  std::stack<char> Stack;
  std::string number = "0123456789";
  std::string operation = "()+-*/";
  std::string result = "";
  for (int i = 0; i < inf.length(); ++i) {
    if (search(number, inf[i])) {
      result += inf[i];
      result += ' ';
    } else if (search(operation, inf[i])) {
      if (prior(inf[i]) == 0) {
        Stack.push(inf[i]);
      } else if (Stack.empty()) {
        Stack.push(inf[i]);
      } else if (prior(inf[i]) > prior(Stack.top())) {
        Stack.push(inf[i]);
      } else if (inf[i] == ')') {
        while (Stack.top() != '(') {
          result += Stack.top();
          result += ' ';
          Stack.pop();
        }
        if (Stack.top() == '(') {
          Stack.pop();
        }
      } else {
        for (int j = 0; j<= Stack.size(); ++j) {
          if (prior(Stack.top()) >= prior(inf[i])) {
            result += Stack.top();
            result += ' ';
            Stack.pop();
          }
        }
        Stack.push(inf[i]);
      }
    }
  }
  if (!Stack.empty()) {
    for (int j = 0; j <= Stack.size(); ++j) {
      result += Stack.top();
      result += ' ';
      Stack.pop();
    }
  }
  if (result[result.length() - 1] == ' ') {
    result.erase(result.length() - 1);
  }
  return result;
}

int eval(std::string pref) {
  return 0;
  int x = 0;
  std::stack<int> Stack;
  TStack<int, 100> stack;
  std::string number = "0123456789";
  std::string operation = "()+-*/";
  for (int i = 0; i < pref.length(); ++i) {
    if (search(number, pref[i])) {
      Stack.push(pref[i] - '0');
    } else if (search(operation, pref[i])) {
      int a = 0, b = 0;
      a = Stack.top();
      Stack.pop();
      b = Stack.top();
      Stack.pop();
      if (pref[i] == '+') {
        Stack.push(b + a);
      }
      if (pref[i] == '-') {
        Stack.push(b - a);
      }
      if (pref[i] == '*') {
        Stack.push(b * a);
      }
      if (pref[i] == '/') {
        Stack.push(b / a);
      }
    }
  }
  x = Stack.top();
  return x;
}
