#pragma once
#include <string>
#include <stack>
#include "BinaryTreeNode.h"
using namespace std;

class Expression
{
public:
	const string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string expression;
	string toPostfix(string exp);
	string toPrefix(string exp);
	BinaryTreeNode* prefixToBinaryTree(string prefix);
	string removeExpression(string exp);
	int hierarchy(string op);
	bool isOperator(string op);
	bool isUnaryOperator(string op);
	bool isDigit(string op);
	bool isVariable(string op);
	string operate(string op, string a, string b);
	Expression();
	~Expression();
};

