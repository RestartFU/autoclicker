#include "ClickerForm.h"
#include <iostream>
#include <thread>

using namespace System;
using namespace Windows::Forms;


void main() 
{
	CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Extern::start_clicker, NULL, 0, 0);

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Clicker::ClickerForm form;
	Application::Run(% form);
}