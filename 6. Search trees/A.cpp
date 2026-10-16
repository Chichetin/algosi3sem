#include <bits/stdc++.h>
using namespace std;


class Node {
public:
    int value;
    Node *left;
    Node *right;

    explicit Node(const int val, Node *left = nullptr, Node *right = nullptr) : value(val), left(left), right(right) {
    }
};

class BST {
public:
    Node *root;

    explicit BST(Node *root = nullptr) : root(root) {
    }

    void add(const int X) {
        if (root == nullptr) {
            root = new Node(X);
            return;
        }
        Node *cur = root;

        while (true) {
            if (cur->value == X) return;
            if (X < cur->value) {
                if (cur->left != nullptr) cur = cur->left;
                else {
                    cur->left = new Node(X);
                    return;
                }
            } else {
                if (cur->right != nullptr) cur = cur->right;
                else {
                    cur->right = new Node(X);
                    return;
                }
            }
        }
    }

    static Node *delete_min(Node *root, int &out_X) {
        if (root->left == nullptr) {
            out_X = root->value;
            Node *temp = root->right;
            delete root;
            return temp;
        }
        root->left = delete_min(root->left, out_X);
        return root;
    }

    static Node *delete_node(const int X, Node *cur) {
        if (cur == nullptr) { return cur; }

        if (cur->value > X) {
            cur->left = delete_node(X, cur->left);
            return cur;
        }
        if (cur->value < X) {
            cur->right = delete_node(X, cur->right);
            return cur;
        } else {
            if (cur->left == nullptr && cur->right == nullptr) {
                delete cur;
                return nullptr;
            } else if (cur->left == nullptr && cur->right != nullptr) {
                Node *temp = cur->right;
                delete cur;
                return temp;
            } else if (cur->left != nullptr && cur->right == nullptr) {
                Node *temp = cur->left;
                delete cur;
                return temp;
            } else {
                cur->right = delete_min(cur->right, cur->value);
                return cur;
            }
        }
    }

    static bool exists(Node *root, const int X) {
        if (root == nullptr) { return false; }
        if (root->value == X) { return true; }
        return exists(root->value > X ? root->left : root->right, X);
    }


    static int height(Node *root) {
        if (root == nullptr) { return 0; }
        return 1 + max(height(root->left), height(root->right));
    }

    static void recursive_print(const Node *root) {
        if (root == nullptr) { return; }
        cout << root->value << " ";
        recursive_print(root->left);
        recursive_print(root->right);
    }

    static void print(const Node *root) {
        if (root == nullptr) {
            cout << "Empty" << endl;;
            return;
        }
        recursive_print(root);
    }
};


int main() {
    BST bst;

    unordered_map<string, function<void()> > commands = {
        {
            "add", [&] {
                int x;
                cin >> x;
                bst.add(x);
            }
        },
        {
            "del", [&] {
                int x;
                cin >> x;
                bst.root = BST::delete_node(x, bst.root);
            }
        },
        {
            "exists", [&] {
                int x;
                cin >> x;
                cout << (BST::exists(bst.root, x) ? "YES" : "NO") << '\n';
            }
        },
        {"height", [&] { cout << BST::height(bst.root) << '\n'; }},
        {
            "print", [&] {
                BST::print(bst.root);
                cout << '\n';
            }
        },
    };

    int n;
    cin >> n;
    string command;
    for (int i = 0; i < n; i++) {
        cin >> command;
        commands[command]();
    }
}
