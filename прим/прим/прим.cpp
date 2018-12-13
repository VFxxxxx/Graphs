// прим.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <set>
//#define long long int;

//#include <bits/stdc++.h>
using namespace std;

//ищем минимальный каркас
int main() {
	ios_base::sync_with_stdio(0);
	const int inf = 1e9;

	int n, m, ans = 0;
	ifstream fin("input.txt");

	fin >> n >> m;//число вершин, число рёбер
	vector<pair<int, int>> graph[1000];
	vector<bool> used(n, false);
	vector<int> dist(n, inf);
	multiset<pair<int, int>> ms;
	dist[0] = 0;
	ms.insert({ 0, 0 });
	for (int i = 1; i < n; i++)
		ms.insert({ inf, i });//по умолчанию делаем очень большое число до начала работы
	for (int i = 0; i < m; i++) {
		int a, b, w;
		fin >> a >> b >> w; //вершина, вершина, ребро
		graph[a - 1].push_back({ b - 1, w }); //добавляем вершине, что у неё есть ребро с вот этой вершиной и с такой длиной
		graph[b - 1].push_back({ a - 1, w });
	}

	for (int i = 0; i < n; i++) {
		int v = ms.begin()->second;//берём вершину
		ms.erase(ms.begin());
		used[v] = true;//чекаем, что с ней уже работаем
		for (auto u : graph[v]) {// идём по рёбрам этой вершины
			int to = u.first, w = u.second;
			if (w < dist[to] && !used[to]) {//если этот путь через непосещённую вершину самый минимальный
				ms.erase({ dist[to], to });
				if (dist[to] != inf)//если это уже не первый шаг
					ans -= dist[to];//считаем расстояние
				dist[to] = w;
				ans += w;
				ms.insert({ dist[to], to });//теперь идём в эту вершину
			}
		}
	}

	cout << ans << endl;//вес 
	cin >> n;
	return 0;
}
