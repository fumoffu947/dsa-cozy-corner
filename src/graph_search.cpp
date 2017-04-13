#include "graph_node.h"
#include <unordered_set>

GraphNode<std::pair<float, float>>* a_star_search(GraphNode<std::pair<float, float>>* start_node, std::pair<float, float> end_point, void(*heuristic)(std::pair<float, float>, std::pair<float, float>)) {
	std::unordered_set<GraphNode<std::pair<float, float>>*> explored_nodes;
}