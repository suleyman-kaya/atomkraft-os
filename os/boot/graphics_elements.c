void DrawWindow(int x, int y, int width, int height, int r, int g, int b) {
    DrawRect(x, y, width, 20, 255, 250, 255);
    DrawRect(x, y + 20, width, height, r, g, b);
}