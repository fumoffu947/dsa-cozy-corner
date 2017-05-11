#ifndef GRAPH_SEARCH
#define GRAPH_SEARCH
#include "graph_node.h"

GraphNode<std::pair<float, float>>* heuristic_search(GraphNode<std::pair<float, float>>* start_node, std::pair<float, float> end_point, void (*heuristic)(std::pair<float, float>, std::pair<float, float>));

#endif // !GRAPH_SEARCH

