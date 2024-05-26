// Khái niệm cây tìm kiếm nhị phân
/* 
Cây tìm kiếm nhị phân (Binary Search Tree) là một cấu trúc dữ liệu dạng cây mà mỗi nút có tối đa hai nút con, 
nút con bên trái có giá trị nhỏ hơn nút cha và nút con bên phải có giá trị lớn hơn nút cha. 
*/

// Cấu trúc lớp của cây tìm kiếm nhị phân
#include <iostream>
#include <vector>
#include <algorithm>

template <class N>
class Node {
public:
  N value;
  Node<N>* left;
  Node<N>* right;

  Node(N val) : value(val), left(nullptr), right(nullptr) {}
};

template <class B>
class BT {
private:
  Node<B>* root;

  Node<B>* insertRecursive(Node<B>* node, B value) {
    if (node == nullptr) {
      return new Node<B>(value);
    }
    if (value < node->value) {
      node->left = insertRecursive(node->left, value);
    } else if (value > node->value) {
      node->right = insertRecursive(node->right, value);
    }
    return node;
  }

  Node<B>* deleteRecursive(Node<B>* node, B value) {
    if (node == nullptr) {
      return node;
    }
    if (value < node->value) {
      node->left = deleteRecursive(node->left, value);
    } else if (value > node->value) {
      node->right = deleteRecursive(node->right, value);
    } else {
      if (node->left == nullptr) {
        Node<B>* temp = node->right;
        delete node;
        return temp;
      } else if (node->right == nullptr) {
        Node<B>* temp = node->left;
        delete node;
        return temp;
      }
      Node<B>* temp = minValueNode(node->right);
      node->value = temp->value;
      node->right = deleteRecursive(node->right, temp->value);
    }
    return node;
  }

  Node<B>* maxValueNode(Node<B>* node) {
    Node<B>* current = node;
    while (current && current->right != nullptr) {
      current = current->right;
    }
    return current;
  }

  Node<B>* minValueNode(Node<B>* node) {
    Node<B>* current = node;
    while (current && current->left != nullptr) {
      current = current->left;
    }
    return current;
  }

  bool searchRecursive(Node<B>* node, B value) {
    if (node == nullptr) {
      return false;
    }
    if (node->value == value) {
      return true;
    }
    if (value < node->value) {
      return searchRecursive(node->left, value);
    } else {
      return searchRecursive(node->right, value);
    }
  }

  void inorderTraversal(Node<B>* node, std::vector<B>& result) {
    if (node == nullptr) {
      return;
    }
    inorderTraversal(node->left, result);
    result.push_back(node->value);
    inorderTraversal(node->right, result);
  }

  void preorderTraversal(Node<B>* node, std::vector<B>& result) {
    if (node == nullptr) {
      return;
    }
    result.push_back(node->value);
    preorderTraversal(node->left, result);
    preorderTraversal(node->right, result);
  }

  void postorderTraversal(Node<B>* node, std::vector<B>& result) {
    if (node == nullptr) {
      return;
    }
    postorderTraversal(node->left, result);
    postorderTraversal(node->right, result);
    result.push_back(node->value);
  }

  int heightRecursive(Node<B>* node) {
    if (node == nullptr) {
      return -1;
    }
    return 1 + std::max(heightRecursive(node->left), heightRecursive(node->right));
  }

public:
  BST() : root(nullptr) {}

  void insert(B value) {
    root = insertRecursive(root, value);
  }

  void remove(B value) {
    root = deleteRecursive(root, value);
  }

  bool search(B value) {
    return searchRecursive(root, value);
  }

  std::vector<B> inorder() {
    std::vector<B> result;
    inorderTraversal(root, result);
    return result;
  }

  std::vector<B> preorder() {
    std::vector<B> result;
    preorderTraversal(root, result);
    return result;
  }

  std::vector<B> postorder() {
    std::vector<B> result;
    postorderTraversal(root, result);
    return result;
  }

  int height() {
    return heightRecursive(root);
  }
};