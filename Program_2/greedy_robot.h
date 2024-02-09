#ifndef GREEDY_ROBOT_H_
#define GREEDY_ROBOT_H_
#include <iostream>
#include <string>

using namespace std;

class GreedyRobot {
    public:
        // Constructors
        GreedyRobot();
        GreedyRobot(int max_distance, int robot_x, int robot_y, int treasure_x, int treasure_y);

        // Recursive function
        void findPaths(int max_distance, int robot_x, int robot_y, int treasure_x, int treasure_y);

        // Output Overload
        friend ostream & operator<<(ostream& os, GreedyRobot& robot);

    private:
        int max_distance_;
        int robot_x_;
        int robot_y_;
        int treausre_x_;
        int treausre_y_;
};

#endif