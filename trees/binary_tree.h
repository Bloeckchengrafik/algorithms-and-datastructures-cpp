#pragma once
#define Node BinaryNode
#include <iostream>

class BinaryNode {
    int value;
    BinaryNode* leftChild;
    BinaryNode* rightChild;


public:
    BinaryNode(int node_value)
        : value(node_value), leftChild(nullptr), rightChild(nullptr) {}

    void insertNode(int node_value) {
        if (node_value > this->value) {
            if (this->rightChild != nullptr) this->rightChild->insertNode(node_value);
            else this->rightChild = new Node(node_value);
        }
        else if (node_value < this->value) {
            if (this->leftChild != nullptr) this->leftChild->insertNode(node_value);
            else this->leftChild = new Node(node_value);
        }
    }

    void deleteNode(int node_value, Node **me) {
        if (this->leftChild != nullptr && this->rightChild != nullptr) {
            // two
            if (this->value == node_value) {
                *me = this->rightChild;
                auto t = this->rightChild;
                while (t->leftChild != nullptr) {
                    t = t->leftChild;
                }
                t->leftChild = this->leftChild;
            } else {
                if (this->value < node_value)  this->leftChild->deleteNode(node_value, &this->rightChild);
                else this->rightChild->deleteNode(node_value, &this->rightChild);
            }
        } else if (this->leftChild != nullptr) {
            // one left
            if (this->value == node_value) *me = this->leftChild;
            else this->leftChild->deleteNode(node_value, &this->rightChild);
        } else if (this->rightChild != nullptr) {
            // one right
            if (this->value == value) *me = this->rightChild;
            else this->rightChild->deleteNode(node_value, &this->rightChild);
        } else {
            // none
            if (this->value == value) *me = nullptr;
        }
    }

    Node* searchNode(int node_value) {
        if (node_value == this->value) return this;
        if (node_value < this->value) {
            if (this->leftChild != nullptr) return this->leftChild->searchNode(node_value);
            return nullptr;
        }
        if (node_value > this->value) {
            if (this->rightChild != nullptr) return this->rightChild->searchNode(node_value);
            return nullptr;
        }
    }

    void preOrder() {
        std::cout << value << " ";
        if (this->leftChild != nullptr) this->leftChild->preOrder();
        if (this->rightChild != nullptr) this->rightChild->preOrder();
    }

    void inOrder() {
        if (this->leftChild != nullptr) this->leftChild->inOrder();
        std::cout << value << " ";
        if (this->rightChild != nullptr) this->rightChild->inOrder();
    }

    void postOrder() {
        if (this->leftChild != nullptr) this->leftChild->postOrder();
        if (this->rightChild != nullptr) this->rightChild->postOrder();
        std::cout << value << " ";
    }
};

class BinaryTree {
    Node* rootNode;

public:
    void insertNode(int node_value) {
        if (rootNode == nullptr) rootNode = new Node(node_value);
        else {
            rootNode->insertNode(node_value);
        }
    }

    void deleteNode(int node_value) {
        if (rootNode == nullptr) return;

    }

    Node* searchNode(int node_value) {
        if (rootNode == nullptr) return nullptr;
        rootNode->searchNode(node_value);
    }

    void preOrder() {
        if (this->rootNode != nullptr) this->rootNode->preOrder();
    }

    void inOrder() {
        if (this->rootNode != nullptr) this->rootNode->inOrder();
    }

    void postOrder() {
        if (this->rootNode != nullptr) this->rootNode->postOrder();
    }
};