#include<iostream>
#include<stdlib.h>
using namespace std;

const int MAXINT = 100000;
const int VERTEXNUM = 7;                                     //����û��IDΪ0�ĵ�,so id�ŷ�Χ1~10

int graph[VERTEXNUM][VERTEXNUM];
int lowcost[VERTEXNUM] = {0};                                         //��¼Vnew��ÿ���㵽V���ڽӵ����̱�
int addvnew[VERTEXNUM];                                             //���ĳ���Ƿ����Vnew
int adjecent[VERTEXNUM] = {0};                                        //��¼V����Vnew���ڽ��ĵ�

void prim(int start, int n) {
     int sum = 0;

     for(int i = 0; i < n; i++) {                                     //�����Ǵ�1��ʼ
        lowcost[i] = graph[start][i];
        addvnew[i] = 0;
		adjecent[i] = start;                                         //�����е�����Vnew֮��,V֮�ڣ�����ֻҪ��Ӧ��Ϊ-1���ͱ�ʾ��Vnew֮��
     }

     addvnew[start] = 1;                                        //����ʼ��start����Vnew
     
     for(int i = 1; i < n; i++) {
        int min = MAXINT;
        int v = -1;
        
        for(int j = 0;j < n; j++) {             
            if(addvnew[j] == 0 && lowcost[j] < min) {                //��Vnew֮��Ѱ�����·��
                min = lowcost[j];
                v = j;
            }
        }
        
        if(v != -1) {
            cout << adjecent[v] << " " << v << " " << lowcost[v] << endl;
            addvnew[v] = 1;                                      //��v��Vnew��

            sum += lowcost[v];                             //����·������֮��
            for(int j = 0;j < n; j++) {
                if(addvnew[j] == 0 && graph[v][j] < lowcost[j]) {
                    lowcost[j] = graph[v][j];                     //��ʱv�����Vnew ��Ҫ����lowcost
                    adjecent[j] = v;
                }
            }
        }
    }
    cout << "the minmum weight is " << sum << endl;
}

void init(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) graph[i][j] = 0;
			else graph[i][j] = MAXINT;
		}
	}
}

void print_graph(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (graph[i][j] != MAXINT) cout << graph[i][j] << " ";
			else cout << "X ";
		}
		cout << endl;
	}
}

void print_adjecent(int n) {
	for (int i = 0; i < n; i++) {
		cout << "adjecent[" << i << "]: " << adjecent[i] << endl;
	}
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	
	init(n);
	
	for (int i = 0; i < m; i++) {
		int a, b, x;
		cin >> a >> b >> x;
		
		a = a-1;
		b = b-1;
		
		graph[a][b] = x;
		graph[b][a] = x;
	}
	print_graph(n);
	
	cout << endl;
	
	prim(1, n);
	
	print_adjecent(n);
	
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
