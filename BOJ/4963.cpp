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

int column, row;
int grid[55][55];

void dfs(int r, int c) {
    if (r < 0 || r >= row || c < 0 || c >= column) return;
    if (grid[r][c] == 0) return;

    grid[r][c] = 0;
    for (int i = 0; i < 8; ++i) {
        int nr = r + dy[i];
        int nc = c + dx[i];
        dfs(nr, nc);
    }
}

int main() {
    while (true) {
        int cnt = 0;
        scanf("%d %d", &column, &row);
        if (row == 0 && column == 0) break;

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < column; ++j) {
                scanf("%d", &grid[i][j]);
            }
        }

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < column; ++j) {
                if (grid[i][j]) ++cnt;
                dfs(i, j);
            }
        }
        printf("%d\n", cnt);
    }

    return 0;
}
