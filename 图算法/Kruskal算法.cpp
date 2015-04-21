#include<iostream>
#include<stdlib.h>
using namespace std;

const int VertexNum = 7;
const int EdgeNum = 11;

struct Graph {
    char vertex[VertexNum];                                //�����         
    int edges[VertexNum][VertexNum];                       //�ڽӾ���,�ɿ����߱�         
    int n,e;                                               //ͼ�е�ǰ�Ķ������ͱ���         
};

struct Edge {  
    int u;                                                 //�ߵ���ʼ����   
    int v;                                                 //�ߵ���ֹ����   
    int w;                                                 //�ߵ�Ȩֵ   
};

void sort(Edge E[], int k) {
	for (int i = 0; i < k-1; i++) {
		for (int j = i+1; j < k; j++) {
			if (E[i].w > E[j].w) {
				Edge tem = E[i];
				E[i] = E[j];
				E[j] = tem;
			}
		}
	}
}

void print_edges(Edge* e, int m) {
	for (int i = 0; i < m; i++) {
		cout << "e[" << i << "]: ";
		cout << "u = " << e[i].u;
		cout << ", v = " << e[i].v;
		cout << ", w = " << e[i].w << endl;
	}
}

void kruskal(Graph G) {  
    int i,j,u1,v1,sn1,sn2,k;  
    int vset[VertexNum];                                    //�������飬�ж����������Ƿ���ͨ   
    Edge E[EdgeNum];                                         //������еı�   
    k=0;                                                    //E������±��0��ʼ  
	int sum = 0; 
    for (i = 0; i < G.n; i++) {  
        for (j  =0;j < G.n; j++) {  
            if (i > j && G.edges[i][j] != 
			0) {  
                E[k].u = i;  
                E[k].v = j;  
                E[k].w = G.edges[i][j];
                k++;
            }  
        }  
    }
    
    sort(E, k);
    //print_edges(E, k);
	//system("pause");
	
    for (i  =0;i < G.n; i++) {                                  //��ʼ����������     
        vset[i] = i;  
    }
    k=1;                                                   //���ɵı��������Ҫ�պ�Ϊ�ܱ���   
    j=0;                                                   //E�е��±�   
    while (k < G.n) {   
        sn1 = vset[E[j].u];  
        sn2 = vset[E[j].v];                                  //�õ����������ڵļ��ϱ��   
        if (sn1 != sn2) {                                    //����ͬһ���ϱ���ڵĻ����ѱ߼�����С������   
			cout << E[j].u << "->" << E[j].v << " " << E[j].w << endl;
			sum += E[j].w;
            k++;
            for (i=0;i<G.n;i++) {
                if (vset[i]==sn2) {
                    vset[i]=sn1;
                }
            }
        }
        j++;
    }
    cout << "sum = " << sum << endl;
}

void print_graph(int (*a)[VertexNum], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}
void init(Graph* g) {
	for (int i = 0; i < g->n; i++) {
		for (int j = 0; j < g->n; j++) {
			g->edges[i][j] = 0;
		}
	}
}

int main() {
	Graph g;
	int n, m;
	cin >> n >> m;
	
	g.n = n;
	g.e = m;
	
	init(&g);
	for (int i = 0; i < m; i++) {
		int a, b, x;
		cin >> a >> b >> x;
		a--;
		b--;
		
		g.edges[a][b] = x;
		g.edges[b][a] = x;
	}
	

	
	print_graph(g.edges, n);
	
	kruskal(g);
	
	system("pause");
}

/*
7 11
1 2 7
1 4 5
2 3 8
2 4 9
2 5 7
3 5 5
4 5 15
4 6 6
5 6 8
5 7 9
6 7 11
*/
