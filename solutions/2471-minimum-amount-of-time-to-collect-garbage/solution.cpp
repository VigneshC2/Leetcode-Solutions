class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int ans = 0;

        auto collect = [&](char g) {
            int time = 0;
            int i = 0;
            int n = garbage.size();
            int free = 0;

            while (i < n) {
                int m = garbage[i].size();
                for (int j = 0; j < m; j++) {
                    char c = garbage[i][j];
                    if (c == g) {
                        time += 1;
                        time += free;
                        free = 0;
                    }
                }

                if (i == n - 1) break;

                free += travel[i];
                i += 1;
            }

            return time;
        };

        ans += collect('G');
        ans += collect('M');
        ans += collect('P');

        return ans;
    }
};