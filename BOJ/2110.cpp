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

using namespace std;

typedef long long ll;

int dx[] = { 0, 0, -1, 1, 1, 1, -1, -1 };
int dy[] = { -1, 1, 0, 0, -1, 1, 1, -1 };

const int INF = 987654321;

/* --- */

int n, m;
vector<int> home;

bool can(int d) {
    int cnt = m - 1;
    int pre = home[0];
    for (int i = 0; i < n; ++i) {
        if (home[i] - pre >= d) {
            pre = home[i];
            --cnt;
        }
    }

    if (cnt <= 0) return true;
    else return false;
}

int search(int left, int right) {
    if (left + 1 == right) {
        if (can(right)) return right;
        else return left;
    }
    
    int mid = (left + right) / 2;

    if (can(mid)) return search(mid, right);
    else return search(left, mid);
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int input;
        scanf("%d", &input);
        home.push_back(input);
    }

    sort(home.begin(), home.end());

    cout << search(0, 1000000000);

    return 0;
}
