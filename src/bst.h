#include <memory>
#include <optional>

class BST {
private:
  struct Node;

  using s_node = std::shared_ptr<Node>;

  struct Node {
    int value;  
    s_node left, right;

    Node(int value, const s_node& left = nullptr, const s_node& right = nullptr)
      : value(value), left(left), right(right) {}
  };

  s_node root;

  void m_add_leaf(int key, const s_node& ptr);
  void m_pretty_print(const s_node& ptr) const;
  s_node m_return_node(int value, const s_node& ptr) const;

public:
  BST();
  s_node create_leaf(int value);
  void add_leaf(int key);
  void pretty_print() const; // in order from least to greatest
  s_node return_node(int value) const;
  std::optional<int> return_root_key() const;
  void print_children(int key) const;
};