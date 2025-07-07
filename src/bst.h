#include <memory>
class BST {
private:
  struct Node;

  using u_node = std::unique_ptr<Node>;

  struct Node {
    int value;
    u_node left, right;

    Node(int value, u_node&& left = nullptr, u_node&& right = nullptr)
      : value(value), left(std::move(left)), right(std::move(right)) {}
  };

  u_node root;

  void m_add_leaf(int key, u_node&& ptr);

public:
  BST();
  u_node create_leaf(int value);
  void add_leaf(int key);
};