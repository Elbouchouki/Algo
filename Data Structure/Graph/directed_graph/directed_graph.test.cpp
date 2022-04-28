#include <iostream>
#include "directed_graph.hpp"
using namespace std;

int main()
{
  directed_graph<char, int> graph;
  graph.add_edge({'A', 'B'});
  graph.add_edge({'A', 'C'});
  graph.add_edge({'B', 'C'});
  graph.add_edge({'C', 'A'});
  graph.add_edge({'C', 'D'});
  graph.add_edge({'D', 'D'});
  graph.print();
  cout << graph.vertex_size() << endl;
  cout << graph.edge_size() << endl;
  graph.bfs('C');

  return 0;
}