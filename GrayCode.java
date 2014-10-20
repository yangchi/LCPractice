public class Solution {
	public List<Integer> grayCode(int n) {
		int current = 0;
		List<Integer> result = new ArrayList<Integer>();
		result.add(current);
		int flip = 0;
		while(flip < n) {
			for(int i = result.size() - 1; i >= 0; i--) {
				result.add(result.get(i) | (1 << flip));
			}
			flip++;
		}
		return result;
	}
}
