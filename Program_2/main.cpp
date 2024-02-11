#include <iostream>
#include "greedy_robot.h"
using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 6) {
        cout << "Usage: " << argv[0] << " <max_distance> <robot_x> <robot_y> <treasure_x> <treasure_y>" << endl;
        return 1;
    }

    int max_distance = atoi(argv[1]);
    int robot_x = atoi(argv[2]);
    int robot_y = atoi(argv[3]);
    int treasure_x = atoi(argv[4]);
    int treasure_y = atoi(argv[5]);

    Coord robot(robot_x, robot_y);
    Coord treasure(treasure_x, treasure_y);
    GreedyRobot rb(max_distance, robot, treasure);
    rb.findPath();

    return 0;
}
