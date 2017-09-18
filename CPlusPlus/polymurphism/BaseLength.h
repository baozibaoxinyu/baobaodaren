#ifndef BASELENGTH_H
#define BASELENGTH_H
class BaseLength{
protected:
    long mm = 0;
    static double mmPerMeter;
    static double mmPerInch;
    static double inchesPerYard;
    static double yardsPerPerch;
public:
    BaseLength(long theM):mm{theM}{}
    BaseLength(){}
    virtual double length() const {
        return mm;
    }
};
class Inches : public BaseLength{
protected:
    double inches{};
public:
    Inches(double inch):BaseLength(static_cast<long>(0.5+inch*mmPerInch)),
            inches{inch}{}
    Inches(){}
    double length() const override {
        return inches;
    }
};
class Meters : public BaseLength{
protected:
    double meters;
public:
    Meters(double theMeter):BaseLength(static_cast<long>(0.5+theMeter*mmPerMeter)),
            meters{theMeter}{}
    Meters(){}
    double length() const override {
        return meters;
    }
};
class Yards : public BaseLength {
protected:
    double yards{};
public:
    Yards(double theYard):BaseLength(static_cast<long>(0.5+theYard*mmPerInch*inchesPerYard)),
            yards{theYard}{}
    Yards(){}
    double length() const override {
        return yards;
    }
};
class Perches : public BaseLength{
protected:
    double perches{};
public:
    Perches(double thePerch):BaseLength(static_cast<long>(0.5+thePerch*yardsPerPerch*inchesPerYard
              *mmPerInch)),perches{thePerch}{}
    Perches(){}
    double length() const override {
        return perches;   
    }
};
double BaseLength::mmPerMeter {1000.0};
double BaseLength::mmPerInch {25.4};
double BaseLength::inchesPerYard {36.0};
double BaseLength::yardsPerPerch {5.5};
#endif
