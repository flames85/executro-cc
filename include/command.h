#pragma once
#include "position.h"

struct Command 
{
	virtual void exec(Position& pos) const = 0;
	void turn(Position& pos, int times) const;
};

struct CommandTurnLeft : public Command 
{
	virtual void exec(Position& pos) const override;
};

struct CommandTurnRight : public Command 
{
	virtual void exec(Position& pos) const override;
};