def largestRectangleArea(height):
    stack = []
    maxarea = 0
    i = 0
    while i < len(height):
        if len(stack) == 0:
            stack.append(i)
            i += 1
            continue
        top = stack[-1]
        if height[i] >= height[top]:
            stack.append(i)
            i += 1
        else:
            stack.pop()
            width = i - stack[-1] - 1 if len(stack) > 0 else i
            area = width * height[top]
            if area > maxarea:
                maxarea = area
    print("after stack: " + str(maxarea))
    print("current stack len: " + str(len(stack)))
    while len(stack) > 0:
        top = stack.pop()
        width = len(height) - stack[-1] - 1 if len(stack) > 0 else len(height)
        area = width * height[top]
        if area > maxarea:
            maxarea = area
    return maxarea


if __name__ == '__main__':
    print(largestRectangleArea([5, 4, 1, 2]))