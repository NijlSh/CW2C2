#include "iofile.h"

void fileOutput(std::vector<std::shared_ptr<figure>>& shp, int counter) 
{
	std::ofstream file;
	file.exceptions(std::ofstream::badbit | std::ofstream::failbit);
	bool is_stream_opened = false;
	std::string file_name = "";

	do
	{
		try
		{
			std::cout << "������� ������ ��� ����� (�������� � ���, ������: ��������.txt) ��� ���� �� ����: ";
			std::getline(std::cin, file_name);
			std::cout << std::endl;
			checkFileName(file_name);
			checkFileExistance(file_name, op);
			file.open(file_name);
			is_stream_opened = true;
		}
		catch (const std::exception&) 
		{
			std::cout << "������ ��� ������� ������� ����." << std::endl;
			continue;
		}
		catch (int)
		{
			continue;
		}
	} while (!is_stream_opened);
	while (true)
	{

		file << counter << std::endl;
		try {
			for (auto& elem : shp) {
				if (elem->getName() == "����") {
					auto tmp = std::dynamic_pointer_cast<circle>(elem);
					file << tmp->getName() << std::endl;
					file << tmp->getRadius() << std::endl;
				}
				else if (elem->getName() == "�������������") {
					auto tmp = std::dynamic_pointer_cast<rectangle>(elem);
					file << tmp->getName() << std::endl;
					file << tmp->getHeight() << std::endl;
					file << tmp->getWidht() << std::endl;
				}
				else {
					auto tmp = std::dynamic_pointer_cast<trapezoid>(elem);
					file << tmp->getName() << std::endl;
					file << tmp->getLargeBase() << std::endl;
					file << tmp->getLeftSide() << std::endl;
					file << tmp->getRightSide() << std::endl;
					file << tmp->getSmallerBase() << std::endl;
				}

			}
			file.close();
		}
		catch (const std::exception&) 
		{
			std::cout << "������ ��� ������ ���������� � ����. ��������� ����." << std::endl;
			continue;
		}
		std::cout << "������ ������� ���������." << std::endl;
		break;
	}
}

void fileInput(std::vector<std::shared_ptr<figure>>& shp) 
{
	std::ifstream file;
	file.exceptions(std::istream::badbit | std::ifstream::failbit);
	bool is_stream_opened = false;
	std::string file_name = "";

	do
	{
		try
		{
			std::cout << "������� ������ ��� ����� (�������� � ���, ������: ��������.txt) ��� ���� �� ����: ";
			std::getline(std::cin, file_name);
			checkFileName(file_name);
			checkFileExistance(file_name, ip);
			file.open(file_name);
			is_stream_opened = true;
		}
		catch (const std::exception&)
		{
			continue;
		}
	} while (!is_stream_opened);

	while (true)
	{
		
		try 
		{
			int size = getLineI(file);
			for (int i = 0; i < size; i++)
			{
				std::string name = getLineS(file);
				if (name == "����")
				{
					auto c_ptr = std::make_shared<circle>();
					c_ptr->setRadius(getLineD(file));
					shp.push_back(c_ptr);
				}
				else if (name == "�������������")
				{
					auto r_ptr = std::make_shared<rectangle>();
					r_ptr->setHeight(getLineD(file));
					r_ptr->setWidth(getLineD(file));
					shp.push_back(r_ptr);
				}
				else if (name == "��������")
				{
					auto t_ptr = std::make_shared<trapezoid>();
					t_ptr->setLargeBase(getLineD(file));
					t_ptr->setLeftSide(getLineD(file));
					t_ptr->setRightSide(getLineD(file));
					t_ptr->setSmallerBase(getLineD(file));
					if (t_ptr->getSmallerBase() > t_ptr->getLargeBase()) throw 1;

					shp.push_back(t_ptr);
				}
				else throw 1;
			}
		}
		catch (int)
		{
			continue;
		}
		catch (const std::exception&) 
		{
			std::cout << "������ ��� ������ ���������� �� �����. ��������� ����." << std::endl;
		}
		break;
	}
}

void fileOutputFin(std::vector<std::shared_ptr<figure>>& shp)
{
	int index = 1;
	std::ofstream  file;
	file.exceptions(std::ofstream::badbit | std::ofstream::failbit);
	bool is_stream_opened = false;
	std::string file_name = "";

	do
	{
		try
		{
			std::cout << "������� ��� ������ ��� ����� (�������� � ���, ������: ��������.txt) ��� ���� �� ����: ";
			std::getline(std::cin, file_name);
			std::cout << std::endl;
			checkFileName(file_name);
			checkFileExistance(file_name, op);
			file.open(file_name);
			is_stream_opened = true;
		}
		catch (const std::exception&)
		{
			continue;
		}
		catch (int)
		{
			continue;
		}
	} while (!is_stream_opened);

	while (true)
	{
		try
		{
			for (auto&& elem : shp) {
				file << "������ � " << index << " �������� ������: ";
				file << elem->getName() << std::endl;
				file << "�������: " << elem->getSquare() << std::endl;
				file << "��������: " << elem->getPerimeter() << std::endl;
				file << "" << std::endl;
				index++;
			}
			std::cout << "������ ������� ��������." << std::endl;

			file.close();
			break;
		}
		catch (const std::exception&)
		{
			std::cout << "������ ��� ������ ���������� � ����." << std::endl;
		}
	}
}


