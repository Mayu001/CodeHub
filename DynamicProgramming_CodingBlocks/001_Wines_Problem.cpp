#include <bits/stdc++.h>

using namespace std;

void io_setup() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

}

/*		Problem Statement

Given n wines in a row, with integers denoting the cost of each wine respectively.
Each year you can sell the first or the last wine in the row. Let the initial profits from the wines be P1, P2, P3…Pn.
In the Yth year, the profit from the ith wine will be Y*P[i].
The goal is to calculate the maximum profit that can be earned by selling all the wines.
*/



int profit(int price[], int i, int j, int year, int dp[][100]) {

	//Base Case
	if (i > j)
		return 0;

	if (dp[i][j] != 0)
		return dp[i][j];

	//Recursive case
	int profit1 = price[i] * year + profit(price, i + 1, j, year + 1, dp);
	int profit2 = price[j] * year + profit (price, i, j - 1, year + 1, dp);
	return max(profit1, profit2);
}


int main() {
	io_setup();

	int n;
	cin >> n;
	int price[n];
	for (int i = 0; i < n; i++)
		cin >> price[i];
	int year = 1;
	int dp[100][100] = {0};

	cout << profit(price, 0, n - 1, year, dp);

	return 0;
}