// AlgebraicExpressions.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <stack>
#include "Expression.h";
#include <iostream>
using namespace std;

int main()
{
	string expression = "2*(2*3)^2";
	Expression exp;
	string post, pre;
	//post = exp.toPostfix(expression);
	pre = exp.toPrefix(expression);
	BinaryTreeNode* bt = exp.prefixToBinaryTree(pre);
	cout << expression << "\n" << post << "\n" << pre;
	cin >> expression;
    return 0;
}

