#include <iostream>
#include <cstring>

using namespace std;

typedef struct TNode {
    int val, length;
    TNode *Left, *Right, *Parent;
} *PNode;

char S[1000006];
int n;

PNode root, nil;

void update_node(PNode x) {
    x->length = x->Left->length + x->Right->length + 1;
}

void set_Left(PNode x, PNode y) {
    x->Left = y;
    y->Parent = x;
}

void set_Right(PNode x, PNode y) {
    x->Right = y;
    y->Parent = x;
}

PNode node_at(PNode x, int i) {
    while (true) {
        int p = x->Left->length + 1;
        if (i == p) break;
        if (i < p) x = x->Left;
        else x = x->Right, i -= p;
    }
    return x;
}

void up_tree(PNode x) {
    PNode y = x->Parent, z = y->Parent;
    if (y->Left == x) set_Left(y, x->Right), set_Right(x, y);
    else set_Right(y, x->Left), set_Left(x, y);
    if (z->Left == y) set_Left(z, x); else set_Right(z, x);
    update_node(y);
    update_node(x);
}

void Splay(PNode x) {
    while (1) {
        PNode y = x->Parent, z = y->Parent;
        if (y == nil) return;
        if (z != nil) {
            if ((z->Left == y) == (y->Left == x)) up_tree(y);
            else up_tree(x);
        }
        up_tree(x);
    }
}

void split(PNode T, int i, PNode &T1, PNode &T2) {
    if (i == 0) {
        T1 = nil;
        T2 = T;
        return;
    }
    T1 = node_at(T, i);
    Splay(T1);
    T2 = T1->Right;
    T1->Right = nil;
    T2->Parent = nil;
    update_node(T1);
}

PNode join(PNode T1, PNode T2) {
    if (T1 == nil) return T2;
    T1 = node_at(T1, T1->length);
    Splay(T1);
    set_Right(T1, T2);
    update_node(T1);
    return T1;
}

void init() {
    nil = new TNode();
    nil->length = nil->val = 0;
    nil->Left = nil->Right = nil->Parent = nil;
    root = nil;
}

void Insert(int i, int m, int j) {
    PNode T1, T2, T3;
    split(root, i-1, T1, T2);
    split(T2, m, T2, T3);
    root = join(T1, T3);
    split(root, j-1, T1, T3);
    root = join(join(T1, T2), T3);
}

PNode Build(int l, int r) {
    if (l > r) return nil;
    int mid = (l+r)>>1;
    PNode x = new TNode();
    x->val = mid;
    x->Parent = nil;
    set_Left(x, Build(l, mid-1));
    set_Right(x, Build(mid+1, r));
    update_node(x);
    return x;
}

char res[1000006];
int num = 0;

void DFS(PNode x) {
    if (x == nil) return;
    DFS(x->Left);
    res[++num] = S[x->val];
    DFS(x->Right);
}

int main() {
    scanf("%s", S+1); n = strlen(S+1);
    init();
    root = Build(1, n);
    int t; scanf("%d", &t);
    while (t--) {
        int u, v, l;
        scanf("%d%d%d", &u, &v, &l);
        l %= (v - u + 1);
        Insert(v-l+1, l, u);
    }
    DFS(root);
    cout << res + 1;
    return 0;
}
    
