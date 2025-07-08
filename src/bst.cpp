#include "bst.h"
#include <format>
#include <iostream>

BST::BST() {
  root = nullptr;
}

BST::s_node BST::create_leaf(int value) {
  return std::make_unique<Node>(value);
}

void BST::add_leaf(int value) {
  m_add_leaf(value, root);
}

void BST::m_add_leaf(int value, const s_node& ptr) {
  if(!ptr) {
    root = create_leaf(value);
  } else if(value < ptr->value) {
    if(ptr->left) {
      m_add_leaf(value, ptr->left);
    } else {
      ptr->left = create_leaf(value);
    }
  } else if(value > ptr->value) {
    if(ptr->right) {
      m_add_leaf(value, ptr->right);
    } else {
      ptr->right = create_leaf(value);
    }
  } else {
    throw std::runtime_error(std::format("key {} already exists", value));
  }
}

void BST::pretty_print() const {
  m_pretty_print(root);
}

void BST::m_pretty_print(const s_node& ptr) const {
  // recursively traverse tree from lowest to highest
  if(root) {
    if(ptr->left) { // step 1 go left part recursively if possible
      m_pretty_print(ptr->left);
    }
    std::cout << ptr->value << ' '; // step 2 just print
    if(ptr->right) { // step 3 go right part recursively if possible
      m_pretty_print(ptr->right);
    }

  } else {
    std::cout << "tree is empty\n";
  }
}

BST::s_node BST::return_node(int value) const {
  return m_return_node(value, root);
}

BST::s_node BST::m_return_node(int value, const s_node& ptr) const {
  if(ptr) {
    if(ptr->value == value) {
      return ptr;
    } else {
      if(value < ptr->value) {
        return m_return_node(value, ptr->left);
      } else {
        return m_return_node(value, ptr->right);
      }
    }
  } else {
    return nullptr;
  }
}

std::optional<int> BST::return_root_key() const {
  if(root) {
    return root->value;
  } else {
    return std::nullopt;
  }
}

void BST::print_children(int key) const {
  s_node ptr = return_node(key); // if that key exists just return pointer to it
  // this wil be nullptr if key doesnt exist

  if(ptr) {
    std::cout << std::format("parent node: {}", ptr->value)
              << '\n';

    !ptr->left ? std::cout << "left child is null\n"
               : std::cout << std::format("left child: {}", ptr->left->value) << '\n';

    !ptr->right ? std::cout << "right child is null\n"
                : std::cout << std::format("right child: {}", ptr->right->value) << '\n';
  } else {
    std::cout << std::format("key {} does not exist in the tree", key) << '\n';
  }
}