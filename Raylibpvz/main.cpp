#include <iostream>
#include <vector>
#include "raylib.h"
#include "Bullet.hpp"

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;
    Vector2 mousePos = GetMousePosition();

    InitWindow(screenWidth, screenHeight, "Plants versus Zombies");

    // NOTE: Textures MUST be loaded after Window initialization (OpenGL context is required)
    Texture2D peashooter = LoadTexture("res/img/peashooter.png");        // Texture loading
    Texture2D pea = LoadTexture("res/img/pea.png");
    
    Bullet bullet1 = Bullet(mousePos, Vector2{1, 0}, pea);
    std::vector<Bullet> bullets;
    
    //---------------------------------------------------------------------------------------
    SetTargetFPS(240);
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        mousePos = GetMousePosition();
        

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            bullets.push_back(Bullet(mousePos, pea));
        }
        for (auto & b : bullets)
        {
            b.move();
        }
        bullet1.move();
        
        BeginDrawing();
        
        ClearBackground(RAYWHITE);

        DrawTexture(peashooter, mousePos.x - peashooter.width / 2, mousePos.y - peashooter.height / 2, WHITE);
        for (Bullet bullet : bullets)
        {
            bullet.render();
        }
        bullet1.render();
        DrawText("this IS a texture following the mouse!", 360, 370, 10, GRAY);
        

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadTexture(peashooter);       // Texture unloading
    UnloadTexture(pea);

    CloseWindow();                // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}