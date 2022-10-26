#include "GetFileName.h"

bool IsValidName(std::string name)
{
	std::cout << std::endl;
	try
	{
		if (name.find(".txt") >= std::string::npos)
		{
			std::cout << "�������� ��� �����. ��������� ����." << std::endl;
			return false;
		}

		std::string temp1 = "", temp2 = name;
		for (int i = 0; i < WIN_NAME_SIZE; i++)
		{
			temp1 = win_name[i] + ".TXT";
			if (temp1.size() == temp2.size()) 
			{
				for (int j = 0; temp1[j]; j++)
				{
					temp1[j] = static_cast<char>(toupper(temp1[j]));
				}
				if (temp1 == temp2)
				{
					std::cout << "������� ����������������� ������������ �������� Windows �����. ��������� ����." << std::endl;
					return false;
				}
			}
		}

		return true;
	}

	catch (std::exception&)
	{
		std::cout << "������." << std::endl;
		return false;
	}
}

bool IsCanOpenFile(const std::string file_name, const int stream_type)
{
	const int this_file = 1;

	try {
		if (std::ifstream(file_name))
		{
			if (stream_type == output)
			{
				std::cout << "���� ��� ����������. �� ������ ����������� ���?" << std::endl
					<< "0 - ���." << std::endl
					<< "1 - ��." << std::endl;
				int user_choice = getBinChoice();
				if (user_choice != this_file)
					return false;
			}
		}
		else if (stream_type == input)
		{
			std::cout << "����� � ����� ��������� �� ����������. ��������� ����." << std::endl;
			return false;
		}
		return true;
	}
	catch (std::exception&) 
	{
		std::cout << "������." << std::endl;
		return false;
	}
}

std::string GetFileName(int stream_type)
{
	std::string name; //�������� �����

	while (true)
	{
		std::cout << "������� �������� ����� ��� ������ ���� �� ����." << std::endl << "����: "; 
		std::getline(std::cin, name); //���� 

		if (!IsValidName(name)) //���� �������� �������� ����������
		{
			std::cin.sync(); //�������� ����� cin
			continue; //���� �� ����� ����
		}
		try
		{
			if (IsCanOpenFile(name, stream_type)) //���� ����� ��������� ����
				return name; //������� ���
		}
		catch (const std::exception&)
		{
			std::cout << "������." << std::endl;
		}
	}
}

