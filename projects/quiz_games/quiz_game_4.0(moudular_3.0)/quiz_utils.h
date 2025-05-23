// quiz_utils.h
#ifndef QUIZUTILS_H
#define QUIZUTILS_H

#include "quiz_structure.h" //to define flowed data

// function multiple declarations
int load_questions_from_file(QuizStruct quizzes[], const char *filename);
void run_quiz(QuizStruct quizzes[], int totalQuestions);
void shuffle_quizzes(QuizStruct quizzes[], int total);

#endif