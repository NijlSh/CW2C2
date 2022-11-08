#include "GetFileName.h"

std::string FileInput()
{
	while (true)
	{
		std::string file_path;

		std::cout << "����: ";
		getline(std::cin, file_path);

		if (file_path.find(".txt") >= std::string::npos)
		{
			std::cout << "�� ��������� ����. ��������� ����." << std::endl;
			return false;
		}

		if (!std::ifstream(file_path)) {
			std::cout << "���� �� ����������. ��������� ����." << std::endl;
			continue;
		}

		std::error_code ec;
		if (!is_regular_file(file_path, ec))
		{
			std::cout << "����� �������� ������������ ��������. ��������� ����." << std::endl;
			continue;
		}

		std::ifstream myFile(file_path);
		if (!myFile) {
			std::cout << "�������� ���������. ��������� ����." << std::endl;
			myFile.close();
			continue;
		}
		myFile.close();
		return file_path;
	}
}

std::string FileOutput()
{
	const int get_name = 2;

	while (true)
	{
		std::string file_path;

		std::cout << "��������� ��: ";
		getline(std::cin, file_path);

		if (file_path.find(".txt") >= std::string::npos) 
		{
			std::cout << "�� ��������� ����. ��������� ����." << std::endl;
			return false;
		}

		if (std::ifstream(file_path))
		{
			std::cout << "���� ��� ����������." << std::endl;
			std::cout << "[1] - ������������ ������������ ����." << std::endl;
			std::cout << "[2] - ��������� ����." << std::endl;
			int tryAnotherFile = CheckMenu(2);
			if (tryAnotherFile == get_name)
			{
				continue;
			}
		}

		std::ofstream myFile(file_path, std::ofstream::app);

		std::error_code ec;
		if (!is_regular_file(file_path, ec))
		{
			std::cout << "����� �������� ������������ ��������. ��������� ����." << std::endl;
			continue;
		}
		if (!myFile)
		{
			std::cout << "������ ���������. ��������� ����." << std::endl;
			myFile.close();
			continue;
		}
		myFile.close();
		return file_path;
	}
}

std::string GetFileName(int stream_type)
{
	while (true) {
		std::string file_path;

		switch (stream_type)
		{
		case input:
			return file_path = FileInput();
		case output:
			return file_path = FileOutput();
		}
	}
}