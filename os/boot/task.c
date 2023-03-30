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
    if (left_clicked == FALSE)
        iparams[taskId * task_params_length + 9] = FALSE;

    // iparams 0 - x
    // iparams 1 - y
    // iparams 2 - width
    // iparams 3 - height
    // iparams 9 - mouse click held down flag
    if (iparams[taskId * task_params_length + 9] == TRUE || 
        (left_clicked == TRUE && mx > iparams[taskId * task_params_length + 0] &&
         mx < iparams[taskId * task_params_length + 0] + iparams[taskId * task_params_length + 2] - 30 &&
         my > iparams[taskId * task_params_length + 1] &&
         my < iparams[taskId * task_params_length + 1] + 20)) {
             left_clicked = FALSE;

             iparams[taskId * task_params_length + 9] = TRUE;
             iparams[taskId * task_params_length + 0] = mx - (iparams[taskId * task_params_length + 2] / 2);
             iparams[taskId * task_params_length + 1] = my - 10;
    }

    if (DrawWindow(
        iparams[taskId * task_params_length + 0],
        iparams[taskId * task_params_length + 1],
        iparams[taskId * task_params_length + 2],
        iparams[taskId * task_params_length + 3],
        0,
        0,
        0
    ) == 1)
        CloseTask(taskId);

    return 0;
}