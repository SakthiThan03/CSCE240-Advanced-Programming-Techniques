// Copyright Sakthi Thanigai on 03/30/25

#include "weight.h"
#include <cmath>

Weight::Weight(double val, std::string u) {
  if (val >= 0)
    value_ = val;
  else
    value_ = 0;

  if (IsValidUnit(u))
    units_ = u;
  else
    units_ = "pounds";
}

void Weight::SetValue(double val) {
  if (val >= 0)
    value_ = val;
}

void Weight::SetUnits(const std::string& u) {
  if (IsValidUnit(u))
    units_ = u;
}

double Weight::GetValue() const {
  return value_;
}

std::string Weight::GetUnits() const {
  return units_;
}

bool Weight::IsValidUnit(const std::string& u) const {
  return u == "pounds" || u == "ounces" || u == "grams" || u == "kilograms";
}

double Weight::ToPounds() const {
  if (units_ == "pounds")
    return value_;
  else if (units_ == "ounces")
    return value_ / 16.0;
  else if (units_ == "grams")
    return value_ / 453.59237;
  else if (units_ == "kilograms")
    return value_ * 2.2046226218;
  return 0;
}

void Weight::FromPounds(double pounds, const std::string& new_units) {
  if (new_units == "pounds")
    value_ = pounds;
  else if (new_units == "ounces")
    value_ = pounds * 16.0;
  else if (new_units == "grams")
    value_ = pounds * 453.59237;
  else if (new_units == "kilograms")
    value_ = pounds / 2.2046226218;
  units_ = new_units;
}

void Weight::ConvertUnits(const std::string& new_units) {
  if (!IsValidUnit(new_units) || new_units == units_)
    return;

  double pounds = ToPounds();
  FromPounds(pounds, new_units);
}

bool Weight::operator<=(const Weight& rhs) const {
  double lhs_pounds = ToPounds();
  double rhs_pounds = rhs.ToPounds();
  return (lhs_pounds < rhs_pounds) || std::fabs(lhs_pounds - rhs_pounds) < 0.0001;
}

std::ostream& operator<<(std::ostream& out, const Weight& w) {
  out << w.value_ << " " << w.units_;
  return out;
}

