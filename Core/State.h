#pragma once
#include"Referenced.h"

class State : public Referenced
{
public:
	virtual void Init() { };
	virtual void Update() { };
	virtual void Draw() { };
	virtual void CleanUp() { }; 
	virtual ~State() { };
};