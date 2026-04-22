#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Node {
    int value;
    vector<Node*> children;
};


Node* createNode(int val) {
    Node* n = new Node;
    n->value = val;
    return n;
}


void addChild(Node* parent, int val) {
    parent->children.push_back(createNode(val));
}


Node* getByPath(Node* root, vector<int> path) {
    Node* cur = root;
    for (int i : path) {
        if (i < 0 || i >= cur->children.size()) return nullptr;
        cur = cur->children[i];
    }
    return cur;
}


void printIndent(Node* root, int d = 0) {
    for (int i = 0; i < d; i++) cout << "  ";
    cout << root->value << "\n";

    for (auto c : root->children)
        printIndent(c, d + 1);
}


void printBrackets(Node* root) {
    cout << root->value;

    if (root->children.empty()) return;

    cout << "(";
    for (int i = 0; i < root->children.size(); i++) {
        printBrackets(root->children[i]);
        if (i != root->children.size() - 1) cout << ", ";
    }
    cout << ")";
}


Node* deleteByPath(Node* root, vector<int> path) {
    if (path.empty()) return root;

    Node* cur = root;
    for (int i = 0; i < path.size() - 1; i++) {
        cur = cur->children[path[i]];
    }

    int idx = path.back();
    Node* removed = cur->children[idx];
    cur->children.erase(cur->children.begin() + idx);

    return removed;
}

void demo() {
    Node* root = createNode(1);

    addChild(root, 2);
    addChild(root, 3);
    addChild(root->children[0], 4);
    addChild(root->children[0], 5);
    addChild(root->children[1], 6);

    cout << "\n--- INDENT ---\n";
    printIndent(root);

    cout << "\n--- BRACKETS ---\n";
    printBrackets(root);
    cout << "\n";

    cout << "\nDelete node [0,1] (value 5)\n";
    deleteByPath(root, {0,1});

    cout << "\nAfter delete:\n";
    printIndent(root);
}

void interactive() {
    Node* root = createNode(1);

    while (true) {
        cout << "\n1-add child\n2-print\n3-brackets\n4-delete\n0-exit\n> ";
        int cmd;
        cin >> cmd;

        if (cmd == 0) break;

        if (cmd == 1) {
            int val;
            cout << "value: ";
            cin >> val;

            cout << "parent path size: ";
            int n; cin >> n;

            vector<int> path(n);
            for (int i = 0; i < n; i++) cin >> path[i];

            Node* p = getByPath(root, path);
            if (p) addChild(p, val);
        }

        if (cmd == 2) printIndent(root);
        if (cmd == 3) { printBrackets(root); cout << "\n"; }

        if (cmd == 4) {
            int n; cout << "path size: ";
            cin >> n;

            vector<int> path(n);
            for (int i = 0; i < n; i++) cin >> path[i];

            deleteByPath(root, path);
        }
    }
}

// main
int main() {
    int mode;
    cout << "Mode (1-demo, 2-interactive): ";
    cin >> mode;

    if (mode == 1) demo();
    else interactive();

    return 0;
}