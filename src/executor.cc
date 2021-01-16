#include "executor.h"
#include <iostream>
#include "command.h"

const Position& Executor::getPosition() const
{
	return pos; 
}
void Executor::config(const Position& pos)
{
	this->pos = pos;
}
void Executor::exec(const Command &cmd)
{
	pos = cmd.exec(pos);
}