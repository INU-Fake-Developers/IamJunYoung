#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <array>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <numeric>
#include <deque>

typedef long long int LLI;

using namespace std;

int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

/* 뚜루루뚜루 */

int n;
bool grid[30][30];

int dfs(int x, int y) {
	if (x < 0 || y < 0 || x == n || y == n || grid[y][x] == 0) return 0;

	int ret = 1;
	grid[y][x] = 0;

	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		ret += dfs(nx, ny);
	}

	return ret;
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%1d", &grid[i][j]);
		}
	}
	priority_queue<int, vector<int>, greater<int>> q;
	for(int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int res = dfs(i, j);
			if (res) q.push(res);
		}
	}

	cout << q.size() << endl;
	while (!q.empty()) {
		cout << q.top() << endl;
		q.pop();
	}
	return 0;
}
