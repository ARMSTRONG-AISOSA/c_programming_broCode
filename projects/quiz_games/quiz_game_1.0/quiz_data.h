#ifndef QUIZ_DATA_H
#define QUIZ_DATA_H

char questions[][100] = {
    "1. What year did the C language debut?: ",
    "2. Who is credited with creating C?:",
    "3. What is the predecessor of C?: "};

// You have 12 rows: 4 options for each of the 3 questions.
char options[][100] = {"A. 1969", "B. 1972", "C. 1975", "D. 1999",
                       "A. Dennis Ritchie", "B. Nikola Tesla", "C. John Carmack", "D. Doc Brown",
                       "A. Objective C", "B. B", "C. C++", "D. C#"};

char answers[3] = {'B', 'A', 'B'};

#endif
