#include "../gc.h"
#include "../node.h"
#include "../BigNode.h"
#include <cassert>
#include <iostream>


bool test1() {
	/**
	basic test
	**/

	for (int i = 0; i < 100; i++) {
		assert(GarbageCollector::GC.live() == i);
		Node *n = new Node();
	}
	GarbageCollector::GC.collect();
	assert(GarbageCollector::GC.live() == 0);
	return true;
}

bool test2() {
	/**
	basic test 
	**/

	for (int i = 0; i < 100; i++) {
		if (i%50 == 1) 
			GarbageCollector::GC.collect();
	}
	assert(GarbageCollector::GC.live() == 0);
	return true;
}

bool test3() {
	/**
	basic test
	**/

	for (int i = 0; i < 100; i++) {
		Node *n = new Node();		
		if (i%10 == 0) { 
			if (GarbageCollector::GC.live() != 1)
				return false;
		}
		GarbageCollector::GC.collect();
	}

	assert(GarbageCollector::GC.live() == 0);
	return true;
}

bool test4() {
	/**
	stress test
	not sure how to set limit on heap to get the program to fail 
	but you can clearly see the difference when you comment out the collect vs with it there
	**/

	long long bigNum = 10000; // can set larger number once we are able to limit heap

	for (long long i = 0; i < bigNum; i++) {

		BigNode *n = new BigNode();

		// if (i % 10000 == 0)
		// 	GarbageCollector::GC.collect();

	}

	GarbageCollector::GC.collect();

	assert(GarbageCollector::GC.live() == 0);
	return true;

}

bool test5() {
	/**
	test with manual delete
	**/

	for (int i = 0; i < 100; i++) {
		Node *n = new Node();
		if (i%2==0) 
			delete n;
	}
	assert (GarbageCollector::GC.live() == 50);

	GarbageCollector::GC.collect();

	assert(GarbageCollector::GC.live() == 0);
	return true;
}

bool test6() {
	/**
	simple test with multiple type of object allocation
	**/

	int NUM = 1000;

	for (int i = 0; i < NUM; i++) {
		if (rand() % 3 == 0) {
			Node *n = new Node();
		}
		else if (rand () % 3 == 1) {
			BigNode *n = new BigNode();
		}
	}

	GarbageCollector::GC.collect();

	assert(GarbageCollector::GC.live() == 0);
	return true;	
}

bool test7() {
	/**
	testing collect with referenced object
	**/
	/**
	Error: GC.live() not working
	should be 1 after collect line, but showing 0.
	**/

	Node *n = new Node();
	GarbageCollector::GC.collect();
	assert (GarbageCollector::GC.live() == 1);
	return true;

}


// bool test8() {
// 	/**
// 	ERROR: FIX
// 	test with reference still there
// 	**/

// 	Node *n = new Node();

// 	assert(GarbageCollector::GC.live() == 1);
// 	delete n; // this is not deleting for some reason

// 	assert(GarbageCollector::GC.live() == 0); 
// 	return true;
// }

// bool test9() {
// 	/**
// 	linked list 
// 	**/

// 	Node *n = new Node();

// 	for (int i = 0; i < 100; i++) {
// 		n = n->next;
// 		n = new Node();
// 	}
// 	GarbageCollector::GC.collect();
// 	std::cout << GarbageCollector::GC.live() << std::endl;

// 	assert(GarbageCollector::GC.live() == 100);

// 	return true;

// 	n = NULL;
// 	assert(GarbageCollector::GC.live() == 1);

// 	GarbageCollector::GC.collect();

// 	assert(GarbageCollector::GC.live() == 0);
// 	return true;
// }




int main(){
	std::cout << "test_MemoryLeakLoop: " << std::endl; 

	assert(test1());
	std::cout << "Test 1 Passed" << std::endl;

	assert(test2());
	std::cout << "Test 2 Passed" << std::endl;

	assert(test3());
	std::cout << "Test 3 Passed" << std::endl;

	assert(test4());
	std::cout << "Test 4 Passed" << std::endl;

	assert(test5());
	std::cout << "Test 5 Passed" << std::endl;

	assert(test6());
	std::cout << "Test 6 Passed" << std::endl;

	assert(test7()); // Does not work, live is not working as expected
	std::cout << "Test 7 Passed" << std::endl;

	// Has Error
	// assert(test7()); 
	// std::cout << "Test 8 Passed" << std::endl;

	// assert(test8());
	// std::cout << "Test 9 Passed" << std::endl;
	

	std::cout << "All Passed" << std::endl;
	// add more tests
	// use an actual testing framework

	return 0;
}