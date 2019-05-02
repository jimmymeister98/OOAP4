
//=============================================================================
#ifndef _NODE_HPP
#define _NODE_HPP

#include <string>

#include "edge.hpp"
#include "liste.hpp"


class Node {
	
	public:
		
		Node(void);
		Node(std::string key);
		Node(const Node& old);
		~Node();

	
	private:
	
		std::string 	node_key;
		Liste<Edge*>	edges;
		
};

#endif
