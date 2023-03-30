Graphics Header File Documentation
----------------------------------

This header file contains functions and structures for graphics manipulation, particularly for drawing to a screen buffer.

### VBEInfoBlock Structure

The `VBEInfoBlockStruct` structure defines the structure of a VESA BIOS Extension (VBE) information block. This structure is used to hold information about the graphics mode being used.

### Constants

#### VBEInfoAddress

This constant specifies the starting address of the VBE information block in memory.

#### ScreenBufferAddress

This constant specifies the starting address of the screen buffer in memory.

### Variables

#### font\_arial\_width

This variable is an integer that specifies the width of the Arial font used in the DrawString and DrawCharacter functions.

#### font\_arial\_height

This variable is an integer that specifies the height of the Arial font used in the DrawString and DrawCharacter functions.

### Functions

#### int getArialCharacter(int index, int y)

This function returns a 32-bit integer representation of a character in the Arial font at a specified index and y-coordinate.

#### int rgb(int r, int g, int b)

This function returns a 32-bit integer representation of a color with the specified red, green, and blue values.

#### void Draw(int x, int y, int r, int g, int b)

This function draws a single pixel at the specified x and y coordinates with the specified RGB color values.

#### void ClearScreen(int r, int g, int b)

This function clears the entire screen buffer with the specified RGB color values.

#### void DrawRect(int x, int y, int width, int height, int r, int g, int b)

This function draws a rectangle with the specified width, height, and RGB color values at the specified x and y coordinates.

#### void DrawCharacter(int (\*f)(int, int), int font\_width, int font\_height, char character, int x, int y, int r, int g, int b)

This function draws a single character in the specified font and RGB color values at the specified x and y coordinates.

#### void DrawString(int (_f)(int, int), int font\_width, int font\_height, char_ string, int x, int y, int r, int g, int b)

This function draws a string in the specified font and RGB color values at the specified x and y coordinates.

#### void Flush()

This function copies the contents of the screen buffer to the video memory, displaying it on the screen.

### Conclusion

This header file provides useful functions and structures for graphics manipulation and drawing to a screen buffer. It can be used in applications that require basic graphics capabilities like mines.