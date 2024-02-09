#ifndef TIME_SPAN_H_
#define TIME_SPAN_H_
#include <iostream>

class TimeSpan {

    public:
        // Constructors
        TimeSpan();
        TimeSpan(double seconds);
        TimeSpan(double minutes, double seconds);
        TimeSpan(double hours, double minutes, double seconds);

        // Getters
        int hours() const;
        int minutes() const;
        int seconds() const;

        // Setters
        void set_time(int hours, int minutes, int seconds);

        // Overload Math Operators
        TimeSpan operator+(const TimeSpan& other) const;
        TimeSpan operator-(const TimeSpan& other) const;
        TimeSpan operator-() const;

        // Overload Logical Operators
        bool operator==(const TimeSpan& other) const;
        bool operator!=(const TimeSpan& other) const;
        bool operator<(const TimeSpan& other) const;
        bool operator>(const TimeSpan& other) const;
        bool operator<=(const TimeSpan& other) const;
        bool operator>=(const TimeSpan& other) const;

        // Overload Assignment Operators
        TimeSpan operator+=(const TimeSpan& other);
        TimeSpan operator-=(const TimeSpan& other);

        // Overload Input and Output Operators
        friend std::istream& operator>>(std::istream& input, TimeSpan& timeSpan);
        friend std::ostream& operator<<(std::ostream& output, const TimeSpan& timeSpan);

    private:
        // Private Data Members
        int hours_;
        int minutes_;
        int seconds_;

        // Normalizer function
        void normalize(int hours, int minutes, int seconds);

        // Convert double to int
        void double_to_int(double hours, double minutes, double seconds);

};

#endif