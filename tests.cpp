#include "src/bst.h"
#include <iostream>

BSTNode build(const std::vector<int>& elements) {
	BSTNode root(elements.at(0));

	for(int i=0; i<(int)elements.size(); i++) {
		root.add_child(elements.at(i));
	}

	return root;
}

int main() {
	std::vector<int> numbers{17, 4, 1, 20, 9, 23, 18, 34};
	BSTNode numbers_tree = build(numbers);
	std::vector<int> in_order = numbers_tree.in_order_traversal();

	std::cout << '[';
	for(int i=0; i<(int)in_order.size(); i++) {
		std::cout << in_order.at(i);

		if(i!=(int)in_order.size()-1) {
			std::cout << ", ";
		}
	}
	std::cout << "]\n";
}