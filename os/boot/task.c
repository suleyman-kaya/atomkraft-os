int TasksLength = 0;

#define task_type_void 0
#define task_type_string_buffer 1
#define task_params_length 10

struct Task {
    // 0 to 5 with zero being the highest priority
    int priority;
    int taskId;
    char ca1[100];
    int i1;

    // Function pointers
    int (*function)(int);
};

struct Task tasks[256];
int iparams[100] = {10};

void ProcessTasks() {
    int priority = 0;

    while (priority <= 5) {
        for (int i = 0; i < TasksLength; i++) {
            if (tasks[i].priority == priority) {
                tasks[i].function(tasks[i].taskId);
            }
        }

        priority++;
    }
}

void CloseTask(int taskId) {
    for (int i = taskId; i < TasksLength-1; i++) {
        tasks[i] = tasks[i+1];
    }

    TasksLength--;
}

int ClearScreenTask(int taskId) {
    ClearScreen(181.0f / 255.0f * 16.0f, 232.0f / 255.0f * 32.0f, 255.0f / 255.0f * 16.0f);
    
    return 0;
}

int DrawMouseTask(int taskId) {
    DrawMouse(mx, my, 16, 100.0 / 255.0 * 32, 100.0 / 255.0 * 16);

    return 0;
}

int HandleKeyboardTask(int taskId) {
    char* characterBuffer = tasks[taskId].ca1;
    int* characterBufferLength = &tasks[taskId].i1;

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

    DrawString(getArialCharacter, font_arial_width, font_arial_height, characterBuffer, 100, 100, 16, 32, 16);

    return 0;
}

int TestGraphicalElementsTask(int taskId) {
    int* r = &iparams[taskId * task_params_length + 4];
    int* g = &iparams[taskId * task_params_length + 5];
    int* b = &iparams[taskId * task_params_length + 6];

    if (DrawWindow(
        &iparams[taskId * task_params_length + 0],
        &iparams[taskId * task_params_length + 1],
        &iparams[taskId * task_params_length + 2],
        &iparams[taskId * task_params_length + 3],
        *r,
        *g,
        *b,
        &iparams[taskId * task_params_length + 9]
    ) == 1)
        CloseTask(taskId);

    char text[] = "Dark\0";
    char text1[] = "Light\0";
    char text2[] = "Suleyman\0";
    char text3[] = "Kaya\0";
    char text4[] = "Example\0";
    char text5[] = "Green\0";

    if (DrawButton(iparams[taskId * task_params_length + 0] + 20, iparams[taskId * task_params_length + 1] + 20, 50, 20, 0, 32, 0,text, 16, 32, 16) == TRUE) {
        *r = 0;
        *g = 0;
        *b = 0;
    }

    if (DrawButton(iparams[taskId * task_params_length + 0] + 100, iparams[taskId * task_params_length + 1] + 20, 50, 20, 0, 32, 0, text1, 16, 32, 16) == TRUE) {
        *r = 16;
        *g = 31;
        *b = 16;
    }

    if (DrawButton(iparams[taskId * task_params_length + 0] + 180, iparams[taskId * task_params_length + 1] + 20, 80, 20, 0, 32, 0, text2, 16, 32, 16) == TRUE) {
        *r = 72;
        *g = 31;
        *b = 78;
    }

    if (DrawButton(iparams[taskId * task_params_length + 0] + 20, iparams[taskId * task_params_length + 1] + 50, 50, 20, 0, 32, 0, text3, 16, 32, 16) == TRUE) {
        *r = 72;
        *g = 31;
        *b = 78;
    }

    return 0;
}