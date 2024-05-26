// Khái niệm cây tổng quát
/*
Cây tổng quát (General Tree) là một cấu trúc dữ liệu dạng cây mà mỗi nút có thể có nhiều hơn hai nút con.
*/

// Cấu trúc lớp của cây tổng quát
#include <iostream>
#include <vector>

template <class N>
class Node {
public:
  N value;
  std::vector<Node<N>*> children;

  Node(N val) : value(val) {}
};

template <class G>
class GT {
private:
  Node<G>* root;

  Node<G>* insertRecursive(Node<G>* node, G value) {
    if (node == nullptr) {
      return new Node<G>(value);
    }
    node->children.push_back(new Node<G>(value));
    return node;
  }

  Node<G>* searchRecursive(Node<G>* node, G value) {
    if (node == nullptr) {
      return nullptr;
    }
    if (node->value == value) {
      return node;
    }
    for (Node<G>* child : node->children) {
      Node<G>* result = searchRecursive(child, value);
      if (result != nullptr) {
        return result;
      }
    }
    return nullptr;
  }

  Node<G>* deleteRecursive(Node<G>* node, G value) {
    if (node == nullptr) {
      return node;
    }
    if (node->value == value) {
      delete node;
      return nullptr;
    }
    for (Node<G>* child : node->children) {
      child = deleteRecursive(child, value);
    }
    return node;
  }

  void inorderRecursive(Node<G>* node) {
    if (node == nullptr) {
      return;
    }
    for (Node<G>* child : node->children) {
      inorderRecursive(child);
    }
    std::cout << node->value << " ";
  }

  void preorderRecursive(Node<G>* node) {
    if (node == nullptr) {
      return;
    }
    std::cout << node->value << " ";
    for (Node<G>* child : node->children) {
      preorderRecursive(child);
    }
  }

  void postorderRecursive(Node<G>* node) {
    if (node == nullptr) {
      return;
    }
    for (Node<G>* child : node->children) {
      postorderRecursive(child);
    }
    std::cout << node->value << " ";
  }
};