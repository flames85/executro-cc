#pragma once
#include "position.h"

struct Command;
struct Executor
{
	const Position& getPosition() const;
	void config(const Position &pos);
	void exec(const Command &cmd);
private:
	Position pos{ 0, 0,  Direction::NORTH };
};
