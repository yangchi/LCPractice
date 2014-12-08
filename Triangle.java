public class Solution {
	public int minimumTotal(List<List<Integer>> triangle) {
		ArrayList<ArrayList<Integer>> lookuptable = new ArrayList<ArrayList<Integer>>();
		for(int i = 0; i < triangle.size(); i++) {
			lookuptable.add(new ArrayList<Integer>());
			for(int j = 0; j < triangle.get(i).size(); j++) {
				lookuptable.get(i).add(-1);
			}
		}
		return minimalTotalRecur(triangle, 0, 0, lookuptable);
	}

	public int minimalTotalRecur(List<List<Integer>> triangle, int row, int position, ArrayList<ArrayList<Integer>> table) {
		if(row >= triangle.size() || position >= triangle.get(row).size())
			return 0;
		if(table.get(row).get(position) != -1)
			return table.get(row).get(position);
		table.get(row).set(position, 
				triangle.get(row).get(position) + Math.min(minimalTotalRecur(triangle, row + 1, position, table),
					minimalTotalRecur(triangle, row + 1, position + 1, table)));
		return table.get(row).get(position);
	}
}
