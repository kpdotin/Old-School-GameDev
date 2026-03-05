#include <iostream>
#include <raylib.h>
#include <string>

void SnakeGame() {
    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 800;
    int ball_x = 300;
    int ball_y = 100;
    int ball_speed_x = 5;
    int ball_speed_y = 5;
    int ball_radius = 15;

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Template");
    SetTargetFPS(60);

    while (WindowShouldClose() == false) {
        ball_x += ball_speed_x;
        ball_y += ball_speed_y;

        if (ball_x + ball_radius >= SCREEN_WIDTH || ball_x - ball_radius <= 0) {
            ball_speed_x *= -1;
        }

        if (ball_y + ball_radius >= SCREEN_HEIGHT || ball_y - ball_radius <= 0) {
            ball_speed_y *= -1;
        }

        BeginDrawing();
        ClearBackground(BLACK);
        DrawCircle(ball_x, ball_y, ball_radius, RED);
        EndDrawing();
    }

}
void ExpandWindowLogic() {

    int xPos = 400;
    int yPos = 400;

    int screenWidth = 800;
    int screenHeight = 800;


    InitWindow(screenWidth, screenHeight, "trying the window extension");

    SetTargetFPS(60);

    BeginDrawing();

    //place points at the corners of the window
    DrawCircle(1000, 1000, 5, RED); // bottom right
    DrawCircle(0, 1000, 5, RED); // bottom left
    DrawCircle(0, 0, 5, RED); // top left
    DrawCircle(1000, 0, 5, RED); // top right

    EndDrawing();

    while (WindowShouldClose() == false) {

        int currentWindowPositionX = GetWindowPosition().x;
        int currentWindowPositionY = GetWindowPosition().y;

        if (IsKeyDown(KEY_RIGHT)) {
            xPos += 10;
        }
        else if (IsKeyDown(KEY_LEFT)) {
            xPos -= 10;
        }
        else if (IsKeyDown(KEY_UP)) {
            yPos -= 10;
        }
        else if (IsKeyDown(KEY_DOWN)) {
            yPos += 10;
        }

        // Expand right (right side moves out, left stays static)
        if (xPos + 50 >= screenWidth) {
            screenWidth = xPos + 50 + 10;
            SetWindowSize(screenWidth, screenHeight);
        }
        // Expand bottom (bottom side moves out, top stays static)
        if (yPos + 50 >= screenHeight) {
            screenHeight = yPos + 50 + 10;
            SetWindowSize(screenWidth, screenHeight);
        }
        // Expand left (left side moves out, right stays static)
        if (xPos < 0) {
            int expansion = -xPos + 10;
            screenWidth += expansion;
            xPos = 10;
            SetWindowSize(screenWidth, screenHeight);
            SetWindowPosition(currentWindowPositionX - expansion, currentWindowPositionY);
        }
        // Expand top (top side moves out, bottom stays static)
        if (yPos < 0) {
            int expansion = -yPos + 10;
            screenHeight += expansion;
            yPos = 10;
            SetWindowSize(screenWidth, screenHeight);
            SetWindowPosition(currentWindowPositionX, currentWindowPositionY - expansion);
        }

        BeginDrawing();

        ClearBackground(BLACK);
        DrawText("Use the arrow keys to move the square", 10, 10, 20, DARKGRAY);


        DrawRectangle(xPos, yPos, 50, 50, RED);
        std::string positionText = "xPos = " + std::to_string(xPos) + " , yPos = " + std::to_string(yPos);
        DrawText(positionText.c_str(), xPos - 60, yPos + 60, 20, DARKGRAY);

        // TraceLog(LOG_INFO, "xPos = %d , yPos = %d", xPos, yPos);



        EndDrawing();
    }

    CloseWindow();
}

int main() {
    SnakeGame();
    return 0;
}

