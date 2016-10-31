#include "stdafx.h"
#include "Expression.h"


string Expression::toPostfix(string exp)
{
	string postfix = "";
	stack<string> operators;
	string currentNumber = "";
	for (int i = 0; i < exp.length(); i++)
	{
		string currentItem = exp.substr(i, 1);

		if (isDigit(currentItem))
		{
			postfix += currentItem;
			continue;
		}

		if (isOperator(currentItem))
		{
			while ((!operators.empty()) &&
				(hierarchy(operators.top()) >= hierarchy(currentItem)))
			{
				postfix += operators.top(); 
				operators.pop();
			}
			operators.push(currentItem);
		}
	}
			
	while (!operators.empty())
	{
		postfix += operators.top(); operators.pop();
	}
		
	return postfix;
}

string Expression::toPrefix(string exp)
{
	string prefix = "";	
	stack<string> operators;
	string currentNumber = "";
	for (int i = exp.length() ; i > 0; i--)
	{
		string currentItem = exp.substr(i-1, 1);

		if (isDigit(currentItem))
		{
			prefix = currentItem+prefix;
			continue;
		}

		if (isOperator(currentItem))
		{
			while ((!operators.empty()) &&
				(hierarchy(operators.top()) >= hierarchy(currentItem)))
			{
				prefix = operators.top() + prefix;
				operators.pop();
			}
			operators.push(currentItem);
		}
	}

	while (!operators.empty())
	{
		prefix = operators.top() + prefix; operators.pop();
	}

	return prefix;
}

BinaryTreeNode* Expression::prefixToBinaryTree(string prefix)
{
	static int index = 0;
	BinaryTreeNode* tree = new BinaryTreeNode();
	string currentElement = prefix.substr(index++,1);
	
	if (isOperator(currentElement))
	{
		tree->value = currentElement;
		tree->left = prefixToBinaryTree(prefix);
		tree->right = prefixToBinaryTree(prefix);
	}	

	if (isDigit(currentElement))
	{
		tree->value = currentElement;
	}

	return tree;

}

string Expression::removeExpression(string exp)
{
	return "";
}

int Expression::hierarchy(string op)
{
	if (op == "~")
		return 10;
	if (op == "+" || op == "-")
		return 1;
	if (op == "*" || op == "/")
		return 2;
	if (op == "^" || op == "^")
		return 3;
}

bool Expression::isOperator(string op)
{
	string operators = "~+-*/^";
	return operators.find(op) != string::npos;
}

bool Expression::isUnaryOperator(string op)
{
	string operators = "~CST";
	return operators.find(op) != string::npos;
}

bool Expression::isDigit(string op)
{	
	return digits.find(op) != string::npos;
}

string Expression::operate(string op, string aExp, string bExp)
{
	float a, b, c;
	a = std::stof(aExp);
	if (bExp != "")
	{
		b = std::stof(bExp);

		if (op == "+")
		{
			c = a + b;
		}
		if (op == "-")
		{
			c = a - b;
		}
		if (op == "*")
		{
			c = a * b;
		}
		if (op == "/")
		{
			c = a / b;
		}
		
		if (op == "^")
		{
			c = pow(a, b);
		}
	}

	if (op == "~")
	{
		c = -a;
	}

	
		
	return to_string(c);
}
 
Expression::Expression()
{
}

Expression::~Expression()
{
}
