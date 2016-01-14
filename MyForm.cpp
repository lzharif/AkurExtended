#include "MyForm.h"

using namespace UjiKenalDigit; // Change based your project's name
[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	// buat form yang dirancang dan jalankan
	Application::Run(gcnew MyForm());
	return 0;
}
