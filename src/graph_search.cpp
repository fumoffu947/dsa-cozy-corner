#include "graph_search.h"
#include <vector>
#include <queue>
#include <unordered_set>
#include <functional>

// Defining a new typename to shorten functionnames and more
typedef GraphNode<std::pair<float, float>>* GNodePtr;

bool GraphNodeLesser(GNodePtr a, GNodePtr b) {
	return a->getHeuristicCost() < b->getHeuristicCost();
}


std::vector<GNodePtr> a_start_heuristic_search(GNodePtr start_node, std::pair<float, float> end_point, float (*heuristic)(std::pair<float, float>, std::pair<float, float>)) {
	// The nodes that has been explored is keept here, so that they should not be explored again
	std::unordered_set<GNodePtr> explored_nodes;
	// The nodes to be explored, are sorted by the total cost to the end node
	std::priority_queue<GNodePtr, std::vector<GNodePtr>, std::function<bool(GNodePtr, GNodePtr)>> frontier(GraphNodeLesser);

	// Initialise the nodes and queues
	start_node->setCostFromStart(0);
	start_node->setHeuristicCost(heuristic(start_node->getValue(), end_point));
	frontier.push(start_node);
}