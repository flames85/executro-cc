#include <gtest/gtest.h>
#include "executor.h"
#include "command.h"


TEST(ExecutorTest, should_be_ok_by_init)
{
	Executor excutor;
	ASSERT_EQ(Position(0, 0, Direction::NORTH), excutor.getPosition());
}


TEST(ExecutorTest, should_be_ok_by_config)
{
	Executor excutor;
	excutor.config(Position(1, 2, Direction::EAST));
	ASSERT_EQ(Position(1, 2, Direction::EAST), excutor.getPosition());
}


TEST(ExecutorTest, should_be_ok_by_turn_left)
{
	Executor excutor;
	excutor.config(Position(1, 2, Direction::EAST));

	CommandTurnLeft left;
	excutor.exec(&left);

	ASSERT_EQ(Position(1, 2, Direction::NORTH), excutor.getPosition());
}

TEST(ExecutorTest, should_be_ok_by_3_turn_left)
{
	Executor excutor;
	excutor.config(Position(1, 2, Direction::EAST));

	CommandTurnLeft left;
	excutor.exec(&left);
	excutor.exec(&left);
	excutor.exec(&left);

	ASSERT_EQ(Position(1, 2, Direction::SOUTH), excutor.getPosition());
}

TEST(ExecutorTest, should_be_ok_by_4_turn_left)
{
	Executor excutor;
	excutor.config(Position(1, 2, Direction::EAST));

	CommandTurnLeft left;
	excutor.exec(&left);
	excutor.exec(&left);
	excutor.exec(&left);
	excutor.exec(&left);


	ASSERT_EQ(Position(1, 2, Direction::EAST), excutor.getPosition());
}


TEST(ExecutorTest, should_be_ok_by_1_turn_right)
{
	Executor excutor;
	excutor.config(Position(1, 2, Direction::EAST));

	CommandTurnRight right;

	excutor.exec(&right);

	ASSERT_EQ(Position(1, 2, Direction::SOUTH), excutor.getPosition());
}

TEST(ExecutorTest, should_be_ok_by_3_turn_right)
{
	Executor excutor;
	excutor.config(Position(1, 2, Direction::EAST));

	CommandTurnRight right;
	excutor.exec(&right);
	excutor.exec(&right);
	excutor.exec(&right);

	ASSERT_EQ(Position(1, 2, Direction::NORTH), excutor.getPosition());
}

TEST(ExecutorTest, should_be_ok_by_4_turn_right)
{
	Executor excutor;
	excutor.config(Position(1, 2, Direction::EAST));

	CommandTurnRight right;
	excutor.exec(&right);
	excutor.exec(&right);
	excutor.exec(&right);
	excutor.exec(&right);

	ASSERT_EQ(Position(1, 2, Direction::EAST), excutor.getPosition());
}


TEST(ExecutorTest, should_be_ok_from_EAST_and_1_forward)
{
	Executor excutor;
	excutor.config(Position(1, 2, Direction::EAST));

	CommandForward forward;
	excutor.exec(&forward);

	ASSERT_EQ(Position(2, 2, Direction::EAST), excutor.getPosition());
}

TEST(ExecutorTest, should_be_ok_by_3_forward)
{
	Executor excutor;
	excutor.config(Position(201, 322, Direction::SOUTH));

	CommandForward forward;
	excutor.exec(&forward);
	excutor.exec(&forward);
	excutor.exec(&forward);

	ASSERT_EQ(Position(201, 319, Direction::SOUTH), excutor.getPosition());
}


TEST(ExecutorTest, should_be_ok_by_1_backward)
{
	Executor excutor;
	excutor.config(Position(1, 2, Direction::EAST));

	CommandBackward backward;
	excutor.exec(&backward);

	ASSERT_EQ(Position(0, 2, Direction::EAST), excutor.getPosition());
}


TEST(ExecutorTest, should_be_ok_by_2_backward)
{
	Executor excutor;
	excutor.config(Position(100, 200, Direction::NORTH));

	CommandBackward backward;
	excutor.exec(&backward);
	excutor.exec(&backward);

	ASSERT_EQ(Position(100, 198, Direction::NORTH), excutor.getPosition());
}


TEST(ExecutorTest, should_be_ok_by_1_trun_round)
{
	Executor excutor;
	excutor.config(Position(1, 2, Direction::EAST));

	CommandTurnRound rurnRound;
	excutor.exec(&rurnRound);

	ASSERT_EQ(Position(1, 2, Direction::WEST), excutor.getPosition());
}