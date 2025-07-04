#include <memory>
#include <stdexcept>
#include <variant>
#include <vector>

struct Node { // abstract base class node
  int data;
  std::shared_ptr<Node> left;
  std::shared_ptr<Node> right;
  Node(int data): data(data), left(nullptr), right(nullptr) {}

  void add_child(int data);
  std::vector<int> in_order_traversal() const;
  bool search(int data);

  virtual ~Node() {};
};

struct BSTNode : public Node {
  BSTNode(int data): Node(data) {}
};