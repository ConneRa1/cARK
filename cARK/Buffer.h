#pragma once

#include "Role.h";
class Buffer {
public:
	virtual void effect() {};
protected:
	Role target;
};