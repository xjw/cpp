/**
 *  http://scriptasylum.com/tutorials/infix_postfix/algorithms/infix-postfix/index.htm
 *  http://scriptasylum.com/tutorials/infix_postfix/algorithms/postfix-evaluation/index.htm
 */

#include <iostream>
#include <stack>
#include <vector>
#include <sstream>
#include <assert.h>

using namespace std;

enum operator_code {
  ADD, MINUS, MULTIPLY, DIVIDE
};

bool isOperator(string op) {
  return (op == "+" || op == "-" || op == "*" || op == "/");
}

bool isOperator(char op) {
  return (op == '+' || op == '-' || op == '*' || op == '/');
}

int getOperatorPriority(char op) {
  if ( (op=='+') || (op=='-')) return 0;
  if ( (op=='*') || (op=='/')) return 1;
}

operator_code getOperatorCode(string op) {
  if (op=="+") return ADD;
  else if (op=="-") return MINUS;
  else if (op=="*") return MULTIPLY;
  else if (op=="/") return DIVIDE;
}

int calculate(string op, int a, int b) {
  switch (getOperatorCode(op)) {
    case ADD:
        return a+b;
    case MINUS:
        return a-b;
    case MULTIPLY:
        return a*b;
    case DIVIDE:
        return a/b;
  }
  return 0;
}

int calculateUsingPostfix(vector<string> v) {
  int r, a, b, operand;

  stack<int> st;
  for (vector<string>::iterator it = v.begin(); it != v.end(); ++it) {
    if (!isOperator(*it)) {
      stringstream ss(*it);
      ss >> operand;
      st.push(operand);
    }
    else {
      assert(!st.empty());
      a = st.top();
      st.pop();

      assert(!st.empty());
      b = st.top();
      st.pop();

      r = calculate(*it, a, b);
      st.push(r);
    }
  }
  return r;
}

vector<string> infix2postfix(string s) {
  stack<char> st;
  vector<string> v;
  string operand = "";
  string temp;
  for (string::iterator it=s.begin(); it!=s.end(); ++it) {
    if (isOperator(*it)) {
      if (!operand.empty()) {
        v.push_back(operand);
        operand = "";
      }
      while (!st.empty()) {
        char stack_top = st.top();
        if (getOperatorPriority(stack_top) > getOperatorPriority(*it)) {
          temp = "";
          temp += stack_top;
          v.push_back(temp);
          st.pop();
        }
        else {
          break;
        }
      }
      st.push(*it);
    }
    else {
      operand += *it;
    }
  }

  if (!operand.empty()) {
    v.push_back(operand);
  }

  while (!st.empty()) {
    temp = "";
    temp += st.top();
    v.push_back(temp);
    st.pop();
  }

  for (vector<string>::iterator it=v.begin(); it!=v.end(); ++it) {
    cout<<*it;
  }
  cout<<endl;
  return v;
}

int main() {
  string s;
  cin>>s;
  cout<<calculateUsingPostfix(infix2postfix(s))<<endl;

  return 1;
}
