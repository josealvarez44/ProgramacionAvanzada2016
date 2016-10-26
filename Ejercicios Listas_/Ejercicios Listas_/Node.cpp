#include "stdafx.h"
#include "Node.h"


CNode::CNode(int _value)
{
	value = _value;
	previous = NULL;
	next = NULL;
}


CNode::~CNode()
{
}
