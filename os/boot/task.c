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


// Declare tasks over here
void ProcessTasks();
int NullTask();
int TaskbarTask();
int CloseTasks();
int ClearScreenTask();
int DrawProducersName();
int AppWithButtonsTask();
int DrawMouseTask();
int HandleKeyboardTask();
int TextEditorTask();
int BouncingBallTask();




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




int TaskbarTask(int taskId) {
    VBEInfoBlock* VBE = (VBEInfoBlock*) VBEInfoAddress;
    DrawRect(0, 0, VBE->x_resolution, 40, 0, 153, 76);

    int i = iparams[taskId * task_params_length + 4];

    char text[] = "GUI App\0";
    if (DrawButton(0, 0, 65, 40, 0, 0, 255, text, 255, 255, 255, taskId) == TRUE) {
        tasks[TasksLength].priority = 0;
        tasks[TasksLength].taskId = TasksLength;
        tasks[TasksLength].function = &AppWithButtonsTask;
        iparams[TasksLength * task_params_length + 0] = i * 40;
        iparams[TasksLength * task_params_length + 1] = i * 40;
        iparams[TasksLength * task_params_length + 2] = 300;
        iparams[TasksLength * task_params_length + 3] = 300;
        iparams[TasksLength * task_params_length + 4] = 0;
        iparams[TasksLength * task_params_length + 5] = 0;
        iparams[TasksLength * task_params_length + 6] = 0;
        TasksLength++;
        iparams[taskId * task_params_length + 4]++;
    }

    char text1[] = "Text Editor\0";
    if (DrawButton(75, 0, 100, 40, 255, 255, 0, text1, 0, 0, 0, taskId) == TRUE) {
        tasks[TasksLength].priority = 0;
        tasks[TasksLength].taskId = TasksLength;
        tasks[TasksLength].function = &TextEditorTask;
        iparams[TasksLength * task_params_length + 0] = i * 40;
        iparams[TasksLength * task_params_length + 1] = i * 40;
        iparams[TasksLength * task_params_length + 2] = 300;
        iparams[TasksLength * task_params_length + 3] = 300;
        iparams[TasksLength * task_params_length + 4] = 255;
        iparams[TasksLength * task_params_length + 5] = 255;
        iparams[TasksLength * task_params_length + 6] = 255;
        TasksLength++;
        iparams[taskId * task_params_length + 4]++;
    }

    char text3[] = "Ball\0";
    if (DrawButton(185, 0, 50, 40, 255, 0, 0, text3, 0, 0, 0, taskId) == TRUE) {
        tasks[TasksLength].priority = 0;
        tasks[TasksLength].taskId = TasksLength;
        tasks[TasksLength].function = &BouncingBallTask;
        iparams[TasksLength * task_params_length + 0] = i * 40;
        iparams[TasksLength * task_params_length + 1] = i * 40;
        iparams[TasksLength * task_params_length + 2] = 300;
        iparams[TasksLength * task_params_length + 3] = 300;
        iparams[TasksLength * task_params_length + 4] = 0;
        iparams[TasksLength * task_params_length + 5] = 20;
        iparams[TasksLength * task_params_length + 6] = 30;
        iparams[TasksLength * task_params_length + 7] = 5;
        iparams[TasksLength * task_params_length + 8] = 5;
        TasksLength++;
    }
}




void CloseTask(int taskId) {
    tasks[taskId].function = &NullTask;
    iparams[taskId * task_params_length + 0] = 0;
    iparams[taskId * task_params_length + 1] = 0;
    iparams[taskId * task_params_length + 2] = 0;
    iparams[taskId * task_params_length + 3] = 0;
}




int ClearScreenTask(int taskId) {
    //ClearScreen(0.0f / 255.0f * 16.0f, 0.0f / 255.0f * 32.0f, 255.0f / 255.0f * 16.0f);
    ClearScreen(102,255,178);
    
    return 0;
}




int DrawProducersName(int taskId){
    char name[] = "Atomkraft OS by Sueleyman Kaya\0";
    DrawString(getArialCharacter, font_arial_width, font_arial_height, name, 50, 100, 0, 0, 0);

}




int DrawMouseTask(int taskId) {
    DrawMouse(mx, my, 0, 0, 0);

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

    DrawString(getArialCharacter, font_arial_width, font_arial_height, characterBuffer, x + 20, y + 20, 0, 0, 0);
    //DrawString(getArialCharacter, font_arial_width, font_arial_height, characterBuffer, 100, 100, 16, 32, 16);

    return 0;
}




int AppWithButtonsTask(int taskId) {
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
            text, 255, 255, 255, taskId
    ) == TRUE) {
        *r = 0;
        *g = 0;
        *b = 0;
    }

    if (DrawButton(x + 100, y + 20, 50, 20, 0, 32, 0,
            text1, 255, 0, 0, taskId
    ) == TRUE) {
        *r = 16;
        *g = 31;
        *b = 16;
    }

    if (DrawButton(x + 20, y + 50, 80, 20, 153, 51, 255,
            text2, 255, 0, 255, taskId
    ) == TRUE) {
        *r = 153;
        *g = 51;
        *b = 255;
    }

    if (DrawButton(x + 120, y + 50, 150, 20, 102, 255, 102,
            text3, 0, 255, 0, taskId
    ) == TRUE) {
        *r = 102;
        *g = 255;
        *b = 102;
    }

    if (DrawButton(x + 20, y + 100, 100, 20, 255, 255, 51,
            text4, 0, 255, 255, taskId
    ) == TRUE) {
        *r = 255;
        *g = 255;
        *b = 51;
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




int BouncingBallTask(int taskId) {
    int closeClicked = DrawWindow(
        &iparams[taskId * task_params_length + 0],
        &iparams[taskId * task_params_length + 1],
        &iparams[taskId * task_params_length + 2],
        &iparams[taskId * task_params_length + 3],
        0,
        0,
        0,
        &iparams[taskId * task_params_length + 9],
        taskId);

    
    if(closeClicked == TRUE)
        CloseTask(taskId);

    int x = iparams[taskId * task_params_length + 0];
    int y = iparams[taskId * task_params_length + 1];
    int width = iparams[taskId * task_params_length + 2];
    int height = iparams[taskId * task_params_length + 3];

    iparams[taskId * task_params_length + 5] += iparams[taskId * task_params_length + 7];
    iparams[taskId * task_params_length + 6] += iparams[taskId * task_params_length + 8];

    if (iparams[taskId * task_params_length + 5] + 10 > iparams[taskId * task_params_length + 2] ||
        iparams[taskId * task_params_length + 5] - 10 < 0)
        iparams[taskId * task_params_length + 7] = -iparams[taskId * task_params_length + 7];

    if (iparams[taskId * task_params_length + 6] + 10 > iparams[taskId * task_params_length + 3] ||
        iparams[taskId * task_params_length + 6] - 10 < 20)
        iparams[taskId * task_params_length + 8] = -iparams[taskId * task_params_length + 8];

    DrawCircle(x + iparams[taskId * task_params_length + 5], y + iparams[taskId * task_params_length + 6], 10, 16, 32, 16);
}