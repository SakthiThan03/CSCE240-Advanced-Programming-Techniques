// Copyright Sakthi Thanigai on 03/30/25

#ifndef WEIGHT_H
#define WEIGHT_H

#include <string>
#include <iostream>

class Weight {
public:
    // Constructor
    Weight(double val = 0, std::string u = "pounds");

    // Mutators
    void SetValue(double val);
    void SetUnits(const std::string& u);

    // Accessors
    double GetValue() const;
    std::string GetUnits() const;

    void ConvertUnits(const std::string& new_units);

    bool operator<=(const Weight& rhs) const;
    friend std::ostream& operator<<(std::ostream& out, const Weight& w);

private:
    double value_;
    std::string units_;

    bool IsValidUnit(const std::string& u) const;
    double ToPounds() const;
    void FromPounds(double pounds, const std::string& new_units);
};

#endif

