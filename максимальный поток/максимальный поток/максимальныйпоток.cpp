// максимальныйпоток.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include <fstream>
#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 15;
const int INF = 1 * 1000 * 1000;

int n, cF[MAXN][MAXN], s, t, layers[MAXN], ptr[MAXN];

int bfs() {
	queue <int> Q;
	Q.push(s);
	memset(layers, -1, n * sizeof(layers[0]));
	layers[s] = 0;
	while (Q.size()) {
		int v = Q.front();
		Q.pop();
		for (int to = 0; to < n; ++to) {
			if (cF[v][to] && layers[to] == -1) {
				layers[to] = layers[v] + 1;
				Q.push(to);
			}
		}
	}
	return layers[t] != -1;
}

int dfs(int v, int flow) {
	cerr << "    " << v << " " << flow << endl;
	if (!flow)
		return 0;
	if (v == t)
		return flow;
	for (int &to = ptr[v]; to < n; ++to) {
		if (layers[to] != layers[v] + 1)
			continue;
		int pushed = dfs(to, min(flow, cF[v][to]));
		if (pushed) {
			cF[v][to] -= pushed;
			cF[to][v] += pushed;
			return pushed;
		}
	}
	return 0;
}

int dinic() {
	int flow = 0;
	while (bfs()) {
		cerr << "level graph: " << layers[t] << endl;
		memset(ptr, 0, n * sizeof(ptr[0]));
		while (int pushed = dfs(s, INF)) {
			flow += pushed;
		}
	}
	return flow;
}

int main() {
	ifstream fin("input.txt");
	int m;
	fin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		fin >> a >> b >> c;
		a--;
		b--;
		cF[a][b] = c;
	}
	s = 0;
	t = n - 1;
	cout << dinic() << endl;
	cin >> t;
	return 0;
}
