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

/* 뚜루루뚜루 */

bool visited[101];
bool graph[101][101];
int n;
int k;

void DFS(int here)
{
	visited[here] = true;
	
	for (int next = 1; next <= n; ++next) {
		if (visited[next]) continue;
		if (graph[here][next]) DFS(next);
	}
}

int main() {
	cin >> n >> k;
	for (int i = 0; i < k; ++i) {
		int readA, readB;
		cin >> readA >> readB;
		graph[readA][readB] = true;
		graph[readB][readA] = true;
	}

	DFS(1);
	cout << accumulate(begin(visited), begin(visited)+n+1, -1) << endl;

	return 0;
}
