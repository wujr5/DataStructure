#include<iostream>
#include<queue>
#include<stdlib.h>
using namespace std;

int visited[200];
int num = 0;


struct Edge {
	int index;
	int weight;
	Edge* next;
	Edge(int v = 0, int w = 1, Edge* n = NULL) {
		index = v;
		weight = w;
		next = n;
	}
};
struct Vertex {
	int index;
	int data;
	Edge* first_edge;
	Vertex(int i = 0, int d = 0, Edge* f = NULL) {
		index = i;
		data = d;
		first_edge = f;
	}
};
struct Graph {
	int vertex_num;
	int edge_num;
	Vertex adj[200];
	Graph(int v = 0, int e = 0) {
		vertex_num = v;
		edge_num = e;
	}
};

void BFS(Graph* g, int i) {
	queue<int> q;
	q.push(g->adj[i].index);
	
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		
		Edge* p = g->adj[v].first_edge;
		while (p != NULL) {
			if (visited[p->index] == -1) {
				q.push(p->index);
				visited[p->index] = 0;
			}
			p = p->next;
		}
		visited[v] = 1;
	}
}
void BFSTraverse(Graph* g) {
	for (int i = 0; i < g->vertex_num; i++) {
		g->adj[i].index = i;
		visited[i] = -1;
	}
	for (int i = 0; i < g->vertex_num; i++) {
		if (visited[i] == -1) {
			num++;
			BFS(g, i);
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	
	Graph* g = new Graph(n, m);
	
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		
		u--;
		v--;
		
		Edge* s = new Edge(v, 1, g->adj[u].first_edge);
		g->adj[u].first_edge = s;
		
		s = new Edge(u, 1, g->adj[v].first_edge);
		g->adj[v].first_edge = s;
	}
	
	BFSTraverse(g);
	cout << num << endl;
	
	system("pause");
}
