#include <iostream>
#include <cmath>
using namespace std;

// Function to check if a point is inside the circle
bool is_inside_circle(double x, double y, double R) {
    return x * x + y * y <= R * R;
}

// Function to check if a square is fully contained in the circle
bool is_square_contained(int center_x, int center_y, double R) {
    // Check all four corners of the square
    double corners[4][2] = {
        {center_x - 0.5, center_y - 0.5},  // bottom left
        {center_x - 0.5, center_y + 0.5},  // top left
        {center_x + 0.5, center_y - 0.5},  // bottom right
        {center_x + 0.5, center_y + 0.5}   // top right
    };
    for (int i = 0; i < 4; ++i) {
        if (!is_inside_circle(corners[i][0], corners[i][1], R)) {
            return false;
        }
    }
    return true;
}

// Function to count the number of 1x1 squares fully contained within the circle
int count_squares_in_circle(double R) {
    // Determine bounds for checking
    int bound = static_cast<int>(ceil(R)) + 1;
    int count = 0;

    // Iterate over the grid of possible square centers
    for (int i = -bound; i <= bound; ++i) {
        for (int j = -bound; j <= bound; ++j) {
            if (is_square_contained(i, j, R)) {
                ++count;
            }
        }
    }
    return count;
}

int main() {
    // Test for some values
    double test_radii[] = {1, 2, 3, 4,6,7,8};
     for (double R : test_radii) {
        cout << "R = " << R << ": " << count_squares_in_circle(R) << " squares" << endl;
    }
    return 0;
}