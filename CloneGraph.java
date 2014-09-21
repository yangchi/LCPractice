/**
 * Definition for undirected graph.
 * class UndirectedGraphNode {
 *     int label;
 *	   List<UndirectedGraphNode> neighbors;
 *     UndirectedGraphNode(int x) { label = x; neighbors = new ArrayList<UndirectedGraphNode>(); }
 * };
 */
public class Solution {
	public UndirectedGraphNode cloneGraph(UndirectedGraphNode node) {
		if (node == null)
			return null;
		Queue<UndirectedGraphNode> nodeQueue = new LinkedList<UndirectedGraphNode>();
		nodeQueue.add(node);
		UndirectedGraphNode newGraph = new UndirectedGraphNode(node.label);
		HashMap<UndirectedGraphNode, UndirectedGraphNode> mapper = new HashMap<UndirectedGraphNode, UndirectedGraphNode>();
		mapper.put(node, newGraph);
		HashSet<UndirectedGraphNode> visited = new HashSet<UndirectedGraphNode>();
		while(!nodeQueue.isEmpty()) {
			UndirectedGraphNode curr = nodeQueue.remove();
			if(visited.contains(curr))
				continue;
			for(UndirectedGraphNode neighbor : curr.neighbors) {
				if (neighbor == curr) {
					mapper.get(curr).neighbors.add(mapper.get(curr));
				} else {
					UndirectedGraphNode newNeighbor;
					if (mapper.containsKey(neighbor))
						newNeighbor = mapper.get(neighbor);
					else
						newNeighbor = new UndirectedGraphNode(neighbor.label);
					mapper.get(curr).neighbors.add(newNeighbor);
					mapper.put(neighbor, newNeighbor);
					nodeQueue.add(neighbor);
				}
			}
			visited.add(curr);
		}
		return newGraph;
	}
}
