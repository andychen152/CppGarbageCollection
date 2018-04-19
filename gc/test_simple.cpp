#include "gc.h"
#include "node.h"
#include <iostream>

using namespace std;

bool test_MemoryLeakLoop() {
	for (int i = 0; i < 100; i++) {
		Node *n = new Node();		
		if (i%10 == 0) { 
			if (GarbageCollector::GC.live() != 1)
				return false;
		}
		GarbageCollector::GC.collect();
	}
	return true;
}

int main(){
	cout << "test_MemoryLeakLoop: "; 
	if (test_MemoryLeakLoop())
		cout << "pass\n";
	else
		cout << "fail\n";

	// add more tests
	// use an actual testing framework

	return 0;
}