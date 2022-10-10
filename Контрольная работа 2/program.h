#pragma once

#include <windows.h>

#include <vector>
#include <string>
#include <memory>

#include "class.h"
#include "algorithm.h"
#include "iofile.h"
#include "check.h"
#include "interface.h"


#define QUIT 0

enum figureChoise { _circle = 1, _rectangle = 2, _trapezoid = 3 };

int program();