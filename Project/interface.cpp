#include "interface.h"

void showGreetings(void) 
{
	std::cout << "����������� ������ �2, ������� 5, ������� ��������� ������ 415 ��������� �.�." << std::endl;
}

void showTask(void) 
{
	std::cout << "������� ������� ����� ������, ����������� ������: ����, �������������, ��������." << std::endl;
	std::cout << "���������� ����������� ������� ��� ���������� ������� � ���������." << std::endl;
}

void showInputChoice(void) 
{
	std::cout << "�������� ������ ����� ������:" << std::endl;
	std::cout << "0 - ��������� ������" << std::endl;
	std::cout << "1 - �� �����" << std::endl;
	std::cout << "2 - �� �������" << std::endl;
	std::cout << "����: ";
}

void showFigureMenu(void) 
{
	std::cout << "��������, ��� ������ �������:" << std::endl;
	std::cout << "0 - ��������� � ����������� ������" << std::endl;
	std::cout << "1 - ����" << std::endl;
	std::cout << "2 - �������������" << std::endl;
	std::cout << "3 - ��������" << std::endl;
	std::cout << "����: ";

}

void showOutputMenu(void) 
{
	std::cout << "�� ������ �������� ������ � �������� ���� � ����?" << std::endl;
	std::cout << "0 - ���" << std::endl;
	std::cout << "1 - ��" << std::endl;
	std::cout << "����: ";
}

void showContMenu(void) 
{
	std::cout << "������ ������ ����� ������?" << std::endl;
	std::cout << "0 - ���" << std::endl;
	std::cout << "1 - ��" << std::endl;
	std::cout << "����: ";
}

void showFinOutputMenu(void)
{
	std::cout << "������ �������� ������ � ������� ���������� ���� � ����� ����" << std::endl;
	std::cout << "0 - ���" << std::endl;
	std::cout << "1 - ��" << std::endl;
	std::cout << "����: ";
}

void showEndMenu(void) 
{
	std::cout << "�� ������ ��������� ��������� �����?" << std::endl;
	std::cout << "0 - ���" << std::endl;
	std::cout << "1 - ��" << std::endl;
	std::cout << "����: ";
}