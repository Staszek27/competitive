#include <iostream>
using namespace std;
const int S = (1 << 16);
int n, m, q, p, k, l, tab[S];

int query(int poc, int kon){
    int result = tab[poc];
    for (int i = poc + 1; i <= kon; i ++){
        result = max(result, tab[i]);
    }
    return result;
}

void add(int poc, int kon, int value){
    for (int i = poc; i <= kon; i ++){
        tab[i] += value;
    }
}

void solve(){
    for (int i = 0; i <= n; i ++){
        tab[i] = 0;
    }
    cin >> n >> m >> q;
    for (int i = 0; i < q; i ++){
        cin >> p >> k >> l;
        int q = query(p, k);

        if (m - q >= l){
            cout << "T\n";
            add(p, k, l);
        } else {
            cout << "N\n";
        }
    }
}

int main(){
    int t;
    cin >> t;
    while (t --){
        solve();
    }
    return 0;
}