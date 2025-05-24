// quiz_structure.h
#ifndef QUIZ_STRUCTURE_H
#define QUIZ_STRUCTURE_H

#include "constants.h"

typedef struct
{
    char question[QUESTION_ARRAY_SIZE];
    char options[NUM_OF_OPTION_ARRAY_SIZE][INDIVIDUAL_OPTION_ARRAY_SIZE]; //1 * 4 matrix (each)
    char answer; // Ans are single letters
} QuizStruct;

#endif
