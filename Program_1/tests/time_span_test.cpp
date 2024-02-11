#include <iostream>
#include "time_span.h"
using namespace std;

bool checkValues(TimeSpan time, int hours, int minutes, int seconds) {
    return (time.hours() == hours) && (time.minutes() == minutes) && (time.seconds() == seconds);
}

bool testZeros() {
    TimeSpan ts(0, 0, 0);
    return checkValues(ts, 0, 0, 0);
}

bool testThreeDataTypes() {
    TimeSpan ts(1.5f, 4.0, -10);
    return checkValues(ts, 1, 33, 50);
}

bool testTwoDataTypes() {
    TimeSpan ts(7.0, -3);
    return checkValues(ts, 0, 6, 57);
}

bool testOneDataType() {
    TimeSpan ts(-190);
    return checkValues(ts, 0, -3, -10);
}

bool testNegativeMinute() {
    TimeSpan ts(8, -23, 0);
    return checkValues(ts, 7, 37, 0);
}

bool testNegativeHour() {
    TimeSpan ts(-3, 73, 2);
    return checkValues(ts, -1, -46, -58);
}

bool testFloatValues() {
    TimeSpan ts(1.5f, 10.5f, 30.0f);
    return checkValues(ts, 1, 41, 0);
}

bool testDoubleValues() {
    TimeSpan ts(1.5, 10.5, 30.0);
    return checkValues(ts, 1, 41, 0);
}

bool testFloatTwoValues() {
    TimeSpan ts(1.5f, 30.0f);
    return checkValues(ts, 0, 2, 0);
}

bool testDoubleTwoValues() {
    TimeSpan ts(10.5, 30.0);
    return checkValues(ts, 0, 11, 0);
}

bool testFloatOneValue() {
    TimeSpan ts(30.0f);
    return checkValues(ts, 0, 0, 30);
}

bool testDoubleOneValue() {
    TimeSpan ts(20.00000);
    return checkValues(ts, 0, 0, 20);
}

bool testOneParameterSeconds() {
    TimeSpan ts(120);  // 2 minutes
    return checkValues(ts, 0, 2, 0);
}

bool testOneParameterMinutes() {
    TimeSpan ts(-90);  // -1 minute and 30 seconds
    return checkValues(ts, 0, -1, -30);
}

bool testTwoParametersMinutesSeconds() {
    TimeSpan ts(3, -90);  // 1 minute and 30 seconds
    return checkValues(ts, 0, 1, 30);
}

bool testAddition() {
    TimeSpan ts1(2, 30, 45);
    TimeSpan ts2(1, 15, 30);
    ts1 += ts2;
    return checkValues(ts1, 3, 46, 15);
}

bool testSubtraction() {
    TimeSpan ts1(5, 0, 0);
    TimeSpan ts2(1, 15, 30);
    ts1 -= ts2;
    return checkValues(ts1, 3, 44, 30);
}

bool testUnaryNegation() {
    TimeSpan ts(1, 2, 3);
    ts = -ts;
    return checkValues(ts, -1, -2, -3);
}

bool testEquality() {
    TimeSpan ts1(3, 30, 45);
    TimeSpan ts2(3, 30, 45);
    return ts1 == ts2;
}

bool testInequality() {
    TimeSpan ts1(2, 45, 15);
    TimeSpan ts2(1, 30, 45);
    return ts1 != ts2;
}

bool testComparisonLessThan() {
    TimeSpan ts1(2, 45, 15);
    TimeSpan ts2(3, 30, 45);
    return ts1 < ts2;
}

bool testComparisonGreaterThan() {
    TimeSpan ts1(3, 30, 45);
    TimeSpan ts2(2, 45, 15);
    return ts1 > ts2;
}

bool testComparisonLessThanOrEqual() {
    TimeSpan ts1(2, 45, 15);
    TimeSpan ts2(3, 30, 45);
    TimeSpan ts3(2, 45, 15);
    return (ts1 <= ts2) && (ts1 <= ts3);
}

bool testComparisonGreaterThanOrEqual() {
    TimeSpan ts1(3, 30, 45);
    TimeSpan ts2(2, 45, 15);
    TimeSpan ts3(3, 30, 45);
    return (ts1 >= ts2) && (ts1 >= ts3);
}

bool testInputOutput() {
    TimeSpan ts;
    cout << "Enter time (hours minutes seconds): ";
    cin >> ts;
    cout << "Output: " << ts << endl;
    return true;  // Manual inspection required for input/output
}

bool testSetTime() {
    TimeSpan ts;
    ts.set_time(3, 45, 20);
    return checkValues(ts, 3, 45, 20);
}

bool testSetTimeWithNegativeValues() {
    TimeSpan ts;
    ts.set_time(-1, -30, -10);
    return checkValues(ts, -1, -30, -10);
}

bool testSetTimeWithOverflow() {
    TimeSpan ts;
    ts.set_time(25, 70, 120);
    return checkValues(ts, 26, 12, 0);
}

bool testSetTimeWithZeroValues() {
    TimeSpan ts;
    ts.set_time(0, 0, 0);
    return checkValues(ts, 0, 0, 0);
}

bool testSetTimeWithMixedValues() {
    TimeSpan ts;
    ts.set_time(2, -30, 90);
    return checkValues(ts, 1, 31, 30);
}

int main()
{
    cout << "Testing TimeSpan Class" << endl;
    if (!testZeros()) cout << "Failed: testZeros" << endl;
    if(!testThreeDataTypes()) cout << "Failed: TestThreeDataTypes" << endl;
    if(!testTwoDataTypes()) cout << "Failed: TestTwoDataTypes" << endl;
    if(!testOneDataType()) cout << "Failed: TestOneDataType" << endl;
    if (!testNegativeMinute()) cout << "Failed: testNegativeMinute" << endl;
    if (!testNegativeHour()) cout << "Failed: testNegativeHour" << endl;
    if (!testFloatValues()) cout << "Failed: testFloatValues" << endl;
    if (!testDoubleValues()) cout << "Failed: testDoubleValues" << endl;
    if (!testOneParameterSeconds()) cout << "Failed: testOneParameterSeconds" << endl;
    if (!testOneParameterMinutes()) cout << "Failed: testOneParameterMinutes" << endl;
    if (!testTwoParametersMinutesSeconds()) cout << "Failed: testTwoParametersMinutesSeconds" << endl;
    if (!testAddition()) cout << "Failed: testAddition" << endl;
    if (!testSubtraction()) cout << "Failed: testSubtraction" << endl;
    if (!testUnaryNegation()) cout << "Failed: testUnaryNegation" << endl;
    if (!testEquality()) cout << "Failed: testEquality" << endl;
    if (!testInequality()) cout << "Failed: testInequality" << endl;
    if (!testComparisonLessThan()) cout << "Failed: testComparisonLessThan" << endl;
    if (!testComparisonGreaterThan()) cout << "Failed: testComparisonGreaterThan" << endl;
    if (!testComparisonLessThanOrEqual()) cout << "Failed: testComparisonLessThanOrEqual" << endl;
    if (!testComparisonGreaterThanOrEqual()) cout << "Failed: testComparisonGreaterThanOrEqual" << endl;
    if (!testSetTime()) cout << "Failed: testSetTime" << endl;
    if (!testSetTimeWithNegativeValues()) cout << "Failed: testSetTimeWithNegativeValues" << endl;
    if (!testSetTimeWithOverflow()) cout << "Failed: testSetTimeWithOverflow" << endl;
    if (!testSetTimeWithZeroValues()) cout << "Failed: testSetTimeWithZeroValues" << endl;
    if (!testSetTimeWithMixedValues()) cout << "Failed: testSetTimeWithMixedValues" << endl;
    if (!testInputOutput()) cout << "Failed: testInputOutput" << endl;
    cout << "Testing Complete" << endl;

    return 0;
}
