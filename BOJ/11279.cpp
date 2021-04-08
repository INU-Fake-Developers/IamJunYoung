#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

priority_queue<int, vector<int>, less<int>> pq;
int n;

int main(void) {
	cin >> n;
	
	for(int i = 0; i < n; ++i) {
		int input;
		scanf("%d", &input);
		
		if(input == 0) {
			if(pq.empty()) {
				printf("0\n");
			}
			else {
				printf("%d\n", pq.top());
				pq.pop();
			}
		}
		else {
			pq.push(input);
		}
	}	
	
	return 0;
}
