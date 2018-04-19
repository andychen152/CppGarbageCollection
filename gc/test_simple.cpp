#include "gc.h"
#include "node.h"
#include <iostream>
#include <assert.h>

using namespace std;

int main(){
	for (int i = 0; i < 100; i++) {
		Node *n = new Node(10);		
		if (i%10 == 0) 
			assert(GarbageCollector::GC.live() == 1);
		GarbageCollector::GC.collect();
	}
	cout << "Pass\n";
	return 0;
}