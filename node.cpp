
#include "node.hpp"

Node::Node(void):edges(10){
	
}

Node::Node(std::string key):edges(10){
	node_key = key;
}

Node::Node(const Node& old):edges(10){
	node_key = old.node_key;
}	


Node::~Node(){
	// Nothing to remove
}
