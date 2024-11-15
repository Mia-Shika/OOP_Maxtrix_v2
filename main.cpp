#include "Primary.hpp"

State Mode;
Uis Main_Menu;

ArrayDeclaration Grid;

Determinant_Mode Button;

Determinant Solution;

Result Box;

Texture2D Toggle_Button;

int main()
{
    Grid.designating_box();
    // Initiate Window.
    InitWindow(screenWidth, screenHeight, "Matrix Calculator");
    Toggle_Button = LoadTexture("Assets/Toggle_Button.png");
    SetTargetFPS(12);

    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        Main_Menu.uis();
        if(Mode.state == 0) Mode.selection();
        else if(Mode.state == 1)
        {
            Grid.draws();
            Grid.registering_number();
            Button.lever_determinant_mode();
            Solution.determinant();
            Box.designating_output_box_and_draw();
        }
        EndDrawing();
    }
}