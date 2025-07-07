#include "bst.h"
#include <format>

BST::BST() {
  root = nullptr;
}

BST::u_node BST::create_leaf(int value) {
  return std::make_unique<Node>(value);
}

void BST::add_leaf(int value) {
  m_add_leaf(value, std::move(root));
}

void BST::m_add_leaf(int value, u_node&& ptr) {
  if(!ptr) {
    root = create_leaf(value);
  } else if(value < ptr->value) {
    if(ptr->left) {
      m_add_leaf(value, std::move(ptr->left));
    } else {
      ptr->left = create_leaf(value);
    }
  } else if(value > ptr->value) {
    if(ptr->right) {
      m_add_leaf(value, std::move(ptr->right));
    } else {
      ptr->right = create_leaf(value);
    }
  } else {
    throw std::runtime_error(std::format("key {} already exists", value));
  }
}