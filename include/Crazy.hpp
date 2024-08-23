#pragma once

#include "pch.hpp"
#include "ICrazy.hpp"

DERIVED_CLASS(Crazy, ICrazy)
FUNC(int, add, int a, int b)
END_DERIVED_CLASS