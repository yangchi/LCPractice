# Definition for a point
class Point:
    def __init__(self, a=0, b=0):
        self.x = a
        self.y = b

class Line:
    def __init__(self, slope, intercept):
        self.slope = slope
        self.intercept = intercept

class Solution:
    # @param points, a list of Points
    # @return an integer
    def maxPoints(self, points):
        if len(points) < 2:
            return len(points)
        points_to_lines = dict()
        points_to_points = dict()
        line_to_points = dict()
        max_points = 0
        for i in range(len(points)):
            point1 = points[i]
            for j in range(i, len(points)):
                point2 = points[j]
                if point1 is not point2:
                    if point1.x == point2.x and point1.y == point2.y: #same point
                        self.updateDict(point1, points_to_points, point2)
                        self.updateDict(point2, points_to_points, point1)
                    elif point1.x == point2.x or point1.y == point2.y: #not same point not same line
                        pass
                    else: #not same point but same line
                        slope = (point2.y - point1.y) / (point2.x - point1.x)
                        intercept = point2.y - slope * point2.x
                        line = Line(slope, intercept)
                        self.updateDict(point1, points_to_lines, line)
                        self.updateDict(point2, points_to_lines, line)
                        self.updateDict(line, line_to_points, point1)
                        self.updateDict(line, line_to_points, point2)
        '''
        for point in points_to_points:
            max_points = max(max_points, len(points_to_points[point]))
        for line in line_to_points:
            for point in line_to_points[line].copy():
                if point in points_to_points:
                    line_to_points[line].union(points_to_points[point])
            max_points = max(max_points, len(line_to_points[line]))
        '''
        for point in points:
            with_me = 0
            on_line = 0
            if point in points_to_points:
                with_me += len(points_to_points[point])
            if point in points_to_lines:
                for lines in points_to_lines[point]:
                    on_line = max(on_line, len(line_to_points[lines]))
            max_points = max(max_points, with_me + on_line if with_me + on_line > 0 else 1)
        return max_points

    def updateDict(self, point, dict, new_elem):
        if point not in dict:
            dict[point] = set()
        dict[point].add(new_elem)

'''
    def test(self):
        point_list = []
        point_list.append(Point(1, 2))
        point_list.append(Point(2, 3))
        print(self.maxPoints(point_list))


if __name__ == '__main__':
    sol = Solution()
    sol.test()
'''



