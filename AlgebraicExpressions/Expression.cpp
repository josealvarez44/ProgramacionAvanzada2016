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
	//Start with an empty string.
	string prefix = "";	

	//A stack to order operators until they can be written on the 
	//prefix expression.
	stack<string> operators;

	//Traverse the infix expression from last element to first element.
	for (int i = exp.length() ; i > 0; i--)
	{
		//Get previous element on string.
		string currentItem = exp.substr(i-1, 1);

		// If the element is a number, constant or variable 
		// Prepend it to the final prefix expression.
		if (isDigit(currentItem))
		{
			prefix = currentItem+prefix;
			continue;
		}

		//If the current element is an operator we need to check for hierarchies and grouping orders.
		if (isOperator(currentItem))
		{
			//If the stack is not empty, we have to pop out from the stack any 
			//elements that have greater or equal hierarchy that the current element 
			//except when the  top element in the stack is a closing parenthesis.
			while ((!operators.empty()) && (operators.top() != ")") &&
				(hierarchy(operators.top()) >= hierarchy(currentItem)))
			{
				prefix = operators.top() + prefix;
				operators.pop();
			}
			

			//If the current element is an opening parenthesis we pop out everything
			//until we find a closing parentesis.
			if (currentItem == "(")
			{
				while (operators.top() != ")")
				{
					prefix = operators.top() + prefix;
					operators.pop();
				}
				//We take out the closing parentesis (needed because the while does not
				//pops it out)
				operators.pop();
				continue;
			}
			//Push the operator is none of the other two conditions was met.
			operators.push(currentItem);
		}
	}

	//Clear any remaining elements on stack.
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
	if (op == ")")
		return INT_MAX;
	if (op == "(")
		return INT_MIN;
	if (op == "+" || op == "-")
		return 1;
	if (op == "*" || op == "/")
		return 2;
	if (op == "^" || op == "^")
		return 3;
	if (op == "~")
		return 10;
}

bool Expression::isOperator(string op)
{
	string operators = "~+-*/^()";
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
