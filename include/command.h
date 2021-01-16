#pragma once
#include "position.h"

struct Command 
{
	virtual Position exec(const Position& pos) const = 0;
	virtual ~Command() = default;
};
struct CommandTurnLeft : public Command 
{	
private:
	virtual Position exec(const Position& pos)  const override;
};
struct CommandTurnRound : public Command
{
private:
	virtual Position exec(const Position& pos)  const override;
};
struct CommandTurnRight : public Command 
{
private:
	virtual Position exec(const Position& pos) const override;
};

struct CommandForward : public Command
{
	virtual Position exec(const Position& pos) const override;
};

struct CommandBackward : public Command
{
private:
	virtual Position exec(const Position& pos) const override;
};

