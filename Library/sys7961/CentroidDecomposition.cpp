#include<bits/stdc++.h>
using std::vector;
using std::pair;
using lint = long long int;
using pii = std::pair<int, int>;


struct edge {
	int to;
	int rev;
	bool vaild;
};

vector<edge> G[100100];
bool chk[100100];
int weight[100100];
int parent[100100];
void add_edge(int a, int b) {
	edge e = { b,G[b].size(),true };
	edge re = { a,G[a].size(),true };
	G[a].push_back(e);
	G[b].push_back(re);
}

int dfs(int idx) {
	chk[idx] = true;
	weight[idx] = 1;
	for (edge& e : G[idx]) {
		if (e.vaild && !chk[e.to]) {
			parent[e.to] = idx;
			weight[idx] += dfs(e.to);
		}
	}
	chk[idx] = false;
	return weight[idx];
}
int find_centroid(int idx) {
	parent[idx] = -1;
	dfs(idx);
	int n = weight[idx];
	while (true) {
		bool flag = false;
		for (edge& e : G[idx]) {
			if (e.vaild && parent[idx] != e.to && weight[e.to]>n / 2) {
				idx = e.to;
				flag = true;
				break;
			}
		}
		if (!flag)break;
	}
	return idx;
}
struct node {
	std::unordered_set<int> V;
};
node P[100100];
vector<int> CG[100100];
bool chk2[100100];
int divide(int idx) {
	idx = find_centroid(idx);
	//calculate
	for (edge& e : G[idx]) {
		if (e.vaild) {
			e.vaild = false;
			G[e.to][e.rev].vaild = false;

			/*
				find answer
			*/
			CG[idx].push_back(divide(e.to));
		}
	}
	P[idx].V.insert(idx);
	for (int to : CG[idx]) {
		for (int i : P[to].V) {
			P[idx].V.insert(i);
		}
	}
	return idx;
}
void update(int idx, int p, bool add) {
	int d = P[idx].dist[p];
	auto& set = P[idx].smallest;
	if (add)set.insert(d);
	else set.erase(set.find(d));
	if (idx == p)return;
	for (int to : CG[idx]) {
		if (P[to].V.count(p)) {
			update(to, p, add);
			return;
		}
	}
}
int getClosest(int idx, int p) {
	int ret = 0x7fffffff / 2;
	if (!P[idx].smallest.empty())ret = std::min(ret, *P[idx].smallest.begin() + P[idx].dist[p]);

	if (idx == p)return ret;
	for (int to : CG[idx]) {
		if (P[to].V.count(p)) {
			ret = std::min(ret, getClosest(to, p));
			break;
		}
	}
	return ret;
}