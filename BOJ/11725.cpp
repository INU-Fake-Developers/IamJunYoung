#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <numeric>
#include <functional>
#include <stack>

using namespace std;

typedef long long ll;

int dx[] = { 0, 0, -1, 1, 1, 1, -1, -1 };
int dy[] = { -1, 1, 0, 0, -1, 1, 1, -1 };

const int INF = 987654321;

/* --- */

int n;
vector<int> tree[100005];
bool visited[100005];
int parent[100005];

void dfs(int cur) {
    visited[cur] = true;

    for (int i = 0; i < tree[cur].size(); ++i) {
        int next = tree[cur][i];

        if (!visited[next]) {
            dfs(next);
            parent[next] = cur;
        }
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs(1);

    for (int i = 2; i <= n; ++i) {
        printf("%d\n", parent[i]);
    }

    return 0;
}
