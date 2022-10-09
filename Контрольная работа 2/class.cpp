#define _USE_MATH_DEFINES

#include <cmath>

#include "class.h"

circle::circle(double radius) :radius_(radius) {}

void circle::setRadius(double rad)
{
	radius_ = rad;
}

double circle::getRadius()
{
	return radius_;
}

double circle::getSquare()
{
	return M_PI * pow(radius_, 2);
}

double circle::getPerimeter()
{
	return 2 * M_PI * radius_;
}

std::string circle::getName()
{
	return name_;
}

rectangle::rectangle(double width, double height) :width_(width), height_(height)
{
}

void rectangle::setWidth(double width)
{
	width_ = width;
}

double rectangle::getWidht()
{
	return width_;
}

void rectangle::setHeight(double height)
{
	height_ = height;
}

double rectangle::getHeight()
{
	return height_;
}

double rectangle::getSquare()
{
	return width_ * height_;
}

double rectangle::getPerimeter()
{
	return 2 * (width_ + height_);
}

std::string rectangle::getName()
{
	return name_;
}



trapezoid::trapezoid(double largeBase, double smallerBase, double rightSide, double leftSide) :large_base_(largeBase), smaller_base_(smallerBase), right_side_(rightSide), left_side_(leftSide)
{
}

bool trapezoid::checkTrapezoid(double lb, double ls, double rs, double sb)
{
	double side[4] = { lb, ls, rs, sb };
	double sum = 0.0f;

	for (int i = 0; i < 4; i++) sum += side[i];
	 
	for (int i = 0; i < 4; i++) if (side[i] >= sum - side[i]) return false;

	if (fabs(lb - sb) <= 0) return false;

	return true;
}

void trapezoid::setLargeBase(double lb)
{
	large_base_ = lb;
}

double trapezoid::getLargeBase()
{
	return large_base_;
}

void trapezoid::setSmallerBase(double sb)
{
	smaller_base_ = sb;
}

double trapezoid::getSmallerBase()
{
	return smaller_base_;
}

void trapezoid::setRightSide(double rs)
{
	right_side_ = rs;
}

double trapezoid::getRightSide()
{
	return right_side_;
}

void trapezoid::setLeftSide(double ls)
{
	left_side_ = ls;
}

double trapezoid::getLeftSide()
{
	return left_side_;
}

double trapezoid::getSquare()
{
	return (((smaller_base_ + large_base_) / 2) * (sqrt(pow(left_side_, 2) 
		- pow(((pow(smaller_base_ - large_base_, 2) + pow(left_side_, 2) 
		- pow(right_side_, 2)) / (2 * smaller_base_ - 2 * large_base_)), 2))));
}

double trapezoid::getPerimeter()
{
	return left_side_ + right_side_ + large_base_ + smaller_base_;
}

std::string trapezoid::getName()
{
	return name_;
}
