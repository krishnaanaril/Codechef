#include<iostream>
#include<vector>
 
using namespace std;
 
#define MOD 1000000007
#define MAXK 8
#define MAXSTATE MAXK*MAXK
#define fi first
#define se second
 
typedef long long ll;
typedef pair<int, int> pii;
 
struct matrix {
    int m, n, v[MAXSTATE][MAXSTATE];
} mat, mat0;
 
int n, adj[MAXK][MAXK][MAXK][MAXK];
 
matrix mul(matrix *m1, matrix *m2) {
    matrix ret;
    ret.m = (*m1).m; ret.n = (*m2).n;
    for (int i = 0; i < ret.m; i++)
        for (int j = 0; j < ret.n; j++) {
            ret.v[i][j] = 0;
            for (int k = 0; k < (*m1).n; k++) {
                ret.v[i][j] += ((ll)(*m1).v[i][k] * (*m2).v[k][j]) % MOD;
                ret.v[i][j] %= MOD;
            }
        }
    return ret;
}
 
matrix pow(matrix *m, int a) {
    if (a == 1) return *m;
    matrix ret = pow(m, a / 2);
    ret = mul(&ret, &ret);
    if (a & 1) ret = mul(&ret, m);
    return ret;
}
 
int main() {
    ios::sync_with_stdio(false);
 
    int d, k;
    cin >> d >> k;
 
    if (k < 2) {
        switch (k) {
            case 0:
                cout << 1;
                break;
            default: cout << 0;
        }
        cout << endl;
        return 0;
    }
 
    vector<pii> states;
 
    for (int i = 0; i <= d; i++)
        for (int j = 0; j <= d; j++) {
            states.push_back(pii(i, j));
            if (i) adj[i][j][i - 1][j] = 1;
            if (i < d && j) adj[i][j][i + 1][j - 1] = 1;
            if (j < d) adj[i][j][i][j + 1] = 1;
        }
 
    n = states.size();
 
    memset(mat0.v, 0, sizeof(mat0.v));
 
    mat.m = mat.n = n;
    mat0.m = mat0.n = n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            mat.v[i][j] = adj[states[i].fi][states[i].se][states[j].fi][states[j].se];
            if (!i) mat0.v[i][j] = mat.v[i][j];
        }
 
    mat = pow(&mat, k - 1);
    mat0 = mul(&mat0, &mat);
 
    int res = 0;
 
    for (int i = 0; i < n; i++) {
        res += mat0.v[i][0];
        res %= MOD;
    }
 
    cout << res << endl;
 
    return 0;
}
 