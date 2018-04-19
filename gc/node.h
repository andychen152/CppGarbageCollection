#ifndef NODE_H
#define NODE_H

#include "gc.h"

class Node : public GCObject  {
	public:
		int value;
		Node *next;

		Node () { value = 0; next = 0; }
		Node (int v) { value = v; next = 0; }
};

#endif
