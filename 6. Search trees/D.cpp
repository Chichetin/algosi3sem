#include <bits/stdc++.h>
using namespace std;


class Node {
public:
    int value;
    Node *left;
    Node *right;
    int h = 1;

    explicit Node(const int val, Node *left = nullptr, Node *right = nullptr) : value(val), left(left), right(right) {
    }

    static int hv(Node *v) {
        return v == nullptr ? 0 : v->h;
    }

    static void upd(Node *v) {
        v->h = 1 + max(hv(v->left), hv(v->right));
    }
};

class BST {
public:
    Node *root;

    explicit BST(Node *root = nullptr) : root(root) {
    }


    static Node *delete_min(Node *root, int &out_X) {
        if (root->left == nullptr) {
            out_X = root->value;
            Node *temp = root->right;
            delete root;
            return temp;
        }
        root->left = delete_min(root->left, out_X);
        return balance(root);
    }


    static Node *delete_node(const int X, Node *cur) {
        if (cur == nullptr) { return cur; }

        if (cur->value > X) {
            cur->left = delete_node(X, cur->left);
            return balance(cur);
        }
        if (cur->value < X) {
            cur->right = delete_node(X, cur->right);
            return balance(cur);
        } else {
            if (cur->left == nullptr && cur->right == nullptr) {
                delete cur;
                return nullptr;
            } else if (cur->left == nullptr && cur->right != nullptr) {
                Node *temp = cur->right;
                delete cur;
                return balance(temp);
            } else if (cur->left != nullptr && cur->right == nullptr) {
                Node *temp = cur->left;
                delete cur;
                return balance(temp);
            } else {
                cur->right = delete_min(cur->right, cur->value);
                return balance(cur);
            }
        }
    }

    static int bal(Node *v) {
        return Node::hv(v->right) - Node::hv(v->left);
    }

    static Node *balance(Node *v) {
        Node::upd(v);

        if (bal(v) == 2) {
            if (bal(v->right) < 0) {
                v->right = rotate_right(v->right);
            }
            return rotate_left(v);
        }
        if (bal(v) == -2) {
            if (bal(v->left) > 0) {
                v->left = rotate_left(v->left);
            }
            return rotate_right(v);
        }
        return v;
    }

    static Node *insert_node(const int X, Node *cur) {
        if (cur == nullptr) { return new Node(X); }
        if (cur->value == X) { return cur; }

        if (cur->value > X) {
            cur->left = insert_node(X, cur->left);
        } else {
            cur->right = insert_node(X, cur->right);
        }
        return balance(cur);
    }


    static bool exists(Node *root, const int X) {
        if (root == nullptr) { return false; }
        if (root->value == X) { return true; }
        return exists(root->value > X ? root->left : root->right, X);
    }

    static Node *next_node(Node *root, const int X) {
        if (root == nullptr) { return nullptr; }
        if (root->value == X) { return root; }
        if (root->value < X) { return next_node(root->right, X); }

        Node *temp = next_node(root->left, X);
        return temp == nullptr ? root : temp;
    }

    static Node *prev_node(Node *root, const int X) {
        if (root == nullptr) { return nullptr; }
        if (root->value == X) { return root; }
        if (root->value > X) { return prev_node(root->left, X); }

        Node *temp = prev_node(root->right, X);
        return temp == nullptr ? root : temp;
    }

    static Node *rotate_left(Node *a) {
        if (a == nullptr) { return a; }
        Node *b = a->right;
        a->right = b->left;
        b->left = a;

        Node::upd(a);
        Node::upd(b);
        return b;
    }

    static Node *rotate_right(Node *a) {
        if (a == nullptr) { return a; }
        Node *b = a->left;
        a->left = b->right;
        b->right = a;
        Node::upd(a);
        Node::upd(b);
        return b;
    }

    static void recursive_print(const Node *root) {
        if (root == nullptr) { return; }
        cout << root->value << " ";
        recursive_print(root->left);
        recursive_print(root->right);
    }

    static void print(const Node *root) {
        if (root == nullptr) {
            cout << "Empty";
            return;
        }
        recursive_print(root);
    }
};


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    BST bst;

    unordered_map<string, function<void()> > commands = {
        {
            "add", [&] {
                int x;
                cin >> x;
                bst.root = BST::insert_node(x, bst.root);
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
        {
            "next", [&] {
                int x;
                cin >> x;
                Node *res = BST::next_node(bst.root, x);
                if (res == nullptr)
                    cout << "None" << '\n';
                else
                    cout << res->value << '\n';
            }
        },
        {
            "prev", [&] {
                int x;
                cin >> x;
                Node *res = BST::prev_node(bst.root, x);
                if (res == nullptr)
                    cout << "None" << '\n';
                else
                    cout << res->value << '\n';
            }
        },
        {"height", [&] { cout << Node::hv(bst.root) << '\n'; }},
        {
            "print", [&] {
                BST::print(bst.root);
                cout << '\n';
            }
        },
        {
            "root", [&] {
                if (bst.root == nullptr)
                    cout << "Empty" << '\n';
                else
                    cout << bst.root->value << '\n';
            }
        }
    };

    int q;
    cin >> q;
    string command;
    for (int i = 0; i < q; i++) {
        cin >> command;
        commands[command]();
    }
}
