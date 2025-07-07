#include <array>
#include <iostream>
#include <cstdlib>

#include "src/bst.h"

using std::cout;

int main() {
  std::array<int, 16> keys{
    50, 76, 21, 4, 32, 64, 15, 52, 14, 100, 83, 2, 3, 70, 87, 80
  };
  BST my_tree;

  cout << "printing in order\nbefore adding numbers\n";

  my_tree.pretty_print();
  
  cout << "printing in order\nfter adding numbers\n";

  for(int i=0; i<16; i++) {
    my_tree.add_leaf(keys.at(i));
  }

  my_tree.pretty_print();

  return 0;
}