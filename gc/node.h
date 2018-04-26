#ifndef NODE_H
#define NODE_H

#include "gc.h"

class Node : public GCObject  {
	/**
	24 bytes
	**/
	public:
		int value;
		Node *next;

		Node () { value = 0; next = 0; }
		Node (int v) { value = v; next = 0; }
};

class BigNode : public GCObject  {
	/**
	400024 bytes
	**/
	public:
		int value[100000];
		BigNode *next;

		BigNode () { next = 0; }
		BigNode (int v) { value[0] = v; next = 0; }
};

#endif
