public class Solution {
	public int minimumTotal(List<List<Integer>> triangle) {
		return minimalTotalRecur(triangle, 0, 0);
	}

	public int minimalTotalRecur(List<List<Integer>> triangle, int row, int position) {
		if(row >= triangle.size() || position >= triangle.get(row).size())
			return 0;
		return triangle.get(row).get(position) + Math.min(minimalTotalRecur(triangle, row + 1, position), minimalTotalRecur(triangle, row + 1, position + 1));
	}
}
