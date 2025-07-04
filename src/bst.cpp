#include "bst.h"

void Node::add_child(int data) {
  if(data == this->data)
    return;

  if(data < this->data) {
    if(this->left) {
      this->left->add_child(data);
    } else {
      this->left = std::make_unique<BSTNode>(data);
    }
  } else {
    if(this->right) {
      this->right->add_child(data);
    } else {
      this->right = std::make_unique<BSTNode>(data);
    }
  }
}

std::vector<int> Node::in_order_traversal() const {
  std::vector<int> elements;

  // visit left
  if(this->left) {
    elements.insert_range(elements.end(), this->left->in_order_traversal());
  }

  // visit base
  elements.push_back(data);

  // visit right
  if(this->right) {
    elements.insert_range(elements.end(), this->right->in_order_traversal());
  }

  return elements;
}

bool Node::search(int data) {
  
}