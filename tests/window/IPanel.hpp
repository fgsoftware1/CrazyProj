#ifndef IPANEL_HPP
#define IPANEL_HPP

#include "pch.hpp"

INTERFACE(Panel)
FUNC_VIRTUAL(void, draw, const fs::path &path);
END_INTERFACE

#endif