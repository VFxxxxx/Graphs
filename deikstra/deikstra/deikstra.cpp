
//#include <bits/stdc++.h>
//#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <set>
#define long long int;

using namespace std;

const int INF = 2000000009;

signed main()
{
	ifstream fin("input.txt");
	int n, s, f;
	fin >> n >> s >> f;//размер старт финальная
	s--;
	f--;
	vector < vector < pair <int, int> > > g(n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			int t;
			fin >> t;
			if (t >= 0)
				g[i].push_back(make_pair(j, t)); //считываем матрицу смежности
		}
	vector <int> d(n, INF);
	d[s] = 0;
	set <pair <int, int> > q;
	q.insert(make_pair(d[s], s));
	while (!q.empty()) {
		int v = q.begin()->second;
		q.erase(q.begin());
		for (size_t i = 0; i < g[v].size(); i++) {//смотрим все рёбра текущей вершины
			int to = g[v][i].first, len = g[v][i].second; //номер вершины и длина ребра до неё
			if (d[v] + len < d[to]) {
				q.erase(make_pair(d[to], to));
				d[to] = d[v] + len;
				q.insert(make_pair(d[to], to));
			}
		}
	}


	ofstream fout("output.txt");
	if (d[f] == INF)
		return fout << -1, 0;
	fout << d[f];

	fout.close();
	return 0;
}


