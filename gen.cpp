#include <iostream>
using namespace std;

int rnd(int poc, int kon){
    return poc + rand() % (kon - poc + 1);
}

int main(int argc, char* argv[]){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    srand(atoi(argv[1]));
    cout << 1 << endl;
    int n = 1000;
    int m = 1000;
    int q = 1000;
    cout << n << " " << m << "  " << q << "\n";
    for (int i = 0; i < q; i ++){
        int p = rnd(1, n);
        int k = rnd(p, n);
        int l = rnd(1, m);
        cout << p << " " << k << " " << l << endl;
    }
    return 0;
}