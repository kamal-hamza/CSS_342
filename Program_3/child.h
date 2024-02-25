#ifndef CHILD_H_
#define CHILD_H_

#include <iostream>
#include <string>

using namespace std;

class Child 
{
public:
    Child();
    Child(string first_name, string last_name, int age);
    virtual ~Child(); //destructor

    string get_last_name() const;
    string get_first_name() const;
        
    int get_age() const;

    void set_last_name(const string &last_name);
    void set_first_name(const string &first_name);
    void set_age(const int &age);

    //Operator Overloads
    bool operator==(const Child &rhs) const;
    bool operator!=(const Child &rhs) const;

    bool operator>(const Child &rhs) const;
    bool operator>=(const Child &rhs) const;

    bool operator<(const Child &rhs) const;
    bool operator<=(const Child &rhs) const;
        
    Child& operator=(const Child &rhs);

    //Stream Overloads
    friend ostream& operator<<(ostream &stream, const Child &child);
    friend istream& operator>>(istream &stream, const Child &child);

private:
    string first_name_;
    string last_name_;
    int age_;
};

Child::Child() : first_name_(""), last_name_(""), age_(0)
{
    //empty constructor
}

Child::Child(string the_first_name, string the_last_name, int the_age) : first_name_(the_first_name), last_name_(the_last_name), age_(the_age)
{

}

Child::~Child() 
{
    //empty destructor
}

string Child::get_last_name() const
{
    return last_name_;
}

string Child::get_first_name() const
{
    return first_name_;
}

int Child::get_age() const
{
    return age_;
}

void Child::set_last_name(const string &last_name)
{
    this->last_name_ = last_name;
}

void Child::set_first_name(const string &first_name)
{
    this->first_name_ = first_name;
}

void Child::set_age(const int &age)
{
    this->age_ = age;
}

bool Child::operator==(const Child &rhs) const
{
    if ((this->last_name_ == rhs.last_name_) && (this->first_name_ == rhs.first_name_) && (this->age_ == rhs.age_)) 
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Child::operator!=(const Child &rhs) const
{
    return !(*this == rhs);
}

bool Child::operator>(const Child &rhs) const
{
    if (last_name_ > rhs.last_name_)
    {
        return true;
    }

    if ((last_name_ == rhs.last_name_) && (first_name_ > rhs.first_name_))
    {
        return true;
    }

    if ((last_name_ == rhs.last_name_) && (first_name_ == rhs.first_name_) && (age_ > rhs.age_))
    {
        return true;
    }
    return false;
}

bool Child::operator>=(const Child &rhs) const
{
    return (*this > rhs || *this == rhs);
}

bool Child::operator<(const Child &rhs) const
{
    if (last_name_ < rhs.last_name_)
    {
        return true;
    }

    if ((last_name_ == rhs.last_name_) && (first_name_ < rhs.first_name_))
    {
        return true;
    }

    if ((last_name_ == rhs.last_name_) && (first_name_ == rhs.first_name_) && (age_ < rhs.age_))
    {
        return true;
    }

    return false;
}

bool Child::operator<=(const Child &rhs) const
{
    return (*this < rhs || *this == rhs);
}

Child& Child::operator=(const Child &rhs)
{
    last_name_ = rhs.last_name_;
    first_name_ = rhs.first_name_;
    age_ = rhs.age_;

    return *this;
}

ostream& operator<<(ostream &stream, const Child &child)
{
    stream << child.get_first_name() << child.get_last_name() << child.get_age();
    
    return stream;
}

istream& operator>>(istream &stream, Child &child)
{
    int age;
    string first_name, last_name;

    stream >> first_name >> last_name >> age;

    child.set_first_name(first_name);
    child.set_last_name(last_name);
    child.set_age(age);
    
    return stream;
}

#endif