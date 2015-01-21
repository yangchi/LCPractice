/**
* Definition for an interval.
* struct Interval {
*     int start;
*     int end;
*     Interval() : start(0), end(0) {}
*     Interval(int s, int e) : start(s), end(e) {}
* };
*/
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        int index = 0;
        vector<Interval> result;
        while(index < intervals.size()) {
            Interval current_interval = intervals[index];
            if (current_interval.start > newInterval.end) {
                result.push_back(newInterval);
                newInterval.start = current_interval.start;
                newInterval.end = current_interval.end;
                index++;
            } else if (current_interval.end < newInterval.start) {
                result.push_back(current_interval);
                index++;
            } else {
                newInterval.start = min(newInterval.start, current_interval.start);
                newInterval.end = max(newInterval.end, current_interval.end);
                index++;
            }
        }
        result.push_back(newInterval);
        return result;
    }
};
