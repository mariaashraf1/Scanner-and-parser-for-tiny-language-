#include "MyForm.h"


using namespace GUIP;

[STAThread]
void main()
{

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm());
}
