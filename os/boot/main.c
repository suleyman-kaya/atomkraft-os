#include "graphics.h"

int start() {
    VBEInfoBlock* VBE = (VBEInfoBlock*) VBEInfoAddress;

	mx = VBE->x_resolution / 2;
	my = VBE->y_resolution / 2;
	// String literals cannot be more than 61 characters.
	char str1[] = "Willkommen bei Atomkraft OS!";
	char *p = str1;

	char characterBuffer[1000] = "\0";
	char* characterBufferPointer = characterBuffer;
	int characterBufferLength = 0;

	base = (unsigned int) &isr1;
	base12 = (unsigned int) &isr12;

	InitialiseMouse();
	InitialiseIDT();

	// First of all, creating a blank screen by cleaning it.
	tasks[TasksLength].priority = 0;
	tasks[TasksLength].function = &ClearScreenTask;
	TasksLength++;

	// Draw producer's name
	tasks[TasksLength].priority = 0;
	tasks[TasksLength].function = &DrawProducersName;
	TasksLength++;

	// Create a taskbar
	tasks[TasksLength].priority = 0;
	tasks[TasksLength].function = &TaskbarTask;
	tasks[TasksLength].taskId = TasksLength;
	iparams[TasksLength * task_params_length + 0] = 0;
	iparams[TasksLength * task_params_length + 1] = 0;
	iparams[TasksLength * task_params_length + 2] = VBE->x_resolution;
	iparams[TasksLength * task_params_length + 3] = 40;
	iparams[TasksLength * task_params_length + 4] = 1;
	TasksLength++;
	
	// Implementing mouse handler
	tasks[TasksLength].priority = 5;
	tasks[TasksLength].function = &DrawMouseTask;
	TasksLength++;

	// TasksLength++;


	while(1) {
		ProcessTasks();

		Flush();
	}
}