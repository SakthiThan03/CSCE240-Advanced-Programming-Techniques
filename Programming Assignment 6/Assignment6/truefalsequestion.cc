//Copyright Sakthi Thanigai 04/23/25

#include "truefalsequestion.h"

#include <iostream>

namespace csce240_program6 {

    TrueFalseQuestion::TrueFalseQuestion(std::string q, bool ans)
        : Question(q), answer_(ans) {}

    TrueFalseQuestion::~TrueFalseQuestion() = default;

    void TrueFalseQuestion::SetAnswer(bool ans) {
        answer_ = ans;
    }

    bool TrueFalseQuestion::GetAnswer() const {
        return answer_;
    }

    void TrueFalseQuestion::Print(bool include_correct_answer) const {
        std::cout << "Question: " << GetQuestion() << std::endl;
        if (include_correct_answer) {
            std::cout << "Correct Answer: " << (answer_ ? "true" : "false")
                      << std::endl;
        }
    }

}
