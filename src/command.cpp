#include "command.h"


void Command::turn(Position& pos, int times) const
{
	static Direction directions[] = { EAST, SOUTH, WEST, NORTH };
	pos.heading = directions[(pos.heading + times) % DIRECTION_MAX_COUNT];
}

void CommandTurnLeft::exec(Position& pos) const
{
	turn(pos, 3);
}

void CommandTurnRight::exec(Position& pos) const
{
	turn(pos, 1);
}