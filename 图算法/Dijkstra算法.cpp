#include<iostream>
using namespace std;

const int MAXINT = 1000000;
const int MAXNUM = 200;
int dist[MAXNUM];
int prev[MAXNUM];

int A[MAXNUM][MAXNUM];

void Dijkstra(int v0, int n) {
    bool S[MAXNUM];//�ж��Ƿ��Ѿ�����õ㵽s������ 
    
    for (int i = 0; i < n; i++) {
        dist[i] = A[v0][i];
        S[i] = false; //��ʼʱȫ���㶼���ڴ˼�����
        
        if (dist[i] == MAXINT) prev[i] = -1;
        else prev[i] = v0;
    }
    
    dist[v0] = 0;
    S[v0] = true;
    
    for (int i = 1; i < n; i++) {
        int mindist = MAXINT;
        int u = v0;  //�ҳ���ǰδʹ�õĵ㵽dist[j]��Сֵ
        
        for (int j = 0; j < n; j++) {
            if ((!S[j]) && dist[j] < mindist) {
                u = j; //u���浱ǰ�ڽӵ��Ӿ�����С�ĵ�ĺ���
                mindist = dist[j];
            }
        }
        
        S[u] = true;
        
        for (int j = 0; j < n; j++) {
            if ((!S[j]) && A[u][j] < MAXINT) {//��ͨ���¼����u��·���ҵ���v0���̵�·��
                if (dist[u]+A[u][j] < dist[j]) {
                    dist[j] = dist[u]+A[u][j];//����dist
                    prev[j] = u; //��¼��ǰǰ������
                }
            }
        }
    }
}

void init(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) A[i][j] = 0;
            else A[i][j] = MAXINT;
        }
    }
}

int main() {
    int n, m, s, e;
    
    while (cin >> n >> m) {
        init(n);
    
        for (int i = 0; i < m; i++) {
            int a, b, x;
            cin >> a >> b >> x;
    
            if (A[a][b] == MAXINT || (A[a][b] < MAXINT && A[a][b] > x)) {
                A[a][b] = x;
                A[b][a] = x;
            }
        }

        cin >> s >> e;
        Dijkstra(s, n);
        
        if (dist[e] != MAXINT) cout << dist[e] << endl;
        else cout << -1 << endl;
    }
}
