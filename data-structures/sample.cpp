#include <iostream>
#include "binary_heap.hpp"

using std::cout;
using std::endl;

int main(int argc, char** argv) {
	BinaryHeap<int> heap;
	heap.add(20);
	heap.add(15);
	heap.add(40);
	cout << heap << endl;
	return 0;
}
