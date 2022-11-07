#include "GetFileName.h"

std::string FileInput()
{
	std::error_code ec;
	while (true)
	{
		std::string file_path;

		std::cout << "��������� �:" << std::endl;
		getline(std::cin, file_path);

		if (!is_regular_file(file_path, ec))
		{
			std::cout << "����� �������� ������������ ��������. ��������� ����." << std::endl;
			continue;
		}
		if (!std::ifstream(file_path)) {
			std::cout << "���� �� ����������. ��������� ����." << std::endl;
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
	std::error_code ec;
	const int get_name = 2;

	while (true)
	{
		std::string file_path;

		std::cout << "��������� �:" << std::endl;
		getline(std::cin, file_path);

		if (!is_regular_file(file_path, ec))
		{
			std::cout << "����� �������� ������������ ��������. ��������� ����." << std::endl;
			continue;
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