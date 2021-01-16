#include "command.h"

Position CommandTurnLeft::exec(const Position& pos) const
{
	return pos.turn(3);
}
Position CommandTurnRight::exec(const Position& pos) const
{
	return pos.turn(1);
}
Position CommandTurnRound::exec(const Position& pos) const
{
	return pos.turn(2);
}
Position CommandForward::exec(const Position& pos) const
{
	return pos.move(1);
}
Position CommandBackward::exec(const Position& pos) const
{
	return pos.move(-1);
}