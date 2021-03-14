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

typedef long long int LLI;

using namespace std;

/* 뚜루루뚜루 */


int main() 
{ 
	int n;
	priority_queue<int, vector<int>, greater<int>> pq;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int readInt;
		scanf("%d", &readInt);
		pq.push(readInt);
	}
	int total = 0;
	int endTime = 0;
	while (pq.size()) {
		endTime += pq.top();
		total += endTime;
		pq.pop();
	}
	cout << total << endl;
	return 0;
}
