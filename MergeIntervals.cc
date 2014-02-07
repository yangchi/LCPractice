/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

bool CompareInterval (const Interval & interval1, const Interval & interval2)
{
	return interval1.start < interval2.start;
}

class Solution {
	public:
		vector<Interval> merge(vector<Interval> &intervals) {
			sort(intervals.begin(), intervals.end(), CompareInterval);
			vector<Interval> results;
			int i = 0;
			while(i < intervals.size())
			{
				Interval temp(intervals[i].start, intervals[i].end);
				while((i+1) < intervals.size() && (intervals[i+1].start < temp.end || intervals[i+1].start == temp.end))
				{
					temp.end = max(intervals[i+1].end, temp.end);
					i++;
				}
				results.push_back(temp);
				i++;
			}
			return results;
		}
};
