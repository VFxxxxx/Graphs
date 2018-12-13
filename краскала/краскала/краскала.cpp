// краскала.cpp: определяет точку входа для консольного приложения.
//

//за минимальную стоимость делаем граф связным
//#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
//#include <bits/stdc++.h>
using namespace std;
vector <pair <int, pair <int, int> > > g;
int parent[100001];
int rang[100001];
void make_set(int a)
{
	parent[a] = a;
	rang[a] = 1;
}
int find_set(int a)
{
	if (parent[a] == a)
		return a;
	return parent[a] = find_set(parent[a]);
}
void union_set(int a, int b)
{
	a = find_set(a);
	b = find_set(b);
	if (a != b)
	{
		if (rang[a] > rang[b])
		{
			parent[b] = a;
			rang[a] += rang[b];
		}
		else
		{
			parent[a] = b;
			rang[b] += rang[a];
		}
	}
}
long long ans = 0;
int main()
{
	ifstream fin("input.txt");
	ios_base::sync_with_stdio(0);
	int n;
fin >> n;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
		{
			int x;
			fin >> x;
			if (i > j)
				g.push_back({ x,{ i, j } }); //считываем стоимости возможных к добавленнию ребёр
		}
	sort(g.begin(), g.end());
	for (int i = 1; i <= n; ++i)
		make_set(i);//для каждой вершины пока своё множество
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
		{
			int x;
			fin >> x;
			if (x == 1)
				union_set(i, j);//считываем матрицу смежности и объединяем множества, если есть ребро
		}
	for (int i = 0; i < g.size(); ++i)
	{
		int w = g[i].first;//цена
		int x = g[i].second.first;//откуда
		int y = g[i].second.second;//куда
		if (find_set(x) != find_set(y))//если они из разных множеств
		{
			ans += w;//соеденим их
			union_set(x, y);
		}
	}
	cout << ans;
	return 0;
}