#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array
#define mat vector<vector<int>>
#define forn(i, n) for (int i = 0; i < (int)n; ++i)
int m, n;
bool seen[1001][1001];

int dfs(mat &v, int i, int j)
{
  if (i < 0 || i >= m || j < 0 || j >= n || seen[i][j] || !v[i][j])
    return 0;
  seen[i][j] = 1;
  return 1 + dfs(v, i - 1, j) + dfs(v, i + 1, j) + dfs(v, i, j + 1) + dfs(v, i, j - 1);
}

void solve(mat &v)
{
  int ans = 0;
  for (int i = 0; i < m; ++i)
  {
    for (int j = 0; j < n; ++j)
      if (!v[i][j])
      {
        memset(seen, 0, sizeof(seen));
        v[i][j] = 1;
        ans = max(ans, dfs(v, i, j));
        v[i][j] = 0;
      }
  }

  cout << ans;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> m >> n;
  mat v(m, vector<int>(n));
  for (auto &vec : v)
    for (auto &a : vec)
      cin >> a;
  solve(v);
}