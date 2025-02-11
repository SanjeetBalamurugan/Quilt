#pragma once

#include <iostream>
#include <string.h>
#include <vector>
#include <memory>
#include <sstream>
#include <functional>
#include <optional>

#include <GLFW/glfw3.h>

// Macros
#define KEYCODE_TO_STRING_CASE(value) case KeyCode::value: return #value;
#define MOUSECODE_TO_STRING_CASE(value) case MouseCode::value: return #value;