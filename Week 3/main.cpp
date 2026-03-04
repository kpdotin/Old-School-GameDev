#include <raylib.h>
#include <string>

int main() {

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
    return 0;
}


