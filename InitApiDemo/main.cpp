#include "pch.h"
#include <ApplicationApi.h>
#include <iostream>

int main()
{
    const wchar_t* pathToDriveApplication = L"D:\\Program Files\\Sygic\\Sygic Truck Navigation\\bin\\Truck.exe";
	// Init api
	auto result = CApplicationAPI::InitApi(pathToDriveApplication, nullptr, 0, 0, 0, 0);
	if (result == 1)
	{
		std::cout << "InitApi Succesfull\n";
	}
	else
	{
		std::cerr << "InitApi error: " << result << "\n";
		return result;
	}

	// Use API
	Sleep(5000); // Replace with API usage.

	// Close Driver app and close api
	SError e{};
	if (CApplicationAPI::IsApplicationRunning(&e))
	{
	   CApplicationAPI::EndApplication(&e);
	}

    CApplicationAPI::CloseApi();
}
