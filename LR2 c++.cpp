#include <iostream>
#include <windows.h>  
#include "Lib.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//пример работы с динамическим массивом "Build"
	Build* BuildArr = new Build[2];
	for (int i = 0; i < 2; i++)
	{
		BuildArr[i].input_build();
		BuildArr[i].out_build();
	}
	BuildArr[0].ChangeStatus(finished);
	BuildArr[0].out_build();
	delete[] BuildArr;

	//пример работы с массивом динамических объектов "PC"
	PC* PCArr[2];
	PCArr[0] = new PC();
	PCArr[0]->input_pc();
	PCArr[0]->Out_PC();
	(*PCArr[0]).Undervolt_GPU();
	PCArr[0]->Out_PC();
	PCArr[1] = new PC();
	PCArr[1]->Out_PC();
	for (int i = 0; i < 2; i++) delete PCArr[i];
}