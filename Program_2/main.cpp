#include <iostream>
// #include "catalan.h"
#include "greedy_robot.h"
using namespace std;

int main() {
    // Catalan Number
    // cout << "Enter a number to calculate catalan: ";
    // int  num;
    // cin >> num;
    // long long ans = calcCatalan(num);
    // cout << "Catalan: " << ans << endl;

    // Greedy Robot
    int max_distance;
    cin >> max_distance;
    int robot_x, robot_y, treasure_x, treasure_y;
    cin >> robot_x >> robot_y >> treasure_x >> treasure_y;
    greedy_robot(max_distance, robot_x, robot_y, treasure_x, treasure_y);

    return 0;
}