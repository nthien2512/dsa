#include <iostream>
using namespace std;

class TreeNode {
public:
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    TreeNode* root;

    TreeNode* addNode(TreeNode* node, int key) {
        if (!node) return new TreeNode(key);
        if (key < node->value) node->left = addNode(node->left, key);
        else if (key > node->value) node->right = addNode(node->right, key);
        return node;
    }

    TreeNode* findMin(TreeNode* node) {
        while (node->left) node = node->left;
        return node;
    }

    TreeNode* deleteNode(TreeNode* node, int key) {
        if (!node) return node;
        if (key < node->value) node->left = deleteNode(node->left, key);
        else if (key > node->value) node->right = deleteNode(node->right, key);
        else {
            if (!node->left) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            } else if (!node->right) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }
            TreeNode* temp = findMin(node->right);
            node->value = temp->value;
            node->right = deleteNode(node->right, temp->value);
        }
        return node;
    }

    bool searchNode(TreeNode* node, int key) {
        if (!node) return false;
        if (key < node->value) return searchNode(node->left, key);
        else if (key > node->value) return searchNode(node->right, key);
        return true;
    }

    void inorder(TreeNode* node) {
        if (node) {
            inorder(node->left);
            cout << node->value << " ";
            inorder(node->right);
        }
    }

    void preorder(TreeNode* node) {
        if (node) {
            cout << node->value << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }

    void postorder(TreeNode* node) {
        if (node) {
            postorder(node->left);
            postorder(node->right);
            cout << node->value << " ";
        }
    }

    int height(TreeNode* node) {
        if (!node) return 0;
        return max(height(node->left), height(node->right)) + 1;
    }

    int findMax(TreeNode* node) {
        while (node->right) node = node->right;
        return node->value;
    }

    int findMinValues(TreeNode* node) {
        while (node->left) node = node->left;
        return node->value;
    }

public:
    BinaryTree() : root(nullptr) {}

    void addNode(int key) {
        root = addNode(root, key);
    }

    void deleteNode(int key) {
        root = deleteNode(root, key);
    }

    bool searchNode(int key) {
        return searchNode(root, key);
    }

    void inorder() {
        inorder(root);
        cout << endl;
    }

    void preorder() {
        preorder(root);
        cout << endl;
    }

    void postorder() {
        postorder(root);
        cout << endl;
    }

    int height() {
        return height(root);
    }

    int findMax() {
        if (!root) throw runtime_error("Tree is empty");
        return findMax(root);
    }

    int findMin() {
        if (!root) throw runtime_error("Tree is empty");
        return findMinValues(root);
    }
};