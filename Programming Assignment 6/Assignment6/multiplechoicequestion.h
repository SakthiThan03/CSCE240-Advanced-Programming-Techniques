//Copyright Sakthi Thanigai 04/23/25

#ifndef _MULTIPLECHOICEQUESTION_H_
#define _MULTIPLECHOICEQUESTION_H_

#include "question.h"
#include <iostream>
using std::cout;
using std::endl;

namespace csce240_program6 {

    class MultipleChoiceQuestion : public Question {
    public:
        explicit MultipleChoiceQuestion(string q = "?", int n = 0,
                                        const string* choices = nullptr,
                                        const bool* correct = nullptr);

        MultipleChoiceQuestion(const MultipleChoiceQuestion& other);
        MultipleChoiceQuestion& operator=(const MultipleChoiceQuestion& other);
        virtual ~MultipleChoiceQuestion();

        int GetNumChoices() const { return num_choices_; }
        void SetAnswerChoices(int, const string*, const bool*);

        virtual void Print(bool include_correct_answer = false) const;

    private:
        int num_choices_;
        string* answer_choices_;
        bool* correct_answers_;
    };

}

#endif

