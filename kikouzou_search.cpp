#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Tree Node structure
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Binary Search Tree class
class BST {
private:
    TreeNode* root;

    // Insert helper function (recursive)
    TreeNode* insertHelper(TreeNode* node, int value) {
        if (node == nullptr) {
            return new TreeNode(value);
        }

        if (value < node->data) {
            node->left = insertHelper(node->left, value);
        }
        else if (value > node->data) {
            node->right = insertHelper(node->right, value);
        }

        return node;
    }

    // Pre-order traversal (Root -> Left -> Right)
    void preOrderHelper(TreeNode* node) {
        if (node == nullptr) return;

        cout << node->data << " ";
        preOrderHelper(node->left);
        preOrderHelper(node->right);
    }

    // In-order traversal (Left -> Root -> Right)
    // For BST, this gives sorted order
    void inOrderHelper(TreeNode* node) {
        if (node == nullptr) return;

        inOrderHelper(node->left);
        cout << node->data << " ";
        inOrderHelper(node->right);
    }

    // Post-order traversal (Left -> Right -> Root)
    void postOrderHelper(TreeNode* node) {
        if (node == nullptr) return;

        postOrderHelper(node->left);
        postOrderHelper(node->right);
        cout << node->data << " ";
    }

public:
    BST() : root(nullptr) {}

    // Insert a value into BST
    void insert(int value) {
        root = insertHelper(root, value);
    }

    // Search for a value in BST
    // Time Complexity: O(log n) average, O(n) worst case
    bool search(int value) {
        TreeNode* current = root;

        while (current != nullptr) {
            if (value == current->data) {
                return true;
            }
            else if (value < current->data) {
                current = current->left;
            }
            else {
                current = current->right;
            }
        }

        return false;
    }

    // Recursive search
    bool searchRecursive(TreeNode* node, int value) {
        if (node == nullptr) {
            return false;
        }

        if (value == node->data) {
            return true;
        }
        else if (value < node->data) {
            return searchRecursive(node->left, value);
        }
        else {
            return searchRecursive(node->right, value);
        }
    }

    bool searchRecursive(int value) {
        return searchRecursive(root, value);
    }

    // Depth-First Search (DFS) - Pre-order
    void preOrder() {
        cout << "Pre-order (Root -> Left -> Right): ";
        preOrderHelper(root);
        cout << endl;
    }

    // Depth-First Search (DFS) - In-order
    void inOrder() {
        cout << "In-order (Left -> Root -> Right): ";
        inOrderHelper(root);
        cout << endl;
    }

    // Depth-First Search (DFS) - Post-order
    void postOrder() {
        cout << "Post-order (Left -> Right -> Root): ";
        postOrderHelper(root);
        cout << endl;
    }

    // Breadth-First Search (BFS) - Level order traversal
    void levelOrder() {
        if (root == nullptr) return;

        cout << "Level-order (BFS): ";

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();

            cout << current->data << " ";

            if (current->left != nullptr) {
                q.push(current->left);
            }
            if (current->right != nullptr) {
                q.push(current->right);
            }
        }

        cout << endl;
    }

    // Get height of the tree
    int getHeight(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }

        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);

        return max(leftHeight, rightHeight) + 1;
    }

    int getHeight() {
        return getHeight(root);
    }

    // Count total nodes
    int countNodes(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        return 1 + countNodes(node->left) + countNodes(node->right);
    }

    int countNodes() {
        return countNodes(root);
    }
};

int main() {
    BST tree;

    // Insert values into BST
    cout << "=== Building Binary Search Tree ===" << endl;
    vector<int> values = {50, 30, 70, 20, 40, 60, 80, 10, 25, 35, 65};

    cout << "Inserting values: ";
    for (int val : values) {
        cout << val << " ";
        tree.insert(val);
    }
    cout << endl << endl;

    // Display tree structure info
    cout << "Tree height: " << tree.getHeight() << endl;
    cout << "Total nodes: " << tree.countNodes() << endl;
    cout << endl;

    // Tree Traversal Methods
    cout << "=== Tree Traversal Methods ===" << endl;
    tree.preOrder();
    tree.inOrder();
    tree.postOrder();
    tree.levelOrder();
    cout << endl;

    // Search test
    cout << "=== Search Test ===" << endl;
    vector<int> searchValues = {40, 65, 100, 10};

    for (int val : searchValues) {
        if (tree.search(val)) {
            cout << "Value " << val << " found in tree (iterative)" << endl;
        } else {
            cout << "Value " << val << " not found in tree (iterative)" << endl;
        }

        if (tree.searchRecursive(val)) {
            cout << "Value " << val << " found in tree (recursive)" << endl;
        } else {
            cout << "Value " << val << " not found in tree (recursive)" << endl;
        }
        cout << endl;
    }

    return 0;
}
