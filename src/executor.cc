#include "executor.h"
#include <iostream>


const Position& Executor::getPosition() const
{
	return pos; 
}

void Executor::config(const Position& pos)
{
	this->pos = pos;
}

void Executor::exec(Command* cmd)
{
	pos = cmd->exec(pos);
}