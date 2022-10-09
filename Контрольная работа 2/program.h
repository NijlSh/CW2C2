#pragma once

#include <windows.h>

#include <iostream>
#include <vector>
#include <string>
#include <memory>

#include "algorithm.h"
#include "iofile.h"
#include "check.h"
#include "interface.h"
#include "class.h"

#define QUIT 0

enum figureChoise { _circle = 1, _rectangle = 2, _trapezoid = 3 };

int program();