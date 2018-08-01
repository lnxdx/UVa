// ITNOG
// O(1) math by lnxdx, Mashhad, 2018

#include<bits/stdc++.h>
using namespace std;

int main()
{
	double h, m;
	while (scanf("%lf:%02lf", &h, &m) && (h || m))
	{
		double h_ang, m_ang;
		h_ang = h / 12 + m / (12 * 60);
		m_ang = m / 60;
		printf("%.3lf\n", 360 * min(abs(h_ang - m_ang), 1 - abs(h_ang - m_ang)));
	}
}
