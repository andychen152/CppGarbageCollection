#ifndef BIG_NODE_H
#define BIG_NODE_H

#include "gc.h"

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