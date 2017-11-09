#include "segmenttreerange.h"
#include <cstdio>
 
#define fst first
#define snd second
#define mp make_pair

typedef long long ll;
 
using namespace std;
 
typedef pair<ll,ll> pll;
 
struct update {
	int type;
	ll v; // type 0 = sum, type 1 = replace
	update(int t, ll v) : type(t), v(v) {}
};
 
template <typename node>
struct apply_range {
	pll operator () (const update &u, const shared_ptr<node> &n) const {
		int L = n->y - n->x + 1;

		if (u.type == 1)
			return mp(u.v * L, u.v * u.v * L);

		return mp(
			n->v.fst + u.v * L,
			n->v.snd + L * u.v * u.v + 2 * u.v * n->v.fst
		);
	}
};
 
struct add {
	pll operator () (const pll &a, const pll &b) const {
		return mp(a.fst + b.fst, a.snd + b.snd);
	}
};
 
struct compose {
	update operator () (update a, update b) const {
		if (a.type == 1) return a;
		b.v += a.v;
		return b;
	}
};
 
int T, N, Q;
 
int main(){
	scanf("%d", &T);
 
	for (int t = 1; t <= T; t++){
		printf("Case %d:\n", t);
 
		scanf("%d %d", &N, &Q);
 
		vector<pll> v(N);
 
		for (int i = 0; i < N; i++){
			scanf("%lld", &v[i].fst);
			v[i].snd = v[i].fst * v[i].fst;
		}
 
		SegmentTreeRangeUpdates<pll,update,apply_range,add,compose> st(v, mp(0,0), update(0,0));

		while (Q--){
			int op, x, y, val;

			scanf("%d %d %d", &op, &x, &y);
			x--; y--;

			if (op == 2){
				printf("%lld\n", st.query(x, y).snd);
				continue;
			}

			scanf("%d", &val);

			st.update(x, y, update(op == 0, val));
		}
	}
}
