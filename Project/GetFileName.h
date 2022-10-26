#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

#include "check.h"

#define WIN_NAME_SIZE 22

enum 
{ 
	output = 0,
	input = 1
};

const int restart = 2;

const std::string win_name[WIN_NAME_SIZE] = { "CON", "PRN", "AUX", "NUL",
								"COM1", "COM2", "COM3", "COM4", "COM5",
								"COM6", "COM7", "COM8", "COM9", "LPT1",
								"LPT2", "LPT3", "LPT4", "LPT5", "LPT6",
								"LPT7", "LPT8", "LPT9" };

bool IsValidName(std::string name);
bool IsCanOpenFile(const std::string file_name, const int stream_type);
std::string GetFileName(int stream_type);

