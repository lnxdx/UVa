// ITNOG
// bidirectional bfs by lnxdx

#include<bits/stdc++.h>
using namespace std;

map<string, bool>seen;
map<string, bool>seen2;
//map<string, string>par;

int bfs(string source, string goal)
{
	queue<pair<string, int>>q;
	q.push({ source,0 });
	seen[source] = true;
	while (q.size())
	{
		pair<string, int> curp = q.front();
		string cur = curp.first;
		string temp;
		q.pop();
		if (cur == goal)
			return curp.second;
		if (curp.second <2)
			for (int i = 0;i<cur.size();i++)
				for (int j = i; j < cur.size(); j++)
				{
					string move = cur.substr(i, j - i + 1);
					for (int k = 0; k <= cur.size(); k++)
					{
						temp = cur;
						if (k > j)
							temp = cur.substr(0, i) + cur.substr(j + 1, k - 1 - (j + 1) + 1) + move + cur.substr(k);
						else if (k <= i)
							temp = cur.substr(0, k) + move + cur.substr(k, i - 1 - k + 1) + cur.substr(j + 1);
						if ((k > j || k <= i))
						{
							if (!seen.count(temp))
							{
								q.push({ temp,curp.second + 1 });
								seen[temp] = true;
							}
						}
					}
				}
	}
	return -1;
}
int bfs2(string source, string goal)
{
	queue<pair<string, int>>q;
	q.push({ source,0 });
	seen2[source] = true;
	while (q.size())
	{
		pair<string, int> curp = q.front();
		string cur = curp.first;
		string temp;
		q.pop();
		if (seen.count(cur))
			return curp.second;
		if (curp.second <2)
			for (int i = 0;i<cur.size();i++)
				for (int j = i; j < cur.size(); j++)
				{
					string move = cur.substr(i, j - i + 1);
					for (int k = 0; k <= cur.size(); k++)
					{
						temp = cur;
						if (k > j)
							temp = cur.substr(0, i) + cur.substr(j + 1, k - 1 - (j + 1) + 1) + move + cur.substr(k);
						else if (k <= i)
							temp = cur.substr(0, k) + move + cur.substr(k, i - 1 - k + 1) + cur.substr(j + 1);
						if ((k > j || k <= i))
						{
							if (!seen2.count(temp))
							{
								q.push({ temp,curp.second + 1 });
								seen2[temp] = true;
							}
						}
					}
				}
	}
	return -1;
}
int main()
{
	int casi = 0, n;

	while (~scanf("%d", &n) && n)
	{
		string v, u;
		printf("Case %d: ", ++casi);
		for (int i = 0;i < n;i++)
		{
			int c;
			scanf("%d", &c);
			v += char(c + '0');
			u += char(i + 1 + '0');
		}
		//cout << u << ' ' << v << "\n";
		int f1 = bfs(u, v);
		if (f1 != -1)
			printf("%d", f1);
		else
		{
			int f2 = bfs2(v, u);
			if (f2 == 1)
				printf("3");
			else if (f2 == 2)
				printf("4");
			else if (f2 == -1)
				printf("5");
		}
		seen.clear();
		seen2.clear();
		cout << "\n";
	}
}
