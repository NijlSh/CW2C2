#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <experimental/filesystem>
#include <filesystem>

#include "Check.h"

#define WIN_NAME_SIZE 22

using namespace std::experimental::filesystem;

enum 
{ 
	output = 0,
	input = 1
};

std::string GetFileName(int stream_type);

