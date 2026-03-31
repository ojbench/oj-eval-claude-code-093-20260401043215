#include <iostream>
#include <vector>
#include <set>
#include <tuple>
using namespace std;

int main() {
    vector<vector<int>> grid(10, vector<int>(10));
    int start_r = -1, start_c = -1;

    // Read the grid
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 4) {
                start_r = i;
                start_c = j;
            }
        }
    }

    // Directions: 0=up, 1=right, 2=down, 3=left
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};

    int r = start_r, c = start_c;
    int dir = 0; // Start by going up
    int score = 0;

    // Track visited states: (row, col, direction)
    set<tuple<int, int, int>> visited;

    while (true) {
        // Determine next direction using right-hand rule
        // Right-hand rule: try right > straight > left > back
        int priorities[] = {(dir + 1) % 4, dir, (dir + 3) % 4, (dir + 2) % 4}; // right, straight, left, back

        bool found_direction = false;
        int next_dir = dir;
        int next_r = r, next_c = c;

        for (int i = 0; i < 4; i++) {
            int try_dir = priorities[i];
            int try_r = r + dr[try_dir];
            int try_c = c + dc[try_dir];

            if (try_r >= 0 && try_r < 10 && try_c >= 0 && try_c < 10 && grid[try_r][try_c] != 0) {
                next_dir = try_dir;
                next_r = try_r;
                next_c = try_c;
                found_direction = true;
                break;
            }
        }

        // If no direction found, we're stuck
        if (!found_direction) {
            cout << score << endl;
            return 0;
        }

        // Check for infinite loop before moving
        if (visited.count({next_r, next_c, next_dir})) {
            cout << "Silly Pacman" << endl;
            return 0;
        }

        // Move to next position
        r = next_r;
        c = next_c;
        dir = next_dir;

        visited.insert({r, c, dir});

        // Check what's on this cell
        if (grid[r][c] == 2) {
            score += 2;
            grid[r][c] = 1; // Eat the bean
        } else if (grid[r][c] == 3) {
            score -= 500;
            cout << score << endl;
            return 0;
        }
    }

    return 0;
}
