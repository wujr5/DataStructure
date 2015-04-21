#include<iostream>
#include<queue>
#include<stdlib.h>
using namespace std;

const int VERTEXNUM = 8;
int visited[VERTEXNUM];
int dist[VERTEXNUM];

struct Edge {
	int vertex;
	int weight;
	Edge* next;
	Edge(int i = 0, int w = 1, Edge* n = NULL) {
		vertex = i;
		weight = w;
		next = n;
	}
};

struct Vertex {
	int data;
	Edge* first_edge;
	Vertex(int d = 0, Edge* f = NULL) {
		data = d;
		first_edge = f;
	}
};

struct Graph {
	int vertex_num;
	int edge_num;
	Vertex adj[VERTEXNUM];
	Graph(int v = 0, int e = 0) {
		vertex_num = v;
		edge_num = e;
	}
};

void create_graph(Graph*& g) {
	int v, e;
	
	cout << "输入顶点数，边数：" << endl;
	cin >> v >> e;
	
	g->vertex_num = v;
	g->edge_num = e;
	
	for (int i = 0; i < v; i++) {
		g->adj[i].data = i;
	}
	
	cout << "输入边信息： " << endl;
	 
	for (int i = 0; i < g->edge_num; i++) {
		int a, b;
		cin >> a >> b;
		
		Edge* s = new Edge(b, 1, g->adj[a].first_edge);
		g->adj[a].first_edge = s;
		
		s = new Edge(a, 1, g->adj[b].first_edge);
		g->adj[b].first_edge = s;
	}
} 

void print_graph(Graph* g) {
	for (int i = 0; i < g->vertex_num; i++) {
		cout << "adj[" << i << "]" << ":";
		
		Edge* p = g->adj[i].first_edge;
		while (p != NULL) {
			cout << p->vertex << "->";
			p = p->next;
		}
		
		cout << "NULL" << endl;
	}
}

//深度优先遍历 
//===========================================================
void DFS(Graph* g, int i) {
	Edge* p;
	cout << "visit vertex: " << g->adj[i].data << endl;
	visited[i] = true;
	p = g->adj[i].first_edge;
	
	while(p != NULL) {
		if (!visited[p->vertex]) DFS(g, p->vertex);
		p = p->next;
	}
} 

void DFSTraverse(Graph* g) {
	for (int i = 0; i < g->vertex_num; i++) {
		visited[i] = false;
	}
	
	for (int i = 0; i < g->vertex_num; i++) {
		if (!visited[i]) {
			DFS(g, i);
		}
	}
}

//===========================================================




//广度优先遍历
//===========================================================


void BFS(Graph* g, int i) {
	queue<int> q;
	
	q.push(i);
	visited[i] = 0;
	
	
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		
		if (visited[u] == 0) {
			cout << "visit vertex: " << g->adj[u].data << endl;
			Edge* p = g->adj[u].first_edge;
			while (p != NULL) {
				if (visited[p->vertex] == -1) {
					dist[p->vertex] = dist[u]+1;
					q.push(p->vertex);
					visited[p->vertex] = 0;
				}
				p = p->next;
			}
			visited[u] = 1;
		}
	}
} 

void BFSTraverse(Graph* g) {
	for (int i = 0; i < g->vertex_num; i++) {
		visited[i] = -1;
		dist[i] = 0;
	}
	for (int i = 0; i < g->vertex_num; i++) {
		if (visited[i] == -1) BFS(g, i);
	}
}

void print_dist() {
	for (int i = 0; i < VERTEXNUM; i++) {
		cout << "dist[" << i << "]:" << dist[i] << endl;
	}
}

//=========================================================== 
int main() {
	Graph* g = new Graph();
	
	create_graph(g);
	print_graph(g);
	
	cout << "DFS" << endl;
	DFSTraverse(g);
	
	cout << "BFS" << endl;
	BFSTraverse(g);
	
	print_dist();
	
	system("pause");
}
//输入：
/*
8 9

0 1
0 2
1 3
1 4
2 5
2 6
3 7
4 7
5 6
*/ 
