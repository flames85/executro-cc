#include <gtest/gtest.h>
#include "executor.h"
#include "command.h"


TEST(ExecutorTest, should_be_ok_by_init)
{
	Executor excutor;
	ASSERT_EQ(Position(0, 0, NORTH), excutor.getPosition());
}


TEST(ExecutorTest, should_be_ok_by_config)
{
	Executor excutor;
	excutor.config(Position(1, 2, EAST));
	ASSERT_EQ(Position(1, 2, EAST), excutor.getPosition());
}


TEST(ExecutorTest, should_be_ok_by_turn_left)
{
	Executor excutor;
	excutor.config(Position(1, 2, EAST));

	CommandTurnLeft left;
	excutor.exec(&left);

	ASSERT_EQ(Position(1, 2, NORTH), excutor.getPosition());
}

TEST(ExecutorTest, should_be_ok_by_3_turn_left)
{
	Executor excutor;
	excutor.config(Position(1, 2, EAST));

	CommandTurnLeft left;
	excutor.exec(&left);
	excutor.exec(&left);
	excutor.exec(&left);

	ASSERT_EQ(Position(1, 2, SOUTH), excutor.getPosition());
}

TEST(ExecutorTest, should_be_ok_by_4_turn_left)
{
	Executor excutor;
	excutor.config(Position(1, 2, EAST));

	CommandTurnLeft left;
	excutor.exec(&left);
	excutor.exec(&left);
	excutor.exec(&left);
	excutor.exec(&left);


	ASSERT_EQ(Position(1, 2, EAST), excutor.getPosition());
}


TEST(ExecutorTest, should_be_ok_by_1_turn_right)
{
	Executor excutor;
	excutor.config(Position(1, 2, EAST));

	CommandTurnRight right;

	excutor.exec(&right);

	ASSERT_EQ(Position(1, 2, SOUTH), excutor.getPosition());
}

TEST(ExecutorTest, should_be_ok_by_3_turn_right)
{
	Executor excutor;
	excutor.config(Position(1, 2, EAST));

	CommandTurnRight right;
	excutor.exec(&right);
	excutor.exec(&right);
	excutor.exec(&right);

	ASSERT_EQ(Position(1, 2, NORTH), excutor.getPosition());
}

TEST(ExecutorTest, should_be_ok_by_4_turn_right)
{
	Executor excutor;
	excutor.config(Position(1, 2, EAST));

	CommandTurnRight right;
	excutor.exec(&right);
	excutor.exec(&right);
	excutor.exec(&right);
	excutor.exec(&right);

	ASSERT_EQ(Position(1, 2, EAST), excutor.getPosition());
}


TEST(ExecutorTest, should_be_ok_by_1_forward)
{
	Executor excutor;
	excutor.config(Position(1, 2, EAST));

	CommandForward forward;
	excutor.exec(&forward);

	ASSERT_EQ(Position(2, 2, EAST), excutor.getPosition());
}


TEST(ExecutorTest, should_be_ok_by_1_backward)
{
	Executor excutor;
	excutor.config(Position(1, 2, EAST));

	CommandBackward backward;
	excutor.exec(&backward);

	ASSERT_EQ(Position(0, 2, EAST), excutor.getPosition());
}


TEST(ExecutorTest, should_be_ok_by_1_trun_round)
{
	Executor excutor;
	excutor.config(Position(1, 2, EAST));

	CommandTurnRound rurnRound;
	excutor.exec(&rurnRound);

	ASSERT_EQ(Position(1, 2, WEST), excutor.getPosition());
}