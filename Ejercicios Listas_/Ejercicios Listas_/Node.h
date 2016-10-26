#pragma once
class CNode
{
public:
	CNode(int _value);
	~CNode();

	int value;
	CNode* previous;
	CNode* next;

};

