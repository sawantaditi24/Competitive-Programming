/*On an N x N grid, each square grid[i][j] represents the elevation at that point (i,j).

Now rain starts to fall. At time t, the depth of the water everywhere is t. You can swim from a square to another 4-directionally adjacent square if and only if the elevation of both squares individually are at most t. You can swim infinite distance in zero time. Of course, you must stay within the boundaries of the grid during your swim.

You start at the top left square (0, 0). What is the least time until you can reach the bottom right square (N-1, N-1)?
*/

int swimInWater(vector<vector<int>>& grid) {
        typedef pair<int, pair<int, int>> vv;

	vector<vector<int>> cnt(grid.size(), vector<int>(grid[0].size(), -1));
	priority_queue<vv, vector<vv>, greater<vv>> q;
	int n = (int)grid.size();
	cnt[n - 1][n - 1] = grid[n - 1][n - 1];
	q.push({cnt[n - 1][n - 1], {n - 1, n - 1}});

	while (!q.empty()) {
		int val = q.top().first;
		int x = q.top().second.first;
		int y = q.top().second.second;

		q.pop();
		if (x == 0 && y == 0) return val;

		if (x > 0 && cnt[x - 1][y] < 0) q.push({cnt[x - 1][y] = max(grid[x - 1][y], cnt[x][y]), {x - 1, y}});
		if (x < n - 1 && cnt[x + 1][y] < 0) q.push({cnt[x + 1][y] = max(grid[x + 1][y], cnt[x][y]), {x + 1, y}});
		if (y > 0 && cnt[x][y - 1] < 0) q.push({cnt[x][y - 1] = max(grid[x][y - 1], cnt[x][y]), {x, y - 1}});
		if (y < n - 1 && cnt[x][y + 1] < 0) q.push({cnt[x][y + 1] = max(grid[x][y + 1], cnt[x][y]), {x, y + 1}});

	}

	return 0;
    }
