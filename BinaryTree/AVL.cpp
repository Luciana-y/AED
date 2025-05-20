#include <iostream>
#include <queue>

using namespace std;

template<typename T>
struct Node {
    T val;
    int height;
    Node *left;
    Node *right;

    explicit Node(const T &val): val(val), height(0), left(nullptr), right(nullptr) {
    }

    ~Node() = default;
};

template<typename T>
class AVL {
    Node<T> *root;

    void destroy(Node<T> *node) {
        if (node == nullptr) {
            return;
        }
        destroy(node->left);
        destroy(node->right);
        delete node;
    }

    static int getHeight(Node<T> *node) {
        return node ? node->height : -1;
    }

    void updateHeight(Node<T> *node) const {
        if (node) {
            node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
        }
    }

    int getBalance(Node<T> *node) const {
        return node ? getHeight(node->left) - getHeight(node->right) : 0;
    }

    //Rotation for LL insertion
    Node<T> *LL(Node<T> *A) {
        Node<T> *B = A->left;
        A->left = B->right;
        B->right = A;
        updateHeight(A);
        updateHeight(B);
        return B;
    }

    //Rotation for RR insertion
    Node<T> *RR(Node<T> *A) {
        Node<T> *B = A->right;
        A->right = B->left;
        B->left = A;
        updateHeight(A);
        updateHeight(B);
        return B;
    }

    //Rotation for LR insertion
    Node<T> *LR(Node<T> *A) {
        Node<T> *B = A->left;
        Node<T> *C = B->right;
        B->right = C->left;
        C->left = B;
        A->left = C->right;
        C->right = A;
        updateHeight(A);
        updateHeight(B);
        updateHeight(C);
        return C;
    }

    //Rotation for RL insertion
    Node<T> *RL(Node<T> *A) {
        Node<T> *B = A->right;
        Node<T> *C = B->left;
        B->left = C->right;
        C->right = B;
        A->right = C->left;
        C->left = A;
        updateHeight(A);
        updateHeight(B);
        updateHeight(C);
        return C;
    }

    Node<T> *balance(Node<T> *node) {
        const int balance = getBalance(node);

        if (balance == 2) {
            if (getBalance(node->left) == -1) {
                return LR(node);
            }
            return LL(node);
        }
        if (balance == -2) {
            if (getBalance(node->right) == 1) {
                return RL(node);
            }
            return RR(node);
        }
        return node;
    }

    Node<T> *insert(Node<T> *node, const T &val) {
        if (node == nullptr) {
            return new Node<T>(val);
        }
        if (node->val == val) {
            std::cout << "Duplicate value: " << val << '\n';
            return node;
        }
        if (val < node->val) {
            node->left = insert(node->left, val);
        } else if (val > node->val) {
            node->right = insert(node->right, val);
        }
        updateHeight(node);
        return balance(node);
    }

    bool search(Node<T> *node, const T &val) const {
        if (node == nullptr) {
            return false;
        }
        if (node->val == val) {
            return true;
        }
        if (val < node->val) {
            return search(node->left, val);
        }
        return search(node->right, val);
    }

    Node<T> *minValNode(Node<T> *node) const {
        return node->left ? minValNode(node->left) : node;
    }

    Node<T> *remove(Node<T> *node, const T &val) {
        if (node == nullptr) {
            std::cout << "Deletion failed, value not found.\n";
            return nullptr;
        }
        if (val < node->val) {
            node->left = remove(node->left, val);
        } else if (val > node->val) {
            node->right = remove(node->right, val);
        } else {
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                return nullptr;
            }
            if (node->left == nullptr) {
                Node<T> *temp = node->right;
                delete node;
                return temp;
            }
            if (node->right == nullptr) {
                Node<T> *temp = node->left;
                delete node;
                return temp;
            }
            Node<T> *successor = minValNode(node->right);
            node->val = successor->val;
            node->right = remove(node->right, successor->val);
        }
        updateHeight(node);
        return balance(node);
    }

    void DFS(Node<T> *node) {
        if (node == nullptr) {
            return;
        }
        DFS(node->left);
        std::cout << node->val << ' ';
        DFS(node->right);
    }

public:
    AVL() : root(nullptr) {
    }

    ~AVL() {
        destroy(root);
    }

    void insert(const T &val) {
        root = insert(root, val);
    }

    template<typename... Ts>
    void insert(Ts... vals) {
        (insert(vals), ...);
    }

    bool search(const T &val) const {
        return search(root, val);
    }

    void remove(const T &val) {
        root = remove(root, val);
    }

    void DFS() {
        DFS(root);
        std::cout << '\n';
    }

    void BFS() {
        if (root == nullptr) {
            std::cout << "Tree is empty\n";
            return;
        }
        std::cout << "BFS Traversal:\n";
        std::queue<Node<T> *> q;
        q.push(root);
        while (!q.empty()) {
            int levelSize = q.size();
            for (size_t i = 0; i < levelSize; ++i) {
                Node<T> *node = q.front();
                q.pop();
                std::cout << node->val << ' ';
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            std::cout << '\n';
        }
        std::cout << "End of BFS\n\n";
    }
};
