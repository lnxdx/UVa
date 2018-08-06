#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 3e3 + 33;

int row[8], a, b, line_counter; // ok to use global variables
bool check(int r, int c)
{
	for (int prev = 0; prev < c; prev++) // check previously placed queens
		if (row[prev] == r || (abs(row[prev] - r) == abs(prev - c)))
			return false; // share same row or same diagonal -> infeasible
	return true;
}
void backtrack(int c)
{
	if (c == 8 && row[b] == a) // candidate sol, (a, b) has 1 queen
	{
		printf("%2d      %d", ++line_counter, row[0] + 1);
		for (int j = 1; j < 8; j++)
			printf(" %d", row[j] + 1);
		printf("\n");
	}
	for (int r = 0; r < 8; r++) // try all possible row
		if (check(r, c)) // if can place a queen at this col and row
		{
			row[c] = r; // put this queen here and recurse
			backtrack(c + 1);
		}
}
int main() 
{
	int t;
	scanf("%d", &t);
	while (t--) 
	{
		scanf("%d %d", &a, &b);
		a--; b--;
		memset(row, 0, sizeof row);
		line_counter = 0;
		
		printf("SOLN       COLUMN\n");
		printf(" #      1 2 3 4 5 6 7 8\n\n");
		backtrack(0);
		
		if (t)
			printf("\n");
	}
}
