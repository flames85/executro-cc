#include <gtest/gtest.h>
#include "executor.h"
#include "command.h"
////////////////////////////////////////////////////////////////////////////////////
struct ExecutorTest : testing::Test
{
protected:
	Executor		excutor;
};
TEST_F(ExecutorTest, should_be_ok_by_init)
{
	ASSERT_EQ(Position(0, 0, Direction::NORTH), excutor.getPosition());
}
TEST_F(ExecutorTest, should_be_ok_by_config)
{
	excutor.config(Position(1, 2, Direction::EAST));

	ASSERT_EQ(Position(1, 2, Direction::EAST), excutor.getPosition());
}
////////////////////////////////////////////////////////////////////////////////////
struct ExecutorTestTurnLeft : public ExecutorTest
{
	virtual void SetUp()
	{
		excutor.config(Position(1, 2, Direction::EAST));
	}
protected:
	CommandTurnLeft left; 
};
TEST_F(ExecutorTestTurnLeft, should_be_ok_by_3_turn_left)
{
	excutor.exec(left);
	excutor.exec(left);
	excutor.exec(left);
	ASSERT_EQ(Position(1, 2, Direction::SOUTH), excutor.getPosition());
}

TEST_F(ExecutorTestTurnLeft, should_be_ok_by_4_turn_left)
{
	excutor.exec(left);
	excutor.exec(left);
	excutor.exec(left);
	excutor.exec(left);

	ASSERT_EQ(Position(1, 2, Direction::EAST), excutor.getPosition());
}
TEST_F(ExecutorTestTurnLeft, should_be_ok_by_turn_left)
{
	excutor.exec(left);
	ASSERT_EQ(Position(1, 2, Direction::NORTH), excutor.getPosition());
}


////////////////////////////////////////////////////////////////////////////////////
struct ExecutorTestTurnRight : public ExecutorTest
{
	virtual void SetUp()
	{
		excutor.config(Position(1, 2, Direction::EAST));
	}
protected:
	CommandTurnRight right;
};
TEST_F(ExecutorTestTurnRight, should_be_ok_by_1_turn_right)
{
	excutor.exec(right);

	ASSERT_EQ(Position(1, 2, Direction::SOUTH), excutor.getPosition());
}
TEST_F(ExecutorTestTurnRight, should_be_ok_by_3_turn_right)
{
	CommandTurnRight right;
	excutor.exec(right);
	excutor.exec(right);
	excutor.exec(right);

	ASSERT_EQ(Position(1, 2, Direction::NORTH), excutor.getPosition());
}
TEST_F(ExecutorTestTurnRight, should_be_ok_by_4_turn_right)
{
	excutor.exec(right);
	excutor.exec(right);
	excutor.exec(right);
	excutor.exec(right);

	ASSERT_EQ(Position(1, 2, Direction::EAST), excutor.getPosition());
}

////////////////////////////////////////////////////////////////////////////////////
struct ExecutorTestForward : public ExecutorTest
{
	virtual void SetUp()
	{
		excutor.config(Position(1, 2, Direction::EAST));
	}
protected:
	CommandForward forward;
};
TEST_F(ExecutorTestForward, should_be_ok_from_and_1_forward)
{
	excutor.exec(forward);

	ASSERT_EQ(Position(2, 2, Direction::EAST), excutor.getPosition());
}

TEST_F(ExecutorTestForward, should_be_ok_by_3_forward)
{
	excutor.config(Position(201, 322, Direction::SOUTH));

	excutor.exec(forward);
	excutor.exec(forward);
	excutor.exec(forward);

	ASSERT_EQ(Position(201, 319, Direction::SOUTH), excutor.getPosition());
}
////////////////////////////////////////////////////////////////////////////////////

struct ExecutorTestBackward : public ExecutorTest
{
	virtual void SetUp()
	{
		excutor.config(Position(1, 2, Direction::EAST));
	}
protected:
	CommandBackward backward;
};
TEST_F(ExecutorTestBackward, should_be_ok_by_1_backward)
{
	excutor.exec(backward);

	ASSERT_EQ(Position(0, 2, Direction::EAST), excutor.getPosition());
}
TEST_F(ExecutorTestBackward, should_be_ok_by_2_backward)
{
	excutor.config(Position(100, 200, Direction::NORTH));

	excutor.exec(backward);
	excutor.exec(backward);

	ASSERT_EQ(Position(100, 198, Direction::NORTH), excutor.getPosition());
}

////////////////////////////////////////////////////////////////////////////////////
struct ExecutorTestTurnround : public ExecutorTest
{
	virtual void SetUp()
	{
		excutor.config(Position(1, 2, Direction::EAST));
	}
protected:
	CommandTurnRound roundRound;
};
TEST_F(ExecutorTestTurnround, should_be_ok_by_1_trun_round)
{
	excutor.exec(roundRound);
	ASSERT_EQ(Position(1, 2, Direction::WEST), excutor.getPosition());
}