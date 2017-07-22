#ifndef GRAPH_SEARCH
#define GRAPH_SEARCH
#include "graph_node.h"

struct GraphNodeHolder {
	float heuristic_value = 0;
	float path_here_value = 0;
	GraphNode<std::pair<float, float>>* node;
};

std::vector<GraphNode<std::pair<float, float>>*> a_start_heuristic_search(GraphNode<std::pair<float, float>>* start_node, std::pair<float, float> end_point, float (*heuristic)(std::pair<float, float>, std::pair<float, float>));

#endif // !GRAPH_SEARCH

