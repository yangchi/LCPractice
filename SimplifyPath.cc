class Solution {
    public:
        string simplifyPath(string path) {
            vector<string> valid_paths;
            if (path[path.size() - 1] != '/') {
                path.append("/");
            }
            int index = path.find_first_not_of("/");
            while(index != string::npos && index < path.size()) {
                int slash = path.find_first_of("/", index);
                string subpath = path.substr(index, slash - index);
                if (subpath == ".") {
                    index = path.find_first_not_of("/", slash);
                } else if (subpath == "..") {
                    if (!valid_paths.empty())
                        valid_paths.pop_back();
                    index = path.find_first_not_of("/", slash);
                } else {
                    valid_paths.push_back(subpath);
                    index = path.find_first_not_of("/", slash);
                }
            }
            string result = "";
            for (auto & elem : valid_paths) {
                result += "/" + elem;
            }

            return result.empty() ? "/" : result;
        }
};
