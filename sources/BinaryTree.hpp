#pragma once

#include <iostream>
#include <stdexcept>

namespace ariel {
    template<typename T>
    class BinaryTree {
    private:
        struct Node {
            Node *left;
            Node *right;
            Node *father;
            T data;

            Node(const T &value) : left(nullptr), right(nullptr), father(nullptr), data(value) {}
        };

    public:
        class preOrderIterator {
        private:
            Node *pointer_to_node;
        public:
            preOrderIterator(Node *ptr = nullptr) : pointer_to_node(ptr) {}

            bool operator!=(const preOrderIterator &iter) const {
                return pointer_to_node != iter.pointer_to_node;
            }

            bool operator==(const preOrderIterator &iter) const {
                return pointer_to_node == iter.pointer_to_node;
            }

            T &operator*() const {
                return pointer_to_node->data;
            }

            T *operator->() const {
                return &(pointer_to_node->data);
            }

            preOrderIterator &operator++() {
                pointer_to_node = pointer_to_node->left;
                return *this;
            }

            const preOrderIterator operator++(int) {
                preOrderIterator temp = *this;
                pointer_to_node = pointer_to_node->left;
                return temp;
            }
        };

        class inOrderIterator {
        private:
            Node *pointer_to_node;
        public:
            inOrderIterator(Node *ptr = nullptr) : pointer_to_node(ptr) {}

            bool operator!=(const inOrderIterator &iter) const {
                return pointer_to_node != iter.pointer_to_node;
            }

            bool operator==(const inOrderIterator &iter) const {
                return pointer_to_node == iter.pointer_to_node;
            }

            T &operator*() const {
                return pointer_to_node->data;
            }

            T *operator->() const {
                return &(pointer_to_node->data);
            }

            inOrderIterator &operator++() {
                Node *p;
                if (pointer_to_node == nullptr) {
                    throw std::invalid_argument("Cant increment end of iter");
                } else if (pointer_to_node->right != nullptr) {
                    pointer_to_node = pointer_to_node->right;
                    while (pointer_to_node->left != nullptr) {
                        pointer_to_node = pointer_to_node->left;
                    }
                } else {
                    p = pointer_to_node->father;
                    while (p != nullptr && pointer_to_node == p->right) {
                        pointer_to_node = p;
                        p = p->father;
                    }
                    pointer_to_node = p;
                }
                return *this;
            }

            const inOrderIterator operator++(int) {
                inOrderIterator temp = *this;
                pointer_to_node = pointer_to_node->left;
                return temp;
            }
        };

        class postOrderIterator {
        private:
            Node *pointer_to_node;
        public:
            postOrderIterator(Node *ptr = nullptr) : pointer_to_node(ptr) {}

            bool operator!=(const postOrderIterator &iter) const {
                return pointer_to_node != iter.pointer_to_node;
            }

            bool operator==(const postOrderIterator &iter) const {
                return pointer_to_node == iter.pointer_to_node;
            }

            T &operator*() const {
                return pointer_to_node->data;
            }

            T *operator->() const {
                return &(pointer_to_node->data);
            }


            /** if left and right == null go to parent
             *  if im a left child parent, go to uncle, and go left
             *  if im a right child parent, go to parent
             *
             */
            postOrderIterator &operator++() {
                if (pointer_to_node == nullptr) {
                    throw std::invalid_argument("Cant increment end of iter");
                }
                if (pointer_to_node->father == nullptr) {
                    pointer_to_node = nullptr;
                    return *this;
                }
                if (pointer_to_node->father->right == pointer_to_node) { // we are right child
                    pointer_to_node = pointer_to_node->father;
                    return *this;
                } else { // we are left child
                    if (pointer_to_node->father->right != nullptr) {
                        pointer_to_node = pointer_to_node->father->right;
                        while (pointer_to_node->left != nullptr || pointer_to_node->right != nullptr) {
                            if (pointer_to_node->left != nullptr) {
                                pointer_to_node = pointer_to_node->left;
                            } else if (pointer_to_node->right != nullptr) {
                                pointer_to_node = pointer_to_node->right;
                            }
                        }
                        return *this;
                    } else {
                        pointer_to_node = pointer_to_node->father;
                    }
                }
                return *this;
            }

            const postOrderIterator operator++(int) {
                preOrderIterator temp = *this;
                pointer_to_node = pointer_to_node->left;
                return temp;
            }
        };

    private:
        Node *findNode(const T &data, Node *node) {
            if (node != nullptr) {
                if (node->data == data) {
                    return node;
                } else {
                    Node *foundNode = findNode(data, node->left);
                    if (foundNode == nullptr) {
                        foundNode = findNode(data, node->right);
                    }
                    return foundNode;
                }
            } else {
                return nullptr;
            }
        }

        Node *root;
    public:
        BinaryTree() : root(nullptr) {}

        BinaryTree &add_root(const T &t) {
            if (root != nullptr) {
                throw std::invalid_argument("There is already root");
            }
            Node *newNode = new Node{t};
            root = newNode;
            return *this;
        }

        BinaryTree &add_left(const T &t1, const T &t2) {
            Node *node = findNode(t1, this->root);
            if (node == nullptr) {
                throw std::invalid_argument("Cant find node to add to");
            }
            if (node->left != nullptr) {
                node->left->data = t2;
                return *this;
            }
            Node *newNode = new Node{t2};
            newNode->father = node;
            node->left = newNode;
            return *this;
        }

        BinaryTree &add_right(const T &t1, const T &t2) {
            Node *node = findNode(t1, this->root);
            if (node == nullptr) {
                throw std::invalid_argument("Cant find node to add to");
            }
            if (node->right != nullptr) {
                node->right->data = t2;
                return *this;
            }
            Node *newNode = new Node{t2};
            newNode->father = node;
            node->right = newNode;
            return *this;
        }

        preOrderIterator begin_preorder() {
            if (root == nullptr) {
                return preOrderIterator{nullptr};
            }

            return preOrderIterator{this->root};
        }

        preOrderIterator end_preorder() {
            return preOrderIterator{nullptr};
        }

        inOrderIterator begin_inorder() {
            if (root == nullptr) {
                return inOrderIterator{nullptr};
            }
            Node *temp = root;
            while (temp->left != nullptr) {
                temp = temp->left;
            }
            return inOrderIterator{temp};
        }

        inOrderIterator end_inorder() {
            return inOrderIterator{nullptr};
        }

        postOrderIterator begin_postorder() {
            if (root == nullptr) {
                return postOrderIterator{nullptr};
            }
            Node *temp = root;
            while (temp->left != nullptr || temp->right != nullptr) {
                if (temp->left != nullptr) {
                    temp = temp->left;
                } else if (temp->right != nullptr) {
                    temp = temp->right;
                }
            }
            return postOrderIterator{temp};
        }

        postOrderIterator end_postorder() {
            return postOrderIterator{nullptr};
        }

        inOrderIterator begin() {
            if (root == nullptr) {
                return inOrderIterator{nullptr};
            }
            Node *temp = root;
            while (temp->left != nullptr) {
                temp = temp->left;
            }
            return inOrderIterator{temp};
        }

        inOrderIterator end() {
            return inOrderIterator{nullptr};
        }

        friend std::ostream &operator<<(std::ostream &os, const BinaryTree<T> &tree) {
            return os;
        }
    };
}