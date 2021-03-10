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

using namespace std;

typedef long long ll;

int dx[] = { 0, 0, -1, 1, 1, 1, -1, -1 };
int dy[] = { -1, 1, 0, 0, -1, 1, 1, -1 };

const int INF = 987654321;

/* --- */

int n;

int main() {
    cin >> n;
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < n; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        pq.push(make_pair(-b, -a));
    }
    
    int cnt = 0;
    int last = 0;
    while (!pq.empty()) {
        if (-pq.top().second >= last) {
            last = -pq.top().first;
            ++cnt;
        }
        pq.pop();
    }

    cout << cnt;

    return 0;
}
