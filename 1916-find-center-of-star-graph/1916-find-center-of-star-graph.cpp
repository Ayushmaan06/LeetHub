
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        // Since it's a star graph, the center will be one of the nodes in the first edge.
        // We just need to check if the first node of the first edge is present in the second edge.
        // If it is, then it's the center; otherwise, the second node of the first edge is the center.
        
        int node1 = edges[0][0];
        int node2 = edges[0][1];
        
        // Check if node1 is in the second edge
        if (edges[1][0] == node1 || edges[1][1] == node1) {
            return node1; // node1 is the center
        } else {
            return node2; // node2 is the center
        }
    }
};