// 1. add on segment
// 2. get max on segment

#include <iostream>
using namespace std;

const int S = (1 << 16);
int p, k, l, n, m, q, tree[S * 2 + 7], lazy[S * 2 + 7];

bool is_leaf(int node){
    return node >= S;
}

void clear_all(){
    // mozna zoptowac
    for (int i = 0; i < S * 2 + 7; i ++){
        tree[i] = lazy[i] = 0;
    }
}

void propagate(int node){
    cout << "propaguje: " << node << endl;
    if (lazy[node] == 0){
        return;
        // nothing to do
    }
    tree[node] += lazy[node];
    if (!is_leaf(node)){
        lazy[node * 2] += lazy[node];
        lazy[node * 2 + 1] += lazy[node];
    }
    lazy[node] = 0;
}

void upd(int beg, int en, int val, int node = 1, int subtree_beg = 0, int subtree_en = S - 1){
    if (en < subtree_beg || beg > subtree_en){
        return;
        // nothing to do
    }
    if (beg <= subtree_beg && subtree_en <= en){
        lazy[node] += val;
        // we take whole subtree
    } else {
        int mid = (subtree_beg + subtree_en) / 2;
        upd(beg, en, val, node * 2, subtree_beg, mid); // go left
        upd(beg, en, val, node * 2 + 1, mid + 1, subtree_en); // go right
    }
}

int query(int beg, int en, int node = 1, int subtree_beg = 0, int subtree_en = S - 1){
    propagate(node);
    if (en < subtree_beg || beg > subtree_en){
        return 0;
        // nothing to do
    }
    
    if (beg <= subtree_beg && subtree_en <= en){
        cout << "zwracam " << node << endl;
        return tree[node];
        // we take whole subtree
    }
    int mid = (subtree_beg + subtree_en) / 2;
    return max(
        query(beg, en, node * 2 + 1, subtree_beg, mid),
        query(beg, en, node * 2 + 1, mid + 1, subtree_en)
    );
}

void solve(){
    cin >> n >> m >> q;
    clear_all();
    for (int i = 0; i < q; i ++){
        cin >> p >> k >> l;
        int q = query(p, k);
        cout << "q = " <<  q << "\n";
        int left = m - q;
        
        if (left >= l){
            cout << "T\n";
            upd(p, k, l);
        } else {
            cout << "N\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t --){
        solve();
    }

    return 0;
}