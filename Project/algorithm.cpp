#include "algorithm.h"

void circleChoice(std::vector<std::shared_ptr<figure>>& shp) 
{
	auto temp = std::make_shared<circle>();
	std::cout << "������� ������: ";
	temp->setRadius(getPositiveValue<double>());

	shp.push_back(temp);
}
void rectangleChoice(std::vector<std::shared_ptr<figure>>& shp)
{
	auto temp = std::make_shared<rectangle>();
	std::cout << "������� ������: ";
	temp->setHeight(getPositiveValue<double>());
	std::cout << "������� ������: ";
	temp->setWidth(getPositiveValue<double>());

	shp.push_back(temp);
}
void trapezoidChoice(std::vector<std::shared_ptr<figure>>& shp) 
{
	while (true) {
		auto temp = std::make_shared<trapezoid>();
		std::cout << "������� �������� �������� ���������: ";
		temp->setLargeBase(getPositiveValue<double>());
		std::cout << "������� �������� ����� �������: ";
		temp->setLeftSide(getPositiveValue<double>());
		std::cout << "������� �������� ������ �������: ";
		temp->setRightSide(getPositiveValue<double>());
		std::cout << "������� �������� �������� ���������: ";
		temp->setSmallerBase(getPositiveValue<double>());
		if (!(temp->checkTrapezoid(temp->getLargeBase(), temp->getLeftSide(), temp->getRightSide(), temp->getSmallerBase())))
		{
			std::cout << "������� ������������ ������: ";
			temp->getSmallerBase() >= temp->getLargeBase() 
				? std::cout << "������� ��������� ������ �������� ���������." << std::endl 
				: std::cout << "����� ����� �� ������ ������ ����� ���� ��������� ������." << std::endl;
			continue;
		}

		shp.push_back(temp);
		break;
	}
}

void showResult(std::vector<std::shared_ptr<figure>>& shp)
{
	int index = 1;
	std::cout << "��������� ������ ���������:" << std::endl;
	for (auto& elem : shp) {
		std::cout << "������ � " << index << " �������� ������: ";
		std::cout << elem->getName() << std::endl;
		std::cout << "�������: " << elem->getSquare() << std::endl;
		std::cout << "��������: " << elem->getPerimeter() << std::endl;
		std::cout << "" << std::endl;
		index++;
	}
}