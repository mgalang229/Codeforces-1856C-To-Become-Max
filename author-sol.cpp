#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void test_case(int& tc) {
	ll n, k;
	cin >> n >> k;
	vector<ll> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	ll low = 0, high = *max_element(a.begin(), a.end()) + k;
	ll ans = 0;
	while (low <= high) {
		ll mid = low + (high - low) / 2;
		bool good = false;
		for (int i = 0; i < n; i++) {
			vector<ll> min_needed(n);
			min_needed[i] = mid;
			ll c_used = 0;
			for (int j = i; j < n; j++) {
				if (min_needed[j] <= a[j]) {
					break;
				}
				if (j + 1 >= n) {
					c_used = k + 1;
					break;
				}
				c_used += min_needed[j] - a[j];
				min_needed[j+1] = max(0LL, min_needed[j] - 1);
			}
			if (c_used <= k) {
				good = true;
			}
		}
		if (good) {
			ans = mid;
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T = 1;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		test_case(tc);
	}
}
