#if !defined(DIRECTED_GRAPH)
#define DIRECTED_GRAPH
#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include "edge.hpp"
#include "neighbor.hpp"

using namespace std;

template <class type_g, class weight_g>
class directed_graph
{
  map<type_g, vector<neighbor<type_g, weight_g>>> g;
  int edges_count;

public:
  directed_graph();
  directed_graph(map<type_g, vector<type_g>>);

  void add_edge(edge<type_g, weight_g>);
  void delete_edge(edge<type_g, weight_g>);
  bool has_edge(edge<type_g, weight_g>);

  void print();

  int edge_size();
  int vertex_size();

  void bfs(type_g);
  void dfs(type_g);
};

template <class type_g, class weight_g>
directed_graph<type_g, weight_g>::directed_graph()
{
  this->edges_count = 0;
}
template <class type_g, class weight_g>
directed_graph<type_g, weight_g>::directed_graph(map<type_g, vector<type_g>> graph)
{
  this->g = graph;
  this->edges_count = 0;
  for (pair<type_g, vector<type_g>> p : graph)
  {
    this->edges_count += p->second.size();
  }
}

template <class type_g, class weight_g>
void directed_graph<type_g, weight_g>::print()
{
  for (auto vertex_itr = g.begin(); vertex_itr != g.end(); vertex_itr++)
  {
    cout << vertex_itr->first << "[" << vertex_itr->second.size() << "]"
         << " -> ";
    for (auto edge_itr = vertex_itr->second.begin(); edge_itr != vertex_itr->second.end(); edge_itr++)
      cout << "'" << (*edge_itr).key << "' w(" << (*edge_itr).weight << ")"
           << ",";
    cout << "\n";
  }
}

template <class type_g, class weight_g>
void directed_graph<type_g, weight_g>::add_edge(edge<type_g, weight_g> e)
{
  g[e.start()].push_back(neighbor<type_g, weight_g>(e.end(), e.weight()));
  if (g.find(e.end()) == g.end())
    g[e.end()] = {};
  ++edges_count;
}

template <class type_g, class weight_g>
int directed_graph<type_g, weight_g>::edge_size()
{
  return this->edges_count;
}

template <class type_g, class weight_g>
int directed_graph<type_g, weight_g>::vertex_size()
{
  return this->g.size();
}

template <class type_g, class weight_g>
void directed_graph<type_g, weight_g>::bfs(type_g root)
{
  queue<type_g> q;
  set<type_g> visited;

  visited.insert(root);
  q.push(root);

  while (!q.empty())
  {
    type_g current = q.front();
    cout << current << " ";
    q.pop();
    for (auto itr = g[current].begin(); itr != g[current].end(); itr++)
    {
      type_g neighbor_key = (*itr).key;
      if (visited.find(neighbor_key) == visited.end())
      {
        visited.insert(neighbor_key);
        q.push(neighbor_key);
      }
    }
  }
}

#endif // DIRECTED_GRAPH
