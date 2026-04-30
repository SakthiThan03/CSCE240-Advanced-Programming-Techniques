//Copyright Sakthi Thanigai 04/23/25

#ifndef _TRUEFALSEQUESTION_H_
#define _TRUEFALSEQUESTION_H_

#include "question.h"
#include <iostream>
using std::cout;
using std::endl;

namespace csce240_program6 {

    class TrueFalseQuestion : public Question {
    public:
        explicit TrueFalseQuestion(std::string q = "?", bool ans = true);
        ~TrueFalseQuestion() override;

        void SetAnswer(bool ans);
        bool GetAnswer() const;
        void Print(bool include_correct_answer = false) const override;

    private:
        bool answer_;
    };

}


#endif
