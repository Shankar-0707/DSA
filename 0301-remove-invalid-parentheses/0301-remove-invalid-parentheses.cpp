class Solution {
public:
    bool valid(string& s2) {
        int open = 0;
        int close = 0;

        for (int i = 0; i < s2.length(); i++) {
            if (s2[i] >= 'a' && s2[i] <= 'z')
                continue;
            else {
                if (s2[i] == '(') {
                    open++;
                } else {
                    close++;

                    if (close > open)
                        return false;
                }
            }
        }

        return open == close;
    }

    vector<string> removeInvalidParentheses(string s) {
        queue<string> q;
        q.push(s);
        unordered_map<string, bool> visited;
        vector<string> ans;
        bool flag = false;
        visited[s] = true;

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                string str = q.front();
                q.pop();

                // check kro ki ye string valid h ya nhi
                if (valid(str)) {
                    ans.push_back(str);
                    flag = true;
                } else {
                    for (int i = 0; i < str.length(); i++) {
                        string newStr = str;
                        if (newStr[i] == '(' || newStr[i] == ')') {
                            string temp = newStr.erase(i, 1);
                            if (!visited[temp]) {
                                q.push(temp);
                                visited[temp] = true;
                            }
                        }
                    }
                }
            }

            if (flag) {
                break;
            }
        }

        return ans;
    }
};