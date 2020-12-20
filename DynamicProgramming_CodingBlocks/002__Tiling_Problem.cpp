#include <bits/stdc++.h>

using namespace std;

const unsigned int M = 1000000007;

void io_setup() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

}

/*Given a floor of size n x m. Find the number of ways to tile the floor with tiles of size 1 x m .
A tile can either be placed horizontally or vertically.

Input Format
First line of input contains an integer T denoting the number of test cases. Then T test cases follow.
The first line of each test case contains two integers N and M.

Constraints
1 <= T<= 1000
1 <= N,M <= 100000

Output Format
Print answer for every test case in a new line modulo 10^9+7.

Sample Input
2
2 3
4 4
Sample Output
1
2
*/


long long tile(int n, int m, int tiles[]) {

	//Base Case
	if (n < 0)
		return 0;
	if (n == 0 || n < m)
		return 1;

	if (tiles[n] != 0)
		return tiles[n];

	//Recursive case
	return tiles[n] = max(tile(n - 1, m, tiles) + 1, tile(n - m, m, tiles) + 1);
}


int main() {
	io_setup();



	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		int tiles[100000] = {0};

		cout << tile(n, m, tiles) % M << endl;

	}

	return 0;
}