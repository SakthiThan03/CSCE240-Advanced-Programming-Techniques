//Copyright Sakthi Thanigai 04/23/25

#ifndef CSCE240_PROGRAM6_SHORTANSWERQUESTION_H_
#define CSCE240_PROGRAM6_SHORTANSWERQUESTION_H_

#include <string>
#include "question.h"

namespace csce240_program6 {

    class ShortAnswerQuestion : public Question {
    public:
        // Constructor with default arguments
        explicit ShortAnswerQuestion(std::string q = "?", std::string ans = "");

        // Virtual destructor
        ~ShortAnswerQuestion() override;

        // Accessor and mutator for the answer
        void SetAnswer(std::string ans);
        std::string GetAnswer() const;

        // Polymorphic print function
        void Print(bool include_correct_answer = false) const override;

    private:
        std::string answer_;
    };

}

#endif

