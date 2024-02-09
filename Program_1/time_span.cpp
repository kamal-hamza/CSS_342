#include <iostream>
#include "time_span.h"
#include <string>
#include <cmath>
using namespace std;

// Constructors
TimeSpan::TimeSpan() : hours_(0), minutes_(0), seconds_(0) {}

TimeSpan::TimeSpan(double hours, double minutes, double seconds) {
    double_to_int(hours, minutes, seconds);
}

TimeSpan::TimeSpan(double minutes, double seconds) {
    double_to_int(0, minutes, seconds);
}

TimeSpan::TimeSpan(double seconds) {
    double_to_int(0, 0, seconds);
}

// Getters
int TimeSpan::hours() const {
    return hours_;
}

int TimeSpan::minutes() const {
    return minutes_;
}

int TimeSpan::seconds() const {
    return seconds_;
}

// Set time function
void TimeSpan::set_time(int hours, int minutes, int seconds) {
    normalize(hours, minutes, seconds);
}

// Overloading Math Operators
TimeSpan TimeSpan::operator+(const TimeSpan& other) const {
    int total_seconds = ((3600 * hours_) + (60 * minutes_) + (seconds_)) + ((3600 * other.hours_) + (60 * other.minutes_) + (other.seconds_));
    return TimeSpan(total_seconds);
}

TimeSpan TimeSpan::operator-(const TimeSpan& other) const {
    int total_seconds = ((3600 * hours_) + (60 * minutes_) + (seconds_)) - ((3600 * other.hours_) + (60 * other.minutes_) + (other.seconds_));
    return TimeSpan(total_seconds);
}

TimeSpan TimeSpan::operator-() const {
    return TimeSpan(-hours_, -minutes_, -seconds_);
}

// Overloading Logical Operators
bool TimeSpan::operator==(const TimeSpan& other) const {
    return (hours_ == other.hours_) && (minutes_ == other.minutes_) && (seconds_ == other.seconds_);
}

bool TimeSpan::operator!=(const TimeSpan& other) const {
    return !(*this == other);
}

bool TimeSpan::operator<(const TimeSpan& other) const {
    return ((hours_ * 3600) + (minutes_ * 60) + (seconds_)) < ((other.hours_ * 3600) + (other.minutes_ * 60) + (other.seconds_));
}

bool TimeSpan::operator>(const TimeSpan& other) const {
    return ((hours_ * 3600) + (minutes_ * 60) + (seconds_)) > ((other.hours_ * 3600) + (other.minutes_ * 60) + (other.seconds_));
}

bool TimeSpan::operator<=(const TimeSpan& other) const {
    return (((hours_ * 3600) + (minutes_ * 60) + (seconds_)) < ((other.hours_ * 3600) + (other.minutes_ * 60) + (other.seconds_))) || ((hours_ == other.hours_) && (minutes_ == other.minutes_) && (seconds_ == other.seconds_));
}

bool TimeSpan::operator>=(const TimeSpan& other) const {
    return (((hours_ * 3600) + (minutes_ * 60) + (seconds_)) > ((other.hours_ * 3600) + (other.minutes_ * 60) + (other.seconds_))) || ((hours_ == other.hours_) && (minutes_ == other.minutes_) && (seconds_ == other.seconds_));
}

// Overloading Assignment Operators
TimeSpan TimeSpan::operator+=(const TimeSpan& other) {
    normalize(hours_ + other.hours_, minutes_ + other.minutes_, seconds_ + other.seconds_);
    return *this;
}

TimeSpan TimeSpan::operator-=(const TimeSpan& other) {
    normalize(hours_ - other.hours_, minutes_ - other.minutes_, seconds_ - other.seconds_);
    return *this;
}

// Overloading Input Operator
std::istream& operator>>(std::istream& input, TimeSpan& timeSpan) {
    int hours, minutes, seconds;
    input >> hours >> minutes >> seconds;
    timeSpan.normalize(hours, minutes, seconds);
    return input;
}

// Overloading Output Operator
std::ostream& operator<<(std::ostream& output, const TimeSpan& timeSpan) {
    output << "Hours: " << timeSpan.hours() << ", Minutes: " << timeSpan.minutes() << ", Seconds: " << timeSpan.seconds();
    return output;
}



// Normalize time
void TimeSpan::normalize(int hours, int minutes, int seconds) {
    int total_seconds = (hours * 60 * 60) + (minutes * 60) + seconds;
    seconds_ = total_seconds % 60;
    int total_minutes = total_seconds / 60;
    minutes_ = total_minutes % 60;
    hours_ = total_minutes / 60;
    if (seconds_ == 60) {
        seconds_ = 0;
        minutes_ += 1;
    }
    else if (seconds_ == -60) {
        seconds_ = 0;
        minutes_ -= 1;
    }
};

// Convert double to int
void TimeSpan::double_to_int(double hours, double minutes, double seconds) {
    int int_hours = (int)hours;
    int int_minutes = (int)(minutes + ((hours - int_hours) * 60));
    int int_seconds = (int)(seconds + ((minutes - (int)minutes) * 60));
    normalize(int_hours, int_minutes, int_seconds);
}
