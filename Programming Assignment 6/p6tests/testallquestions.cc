// Copyright 2025 CSCE240 bhipp
// Test virtual Print function in Question family of classes - Program 6
#include<string>
using std::string;
#include<fstream>
using std::ifstream;
#include<iostream>
using std::cout;
using std::endl;
using std::getline;
#include"question.h"
using csce240_program6::Question;
#include"truefalsequestion.h"
using csce240_program6::TrueFalseQuestion;
#include"shortanswerquestion.h"
using csce240_program6::ShortAnswerQuestion;
#include"multiplechoicequestion.h"
using csce240_program6::MultipleChoiceQuestion;

int main() {
  // samplequestions.txt contains true/false, short answer, and multiple choice
  // questions
  ifstream infile("samplequestions.txt");
  int num_questions, i = 0;
  string next_input, the_question;

  // the first line of the input file holds the number of questions in the file
  getline(infile, next_input);
  num_questions = stoi(next_input);
  Question ** qptr = new Question*[num_questions];

  string * mc_answers;
  bool * correct;

  while ( infile.good() && i < num_questions ) {
    // the line above each question holds the question type which is
    // tf for true/false, sa for short answer, or mc for multiple choice
    getline(infile, next_input);
    if ( next_input == "tf" ) {
      getline(infile, the_question);
      getline(infile, next_input);
      qptr[i] = new TrueFalseQuestion(the_question, next_input == "true");
    } else if ( next_input == "sa" ) {
      getline(infile, the_question);
      getline(infile, next_input);
      qptr[i] = new ShortAnswerQuestion(the_question, next_input);
    } else if ( next_input == "mc" ) {
      int num_answers;
      // for a multiple choice question, the first line holds the number of
      // answer choices
      getline(infile, next_input);
      num_answers = stoi(next_input);
      mc_answers = new string[num_answers];
      correct = new bool[num_answers];
      getline(infile, the_question);

      // each answer choice is on a separate line, followed by a line
      // denoting whether or not that answer choice is a correct (true) answer
      for ( int j = 0; j < num_answers && infile.good(); ++j ) {
        getline(infile, mc_answers[j]);
        getline(infile, next_input);
        correct[j] = next_input == "true";
      }
      qptr[i] = new MultipleChoiceQuestion(the_question, num_answers,
                                           mc_answers, correct);
      delete [] mc_answers;
      delete [] correct;
    } else {  // exit the program if an invalid question type is encountered
      return 1;
    }
    ++i;
  }

  // print each question and answer with a blank line between questions
  for ( i = 0; i < num_questions; ++i ) {
    qptr[i]->Print(true);
    cout << endl;
  }

  return 0;
}
