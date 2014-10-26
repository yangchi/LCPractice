class Solution:
    # @param path, a string
    # @return a string
    def simplifyPath(self, path):
        stack = []
        splitted_path = path.strip().split("/")
        for dir in splitted_path:
            if dir == "." or dir == "":
                pass
            elif dir == "..":
                if len(stack) > 0:
                    stack.pop()
            else:
                stack.append(dir)
        return "/" + "/".join(stack)