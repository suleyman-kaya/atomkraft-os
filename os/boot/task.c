int TasksLength = 0;

#define task_type_void 0
#define task_type_string_buffer 1

struct Task {
    // 0 to 5 with zero being the highest priority
    int priority;
    int type;
    char param1[10000];
    int param2;

    // Function pointers
    int (*function_void)(void);
    int (*function_string_buffer)(char*, int*);
};

struct Task tasks[256];

void ProcessTasks() {
    int priority = 0;

    while (priority <= 5) {
        for (int i = 0; i < TasksLength; i++) {
            if (tasks[i].priority == priority) {
                if (tasks[i].type == task_type_void)
                    tasks[i].function_void();
                else if (tasks[i].type == task_type_string_buffer) 
                    tasks[i].function_string_buffer(tasks[i].param1, &tasks[i].param2);
            }
        }

        priority++;
    }
}

int ClearScreenTask() {
    ClearScreen(181.0f / 255.0f * 16.0f, 232.0f / 255.0f * 32.0f, 255.0f / 255.0f * 16.0f);
    
    return 0;
}

int DrawMouseTask() {
    DrawMouse(x, y, 16, 100.0 / 255.0 * 32, 100.0 / 255.0 * 16);

    return 0;
}

int HandleKeyboardTask(char* characterBuffer, int* characterBufferLength) {
    char character = ProcessScancode(Scancode);

    if (backspace_pressed == TRUE) {
        characterBuffer[*characterBufferLength - 1] = '\0';
        (*characterBufferLength)--;
        backspace_pressed = FALSE;
        Scancode = -1;
    }
    else if (character != '\0') {
        characterBuffer[*characterBufferLength] = character;
        characterBuffer[*characterBufferLength + 1] = '\0';
        (*characterBufferLength)++;
        Scancode = -1;
    }

    DrawString(getArialCharacter, font_arial_width, font_arial_height, characterBuffer, 100, 100, 0, 0, 0);

    return 0;
}