
#ifndef _EDGE_HPP
#define _EDGE_HPP

class Node;


class Edge {
	
	public:
	
		Edge(void);
		Edge(Node *start, Node *end, double new_weight);
		Edge(const Edge& old);
		~Edge();

	
	private:
		
		Node 	*startnode;
		Node 	*endnode;
		double 	weight;

};


#endif
