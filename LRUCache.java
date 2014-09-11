public class LRUCache {

	private HashMap<Integer, Integer> keyvalue;
	private HashMap<Integer, Integer> keyage;
	private int cap;

	public LRUCache(int capacity) {
		cap = capacity;
		keyvalue = new HashMap<Integer, Integer>();
		keyage = new HashMap<Integer, Integer>();
	}

	public int get(int key) {
		int return_value = -1;
		if(keyvalue.containsKey(key)) {
			return_value = keyvalue.get(key);
		} 
		for(int iter_key : keyage.keySet()) {
			if(key != iter_key) {
				keyage.put(iter_key, keyage.get(iter_key) + 1);
			}
		}
		return return_value;
	}

	public void set(int key, int value) {
		if (keyvalue.size() < cap) {
			keyvalue.put(key, value);
			if (keyage.containsKey(key))
				keyage.put(key, keyage.get(key));
			else
				keyage.put(key, 0);
		} else {
			if(keyvalue.containsKey(key)) {
				keyvalue.put(key, value);
			} else {
				int oldkey = oldest();
				keyage.remove(oldkey);
				keyvalue.remove(oldkey);
				keyvalue.put(key, value);
				keyage.put(key, 0);
			}
		}
		for(int key_iter : keyage.keySet()) {
			if (key_iter != key) {
				keyage.put(key_iter, keyage.get(key_iter) + 1);
			}
		}
	}

	public int oldest() {
		int age = 0;
		int old_key = 0;
		for(int key : keyage.keySet()) {
			if(keyage.get(key) > age) {
				age = keyage.get(key);
				old_key = key;
			}
		}
		return old_key;
	}
}
