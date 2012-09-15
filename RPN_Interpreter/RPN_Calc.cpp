/*
 * RPN_Calc.cpp
 *
 *  Created on: 2012-9-14
 *      Author: HalFtaN
 *
 *  Calculates RPN expressions
 */

#include <cctype>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

void add(stack<float>*);
void substract(stack<float>*);
void multi(stack<float>*);
void divide(stack<float>*);

int dmain(void) {
	stack<float> data;
	string input;
	cin >> input;
	typedef string::const_iterator si;
	for (si i = input.begin(); i != input.end(); i++) {
		if (isdigit(*i))
			data.push(*i - (float)'0');
		else
			switch (*i) {
			case '+':
				add(&data);
				break;
			case '-':
				substract(&data);
				break;
			case '*':
				multi(&data);
				break;
			case '/':
				divide(&data);
				break;
			default:
				cerr << "Error input!" << endl;
				exit(2);
			}
	}
	if (data.size() != 1) {
		cerr << "Invalid input!" << endl;
		exit(3);
	}
	cout << "The result is " << data.top() << endl;
	return 0;
}
void add(stack<float> *data) {
	int a = data->top();
	data->pop();
	data->top() += a;
}
void substract(stack<float> *data) {
	int a = data->top();
	data->pop();
	data->top() -= a;
}
void multi(stack<float> *data) {
	int a = data->top();
	data->pop();
	data->top() *= a;
}
void divide(stack<float> *data) {
	int a = data->top();
	data->pop();
	data->top() /= a;
}
