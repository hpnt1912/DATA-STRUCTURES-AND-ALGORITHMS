

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insertNode(Node*& root, Node* node) {
    if (root == NULL) {
        root = node;
        return;
    }

    if (node->data < root->data) {
        if (root->left == NULL) {
            root->left = node;
            return;
        }
        insertNode(root->left, node);
        return;
    }

    if (root->right == NULL) {
        root->right = node;
        return;
    }
    insertNode(root->right, node);
}

// Implement the two functions below. For each, set out_found = true and
// out_val = value if it exists; otherwise set out_found = false.
//   predecessor(root, x, out_found, out_val) -> largest value strictly less than x
//   successor(root, x, out_found, out_val)   -> smallest value strictly greater than x

void predecessor(Node* root, int x, bool& out_found, int& out_val) {
    out_found = false;
    Node* p = root;
    while (p != nullptr) {
        if (p->data < x) {
            out_found = true;
            out_val = p->data; // Lưu ứng viên lớn nhất tính tới hiện tại
            p = p->right;      // Thử tìm bên phải xem có số nào gần x hơn không
        } else {
            // Trường hợp p->data >= x: bắt buộc rẽ trái để tìm số nhỏ hơn x
            p = p->left;
        }
    }
}

void successor(Node* root, int x, bool& out_found, int& out_val) {
    out_found = false;
    Node* p = root;
    while (p != nullptr) {
        if (p->data > x) {
            out_found = true;
            out_val = p->data; // Lưu ứng viên nhỏ nhất tính tới hiện tại
            p = p->left;       // Thử tìm bên trái xem có số nào gần x hơn không
        } else {
            // Trường hợp p->data <= x: bắt buộc rẽ phải để tìm số lớn hơn x
            p = p->right;
        }
    }
}

int main() {
    Node* root = NULL;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        insertNode(root, createNode(data));
    }

    int x;
    cin >> x;

    bool pf, sf;
    int pv, sv;
    predecessor(root, x, pf, pv);
    successor(root, x, sf, sv);

    cout << "Pred: ";
    if (pf) cout << pv; else cout << "NONE";
    cout << "\nSucc: ";
    if (sf) cout << sv; else cout << "NONE";
    cout << "\n";
    return 0;
}
