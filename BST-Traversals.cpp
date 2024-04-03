#include <iostream>
#include <string>
#include <vector>

template <typename T> class TreeNode {
public:
  T data;
  TreeNode *left, *right;

  TreeNode(T data) : data(data), left(nullptr), right(nullptr) {}
};

template <typename T> class BinarySearchTree {
private:
  TreeNode<T> *root;

  void insert(TreeNode<T> *&node, T data) {
    if (node == nullptr) {
      node = new TreeNode<T>(data);
    } else if (data < node->data) {
      insert(node->left, data);
    } else {
      insert(node->right, data);
    }
  }

  void preorderTraversal(TreeNode<T> *node) {
    if (node != nullptr) {
      std::cout << node->data << " ";
      preorderTraversal(node->left);
      preorderTraversal(node->right);
    }
  }

  void inorderTraversal(TreeNode<T> *node) {
    if (node != nullptr) {
      inorderTraversal(node->left);
      std::cout << node->data << " ";
      inorderTraversal(node->right);
    }
  }

  void postorderTraversal(TreeNode<T> *node) {
    if (node != nullptr) {
      postorderTraversal(node->left);
      postorderTraversal(node->right);
      std::cout << node->data << " ";
    }
  }

public:
  BinarySearchTree() : root(nullptr) {}

  void insert(T data) { insert(root, data); }

  void display(int traversalType) {
    switch (traversalType) {
    case 1:
      std::cout << "Preorder Traversal: ";
      preorderTraversal(root);
      break;
    case 2:
      std::cout << "Inorder Traversal: ";
      inorderTraversal(root);
      break;
    case 3:
      std::cout << "Postorder Traversal: ";
      postorderTraversal(root);
      break;
    default:
      std::cout << "Invalid traversal type\n";
    }
    std::cout << std::endl;
  }
};

int main() {
  BinarySearchTree<std::string> stringTree;
  std::vector<std::string> stringData = {
      "Milton",    "Ajax",     "Clarington",  "Brock",      "Oshawa",
      "Pickering", "Uxbridge", "Whitby",      "Burlington", "Oakville",
      "Brampton",  "Caledon",  "Mississauga", "Aurora",     "Georgina"};
  for (const auto &str : stringData) {
    stringTree.insert(str);
  }

  BinarySearchTree<int> intTree;
  std::vector<int> intData = {95, 301, 501, 801, 90, 70, 80, 25, 67, 89, 11};
  for (int num : intData) {
    intTree.insert(num);
  }

  BinarySearchTree<double> decimalTree;
  std::vector<double> decimalData = {84.8, 103.5, 67.8, 90.3,  23.5,
                                     67.1, 44.5,  89.2, 100.5, 300.2};
  for (double num : decimalData) {
    decimalTree.insert(num);
  }

  int choice, dataType;
  std::cout << "Select data type (1: String, 2: Integer, 3: Decimal): ";
  std::cin >> dataType;
  std::cout
      << "Choose traversal type (1: Preorder, 2: Inorder, 3: Postorder): ";
  std::cin >> choice;

  switch (dataType) {
  case 1:
    stringTree.display(choice);
    break;
  case 2:
    intTree.display(choice);
    break;
  case 3:
    decimalTree.display(choice);
    break;
  default:
    std::cout << "Invalid data type\n";
  }

  return 0;
}
