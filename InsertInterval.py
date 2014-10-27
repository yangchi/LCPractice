# Definition for an interval.
# class Interval:
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution:
    # @param intervals, a list of Intervals
    # @param newInterval, a Interval
    # @return a list of Interval
    def insert(self, intervals, newInterval):
        result = []
        for interval in intervals:
            if interval.end < newInterval.start:
                result.append(interval)
            elif interval.start > newInterval.end:
                result.append(copy.copy(newInterval))
                newInterval.start = interval.start
                newInterval.end = interval.end
            elif interval.start <= newInterval.start or interval.end >= newInterval.end:
                newInterval.start = min(interval.start, newInterval.start)
                newInterval.end = max(interval.end, newInterval.end)
        result.append(newInterval)
        return result
