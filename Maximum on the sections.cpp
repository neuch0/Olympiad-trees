#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

typedef long long ll;
using namespace std;
vector<long long> tree;
vector<long long> xx;
 
typedef long long ll;
 
long long popopo(int x, int y){
    return max(x, y);
}
 
const auto INF = 10e13;
 
void build(int x, int lx, int rx){
    if (rx - lx == 1){   //если мы пришли в лист
        tree[x] = xx[lx];
        return;
    }else{
    ll m = (lx + rx) / 2;
    build(2*x+1, lx, m);
    build(2*x+2, m, rx);
    tree[x] = popopo(tree[2*x + 1], tree[2*x + 2]);
    }
}
 
 
void update(ll x, ll lx, ll rx, ll ind, ll vol){  //Ind - на какой позиции стоит тот элемент, который я хочу заменить, vol - новое значение элемента
    if (rx - lx == 1){
        tree[x] = vol;  //пришли, куда надо, элемент заменили
        return;
    }
    ll m = (lx + rx) / 2;
    if (ind < m){
            update(2*x + 1, lx, m, ind, vol);  //запускаемся от левого сына
 
    } else{
    update(2*x + 2, m, rx, ind, vol);
    }
    tree[x] = popopo(tree[2*x + 1], tree[2*x + 2]);
}
 
ll query(ll x, ll lx, ll rx, ll l, ll r){
    if (l <= lx && rx <= r){
        return tree[x];
    }
    if (rx <= l || r <= lx){
        return -INF;
 
    }
    ll m = (lx + rx) / 2;
    ll q1 = query(2*x + 1, lx, m, l, r);
    ll q2 = query(2*x + 2, m, rx, l, r);
    return popopo(q1, q2);
 
}
 
 
 

 
 
int main()
{
        ll n;
    cin >> n;
    xx.resize(n, 0);
 tree.resize(4*n, 0);
 for(int i = 0; i < n; i++){
    cin >> xx[i];
 }
 build(0,0,n);
 
    ll d;
    cin >> d;
    for(int y = 0; y < d; y++){
        char f;
        cin >> f;
        if (f == 'u'){
            ll indf, volf;
            cin >> indf >> volf;
            update(0, 0, n, indf - 1, volf);
        }else{
        ll l, r;
        cin >> l >> r;
        cout << query(0, 0, n, l - 1, r) << "\n";
        }
 
    }
return 0;
}