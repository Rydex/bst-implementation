#include "bst.h"

BST::BST() {
  root = nullptr;
}

BST::u_node BST::create_leaf(int value) {
  return std::make_unique<Node>(value);
}