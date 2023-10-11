#include <bits/stdc++.h>
#define int long long
#define ld long double
#define mask(i) (1LL << (i))
using namespace std;
#define all(x) x.begin(), x.end()
#define maxe(x) max_element(all(x))
#define mine(x) min_element(all(x))
const int inf = 1e18;
const int mxn = 1e5 + 5;
const int mod = 1e9 + 7;
int spf[mxn];
int __gcd(int a, int b)
{
	return !b ? a : __gcd(b, a % b);
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	iota(spf, spf + mxn, 0);
	for (int i = 2; i * i < mxn; i++)
	{
		if (spf[i] == i) for (int j = i * i; j < mxn; j += i) if (spf[j] == j) spf[j] = i;
	}
	const int block = 224;
	int n;
	cin >> n;
	int num_block = (n + block - 1) / block;
	vector<vector<int>> cnt(num_block, vector<int>(mxn));
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		vector<int> d;
		int k = v[i];
		while (k > 1)
		{
			if (d.empty() || spf[k] != d.back()) d.push_back(spf[k]);
			k /= spf[k];
		}
		for (int j = 0; j < mask(d.size()); j++)
		{
			int f = 1;
			for (int l = 0; l < d.size(); l++)
			{
				if (j & mask(l)) f *= d[l];
			}
			cnt[i / block][f]++;
		}
	}
	int q;
	cin >> q;
	while (q--)
	{
		int t;
		cin >> t;
		if (t == 1)
		{
			int p, val;
			cin >> p >> val;
			p--;
			int i = p;
			vector<int> d;
			int k = v[i];
			while (k > 1)
			{
				if (d.empty() || spf[k] != d.back()) d.push_back(spf[k]);
				k /= spf[k];
			}
			for (int j = 0; j < mask(d.size()); j++)
			{
				int f = 1;
				for (int l = 0; l < d.size(); l++)
				{
					if (j & mask(l)) f *= d[l];
				}
				cnt[i / block][f]--;
			}
			d.clear();
			v[i] = val;
			k = v[i];
			while (k > 1)
			{
				if (d.empty() || spf[k] != d.back()) d.push_back(spf[k]);
				k /= spf[k];
			}
			for (int j = 0; j < mask(d.size()); j++)
			{
				int f = 1;
				for (int l = 0; l < d.size(); l++)
				{
					if (j & mask(l)) f *= d[l];
				}
				cnt[i / block][f]++;
			}
		}
		else
		{
			int l, r, val;
			cin >> l >> r >> val;
			int len = r - l + 1;
			l--, r--;
			int ans = 0;
			while (l % block && l <= r)
			{
				ans += __gcd(v[l++], val) != 1;
			}
			while ((r + 1) % block && r >= l)
			{
				ans += __gcd(v[r--], val) != 1;
			}
			vector<int> d;
			int k = val;
			while (k > 1)
			{
				if (d.empty() || spf[k] != d.back()) d.push_back(spf[k]);
				k /= spf[k];
			}
			for (int j = 1; j < mask(d.size()); j++)
			{
				int f = 1, c = 0;
				for (int l = 0; l < d.size(); l++)
				{
					if (j & mask(l)) f *= d[l], c ^= 1;
				}
				if (c)
				{
					for (int i = l; i < r; i += block)
					{
						ans += cnt[i / block][f];
					}
				}
				else
				{
					for (int i = l; i < r; i += block)
					{
						ans -= cnt[i / block][f];
					}
				}
			}
			cout << len - ans << '\n';
		}
	}
	return 0;
}