/*
Solved a problem from a Google interview for a junior position.
Time Complexity:O(n)
Space Complexity:O(n)
It was something like this:
Problem: Evaluate Nested Function Expressions

You are given a string representing a mathematical expression written in function notation.

The supported operations are:

- add(a, b)  -> returns a + b
- sub(a, b)  -> returns a - b
- mult(a, b) -> returns a * b
- div(a, b)  -> returns a / b
- pow(a, b)  -> returns a^b

Each function takes exactly two arguments. An argument can be either an integer or another function call, allowing expressions to be nested.

Your task is to evaluate the given expression and output its result.

Input
A single string representing a valid expression.

Output
Print the result of evaluating the expression.

Constraints
- The input expression is always valid.
- Every operation has exactly two arguments.
- Arguments are either integers or valid nested function calls.
- Division by zero will not occur.

Examples

Input
add(1,2)

Output
3

Input
sub(1,5)

Output
-4

Input
add(2,mult(5,pow(5,2)))

Output
127
*/
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <cmath>
using namespace std;
double aplicaOperatie(const string& operatie, double a, double b)
{
	if (operatie == "add") return a + b;
	if (operatie == "sub") return a - b;
	if (operatie == "mult") return a * b;
	if (operatie == "div") return a / b;
	if (operatie == "pow") return pow(a, b);
	return 0;
}
int main()
{
	string expresie;
	cin >> expresie;
	queue<string> operatiiOrdonate;
	queue<double> numere;
	stack<string> operatiiCurente;
	for (int i = 0; i < (int)expresie.size(); )
	{
		char c = expresie[i];
		if (isalpha(c))
		{
			string numeOperatie;
			while (i < (int)expresie.size() && isalpha(expresie[i]))
			{
				numeOperatie += expresie[i];
				i++;
			}
			operatiiCurente.push(numeOperatie);
		}
		else if (isdigit(c))
		{
			int numar = 0;
			while (i < (int)expresie.size() && isdigit(expresie[i]))
			{
				numar = numar * 10 + (expresie[i] - '0');
				i++;
			}
			numere.push(numar);
		}
		else if (c == ')')
		{
			operatiiOrdonate.push(operatiiCurente.top());
			operatiiCurente.pop();
			i++;
		}
		else
		{
			i++;
		}
	}
	while (!operatiiOrdonate.empty())
	{
		double a = numere.front(); numere.pop();
		double b = numere.front(); numere.pop();
		double rezultat = aplicaOperatie(operatiiOrdonate.front(), a, b);
		operatiiOrdonate.pop();
		numere.push(rezultat);
	}
	cout << numere.front();
	return 0;
}