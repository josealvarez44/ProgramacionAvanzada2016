#pragma once
class CNode
{

public:
	CNode();
	~CNode();
	int value;
	CNode* previous;
	CNode* next;
};

