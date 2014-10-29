public class Solution {
	public int[] twoSum(int[] numbers, int target) {
		HashMap<Integer, Integer> number_map = new HashMap<Integer, Integer>();
		for(int i = 0; i < numbers.length; i++) {
			number_map.put(numbers[i], i);
		}
		for(int i = 0; i < numbers.length; i++) {
			if(number_map.get(target - numbers[i]) != null) {
				if(number_map.get(target - numbers[i]) > i) {
					int [] result = new int[2];
					result[0] = i + 1;
					result[1] = number_map.get(target - numbers[i]) + 1;
					return result;
				}
			}
		}
		return (new int[2]);
	}
}
