#ifndef GREEDY_ROBOT_H_
#define GREEDY_ROBOT_H_
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Coord {
    int x_;
    int y_;
    Coord () {
        x_ = 0;
        y_ = 0;
    }
    Coord (int x, int y) {
        x_ = x;
        y_ = y;
    }
};

class GreedyRobot {

    public:
        // Constructors
        GreedyRobot();
        GreedyRobot(int max_distance, Coord robot, Coord treasure);

        //Callable recursive function
        void findPath();

        // Output Overload
        friend ostream & operator<<(ostream& os, GreedyRobot& robot);

    private:
        int max_distance_;
        int total_paths;
        Coord treasure_;
        vector<Coord> path_;
        // Function to write the path to the console
        string writePath(vector<Coord> path);
        // Checks to see if path is valid
        bool isValid(int max_distance, string path);
        // Recursive function
        void findPaths(Coord treasure, vector<Coord> path);
};

#endif