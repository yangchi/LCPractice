class Solution {
    public:
        int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
            vector<int> effect(gas.size() * 2);
            for(int i = 0; i < gas.size(); i++) {
                effect[i] = gas[i] - cost[i];
                effect[i + gas.size()] = effect[i];
            }
            int starting = 0;
            for(int i = 0; i < effect.size();) {
                if (effect[i] < 0) {
                    i++;
                    continue;
                }
                starting = i;
                int traversal = 0;
                int running_sum = 0;
                int next_starting = starting + 1;
                for(int j = starting; j < effect.size(); j++) {
                    running_sum += effect[j];
                    if (effect[j] < 0 && next_starting == starting + 1) {
                        next_starting = j + 1;
                    }
                    if (running_sum < 0){
                        break;
                    } else {
                        traversal++;
                        if (traversal == gas.size())
                            return starting;
                    }
                }
                i = next_starting;
            }
            return -1;
        }
};
