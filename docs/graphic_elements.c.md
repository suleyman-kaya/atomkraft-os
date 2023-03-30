Overview
--------

This C file provides several functions for drawing buttons and windows on the screen. The functions use several other helper functions that are not defined in this file, such as `DrawRect`, `DrawCircle`, and `DrawString`. The file also declares several external variables, including `mouse_possessed_task_id`, `left_clicked`, `mx`, `my`, `font_arial_width`, and `font_arial_height`.

Functions
---------

### `int DrawCircleButton(int x, int y, int radius, int r, int g, int b, int taskId)`

This function draws a circle button on the screen with the given coordinates, radius, and RGB color values. The function also takes a `taskId` parameter that is used to determine if the button has been clicked by the user. If the mouse cursor is currently over the button and the left mouse button has been clicked, the function returns `1`.

### `int DrawButton(int x, int y, int width, int height, int r, int g, int b, char* text, int r1, int g1, int b1, int taskId)`

This function draws a rectangular button on the screen with the given coordinates, width, height, and RGB color values. The function also takes a `text` parameter that is used to display text on the button. The text is displayed in a separate color that is specified by the `r1`, `g1`, and `b1` parameters. The function also takes a `taskId` parameter that is used to determine if the button has been clicked by the user. If the mouse cursor is currently over the button and the left mouse button has been clicked, the function returns `1`.

### `int DrawWindow(int* x, int* y, int* width, int* height, int r, int g, int b, int* mouse_held, int taskId)`

This function draws a window on the screen with the given coordinates, width, height, and RGB color values. The function also takes pointers to integer variables that specify the current position and size of the window. The function also takes a `mouse_held` parameter that is used to determine if the user is currently dragging the window with the mouse cursor. The function uses several other variables, including `left_clicked`, `mx`, and `my`, to determine if the window has been clicked or dragged. If the window has been dragged, the function updates the position of the window using the `x` and `y` pointers. The function also returns the value of calling `DrawCircleButton` with specific coordinates and a `taskId` parameter.

External Variables
------------------

### `mouse_possessed_task_id`

This external variable is used by the functions in this file to determine which task currently has control of the mouse cursor.

### `left_clicked`

This external variable is used by the functions in this file to determine if the left mouse button has been clicked.

### `mx` and `my`

These external variables are used by the functions in this file to determine the current position of the mouse cursor.

### `font_arial_width` and `font_arial_height`

These external variables are used by the `DrawString` function to determine the size of the Arial font used for displaying text on the screen.

Conclusion
----------

This C file provides a set of useful functions for drawing buttons and windows on the screen. The functions use several helper functions and external variables to determine the position and status of the mouse cursor. These functions can be used to create graphical user interfaces for various applications.