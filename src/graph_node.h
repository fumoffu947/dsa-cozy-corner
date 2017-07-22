#include <vector>

template<typename V>
class GraphNode;

/*
 This is a struct to be used with the GraphNode to define links between the nodes in the graph.
*/
template<typename V>
struct NodeLink {
	GraphNode<V>* node;
	float link_weight = 1;
};

/*
 This class is a node for a graph structure with a value if it is needed.
 It also supports the feature to build a path, by holding a referens to a node (often the node closest
 back to the start node) to be used to build a shortest path back.
 To build this path two values needs to be used, the cost to get to this node and the cost to get to
 the endnode.
*/
template <typename V>
class GraphNode {
private:
	// The value to be contained in the node (often a point)
	V value;
	std::vector<NodeLink<V>> neighbors;
	// The cost from the startnode to this node
	double cost_from_start;
	// The cost from this node to the endnode.
	double heuristic_cost;
	// The reference used to build the path when done
	GraphNode<V>* node_reference;

public:
	void setValue(V new_value);
	V getValue();
	/*
	This function will sum the two costs and return it.
	*/
	double getTotalCost();
	double getCostFromStart();
	double getHeuristicCost();
	void setCostFromStart(double cost);
	void setHeuristicCost(double cost);
	GraphNode<V>* getNodeReference();
	void setNodeReference(GraphNode<V>* node);
	std::vector<NodeLink<V>> getNeighbors() const;

	/*
	 This function will add the gien nod and weight to the NodeLink struct and then
	 add it to the list of neighbors.
	*/
	void addNeighbor(GraphNode<V>* node, float link_weight);
	/*
	It is expected that the user of this structure will get the child befor
	removing it.
	If the index is above the given size of the childrenvector the nullptr will be
	returned.
	*/
	void removeNeighbor(int index);
};

/* --------------------------------------------- ##
 * ---------------------------------------------*/

 /*
 This is the implementation of a graphnode and will follow the expectaions of the
 headerfile,
 that is writen for the functions.
 */

template <typename V>
void GraphNode<V>::setValue(V new_value) {
	value = new_value;
}

template <typename V>
V GraphNode<V>::getValue() {
	return value;
}

template<typename V>
inline double GraphNode<V>::getTotalCost() {
	return cost_from_start + heuristic_cost;
}

template<typename V>
inline double GraphNode<V>::getCostFromStart() {
	return cost_from_start;
}

template<typename V>
inline double GraphNode<V>::getHeuristicCost() {
	return heuristic_cost;
}

template<typename V>
inline void GraphNode<V>::setCostFromStart(double cost) {
	cost_from_start = cost;
}

template<typename V>
inline void GraphNode<V>::setHeuristicCost(double cost) {
	heuristic_cost = cost;
}

template<typename V>
inline GraphNode<V>* GraphNode<V>::getNodeReference() {
	return node_reference;
}

template<typename V>
inline void GraphNode<V>::setNodeReference(GraphNode<V>* node) {
	node_reference = node;
}

template <typename V>
std::vector<NodeLink<V>> GraphNode<V>::getNeighbors() const {
	return neighbors;
}

template <typename V>
void GraphNode<V>::addNeighbor(GraphNode<V>* node, float link_weight) {
	// Create the link and set the weigth and node
	NodeLink<V> nl;
	nl.node = node;
	nl.link_weight = link_weight;

	neighbors.push_back(nl);
}

template <typename V>
void GraphNode<V>::removeNeighbor(int index) {
	if (index < neighbors.size() && index >= 0) {
		neighbors.erase(neighbors.begin() + index);
	}
}