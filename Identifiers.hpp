#pragma once

#ifndef Identifiers.hpp //header guard to prevent re-initiate of the file multiple times.
#define Identifiers.hpp

#include <raylib.h>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <math.h>

#define screenWidth 800 // ScreenWidth.
#define screenHeight 600 // ScreenHeight.
#define number_size 25 // Number font size.
#define font_size 20 // Font size.
#define matrix_rows 3 // Self explainatory.
#define matrix_columns 3 // Self explainatory.


class Numbers 
{
    private:
    //Box
    Vector2 position;
    Vector2 size;
    Rectangle rect = {position.x, position.y, size.x, size.y};

    public:
    //Varible to store inputs
    std::string inputNumber = "";
    double numbersArray;
    bool numberEntered = false;
    float value = 0;

    //Interaction
    bool mouse_over_box = false;    
    int clicked_uppon = 0; // 0 is clear, 1 is hover, 2 is clicked
    void registering_number();
    
    void designating_box(); 
    void draws();
};

extern Numbers box[3][3];

class Determinant_Mode
{
    private:
    //Box
    Vector2 position;
    Vector2 size;
    Rectangle rect = {position.x, position.y, size.x, size.y};

    public:
    bool switch_between_mode = false;
    void lever_determinant_mode();
};

extern Determinant_Mode state_of_mode_determinant;

class Result
{
    private:
    Vector2 size;
    Vector2 position;
    Rectangle rect = {position.x, position.y, size.x, size.y};

    public:
    void designating_output_box(); // Defining output box and drawing it.
    void draw();
};

//Box standard { x, y }
struct input_box {float x, y;};

#endif