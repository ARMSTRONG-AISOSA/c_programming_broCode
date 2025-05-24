#include <stdio.h>

void test_1()
{
    // ANSI CODE txt --> 1.0
    // Color
    printf("\033[32mColor\33[0m\n");
    // Underline
    printf("\033[4;36mUnderline\33[0m\n");
    // Bold
    printf("\033[1;35mBOLD\33[0m\n");
}

void test_2()
{
    // bg-color
    printf("\033[1;33;41mWarning!!!\33[0m\n");

    // Example of 256 colors:
    printf("\033[38;5;46mThis is a 256-color foreground.\033[0m\n");
    printf("\033[48;5;104mThis has a 256-color background.\033[0m\n");

    // Example of True Color:
    printf("\033[38;2;255;105;180mThis is a true color foreground (pink).\033[0m\n");
    printf("\033[48;2;0;128;0mThis has a true color background (green).\033[0m\n");
}

void test_3()
{
    // Faint
    printf("\033[2mFaint Text\033[0m\n"); // Not widely supported

    // Italic
    printf("\033[3mItalic Text\033[0m\n"); // Not widely supported

    // Crossed-out (Strikethrough)
    printf("\033[9mCrossed-out (Strikethrough) Text\033[0m\n"); // Not widely supported

    // Inverse Video
    printf("\033[7mInverse Video Text\033[0m\n");

}

int main()
{
    // test_1();
    test_2();
    // test_3();
    return 0;
};