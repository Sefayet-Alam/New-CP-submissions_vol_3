#include <bits/stdc++.h>
using namespace std;

const int c=1005;
long long n, m, ans, ss, so;
set<long long> sor, oszlop, sum, dif;
bool jo(long long a, long long b) {
	return (1<=a && a<=n && 1<=b && b<=n);
}
void solve() {
	cin >> n >> m;
	for (int i=1; i<=m; i++) {
		long long x, y;
		cin >> x >> y;
		sor.insert(x), oszlop.insert(y);
		sum.insert(x+y), dif.insert(x-y);
	}
	ss=sor.size(), so=oszlop.size();
	ans=(n-ss)*(n-so);

	for (auto ossz:sum) {
		ans-=n-abs(n+1-ossz);
		for (auto x:sor) {
			long long y=ossz-x;
			if (jo(x, y)) ans++;
		}
		for (auto y:oszlop) {
			long long x=ossz-y;
			if (jo(x, y) && sor.find(x)==sor.end()) ans++;
		}
	}

	for (auto kul:dif) {
		ans-=n-abs(kul);
		for (auto x:sor) {
			long long y=x-kul;
			if (jo(x, y)) ans++;
		}
		for (auto y:oszlop) {
			long long x=kul+y;
			if (jo(x, y) && sor.find(x)==sor.end()) ans++;
		}
		for (auto ossz:sum) {
			long long x=(ossz+kul)/2, y=(ossz-kul)/2;
			if (x+y==ossz && x-y==kul && jo(x, y) && sor.find(x)==sor.end() && oszlop.find(y)==oszlop.end()) ans++;
		}
	}

	cout << ans << "\n";


}
int main() {
	ios_base::sync_with_stdio(false);
	int w=1;
	//cin >> w;
	while (w--) {
		solve();
	}
}
