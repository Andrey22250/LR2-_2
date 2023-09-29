#pragma once
#include <iostream>
#include <string>

void clean()  //Очистка потока
{
	while (getchar() != '\n');
}

using namespace std;

class CPU
{
public:
	CPU();
	CPU(string name_cpu);
	CPU(string name_cpu, int frequency, int cores, int treads);
	~CPU();

	bool CheckCor(string name_cpu, int frequency, int cores, int treads);

	string GetName();
	int GetFrequency();
	int GetCores();
	int GetTreads();
	void input_cpu();
	void SetCpu(string name_cpu, int frequency, int cores, int treads);
private:
	string name_cpu;
	int frequency;
	int cores, treads;
};

bool CPU::CheckCor(string name_cpu, int frequency, int cores, int treads)
{
	if (size(name_cpu) != 0 && frequency > 0 && cores > 0 && treads > 0)
		return true;
	else
	{
		printf("Неверно, выход из программы...");
		exit(-1);
	}
}

void CPU::SetCpu(string name_cpu, int frequency, int cores, int treads)
{
	if(CheckCor(name_cpu, frequency, cores, treads))
	{
		this->name_cpu = name_cpu;
		this->frequency = frequency;
		this->cores = cores;
		this->treads = treads;
	}
}

CPU::CPU()
{
	frequency = cores = treads = 0;
}

CPU::CPU(string name_cpu)
{
	this->name_cpu = name_cpu;
	frequency = cores = treads = 0;
}

CPU::CPU(string name_cpu, int frequency, int cores, int treads)
{
	if(CheckCor(name_cpu, frequency, cores, treads))
	{
		this->name_cpu = name_cpu;
		this->frequency = frequency;
		this->cores = cores;
		this->treads = treads;
	}
}

int CPU::GetFrequency()
{
	return frequency;
}

int CPU::GetCores()
{
	return cores;
}

int CPU::GetTreads()
{
	return treads;
}

string CPU::GetName()
{
	return name_cpu;
}

void CPU::input_cpu()
{
	int frequency, cores, treads;
	string name_cpu;
	printf("\nВвод параметров процессора\n");
	printf("\nВведите название процессора: ");
	getline(cin, name_cpu);
	do
	{
		printf("Введите частоту процессора в МГЦ: ");
		scanf("%d", &frequency);
		clean();
	} while (frequency <= 0 || frequency >= 7000);
	do
	{
		printf("Введите кол-во ядер: ");
		scanf("%d", &cores);
		clean();
	} while (cores <= 0 || cores > 256);
	do
	{
		printf("Введите кол-во потоков: ");
		scanf("%d", &treads);
		clean();
	} while (treads <= 0 && treads > 512);
	SetCpu(name_cpu, frequency, cores, treads);
}

class GPU
{
public:
	GPU();
	GPU(string name_gpu);
	GPU(string name_gpu, int vram, int TDP);
	~GPU();

	bool CheckCor(string name_gpu, int vram, int TDP);

	string GetName();
	int GetVram();
	int GetTDP();
	int GetMin_TDP();
	void input_gpu();
	void SetGpu(string name_gpu, int vram, int TDP);
private:
	string name_gpu;
	int vram, TDP, Min_TDP;
};

GPU::GPU()
{
	vram = TDP = Min_TDP = 0;
}

GPU::GPU(string name_gpu)
{
	this->name_gpu = name_gpu;
	vram = TDP = Min_TDP = 0;
}

GPU::GPU(string name_gpu, int vram, int TDP)
{
	if (CheckCor(name_gpu, vram, TDP))
	{
		this->name_gpu = name_gpu;
		this->vram = vram;
		this->TDP = TDP;
		this->Min_TDP = TDP * 0.85;
	}
}

bool GPU::CheckCor(string name_gpu, int vram, int TDP)
{
	if (size(name_gpu) != 0 && vram > 0 && TDP > 0)
		return true;
	else
	{
		printf("Неверно, выход из программы...");
		exit(-1);
	}
}

string GPU::GetName()
{
	return name_gpu;
}

int GPU::GetVram()
{
	return vram;
}

int GPU::GetTDP()
{
	return TDP;
}

int GPU::GetMin_TDP()
{
	return Min_TDP;
}

void GPU::SetGpu(string name_gpu, int vram, int TDP)
{
	if (CheckCor(name_gpu, vram, TDP))
	{
		this->name_gpu = name_gpu;
		this->vram = vram;
		this->TDP = TDP;
		this->Min_TDP = TDP * 0.85;
	}
}

void GPU::input_gpu()
{
	printf("\nВвод параметров видеокарты\n");
	string name_gpu;
	int vram, TDP;
	printf("Введите название видеокарты: ");
	getline(cin, name_gpu);
	do
	{
		printf("Введите объём видеопамяти в МБ: ");
		scanf("%d", &vram);
		clean();
	} while (vram <= 0);
	do
	{
		printf("Введите TDP в ваттах: ");
		scanf("%d", &TDP);
		clean();
	} while (TDP <= 0);
	SetGpu(name_gpu, vram, TDP);
}

class RAM
{
public:
	RAM();
	RAM(string type_ddr);
	RAM(string type_ddr, int frequency, int mem);
	~RAM();

	bool CheckCor(string type_ddr, int frequency, int mem);

	string GetType();
	int GetFrequencyRam();
	int GetMem();
	void SetRam(string type_ddr, int frequency, int mem);
	void input_ram();
private:
	string type_ddr;
	int frequency, mem;
};

RAM::RAM()
{
	frequency = mem = 0;
}

RAM::RAM(string type_ddr)
{
	this->type_ddr = type_ddr;
	frequency = mem = 0;
}

RAM::RAM(string type_ddr, int frequency, int mem)
{
	if (CheckCor(type_ddr, frequency, mem))
	{
		this->type_ddr = type_ddr;
		this->frequency = frequency;
		this->mem = mem;
	}
}

bool RAM::CheckCor(string type_ddr, int frequency, int mem)
{
	if (size(type_ddr) != 0 && frequency > 0 && mem > 0)
		return true;
	else
	{
		printf("Неверно, выход из программы...");
		exit(-1);
	}
}

string RAM::GetType()
{
	return type_ddr;
}

int RAM::GetFrequencyRam()
{
	return frequency;
}

int RAM::GetMem()
{
	return mem;
}

void RAM::input_ram()
{
	printf("\nВвод параметров ОЗУ\n");
	string type_ddr;
	int frequency, mem;
	printf("Введите тип ОЗУ: ");
	getline(cin, type_ddr);
	do
	{
		printf("Введите частоту ОЗУ в МГЦ: ");
		scanf("%d", &frequency);
		clean();
	} while (frequency <= 0 || frequency >= 12000);
	do
	{
		printf("Введите объём ОЗУ: ");
		scanf("%d", &mem);
		clean();
	} while (mem <= 0);
	SetRam(type_ddr, frequency, mem);
}

void RAM::SetRam(string type_ddr, int frequency, int mem)
{
	if (CheckCor(type_ddr, frequency, mem))
	{
		this->type_ddr = type_ddr;
		this->frequency = frequency;
		this->mem = mem;
	}
}