#include <iostream>
using namespace std;

// Node structure for the threaded binary search tree
struct Node {
    int key;
    Node* left;
    Node* right;
    bool lbit; // Left thread indicator
    bool rbit; // Right thread indicator
};

// Function to create a new node
Node* newNode(int key) {
    Node* node = new Node;
    node->key = key;
    node->left = nullptr;
    node->right = nullptr;
    node->lbit = false;
    node->rbit = false;
    return node;
}

// Class for threaded binary search tree
class ThreadedBST {
private:
    Node* root;
    Node* prev; // Pointer to track the previous node during construction

public:
    ThreadedBST() : root(nullptr), prev(nullptr) {}

    // Function to insert a key into the tree
    void insert(int key) {
        if (!root) {
            root = newNode(key);
            return;
        }

        Node* current = root;
        while (true) {
            if (key < current->key) {
                if (current->lbit) { // If left thread exists, insert to the left
                    current = current->left;
                } else {
                    Node* newNode = new Node;
                    newNode->key = key;
                    newNode->left = current->left;
                    newNode->right = current;
                    current->left = newNode;
                    current->lbit = true;
                    return;
                }
            } else if (key > current->key) {
                if (current->rbit) { // If right thread exists, insert to the right
                    current = current->right;
                } else {
                    Node* newNode = new Node;
                    newNode->key = key;
                    newNode->right = current->right;
                    newNode->left = current;
                    current->right = newNode;
                    current->rbit = true;
                    return;
                }
            } else {
                // Key already exists, do nothing
                return;
            }
        }
    }

    // Function to perform inorder traversal
    void inorderTraversal() {
        Node* current = root;
        while (current) {
            while (current->lbit) {
                current = current->left;
            }
            cout << current->key << " ";
            if (current->rbit) {
                current = current->right;
            } else {
                while (!current->rbit && current->right) {
                    current = current->right;
                }
                current = current->right;
            }
        }
        cout << endl;
    }

    // Function to display the smallest and largest values
    void displayMinMax() {
        Node* minNode = root;
        Node* maxNode = root;

        // Finding the leftmost node for the smallest value
        while (minNode->left) {
            minNode = minNode->left;
        }

        // Finding the rightmost node for the largest value
        while (maxNode->right) {
            maxNode = maxNode->right;
        }

        cout << "Smallest value: " << minNode->key << endl;
        cout << "Largest value: " << maxNode->key << endl;
    }

    // Function to display the left and right thread indicators for each node
    void displayThreadIndicators() {
        displayThreadIndicatorsUtil(root);
    }

private:
    // Utility function to display thread indicators
    void displayThreadIndicatorsUtil(Node* node) {
        if (!node) {
            return;
        }

        cout << "Node: " << node->key << ", Left Thread: " << node->lbit << ", Right Thread: " << node->rbit << endl;
        displayThreadIndicatorsUtil(node->left);
        displayThreadIndicatorsUtil(node->right);
    }
};

// Main function
int main() {
    ThreadedBST tree;

    // Inserting elements into the tree
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);

    // Displaying inorder traversal
    cout << "Inorder Traversal: ";
    tree.inorderTraversal();

    // Displaying smallest and largest values
    tree.displayMinMax();

    // Displaying thread indicators
    cout << "Thread Indicators: " << endl;
    tree.displayThreadIndicators();

    return 0;
}
