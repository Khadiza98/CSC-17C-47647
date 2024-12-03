/* 
 * File:   Tree.cpp
 * Author: Khadiza Akter
 * Created on November 23, 2024, 3:14 PM
 * Purpose: Implementation of Tree class
 */

#include "Tree.h"

// Height of AVL Sub-trees
int Tree::height(Node *temp) {
    if (temp == NULL)
        return 0;
    return max(height(temp->left), height(temp->right)) + 1;
}

// Balance factor of AVL Sub-trees
int Tree::diff(Node *temp) {
    if (temp == NULL)
        return 0;
    return height(temp->left) - height(temp->right);
}

// Rotations for balancing
Node *Tree::rr_rotation(Node *parent) {
    Node *temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    return temp;
}

Node *Tree::ll_rotation(Node *parent) {
    Node *temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    return temp;
}

Node *Tree::lr_rotation(Node *parent) {
    parent->left = rr_rotation(parent->left);
    return ll_rotation(parent);
}

Node *Tree::rl_rotation(Node *parent) {
    parent->right = ll_rotation(parent->right);
    return rr_rotation(parent);
}

// Balancing sub-trees
Node *Tree::balance(Node *temp) {
    int balanceFactor = diff(temp);
    if (balanceFactor > 1) {
        if (diff(temp->left) > 0)
            temp = ll_rotation(temp);
        else
            temp = lr_rotation(temp);
    } else if (balanceFactor < -1) {
        if (diff(temp->right) > 0)
            temp = rl_rotation(temp);
        else
            temp = rr_rotation(temp);
    }
    return temp;
}

Node *Tree::insert(Node *root, int value) {
    if (root == NULL) {
        root = new Node;
        root->data = value;
        root->left = root->right = NULL;
        return root;
    }
    if (value < root->data)
        root->left = insert(root->left, value);
    else // This allows duplicates by including equal values
        root->right = insert(root->right, value);

    return balance(root);
}

Node* Tree:: maxValueNode(Node* root) {
    while (root->right != NULL) {
        root = root->right;
    }
    return root;
}

Node* Tree::deleteNode(Node* root, int value) {
    if (root == NULL) {
        std::cout << "Value " << value << " not found in the tree.\n";
        return root;
    }

    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Replace with in-order predecessor (max in left subtree)
        Node* temp = maxValueNode(root->left);
        root->data = temp->data; // Replace root with predecessor's data
        root->left = deleteNode(root->left, temp->data); // Delete predecessor
    }

    return balance(root);
}



// Display the tree
void Tree::display(Node *ptr, int level) {
    if (ptr != NULL) {
        display(ptr->right, level + 1);
        cout << endl;
        if (ptr == root)
            cout << "R -> ";
        for (int i = 0; i < level && ptr != root; i++)
            cout << "     ";
        cout << ptr->data;
        display(ptr->left, level + 1);
    }
}

// Traversals
void Tree::inorder(Node *tree) {
    if (tree == NULL)
        return;
    inorder(tree->left);
    cout << tree->data << " ";
    inorder(tree->right);
}

void Tree::preorder(Node *tree) {
    if (tree == NULL)
        return;
    cout << tree->data << " ";
    preorder(tree->left);
    preorder(tree->right);
}

void Tree::postorder(Node *tree) {
    if (tree == NULL)
        return;
    postorder(tree->left);
    postorder(tree->right);
    cout << tree->data << " ";
}

