// ITNOG
// O((# of tests).(# of events)) Simulation by lnxdx, Mashhad, 2018

#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
	int d = 0, l = 0, old_d = 0, old_l = 0, leak_rate = 0;
	double sum = 0, ans = 0;
	char typ[13], s[13];
	bool end = false;
	while (scanf("%d%s", &d, typ))
	{
		if (string(typ) == "Fuel")
		{
			scanf("%s%d", s, &l);
			if (l == 0)
				break;
			sum += (d - old_d)*leak_rate;
			sum += (d - old_d)*old_l / 100.0;
			ans = max(ans, sum);
			old_l = l;
		}
		else if (string(typ) == "Leak")
		{
			sum += (d - old_d)*leak_rate;
			sum += (d - old_d)*old_l / 100.0;
			ans = max(ans, sum);
			leak_rate += 1;
		}
		else if (string(typ) == "Mechanic")
		{
			sum += (d - old_d)*leak_rate;
			sum += (d - old_d)*old_l / 100.0;
			ans = max(ans, sum);
			leak_rate = 0;
		}
		else if (string(typ) == "Gas")
		{
			scanf("%s", s);
			sum += (d - old_d)*leak_rate;
			sum += (d - old_d)*old_l / 100.0;
			ans = max(ans, sum);
			sum = 0;
		}
		else if (string(typ) == "Goal")
		{
			sum += (d - old_d)*leak_rate;
			sum += (d - old_d)*old_l / 100.0;
			ans = max(ans, sum);
			printf("%.3lf\n", ans);
			d = l = old_d = old_l = ans = sum = leak_rate = 0;
			end = false;
		}
		old_d = d;
	}
}
