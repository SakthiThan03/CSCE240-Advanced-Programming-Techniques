//Copyright Sakthi Thanigai 04/23/25

#include "multiplechoicequestion.h"

#include <iostream>

namespace csce240_program6 {

MultipleChoiceQuestion::MultipleChoiceQuestion(std::string q, int n,
                                             const std::string* choices,
                                               const bool* correct)
    : Question(q), num_choices_(n), answer_choices_(nullptr), correct_answers_(nullptr) {
  if (num_choices_ > 0) {
    answer_choices_ = new std::string[num_choices_];
    correct_answers_ = new bool[num_choices_];
    for (int i = 0; i < num_choices_; ++i) {
      answer_choices_[i] = choices ? choices[i] : "";
      correct_answers_[i] = correct ? correct[i] : true;
    }
  }
}

MultipleChoiceQuestion::MultipleChoiceQuestion(const MultipleChoiceQuestion& other)
    : Question(other), num_choices_(other.num_choices_) {
  answer_choices_ = new std::string[num_choices_];
  correct_answers_ = new bool[num_choices_];
  for (int i = 0; i < num_choices_; ++i) {
    answer_choices_[i] = other.answer_choices_[i];
    correct_answers_[i] = other.correct_answers_[i];
  }
}

MultipleChoiceQuestion& MultipleChoiceQuestion::operator=(
    const MultipleChoiceQuestion& other) {
  if (this != &other) {
    SetQuestion(other.GetQuestion());
    SetAnswerChoices(other.num_choices_, other.answer_choices_, other.correct_answers_);
  }
  return *this;
}

MultipleChoiceQuestion::~MultipleChoiceQuestion() {
  delete[] answer_choices_;
  delete[] correct_answers_;
}

void MultipleChoiceQuestion::SetAnswerChoices(int n,
                                              const std::string* choices,
                                              const bool* correct) {
  delete[] answer_choices_;
  delete[] correct_answers_;

  num_choices_ = n;
  answer_choices_ = new std::string[n];
  correct_answers_ = new bool[n];

  for (int i = 0; i < n; ++i) {
    answer_choices_[i] = choices[i];
    correct_answers_[i] = correct[i];
  }
}

void MultipleChoiceQuestion::Print(bool include_correct_answer) const {
  std::cout << "Question: " << GetQuestion() << std::endl;
  std::cout << "Answer Choices:" << std::endl;
  for (int i = 0; i < num_choices_; ++i) {
    std::cout << (i + 1) << ". " << answer_choices_[i];
    if (include_correct_answer) {
      std::cout << (correct_answers_[i] ? " - correct" : " - incorrect");
    }
    std::cout << std::endl;
  }
}

}
