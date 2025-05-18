//pauseprogram.h
#ifndef PAUSEPROGRAM_H // Include guard to prevent multiple inclusions 
#define PAUSEPROGRAM_H

#include <stdio.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

// Function declaration
void pause_program(unsigned int seconds);

#endif