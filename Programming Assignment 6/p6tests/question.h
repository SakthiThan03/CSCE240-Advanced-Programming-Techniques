// Copyright 2025 CSCE240 bhipp
// definition of the Question base class
#ifndef _QUESTION_H_
#define _QUESTION_H_

#include<string>
using std::string;

namespace csce240_program6 {

class Question {
 public:
  explicit Question(string q = "?") { question_ = q; }
  virtual ~Question() {}
  void SetQuestion(string q) { question_ = q; }
  string GetQuestion() const { return question_; }
  virtual void Print(bool include_correct_answer = false) const = 0;
 private:
  string question_;
};

}  // namespace csce240_program6

#endif  // _QUESTION_H_
