#include "command.h"
namespace
{
	Position turn(const Position& pos, int times)
	{
		static Direction directions[] = 
		{ 
			Direction::EAST,  
			Direction::SOUTH,  
			Direction::WEST,  
			Direction::NORTH 
		};

		Direction heading = 
			directions[(int(pos.heading) + times) % int(Direction::DIRECTION_MAX_COUNT)];

		return Position{ pos.x, pos.y, heading };
	}
	Position move(const Position& pos, int factor) // member of position???
	{
		static Position positions[] = 
		{ 
			{1, 0,  Direction::EAST},
			{0, -1,  Direction::SOUTH},
			{-1, 0,  Direction::WEST},
			{0, 1,  Direction::NORTH}
		};
		Position step = positions[int(pos.heading)];
		return Position{ pos.x + factor*step.x, pos.y + factor * step.y, pos.heading};
	}
}

Position CommandTurnLeft::exec(const Position& pos) const
{
	return turn(pos, 3);
}

Position CommandTurnRight::exec(const Position& pos) const
{
	return turn(pos, 1);
}

Position CommandTurnRound::exec(const Position& pos) const
{
	return turn(pos, 2);
}

Position CommandForward::exec(const Position& pos) const
{
	return move(pos, 1);
}

Position CommandBackward::exec(const Position& pos) const
{
	return move(pos, -1);
}