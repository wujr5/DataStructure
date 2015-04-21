#include<iostream>
#include<list>
#include<queue>
using namespace std; 
typedef int Vertex;
list<Vertex> topological_order;

template <int graph_size>
class Digraph {
public:
   Digraph();

//  methods to do a topological sort
   void depth_sort(list<Vertex> &topological_order);
   void breadth_sort(list<Vertex> &topological_order);

private:
   int count;
   list<Vertex> neighbors[graph_size];
   void recursive_depth_sort(Vertex v, bool visited[], list<Vertex> &topological_order);
};


template <int graph_size>
void Digraph<graph_size>::depth_sort(list<Vertex> &topological_order) {
   bool visited[graph_size];
   Vertex v;
   for (v = 0; v < count; v++) visited[v] = false;
   topological_order.clear();
   for (v = 0; v < count; v++)
      if (!visited[v])  //  Add v and its successors into topological order.
         recursive_depth_sort(v, visited, topological_order);
}


template <int graph_size>
void Digraph<graph_size>::recursive_depth_sort(Vertex v, bool *visited, list<Vertex> &topological_order) {
   visited[v] = true;
   int degree = neighbors[v].size();
   for (int i = 0; i < degree; i++) {
      Vertex w;                       //  A (neighboring) successor of v
      w = *(neighbors[v].begin()+i);
      if (!visited[w])                //  Order the successors of w.
         recursive_depth_sort(w, visited, topological_order);
   }
   topological_order.insert(topological_order.begin(), v);    //  Put v into topological_order.
}


template <int graph_size>
void Digraph<graph_size>::breadth_sort(list<Vertex> &topological_order) {
   topological_order.clear();
   Vertex v, w;
   int predecessor_count[graph_size];
   for (v = 0; v < count; v++) predecessor_count[v] = 0;
   for (v = 0; v < count; v++)
      for (int i = 0; i < neighbors[v].size(); i++) { //  Loop over all edges v -- w.
        w = *(neighbors[v].begin()+i);
         predecessor_count[w]++;
      }
   queue<int> ready_to_process;
   for (v = 0; v < count; v++)
      if (predecessor_count[v] == 0)
         ready_to_process.push(v);
   while (!ready_to_process.empty()) {
      v = ready_to_process.front();
      topological_order.insert(topological_order.end(), v);
      for (int j = 0; j < neighbors[v].size(); j++) { //  Traverse successors of v.
         neighbors[v].retrieve(j, w);
         predecessor_count[w]--;
         if (predecessor_count[w] == 0)
            ready_to_process.push(w);
      }
      ready_to_process.pop();
   }
}

int main() {
	
}
