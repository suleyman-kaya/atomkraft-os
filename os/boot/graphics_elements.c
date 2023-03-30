int DrawCircleButton(int x, int y, int radius, int r, int g, int b) {
    if (((mx - x)*(mx - x) + (my - y)*(my - y)) <= radius*radius) {
        DrawCircle(x, y, radius, r, g, b);

        if (left_clicked == TRUE) {
            left_clicked = FALSE;
            return 1;
        }
    }
    else 
        DrawCircle(x, y, radius, r/4, g/4, b/4);

    return 0;
}

int DrawWindow(int x, int y, int width, int height, int r, int g, int b) {
    DrawRect(x, y, width, 20, 16, 32, 16);
    DrawRect(x, y + 20, width, height, r, g, b);

    return DrawCircleButton(x + width - 10, y + 10, 8, 16, 0, 0);
}