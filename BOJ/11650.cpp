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

typedef long long int LLI;

using namespace std;

/* 뚜루루뚜루 */

int main() 
{	
	vector<pair<int, int>> v;
	int n;
	int readx, ready;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		scanf("%d %d", &readx, &ready);
		v.push_back(make_pair(readx, ready));
	}
	sort(v.begin(), v.end());
	for (auto iter = v.begin(); iter != v.end(); ++iter) {
		printf("%d %d \n", (*iter).first, (*iter).second);
	}
	return 0;
}
