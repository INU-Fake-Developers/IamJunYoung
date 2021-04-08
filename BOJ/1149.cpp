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

int cache[3];

int main() {
    int n;
    cin >> n;
    
    int a, b, c;
    cin >> a >> b >> c;
    cache[0] = a; cache[1] = b; cache[2] = c;
    for (int i = 1; i < n; ++i) {
        scanf("%d %d %d", &a, &b, &c);
        a += min(cache[1], cache[2]);
        b += min(cache[0], cache[2]);
        c += min(cache[0], cache[1]);
        cache[0] = a; cache[1] = b; cache[2] = c;
    }

    int result = min({ cache[0], cache[1], cache[2] });
    cout << result << endl;

    return 0;
}
