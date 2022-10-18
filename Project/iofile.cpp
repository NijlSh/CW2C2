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
			std::cout << "Введите полное имя файла (название и тип, пример: название.txt) или путь до него: ";
			std::getline(std::cin, file_name);
			std::cout << std::endl;
			checkFileName(file_name);
			checkFileExistance(file_name, op);
			file.open(file_name);
			is_stream_opened = true;
		}
		catch (const std::exception&) 
		{
			std::cout << "Ошибка при попытке открыть файл." << std::endl;
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
				if (elem->getName() == "круг") {
					auto tmp = std::dynamic_pointer_cast<circle>(elem);
					file << tmp->getName() << std::endl;
					file << tmp->getRadius() << std::endl;
				}
				else if (elem->getName() == "прямоугольник") {
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
			std::cout << "Ошибка при записи информации в файл. Повторите ввод." << std::endl;
			continue;
		}
		std::cout << "Данные успешно сохранены." << std::endl;
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
			std::cout << "Введите полное имя файла (название и тип, пример: название.txt) или путь до него: ";
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
				if (name == "круг")
				{
					auto c_ptr = std::make_shared<circle>();
					c_ptr->setRadius(getLineD(file));
					shp.push_back(c_ptr);
				}
				else if (name == "прямоугольник")
				{
					auto r_ptr = std::make_shared<rectangle>();
					r_ptr->setHeight(getLineD(file));
					r_ptr->setWidth(getLineD(file));
					shp.push_back(r_ptr);
				}
				else if (name == "трапеция")
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
			std::cout << "Ошибка при чтении информации из файла. Повторите ввод." << std::endl;
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
			std::cout << "Введите имя полное имя файла (название и тип, пример: название.txt) или путь до него: ";
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
				file << "Объект № " << index << " Название фигуры: ";
				file << elem->getName() << std::endl;
				file << "Площадь: " << elem->getSquare() << std::endl;
				file << "Периметр: " << elem->getPerimeter() << std::endl;
				file << "" << std::endl;
				index++;
			}
			std::cout << "Данные успешно записаны." << std::endl;

			file.close();
			break;
		}
		catch (const std::exception&)
		{
			std::cout << "Ошибка при записи информации в файл." << std::endl;
		}
	}
}


