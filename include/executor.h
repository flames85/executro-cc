#ifndef C833410098F34E20A0CA01265DB59AAC
#define C833410098F34E20A0CA01265DB59AAC
#include "../deps/alert/alert.h"
#include "../deps/clean/clean.h"
#include "position.h"
#include "command.h"

struct Executor
{
	const Position& getPosition() const;
	void config(const Position &pos);
	void exec(Command* cmd);

private:
	Position pos{ 0, 0, NORTH };
};


#endif //C833410098F34E20A0CA01265DB59AAC
