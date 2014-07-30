/**
 * Definition for a point.
 * class Point {
 *     int x;
 *     int y;
 *     Point() { x = 0; y = 0; }
 *     Point(int a, int b) { x = a; y = b; }
 * }
 */
package mypack;

import java.util.HashMap;
import java.util.HashSet;

public class Solution {
	
	class Line {
		int slope;
		int intercept;
		Line(int slope, int intercept) { this.slope = slope; this.intercept = intercept; }
		
		public boolean equals(Object o) {
			if (!( o instanceof Line)) {
				return false;
			}
			Line line = (Line)o;
			return this.slope == line.slope && this.intercept == line.intercept;
		}
		
		public int hashCode() {
			return this.slope + this.intercept; // ^ this.slope ^ this.intercept;
		}
	}
	
    public int maxPoints(Point[] points) {
    	HashMap<Point, Integer> same_point_counter = new HashMap<Point, Integer>();
    	HashMap<Line, HashSet<Point>> line_points_counter = new HashMap<Line, HashSet<Point>>();
    	int max = 0;
    	if (points.length < 2)
    		return points.length;
        for(int i = 0; i < points.length; i++) {
        	int points_co_position = 0;
        	int max_points_co_line = 0;
        	for(int j = i + 1; j < points.length; j++) {
        		if (points[i].x == points[j].x && points[i].y == points[j].y) { //same point
        			if (same_point_counter.containsKey(points[i])) {
        				int current_counter = same_point_counter.get(points[i]).intValue();
        				same_point_counter.put(points[i], new Integer(current_counter + 1));
        			} else {
        				same_point_counter.put(points[i], new Integer(1));
        			}
        			if (same_point_counter.containsKey(points[j])) {
        				int current_counter = same_point_counter.get(points[j]).intValue();
        				same_point_counter.put(points[j], new Integer(current_counter + 1));
        			} else {
        				same_point_counter.put(points[j], new Integer(1));
        			}
        			points_co_position = same_point_counter.get(points[i]).intValue();
        		} else { //same line
        			int slope = 0;
        			int intercept = 0;
        			if (points[i].x == points[j].x) {
        				slope = Integer.MAX_VALUE;
        				intercept = 0;
        			} else if (points[i].y == points[j].y) {
        				slope = 0;
        				intercept = Integer.MAX_VALUE;
        			} else {
        				slope = (points[i].y - points[j].y) / (points[i].x - points[j].x);
        				intercept = points[i].y - slope * points[i].x;
        			}
        			Line line = new Line(slope, intercept);
        			if (!line_points_counter.containsKey(line)) {
        				line_points_counter.put(line, new HashSet<Point>());
        			}
        			line_points_counter.get(line).add(points[i]);
    				line_points_counter.get(line).add(points[j]);
    				int points_cur_line = line_points_counter.get(line).size() - 1;
    				max_points_co_line = points_cur_line > max_points_co_line ? points_cur_line : max_points_co_line;
        		}
        		max = (max_points_co_line + points_co_position + 1) > max ? (max_points_co_line + points_co_position + 1) : max;
        	}
        }
        return max;
    }
    
    public static void main(String [] args) {
    	Point [] points = {new Point(1,1), new Point(1, 1), new Point(1, 1)};
    	Solution sol = new Solution();
    	int res = sol.maxPoints(points);
    	System.out.print(res);
    }
}