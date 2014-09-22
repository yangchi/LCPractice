# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

def representNumber(node):
    if node == None:
        return []
    leftNumbers = []
    rightNumbers = []
    if node.left != None:
        leftNumbers = representNumber(node.left)
    if node.right != None:
        rightNumbers = representNumber(node.right)
    if len(leftNumbers) == 0 and len(rightNumbers) == 0:
        return [node.val]
    result = []
    for leftnumber in leftNumbers:
        result.append(str(node.val) + str(leftnumber))
    for rightnumber in rightNumbers:
        result.append(str(node.val) + str(rightnumber))
    return result

class Solution:
    # @param root, a tree node
    # @return an integer
    def sumNumbers(self, root):
        if root == None:
            return 0
        result = 0
        numbers = representNumber(root)
        for number in numbers:
            result += int(number)
        return result


