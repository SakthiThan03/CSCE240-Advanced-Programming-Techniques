//Copyright Sakthi Thanigai 04/23/25

#include "shortanswerquestion.h"

#include <iostream>
#include <utility>  // for std::move

namespace csce240_program6 {

    ShortAnswerQuestion::ShortAnswerQuestion(std::string q, std::string ans)
        : Question(std::move(q)), answer_(std::move(ans)) {}

    ShortAnswerQuestion::~ShortAnswerQuestion() = default;

    void ShortAnswerQuestion::SetAnswer(std::string ans) {
        answer_ = std::move(ans);
    }

    std::string ShortAnswerQuestion::GetAnswer() const {
        return answer_;
    }

    void ShortAnswerQuestion::Print(bool include_correct_answer) const {
        std::cout << "Question: " << GetQuestion() << std::endl;
        if (include_correct_answer) {
            std::cout << "Correct Answer: " << answer_ << std::endl;
        }
    }

}
