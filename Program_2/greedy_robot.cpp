#include <iostream>
#include <string>
#include <vector>
#include "greedy_robot.h"

using namespace std;


// Constructors
GreedyRobot::GreedyRobot() {
    max_distance_ = 0;
    treasure_.x_ = 0;
    treasure_.y_ = 0;
    total_paths = 0;
    path_.push_back(Coord(0, 0));
}

GreedyRobot::GreedyRobot(int max_distance, Coord robot, Coord treasure) {
    max_distance_ = max_distance;
    treasure_.x_ = treasure.x_;
    treasure_.y_ = treasure.y_;
    total_paths = 0;
    path_.push_back(Coord(robot.x_, robot.y_));
}

// Callable recursive function
void GreedyRobot::findPath() {
    findPaths(treasure_, path_);
    cout << "Number of Paths: " << total_paths << endl;
}

// Recursive Function
void GreedyRobot::findPaths(Coord treasure, vector<Coord> path) {
    // Base case
    if ((path.back().x_ == treasure.x_) && (path.back().y_ == treasure.y_)) {
        string pathstr = writePath(path);
        cout << pathstr << endl;
        total_paths = total_paths + 1;
    }

    // Recursive case
    if ((path.back().x_ < treasure.x_) && (path.back().y_ < treasure.y_)) {
        vector<Coord> path1(path);
        path1.push_back(Coord(path.back().x_ + 1, path.back().y_));
        string path1str = writePath(path1);
        if (isValid(max_distance_, path1str)) {
            findPaths(treasure, path1);
        }
        vector<Coord> path2(path);
        path2.push_back(Coord(path.back().x_, path.back().y_ + 1));
        string path2str = writePath(path2);
        if (isValid(max_distance_, path2str)) {
            findPaths(treasure, path2);
        }
    }
    if ((path.back().x_ < treasure.x_) && (path.back().y_ == treasure.y_)) {
        vector<Coord> path1(path);
        path1.push_back(Coord(path.back().x_ + 1, path.back().y_));
        string path1str = writePath(path1);
        if (isValid(max_distance_, path1str)) {
            findPaths(treasure, path1);
        }
    }
    if ((path.back().x_ < treasure.x_) && (path.back().y_ > treasure.y_)) {
        vector<Coord> path1(path);
        path1.push_back(Coord(path.back().x_ + 1, path.back().y_));
        string path1str = writePath(path1);
        if (isValid(max_distance_, path1str)) {
            findPaths(treasure, path1);
        }
        vector<Coord> path2(path);
        path2.push_back(Coord(path.back().x_, path.back().y_ - 1));
        string path2str = writePath(path2);
        if (isValid(max_distance_, path2str)) {
            findPaths(treasure, path2);
        }

    }

    if ((path.back().x_ == treasure.x_) && (path.back().y_ < treasure.y_)) {
        vector<Coord> path1(path);
        path1.push_back(Coord(path.back().x_, path.back().y_ + 1));
        string path1str = writePath(path1);
        if (isValid(max_distance_, path1str)) {
            findPaths(treasure, path1);
        }
    }
    if ((path.back().x_ == treasure.x_) && (path.back().y_ > treasure.y_)) {
        vector<Coord> path1(path);
        path1.push_back(Coord(path.back().x_, path.back().y_ - 1));
        string path1str = writePath(path1);
        if (isValid(max_distance_, path1str)) {
            findPaths(treasure, path1);
        }
    }

    if ((path.back().x_ > treasure.x_) && (path.back().y_ < treasure.y_)) {
        vector<Coord> path1(path);
        path1.push_back(Coord(path.back().x_ - 1, path.back().y_));
        string path1str = writePath(path1);
        if (isValid(max_distance_, path1str)) {
            findPaths(treasure, path1);
        }
        vector<Coord> path2(path);
        path2.push_back(Coord(path.back().x_, path.back().y_ + 1));
        string path2str = writePath(path2);
        if (isValid(max_distance_, path2str)) {
            findPaths(treasure, path2);
        }
    }
    if ((path.back().x_ > treasure.x_) && (path.back().y_ == treasure.y_)) {
        vector<Coord> path1(path);
        path1.push_back(Coord(path.back().x_ - 1, path.back().y_));
        string path1str = writePath(path1);
        if (isValid(max_distance_, path1str)) {
            findPaths(treasure, path1);
        }
    }
    if ((path.back().x_ > treasure.x_) && (path.back().y_ > treasure.y_)) {
        vector<Coord> path1(path);
        path1.push_back(Coord(path.back().x_ - 1, path.back().y_));
        string path1str = writePath(path1);
        if (isValid(max_distance_, path1str)) {
            findPaths(treasure, path1);
        }
        vector<Coord> path2(path);
        path2.push_back(Coord(path.back().x_, path.back().y_ - 1));
        string path2str = writePath(path2);
        if (isValid(max_distance_, path2str)) {
            findPaths(treasure, path2);
        }
    }
}

// Write path function that writes the path to the console
string GreedyRobot::writePath(vector<Coord> path) {
    if (path.empty()) {
        cout << "Empty Path" << endl;
        return "";
    }

    string pathstr;
    for (int i = 1; i < path.size(); i++) {
        int deltaX = path[i].x_ - path[i - 1].x_;
        int deltaY = path[i].y_ - path[i - 1].y_;

        if (deltaY > 0) {
            pathstr += 'N';
        }
        else if (deltaY < 0) {
            pathstr += 'S';
        }
        if (deltaX > 0) {
            pathstr += 'E';
        }
        else if (deltaX < 0) {
            pathstr += 'W';
        }
    }
    return pathstr;
}


// Check if move is valid
bool GreedyRobot::isValid(int max_distance, string path) {
    int constraints_north = 0;
    int constraints_south = 0;
    int constraints_east = 0;
    int constraints_west = 0;

    for (char directions : path) {
        switch (directions) {
            case 'N':
                constraints_north++;
                constraints_south = 0;
                constraints_east = 0;
                constraints_west = 0;
                break;
            case 'S':
                constraints_north = 0;
                constraints_south++;
                constraints_east = 0;
                constraints_west = 0;
                break;
            case 'E':
                constraints_north = 0;
                constraints_south = 0;
                constraints_east++;
                constraints_west = 0;
                break;
            case 'W':
                constraints_north = 0;
                constraints_south = 0;
                constraints_east = 0;
                constraints_west++;
                break;
            default:
                return false;
        }
        if (constraints_north > max_distance || constraints_south > max_distance || constraints_east > max_distance || constraints_west > max_distance) {
            return false;
        }
    }
    return true;
}