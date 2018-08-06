#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	while (cin >> n && n > 0)
	{
		vector<int>scores;
		for (int i = 0;i <= 20;i++)
		{
			scores.push_back(i);
			scores.push_back(i + i);
			scores.push_back(i + i + i);
		}
		scores.push_back(50);
		sort(scores.begin(), scores.end());
		scores.resize(unique(scores.begin(), scores.end()) - scores.begin());

		int comb = 0, perm = 0;
		for (int i = 0;i<scores.size();i++)
			for (int j = i;j<scores.size();j++)
				for (int k = j;k < scores.size();k++)
				{
					if (scores[i] + scores[j] + scores[k] == n)
					{
						comb++;
						set<int>st;
						st.insert(scores[i]), st.insert(scores[j]), st.insert(scores[k]);
						if (st.size() == 1)
							perm++;
						else if (st.size() == 2)
							perm += 3;
						else
							perm += 6;
					}
				}
		if (comb)
		{
			cout << "NUMBER OF COMBINATIONS THAT SCORES " << n << " IS " << comb << ".\n";
			cout << "NUMBER OF PERMUTATIONS THAT SCORES " << n << " IS " << perm << ".\n";
		}
		else
			cout << "THE SCORE OF " << n << " CANNOT BE MADE WITH THREE DARTS.\n";
		cout << string(70, '*') << "\n";;
	}
	cout << "END OF OUTPUT\n";
}
