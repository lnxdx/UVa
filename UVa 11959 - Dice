#include<bits/stdc++.h>
using namespace std;

string r_rot(string s) // front rotation clockwise
{
	int temp = s[2]; // save front
	s[2] = s[1]; // bottom to front
	s[1] = s[4]; // back to bottom
	s[4] = s[0]; // top to back
	s[0] = temp; // front to top
	return s;
}

string f_rot(string s)
{
	int temp = s[5];
	s[5] = s[0];
	s[0] = s[3];
	s[3] = s[1];
	s[1] = temp;
	return s;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string s, ss;
		cin >> s >> ss;;

		bool ans = false;
		for (int f = 0;f<4;f++) // We check some rotations multiple times.
			for (int r = 0;r < 4;r++)
				for (int f2 = 0;f2<4;f2++)
				{
					string t = s;
					for (int i = 0;i < f;i++)
						t = f_rot(t);
					for (int i = 0;i < r;i++)
						t = r_rot(t);
					for (int i = 0;i < f2;i++)
						t = f_rot(t);
					if (t == ss)
						ans = true;
				}

		if (ans)
			cout << "Equal\n";
		else
			cout << "Not Equal\n";

	}
}
