#include <vector>
#include <map>

#include <cstdlib>

using namespace std;

//Definition for undirected graph.
struct UndirectedGraphNode {
  int label;
  vector<UndirectedGraphNode *> neighbors;
  UndirectedGraphNode(int x) : label(x) {};
};

class Solution {

private:
    map<int, UndirectedGraphNode *> newNodes;

public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        //Deal with empty graph
        if (node == NULL) {
            return NULL;
        }

        //if the node is alread in new Nodes, just return
        if (newNodes.find(node->label) != newNodes.end()) {
            return newNodes[node->label];
        }
        
        //Clone the Node
        UndirectedGraphNode *new_node = new UndirectedGraphNode(node->label);
        newNodes[new_node->label] = new_node;

        //Clone all its neighbors
        for(vector<UndirectedGraphNode *>::iterator iterator = node->neighbors.begin(); 
            iterator != node->neighbors.end();
            iterator++) {
            new_node->neighbors.push_back(cloneGraph(*iterator));
        }

        //return
        return new_node;
    }
}; 

int main(int argc, char **argv) {
    return 0;
}
