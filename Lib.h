#pragma once
#include <iostream>
#include <string>

void clean()  //Очистка потока
{
	while (getchar() != '\n');
}

using namespace std;
//Класс процессор
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

//Его функции
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
//Конструкторы
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
//Деструктор
CPU::~CPU()
{
}

//Получение
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
//Ввод
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
	int flag = 0;
};

GPU::GPU()
{
	vram = TDP = Min_TDP = 0;
	flag = 1;
}

GPU::GPU(string name_gpu)
{
	this->name_gpu = name_gpu;
	vram = TDP = Min_TDP = 0;
	flag = 1;
}

GPU::GPU(string name_gpu, int vram, int TDP)
{
	if (CheckCor(name_gpu, vram, TDP))
	{
		this->name_gpu = name_gpu;
		this->vram = vram;
		this->TDP = TDP;
	}
	if (flag == 0)
	{
		this->Min_TDP = TDP * 0.85;
		flag = 1;
	}
}

GPU::~GPU()
{
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
		flag = 1;
	}
}

void GPU::input_gpu()
{
	printf("\nВвод параметров видеокарты\n");
	string name_gpu;
	int vram, TDP;
	printf("\nВведите название видеокарты: ");
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

RAM::~RAM()
{
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
	printf("\nВведите тип ОЗУ: ");
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

class Motherboard
{
public:
	Motherboard();
	Motherboard(string name_mrbrd);
	Motherboard(string name_mrbrd, string chipset);
	~Motherboard();

	bool CheckCor(string name_mrbrd, string chipset);

	string GetName();
	string GetChipset();
	void input_mrbrd();
	void SetMrbrd(string name_mrbrd, string chipset);
private:
	string name_mrbrd, chipset;
};

bool Motherboard::CheckCor(string name_mrbrd, string chipset)
{
	if (size(name_mrbrd) != 0 && size(chipset) != 0)
		return true;
	else
	{
		printf("Неверно, выход из программы...");
		exit(-1);
	}
}

Motherboard::Motherboard()
{
}

Motherboard::Motherboard(string name_mrbrd)
{
	this->name_mrbrd = name_mrbrd;
}

Motherboard::Motherboard(string name_mrbrd, string chipset)
{
	if(CheckCor(name_mrbrd, chipset))
	{
		this->name_mrbrd = name_mrbrd;
		this->chipset = chipset;
	}
}

Motherboard::~Motherboard()
{
}

string Motherboard::GetName()
{
	return name_mrbrd;
}

string Motherboard::GetChipset()
{
	return chipset;
}

void Motherboard::input_mrbrd()
{
	string name_mrbrd, chipset;
	printf("\nВвод параметров материнской платы\n");
	printf("\nВведите название материнской платы: ");
	getline(cin, name_mrbrd);
	printf("Введите чипсет: ");
	getline(cin, chipset);
	SetMrbrd(name_mrbrd, chipset);
}

void Motherboard::SetMrbrd(string name_mrbrd, string chipset)
{
	if (CheckCor(name_mrbrd, chipset))
	{
		this->name_mrbrd = name_mrbrd;
		this->chipset = chipset;
	}
}

class PC
{
public:
	PC();
	PC(float price);
	PC(float price, CPU cpu, GPU gpu, RAM ram, Motherboard mrbrd);
	~PC();

	float GetPrice();
	CPU GetCpu();
	GPU GetGpu();
	RAM GetRam();
	Motherboard GetMrbrd();
	void input_pc();
	void Undervolt_GPU();
	void Out_PC();
	void SetPrice(float price);
private:
	float price;
	CPU cpu;
	GPU gpu;
	RAM ram;
	Motherboard mrbrd;
};

PC::PC()
{
	cpu = CPU();
	gpu = GPU();
	ram = RAM();
	mrbrd = Motherboard();
	price = 0;
}

PC::PC(float price)
{
	if (price>0)
	{
		cpu = CPU();
		gpu = GPU();
		ram = RAM();
		mrbrd = Motherboard();
		this->price = price;
	}
}

PC::PC(float price, CPU cpu, GPU gpu, RAM ram, Motherboard mrbrd)
{
	if(price>0)
	{
		this->price = price;
		this->cpu = cpu;
		this->gpu = gpu;
		this->ram = ram;
		this->mrbrd = mrbrd;
	}
}

PC::~PC()
{
}

float PC::GetPrice()
{
	return price;
}

CPU PC::GetCpu()
{
	return cpu;
}

GPU PC::GetGpu()
{
	return gpu;
}

RAM PC::GetRam()
{
	return ram;
}

Motherboard PC::GetMrbrd()
{
	return mrbrd;
}

void PC::input_pc()
{
	float price;
	printf("\nВвод информации о компьютере\n");
	do
	{
		printf("Введите цену ПК: ");
		scanf("%f", &price);
		clean();
	} while (price <= 0);
	cpu.input_cpu();
	gpu.input_gpu();
	ram.input_ram();
	mrbrd.input_mrbrd();
	SetPrice(price);
}

void PC::Undervolt_GPU()
{
	if (this->gpu.GetTDP() - 3 > this->gpu.GetMin_TDP())
	{
		gpu = GPU(this->gpu.GetName(), this->gpu.GetVram(), this->gpu.GetTDP() - 3);
		if (this->gpu.GetTDP() <= this->gpu.GetMin_TDP())
			gpu = GPU(this->gpu.GetName(), this->gpu.GetVram(), this->gpu.GetMin_TDP());
	}
	else printf("Undervolt невозможен!");
}

void PC::Out_PC()
{
	printf("\nИнформация о сборке:\n\n");
	printf("Процессор: %s, %d МГЦ, %d ядер, %d потоков\n", this->cpu.GetName().c_str(), this->cpu.GetFrequency(), this->cpu.GetCores(), this->cpu.GetTreads());
	printf("Видеокарта: %s, %d VRAM, %d TDP\n", this->gpu.GetName().c_str(), this->gpu.GetVram(), this->gpu.GetTDP());
	printf("ОЗУ: %s, %d частота, %d объём\n", this->ram.GetType().c_str(), this->ram.GetFrequencyRam(), this->ram.GetMem());
	printf("Материнская плата: %s, %s чипсет\n", this->mrbrd.GetName().c_str(), this->mrbrd.GetChipset().c_str());
	printf("Цена сборки: %.2f\n\n", this->price);
}

void PC::SetPrice(float price)
{
	this->price = price;
}
//Нумерованный список статусов
enum Status { create, working, finished };
//Перевод статуса в строку
string StatusToString(Status status)
{
	string strStatus;

	switch (status)
	{
	case create:
		strStatus = "создан";
		break;
	case working:
		strStatus = "в сборке";
		break;
	case finished:
		strStatus = "готов к выдаче";
		break;
	default:
		break;
	}
	return strStatus;
}

class Build
{
public:
	Build();
	Build(int number);
	Build(int number, PC pc, string client, Status status);
	~Build();

	bool CheckCor(int number, PC pc, string client, Status status);

	int GetNum();
	PC GetPC();
	string GetClient();
	Status GetStatus();
	void input_build();
	void out_build();
	void ChangeStatus(Status newstatus);
	void SetPC(PC pc);
	void SetBuild(int number, PC pc, string client, Status status);
private:
	int number;
	PC pc;
	string client;
	Status status;
};

Build::Build()
{
	number = 0;
	pc = PC();
	status = create;
}

Build::Build(int number)
{
	this->number = number;
	pc = PC();
	status = create;
}

Build::Build(int number, PC pc, string client, Status status)
{
	if (CheckCor(number, pc, client, status))
	{
		this->number = number;
		this->pc = pc;
		this->client = client;
		this->status = status;
	}
}

Build::~Build()
{
}

bool Build::CheckCor(int number, PC pc, string client, Status status)
{
	if (number > 0 && size(client) != 0 && (status >= create && status <= finished))
		return true;
	else
	{
		printf("Неверно, выход из программы...");
		exit(-1);
	}
}

int Build::GetNum()
{
	return number;
}

PC Build::GetPC()
{
	return pc;
}

string Build::GetClient()
{
	return client;
}

Status Build::GetStatus()
{
	return status;
}

void Build::input_build()
{
	int number;
	string client;
	printf("Ввод данных заказа\n\n");
	do
	{
		printf("Введите номер заказа: ");
		scanf("%d", &number);
		clean();
	} while (number <= 0);
	printf("Введите имя клиента: ");
	getline(cin, client);
	Status status;
	do
	{
		printf("Введите статус заказа, где\n0 - Заказ создан\n1 - Заказ в работе\n2 - Заказ выполнен\nВаш выбор: ");
		scanf("%d", &status);
		clean();
	} while (status < 0 && status > 2);
	pc.input_pc();
	SetBuild(number, pc, client, status);
}

void Build::out_build()
{
	printf("\nИнформация о заказе:\n\n");
	printf("Номер заказа: %d\n", GetNum());
	printf("Клиент - %s\n", GetClient().c_str());
	printf("Статус - %s\n", StatusToString(GetStatus()).c_str());
	pc.Out_PC();
}

void Build::ChangeStatus(Status newstatus)
{
	if (newstatus >= create && newstatus <= finished) {
		this->status = newstatus;
		printf("Состояние заказа успешно изменено!\n");
	}
	else {
		printf("Неверно, выход из программы...");
		exit(-1);
	}
}

void Build::SetPC(PC pc)
{
	this->pc = pc;
}

void Build::SetBuild(int number, PC pc, string client, Status status)
{
	if (CheckCor(number, pc, client, status))
	{
		this->number = number;
		this->pc = pc;
		this->client = client;
		this->status = status;
	}
}