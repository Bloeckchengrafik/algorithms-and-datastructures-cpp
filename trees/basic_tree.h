#pragma once
#include <vector>
#include <iostream>

class Node {
    int value;
    std::vector<Node*> children;
public:
    Node(int node_value)
        : value(node_value) {}

    Node* add_child(int child_value) {
        Node* child = new Node(child_value);
        this->children.push_back(child);
        return child;
    }

    void preOrder() {
        std::cout << value << " ";
        for (Node* child_node : children) {
            child_node->preOrder();
        }
    }

    void postOrder() {
        // first value to be printed out is when children vector is empty
        // the leaf nodes (empty children vector) will be the ones last called and therefore first printed out
        for (Node* child_node : children) {
            child_node->postOrder();
        }
        std::cout << value << " ";
    }
};

class BasicTree {
    Node* rootNode;

public:
    BasicTree()
        : rootNode(nullptr) {}

    Node* setRootNode(int root_value) {
        Node* root = new Node(root_value);
        this->rootNode = root;
        return root;
    }

    void preOrder() {
        if (this->rootNode != nullptr) this->rootNode->preOrder();
    }

    void postOrder() {
        if (this->rootNode != nullptr) this->rootNode->postOrder();
    }

    // inOrder() is not defined for non-binary trees
};

