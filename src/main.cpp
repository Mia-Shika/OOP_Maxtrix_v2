#include "include/Primary.hpp"

int main()
{
    // Initiate Window.
    InitWindow(screenWidth, screenHeight, "Matrix Calculator");
    SetTargetFPS(12);

    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        EndDrawing();
    }
}