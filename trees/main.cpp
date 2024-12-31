#include <iostream>
//#include "basic_tree.h"
#include "binary_tree.h"

int main (int argc, char *argv[]) {
  BinaryTree tree;
  tree.insertNode(9);
  tree.insertNode(13);
  tree.insertNode(13);
  tree.insertNode(11);
  tree.insertNode(6);
  tree.insertNode(3);
  tree.insertNode(17);
  tree.insertNode(15);
  tree.insertNode(12);

  tree.inOrder();
  return 0;
}
