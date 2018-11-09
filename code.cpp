#include <iostream>
#include <cstring>
#include <stack>
#include <vector>

using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::stack;


void erase_space(string&);      // Removing spaces
double number(string, size_t&); //Return a number from a string
string fstack(string);          // Stack formation
int checker_prior(stack<char>); // Prioritization check
double solver(string);          // Performing calculations
double mpow(double, double);    // Exponentiation

int main(int argc, char const *argv[]) {
  string expression;
  while (true){
    getline(cin,expression);

    if (expression.length() == 0)
      break;

    erase_space(expression);
    size_t o = 0;
    string out = fstack(expression);

  //  cout<< "OUT STR: "<< out<< endl; // view stack
    cout<<"Expression: "<<expression<<" = " << solver(out)<< endl<<endl; //answer
  }
  return 0;
}

void erase_space(string &str)
{
  for (size_t i = 0; i<str.length(); i++){
    if (str[i] == ' ')
      str.erase(i,1);
  }
}

double number(string str, size_t &index)
{
  double value(0.0);
  while(isdigit(str[index]))
    value = 10*value+str[index++] - '0';

  if (str[index] != '.')
    return value;

    double factor(1.0);
    while(isdigit(str[++index])){
      factor *= 0.1;
      value = value + ((str[index]) -'0')* factor;
    }
    return value;
}

int checker_prior(stack<char> sstack)
{
  if (!sstack.empty() && (sstack.top() == '+' || sstack.top() == '-'
      || sstack.top() == '*' || sstack.top() == '/'||sstack.top() == '^'))
      return 1;
  else
   return 0;
}
string fstack(string str)
{
  string outstr;
  stack<char> sstack;
  size_t k = 0;
  for (size_t i = 0; i<str.length();++i){
      if (isdigit(str[i])){
        outstr += std::to_string(number(str,i));
        outstr.push_back(' ');
      }
      if (str[i] == '+')
      {
        while(checker_prior(sstack))
        {
          outstr.push_back(sstack.top());
          sstack.pop();
          outstr.push_back(' ');
        }
        sstack.push(str[i]);
      }
      if (str[i] == '-')
      {
        while(checker_prior(sstack))
        {
          outstr.push_back(sstack.top());
          sstack.pop();
          outstr.push_back(' ');
        }

        sstack.push(str[i]);
      }
      if (str[i] == '*')
      {
        if (!sstack.empty() &&( sstack.top() == '*' || sstack.top() == '/' || sstack.top() == '^'))
        {
          outstr.push_back(sstack.top());
          sstack.pop();
          outstr.push_back(' ');
        }
        sstack.push(str[i]);
      }
      if (str[i] == '/')
      {
        if (!sstack.empty() && (sstack.top() == '*' || sstack.top() == '/'))
        {
          outstr.push_back(sstack.top());
          sstack.pop();
          outstr.push_back(' ');
        }
        sstack.push(str[i]);
      }
      if (str[i] == '(')
      {
        sstack.push(str[i]);
      }
      if (str[i]== ')')
      {
        while(sstack.top() != '(')
        {
          outstr.push_back(sstack.top());
          sstack.pop();
          outstr.push_back(' ');
        }
        sstack.pop();
      }
      if (str[i] == '^')
      {
        if (!sstack.empty() && (sstack.top() == '^'))
        {
          outstr.push_back(sstack.top());
          sstack.pop();
          outstr.push_back(' ');
        }
        sstack.push(str[i]);
      }
  }

  while (!sstack.empty())
  {
    outstr.push_back(sstack.top());
    sstack.pop();
    outstr.push_back(' ');
  }

  return outstr;
}
double mpow(double num, double degree)
{
  if (degree==0) return 1;
  if (degree>0) return (num*mpow(num,degree-1));
  if (degree<0) return (1/(num*mpow(num,degree-1)));
}

double solver(string str)
{
  double answer(0);
  size_t k(0);
  size_t k2(0);
  double temp;
  vector<double> operand;
  for (size_t i = 0; i< str.length(); ++i)
  {
    if (isdigit(str[i]))
    {
      operand.insert(operand.begin()+k, number(str,i));
      ++k;
    }
    if (str[i] == '+')
      {
        temp = operand[k-2]+operand[k-1];
        operand.erase(operand.begin()+k-2, operand.begin()+k);
        k -= 1;

        operand.insert(operand.begin()+k-1, temp);
      }
    if (str[i] == '-')
    {
      temp = operand[k-2]-operand[k-1];
      operand.erase(operand.begin()+k-2, operand.begin()+k);
      k -= 1;
      operand.insert(operand.begin()+k-1, temp);
    }
    if (str[i] == '*')
    {
      temp = operand[k-2]*operand[k-1];
      operand.erase(operand.begin()+k-2, operand.begin()+k);
      k -= 1;
      operand.insert(operand.begin()+k-1, temp);
    }
    if (str[i] == '/')
    {
      temp = operand[k-2]/operand[k-1];
      operand.erase(operand.begin()+k-2, operand.begin()+k);
      k -= 1;
      operand.insert(operand.begin()+k-1, temp);
    }
    if (str[i] == '^')
    {
      temp = mpow(operand[k-2],operand[k-1]);
      operand.erase(operand.begin()+k-2, operand.begin()+k);
      k -= 1;
      operand.insert(operand.begin()+k-1, temp);
    }
  }
  answer = *(operand.begin());
  return answer;
}
