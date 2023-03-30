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
    int priority;
    int i = 0;

    priority = 5;
    while (priority >= 0) {
        i = mouse_possessed_task_id;
        if (left_clicked == TRUE &&
                mx > iparams[i * task_params_length + 0] &&
                mx < iparams[i * task_params_length + 0] + iparams[i * task_params_length + 2] &&
                my > iparams[i * task_params_length + 1] &&
                my < iparams[i * task_params_length + 1] + iparams[i * task_params_length + 3])
                break;

        for (i = 0; i < TasksLength; i++) {
            if (left_clicked == TRUE &&
                mx > iparams[i * task_params_length + 0] &&
                mx < iparams[i * task_params_length + 0] + iparams[i * task_params_length + 2] &&
                my > iparams[i * task_params_length + 1] &&
                my < iparams[i * task_params_length + 1] + iparams[i * task_params_length + 3]) {
                    tasks[mouse_possessed_task_id].priority = 0;
                    mouse_possessed_task_id = i;
                    tasks[i].priority = 2;
                    left_clicked = FALSE;
                }
        }

        priority--;
    }

    priority = 0;
    while (priority <= 5) {
        for (int i = 0; i < TasksLength; i++) {
            if (tasks[i].priority == priority) {
                tasks[i].function(tasks[i].taskId);
            }
        }

        priority++;
    }
}

int NullTask(int taskId) {
    return 0;
}

void CloseTask(int taskId) {
    tasks[taskId].function = &NullTask;
    iparams[taskId * task_params_length + 0] = 0;
    iparams[taskId * task_params_length + 1] = 0;
    iparams[taskId * task_params_length + 2] = 0;
    iparams[taskId * task_params_length + 3] = 0;
}

int ClearScreenTask(int taskId) {
    ClearScreen(181.0f / 255.0f * 16.0f, 232.0f / 255.0f * 32.0f, 255.0f / 255.0f * 16.0f);
    
    return 0;
}

int DrawMouseTask(int taskId) {
    DrawMouse(mx, my, 16, 100.0 / 255.0 * 32, 100.0 / 255.0 * 16);

    return 0;
}

int HandleKeyboardTask(int taskId, int x, int y) {
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

    DrawString(getArialCharacter, font_arial_width, font_arial_height, characterBuffer, x + 20, y + 20, 16, 32, 16);

    //DrawString(getArialCharacter, font_arial_width, font_arial_height, characterBuffer, 100, 100, 16, 32, 16);

    return 0;
}

int TestGraphicalElementsTask(int taskId) {
    int* r = &iparams[taskId * task_params_length + 4];
    int* g = &iparams[taskId * task_params_length + 5];
    int* b = &iparams[taskId * task_params_length + 6];

    int closeClicked = DrawWindow(
        &iparams[taskId * task_params_length + 0],
        &iparams[taskId * task_params_length + 1],
        &iparams[taskId * task_params_length + 2],
        &iparams[taskId * task_params_length + 3],
        *r,
        *g,
        *b,
        &iparams[taskId * task_params_length + 9],
        taskId);

    int x = iparams[taskId * task_params_length + 0];
    int y = iparams[taskId * task_params_length + 1];
    int width = iparams[taskId * task_params_length + 2];
    int height = iparams[taskId * task_params_length + 3];

    if(closeClicked == TRUE)
        CloseTask(taskId);

    char text[] = "Dark\0";
    char text1[] = "Light\0";
    char text2[] = "Suleyman\0";
    char text3[] = "In the memory of\0";
    char text4[] = "Terry Davis\0";

    if (DrawButton(x + 20, y + 20, 50, 20, 0, 32, 0,
            text, 16, 32, 16, taskId
    ) == TRUE) {
        *r = 0;
        *g = 0;
        *b = 0;
    }

    if (DrawButton(x + 100, y + 20, 50, 20, 0, 32, 0,
            text1, 16, 32, 16, taskId
    ) == TRUE) {
        *r = 16;
        *g = 31;
        *b = 16;
    }

    if (DrawButton(x + 20, y + 50, 80, 20, 0, 32, 0,
            text2, 16, 32, 16, taskId
    ) == TRUE) {
        *r = 16;
        *g = 31;
        *b = 16;
    }

    if (DrawButton(x + 120, y + 50, 150, 20, 0, 32, 0,
            text3, 16, 32, 16, taskId
    ) == TRUE) {
        *r = 16;
        *g = 31;
        *b = 16;
    }

    if (DrawButton(x + 20, y + 100, 100, 20, 0, 32, 0,
            text4, 16, 32, 16, taskId
    ) == TRUE) {
        *r = 16;
        *g = 31;
        *b = 16;
    }

    return 0;
}

int TextEditorTask(int taskId) {
    int* r = &iparams[taskId * task_params_length + 4];
    int* g = &iparams[taskId * task_params_length + 5];
    int* b = &iparams[taskId * task_params_length + 6];

    int closeClicked = DrawWindow(
        &iparams[taskId * task_params_length + 0],
        &iparams[taskId * task_params_length + 1],
        &iparams[taskId * task_params_length + 2],
        &iparams[taskId * task_params_length + 3],
        *r,
        *g,
        *b,
        &iparams[taskId * task_params_length + 9],
        taskId);

    int x = iparams[taskId * task_params_length + 0];
    int y = iparams[taskId * task_params_length + 1];
    int width = iparams[taskId * task_params_length + 2];
    int height = iparams[taskId * task_params_length + 3];

    if(closeClicked == TRUE)
        CloseTask(taskId);

    HandleKeyboardTask(taskId, x, y);

    return 0;
}