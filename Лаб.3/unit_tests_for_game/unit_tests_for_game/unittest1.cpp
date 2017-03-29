#include "stdafx.h"
#include "CppUnitTest.h"
#include "catch.hpp"
#include "positions_of_game.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unit_tests_for_game
{		
	bool check_exp(int expect[2][13], int actual[2][13], int n1, int n2)
	{
		if (n1 != n2) return false;
		for (int i = 0; i < n1; i++)
		{
			if (expect[0][i] != actual[0][i]) return false;
			if (expect[1][i] != actual[1][i]) return false;
		}
		return true;
	}
	TEST_CASE("find_possible_steps_for_white_1")
	{
		current_positions *to_test = new current_positions();
		to_test->mtx[0][7] = 'q';
		to_test->mtx[2][5] = 'b';
		int expected[2][13]; memset(expected, 0, sizeof(expected));
		expected[0][0] = 3; expected[1][0] = 4;
		expected[0][1] = 4; expected[1][1] = 3;
		expected[0][2] = 5; expected[1][2] = 2;
		expected[0][3] = 6; expected[1][3] = 1;
		expected[0][4] = 7; expected[1][4] = 0;
		int num_ex = 5; int flag; 
		int real = to_test->find_possible_steps(to_test->mtx, 0, 7,flag);
		REQUIRE(check_exp(expected, to_test->posible_steps, num_ex, real) == true);
	}
	TEST_CASE("find_possible_steps_for_white_2")
	{
		current_positions *to_test = new current_positions();
		to_test->mtx[0][7] = 'q';
		int expected[2][13]; memset(expected, 0, sizeof(expected));
		expected[0][0] = 1; expected[1][0] = 6;
		expected[0][1] = 2; expected[1][1] = 5;
		expected[0][2] = 3; expected[1][2] = 4;
		expected[0][3] = 4; expected[1][3] = 3;
		expected[0][4] = 5; expected[1][4] = 2;
		expected[0][5] = 6; expected[1][5] = 1;
		expected[0][6] = 7; expected[1][6] = 0;
		int num_ex = 7; int flag;
		int real = to_test->find_possible_steps(to_test->mtx, 0, 7, flag);
		REQUIRE(check_exp(expected, to_test->posible_steps, num_ex, real) == true);
	}
	TEST_CASE("find_possible_steps_for_white_3")
	{
		current_positions *to_test = new current_positions();
		to_test->mtx[0][7] = 'q';
		to_test->mtx[3][4] = 'w';
		int expected[2][13]; memset(expected, 0, sizeof(expected));
		expected[0][0] = 1; expected[1][0] = 6;
		expected[0][1] = 2; expected[1][1] = 5;
		int num_ex = 2; int flag;
		int real = to_test->find_possible_steps(to_test->mtx, 0, 7, flag);
		REQUIRE(check_exp(expected, to_test->posible_steps, num_ex, real) == true);
	}
	TEST_CASE("find_possible_steps_for_white_4")
	{
		current_positions *to_test = new current_positions();
		to_test->mtx[7][0] = 'q';
		to_test->mtx[5][2] = 'b';
		int expected[2][13]; memset(expected, 0, sizeof(expected));
		expected[0][0] = 4; expected[1][0] = 3;
		expected[0][1] = 3; expected[1][1] = 4;
		expected[0][2] = 2; expected[1][2] = 5;
		expected[0][3] = 1; expected[1][3] = 6;
		expected[0][4] = 0; expected[1][4] = 7;
		int num_ex = 5; int flag;
		int real = to_test->find_possible_steps(to_test->mtx, 7, 0, flag);
		REQUIRE(check_exp(expected, to_test->posible_steps, num_ex, real) == true);
	}
	TEST_CASE("find_possible_steps_for_white_5")
	{
		current_positions *to_test = new current_positions();
		to_test->mtx[7][0] = 'q';
		int expected[2][13]; memset(expected, 0, sizeof(expected));
		expected[0][0] = 6; expected[1][0] = 1;
		expected[0][1] = 5; expected[1][1] = 2;
		expected[0][2] = 4; expected[1][2] = 3;
		expected[0][3] = 3; expected[1][3] = 4;
		expected[0][4] = 2; expected[1][4] = 5;
		expected[0][5] = 1; expected[1][5] = 6;
		expected[0][6] = 0; expected[1][6] = 7;
		int num_ex = 7; int flag;
		int real = to_test->find_possible_steps(to_test->mtx, 7, 0, flag);
		REQUIRE(check_exp(expected, to_test->posible_steps, num_ex, real) == true);
	}
	TEST_CASE("find_possible_steps_for_white_6")
	{
		current_positions *to_test = new current_positions();
		to_test->mtx[7][0] = 'q';
		to_test->mtx[4][3] = 'w';
		int expected[2][13]; memset(expected, 0, sizeof(expected));
		expected[0][0] = 6; expected[1][0] = 1;
		expected[0][1] = 5; expected[1][1] = 2;
		int num_ex = 2; int flag;
		int real = to_test->find_possible_steps(to_test->mtx, 7, 0, flag);
		REQUIRE(check_exp(expected, to_test->posible_steps, num_ex, real) == true);
	}
	TEST_CASE("find_possible_steps_for_white_7")
	{
		current_positions *to_test = new current_positions();
		to_test->mtx[6][7] = 'q';
		to_test->mtx[4][5] = 'b';
		int expected[2][13]; memset(expected, 0, sizeof(expected));
		expected[0][0] = 3; expected[1][0] = 4;
		expected[0][1] = 2; expected[1][1] = 3;
		expected[0][2] = 1; expected[1][2] = 2;
		expected[0][3] = 0; expected[1][3] = 1;
		int num_ex = 4; int flag;
		int real = to_test->find_possible_steps(to_test->mtx, 6, 7, flag);
		REQUIRE(check_exp(expected, to_test->posible_steps, num_ex, real) == true);
	}
	TEST_CASE("find_possible_steps_for_white_8")
	{
		current_positions *to_test = new current_positions();
		to_test->mtx[6][7] = 'q';
		int expected[2][13]; memset(expected, 0, sizeof(expected));
		expected[0][0] = 5; expected[1][0] = 6;
		expected[0][1] = 4; expected[1][1] = 5;
		expected[0][2] = 3; expected[1][2] = 4;
		expected[0][3] = 2; expected[1][3] = 3;
		expected[0][4] = 1; expected[1][4] = 2;
		expected[0][5] = 0; expected[1][5] = 1;
		expected[0][6] = 7; expected[1][6] = 6;
		int num_ex = 7; int flag;
		int real = to_test->find_possible_steps(to_test->mtx, 6, 7, flag);
		REQUIRE(check_exp(expected, to_test->posible_steps, num_ex, real) == true);
	}
	TEST_CASE("find_possible_steps_for_white_9")
	{
		current_positions *to_test = new current_positions();
		to_test->mtx[6][7] = 'q';
		to_test->mtx[3][4] = 'w';
		int expected[2][13]; memset(expected, 0, sizeof(expected));
		expected[0][0] = 5; expected[1][0] = 6;
		expected[0][1] = 4; expected[1][1] = 5;
		expected[0][2] = 7; expected[1][2] = 6;
		int num_ex = 3; int flag;
		int real = to_test->find_possible_steps(to_test->mtx, 6, 7, flag);
		REQUIRE(check_exp(expected, to_test->posible_steps, num_ex, real) == true);
	}
	TEST_CASE("find_possible_steps_for_white_10")
	{
		current_positions *to_test = new current_positions();
		to_test->mtx[0][1] = 'q';
		to_test->mtx[2][3] = 'b';
		int expected[2][13]; memset(expected, 0, sizeof(expected));
		expected[0][0] = 3; expected[1][0] = 4;
		expected[0][1] = 4; expected[1][1] = 5;
		expected[0][2] = 5; expected[1][2] = 6;
		expected[0][3] = 6; expected[1][3] = 7;
		int num_ex = 4; int flag;
		int real = to_test->find_possible_steps(to_test->mtx, 0, 1, flag);
		REQUIRE(check_exp(expected, to_test->posible_steps, num_ex, real) == true);
	}
	TEST_CASE("find_possible_steps_for_white_11")
	{
		current_positions *to_test = new current_positions();
		to_test->mtx[0][1] = 'q';
		int expected[2][13]; memset(expected, 0, sizeof(expected));
		expected[0][0] = 1; expected[1][0] = 2;
		expected[0][1] = 2; expected[1][1] = 3;
		expected[0][2] = 3; expected[1][2] = 4;
		expected[0][3] = 4; expected[1][3] = 5;
		expected[0][4] = 5; expected[1][4] = 6;
		expected[0][5] = 6; expected[1][5] = 7;
		expected[0][6] = 1; expected[1][6] = 0;
		int num_ex = 7; int flag;
		int real = to_test->find_possible_steps(to_test->mtx, 0, 1, flag);
		REQUIRE(check_exp(expected, to_test->posible_steps, num_ex, real) == true);
	}
	TEST_CASE("find_possible_steps_for_white_12")
	{
		current_positions *to_test = new current_positions();
		to_test->mtx[0][1] = 'q';
		to_test->mtx[3][4] = 'w';
		int expected[2][13]; memset(expected, 0, sizeof(expected));
		expected[0][0] = 1; expected[1][0] = 2;
		expected[0][1] = 2; expected[1][1] = 3;
		expected[0][2] = 1; expected[1][2] = 0;
		int num_ex = 3; int flag;
		int real = to_test->find_possible_steps(to_test->mtx, 0, 1, flag);
		REQUIRE(check_exp(expected, to_test->posible_steps, num_ex, real) == true);
	}
	TEST_CASE("find_possible_steps_for_white_13")
	{
		current_positions *to_test = new current_positions();
		to_test->mtx[0][7] = 'q';
		to_test->mtx[2][5] = 'b';
		to_test->mtx[1][6] = 'b';
		int expected[2][13]; memset(expected, 0, sizeof(expected));
		int num_ex = 0; int flag;
		int real = to_test->find_possible_steps(to_test->mtx, 0, 7, flag);
		REQUIRE(check_exp(expected, to_test->posible_steps, num_ex, real) == true);
	}
	TEST_CASE("find_possible_steps_for_simple_white_1")
	{
		current_positions *to_test = new current_positions();
		to_test->mtx[2][5] = 'w';
		to_test->mtx[1][4] = 'b';
		to_test->mtx[3][4] = 'b';
		to_test->mtx[1][6] = 'b';
		to_test->mtx[3][6] = 'b';
		int expected[2][13]; memset(expected, 0, sizeof(expected));
		expected[0][0] = 4; expected[1][0] = 3;
		expected[0][1] = 0; expected[1][1] = 3;
		expected[0][2] = 4; expected[1][2] = 7;
		expected[0][3] = 0; expected[1][3] = 7;
		int num_ex = 4; int flag;
		int real = to_test->find_possible_steps(to_test->mtx, 2, 5, flag);
		REQUIRE(check_exp(expected, to_test->posible_steps, num_ex, real) == true);
	}
	TEST_CASE("find_possible_steps_for_simple_white_2")
	{
		current_positions *to_test = new current_positions();
		to_test->mtx[2][5] = 'w';
		int expected[2][13]; memset(expected, 0, sizeof(expected));
		expected[0][0] = 1; expected[1][0] = 4;
		expected[0][1] = 3; expected[1][1] = 4;
		int num_ex = 2; int flag;
		int real = to_test->find_possible_steps(to_test->mtx, 2, 5, flag);
		REQUIRE(check_exp(expected, to_test->posible_steps, num_ex, real) == true);
	}
	TEST_CASE("find_possible_steps_for_simple_white_3")
	{
		current_positions *to_test = new current_positions();
		to_test->mtx[2][5] = 'w';
		to_test->mtx[1][4] = 'w';
		int expected[2][13]; memset(expected, 0, sizeof(expected));
		expected[0][0] = 3; expected[1][0] = 4;
		int num_ex = 1; int flag;
		int real = to_test->find_possible_steps(to_test->mtx, 2, 5, flag);
		REQUIRE(check_exp(expected, to_test->posible_steps, num_ex, real) == true);
	}
	TEST_CASE("find_possible_steps_for_simple_white_4")
	{
		current_positions *to_test = new current_positions();
		to_test->mtx[2][5] = 'w';
		to_test->mtx[1][4] = 'w';
		to_test->mtx[3][4] = 'w';
		int expected[2][13]; memset(expected, 0, sizeof(expected));
		int num_ex = 0; int flag;
		int real = to_test->find_possible_steps(to_test->mtx, 2, 5, flag);
		REQUIRE(check_exp(expected, to_test->posible_steps, num_ex, real) == true);
	}
	TEST_CASE("find_possible_steps_for_black_1")
	{
		current_positions *to_test = new current_positions();
		to_test->mtx[0][7] = 'd';
		to_test->mtx[2][5] = 'q';
		int expected[2][13]; memset(expected, 0, sizeof(expected));
		expected[0][0] = 3; expected[1][0] = 4;
		expected[0][1] = 4; expected[1][1] = 3;
		expected[0][2] = 5; expected[1][2] = 2;
		expected[0][3] = 6; expected[1][3] = 1;
		expected[0][4] = 7; expected[1][4] = 0;
		int num_ex = 5; int flag;
		int real = to_test->find_comp_possible_steps(to_test->mtx, 0, 7, flag);
		REQUIRE(check_exp(expected, to_test->comp_posible_steps, num_ex, real) == true);
	}
	TEST_CASE("find_possible_steps_for_black_2")
	{
		current_positions *to_test = new current_positions();
		to_test->mtx[0][7] = 'd';
		int expected[2][13]; memset(expected, 0, sizeof(expected));
		expected[0][0] = 1; expected[1][0] = 6;
		expected[0][1] = 2; expected[1][1] = 5;
		expected[0][2] = 3; expected[1][2] = 4;
		expected[0][3] = 4; expected[1][3] = 3;
		expected[0][4] = 5; expected[1][4] = 2;
		expected[0][5] = 6; expected[1][5] = 1;
		expected[0][6] = 7; expected[1][6] = 0;
		int num_ex = 7; int flag;
		int real = to_test->find_comp_possible_steps(to_test->mtx, 0, 7, flag);
		REQUIRE(check_exp(expected, to_test->comp_posible_steps, num_ex, real) == true);
	}
	TEST_CASE("find_possible_steps_for_black_3")
	{
		current_positions *to_test = new current_positions();
		to_test->mtx[0][7] = 'd';
		to_test->mtx[3][4] = 'b';
		int expected[2][13]; memset(expected, 0, sizeof(expected));
		expected[0][0] = 1; expected[1][0] = 6;
		expected[0][1] = 2; expected[1][1] = 5;
		int num_ex = 2; int flag;
		int real = to_test->find_comp_possible_steps(to_test->mtx, 0, 7, flag);
		REQUIRE(check_exp(expected, to_test->comp_posible_steps, num_ex, real) == true);
	}
	TEST_CASE("find_possible_steps_for_black_4")
	{
		current_positions *to_test = new current_positions();
		to_test->mtx[7][0] = 'd';
		to_test->mtx[5][2] = 'w';
		int expected[2][13]; memset(expected, 0, sizeof(expected));
		expected[0][0] = 4; expected[1][0] = 3;
		expected[0][1] = 3; expected[1][1] = 4;
		expected[0][2] = 2; expected[1][2] = 5;
		expected[0][3] = 1; expected[1][3] = 6;
		expected[0][4] = 0; expected[1][4] = 7;
		int num_ex = 5; int flag;
		int real = to_test->find_comp_possible_steps(to_test->mtx, 7, 0, flag);
		REQUIRE(check_exp(expected, to_test->comp_posible_steps, num_ex, real) == true);
	}
	TEST_CASE("find_possible_steps_for_black_5")
	{
		current_positions *to_test = new current_positions();
		to_test->mtx[7][0] = 'd';
		int expected[2][13]; memset(expected, 0, sizeof(expected));
		expected[0][0] = 6; expected[1][0] = 1;
		expected[0][1] = 5; expected[1][1] = 2;
		expected[0][2] = 4; expected[1][2] = 3;
		expected[0][3] = 3; expected[1][3] = 4;
		expected[0][4] = 2; expected[1][4] = 5;
		expected[0][5] = 1; expected[1][5] = 6;
		expected[0][6] = 0; expected[1][6] = 7;
		int num_ex = 7; int flag;
		int real = to_test->find_comp_possible_steps(to_test->mtx, 7, 0, flag);
		REQUIRE(check_exp(expected, to_test->comp_posible_steps, num_ex, real) == true);
	}
	TEST_CASE("find_possible_steps_for_black_6")
	{
		current_positions *to_test = new current_positions();
		to_test->mtx[7][0] = 'd';
		to_test->mtx[4][3] = 'b';
		int expected[2][13]; memset(expected, 0, sizeof(expected));
		expected[0][0] = 6; expected[1][0] = 1;
		expected[0][1] = 5; expected[1][1] = 2;
		int num_ex = 2; int flag;
		int real = to_test->find_comp_possible_steps(to_test->mtx, 7, 0, flag);
		REQUIRE(check_exp(expected, to_test->comp_posible_steps, num_ex, real) == true);
	}
	TEST_CASE("find_possible_steps_for_black_7")
	{
		current_positions *to_test = new current_positions();
		to_test->mtx[6][7] = 'd';
		to_test->mtx[4][5] = 'w';
		int expected[2][13]; memset(expected, 0, sizeof(expected));
		expected[0][0] = 3; expected[1][0] = 4;
		expected[0][1] = 2; expected[1][1] = 3;
		expected[0][2] = 1; expected[1][2] = 2;
		expected[0][3] = 0; expected[1][3] = 1;
		int num_ex = 4; int flag;
		int real = to_test->find_comp_possible_steps(to_test->mtx, 6, 7, flag);
		REQUIRE(check_exp(expected, to_test->comp_posible_steps, num_ex, real) == true);
	}
	TEST_CASE("find_possible_steps_for_black_8")
	{
		current_positions *to_test = new current_positions();
		to_test->mtx[6][7] = 'd';
		int expected[2][13]; memset(expected, 0, sizeof(expected));
		expected[0][0] = 5; expected[1][0] = 6;
		expected[0][1] = 4; expected[1][1] = 5;
		expected[0][2] = 3; expected[1][2] = 4;
		expected[0][3] = 2; expected[1][3] = 3;
		expected[0][4] = 1; expected[1][4] = 2;
		expected[0][5] = 0; expected[1][5] = 1;
		expected[0][6] = 7; expected[1][6] = 6;
		int num_ex = 7; int flag;
		int real = to_test->find_comp_possible_steps(to_test->mtx, 6, 7, flag);
		REQUIRE(check_exp(expected, to_test->comp_posible_steps, num_ex, real) == true);
	}
	TEST_CASE("find_possible_steps_for_black_9")
	{
		current_positions *to_test = new current_positions();
		to_test->mtx[6][7] = 'd';
		to_test->mtx[3][4] = 'b';
		int expected[2][13]; memset(expected, 0, sizeof(expected));
		expected[0][0] = 5; expected[1][0] = 6;
		expected[0][1] = 4; expected[1][1] = 5;
		expected[0][2] = 7; expected[1][2] = 6;
		int num_ex = 3; int flag;
		int real = to_test->find_comp_possible_steps(to_test->mtx, 6, 7, flag);
		REQUIRE(check_exp(expected, to_test->comp_posible_steps, num_ex, real) == true);
	}
	TEST_CASE("find_possible_steps_for_black_10")
	{
		current_positions *to_test = new current_positions();
		to_test->mtx[0][1] = 'd';
		to_test->mtx[2][3] = 'w';
		int expected[2][13]; memset(expected, 0, sizeof(expected));
		expected[0][0] = 3; expected[1][0] = 4;
		expected[0][1] = 4; expected[1][1] = 5;
		expected[0][2] = 5; expected[1][2] = 6;
		expected[0][3] = 6; expected[1][3] = 7;
		int num_ex = 4; int flag;
		int real = to_test->find_comp_possible_steps(to_test->mtx, 0, 1, flag);
		REQUIRE(check_exp(expected, to_test->comp_posible_steps, num_ex, real) == true);
	}
	TEST_CASE("find_possible_steps_for_black_11")
	{
		current_positions *to_test = new current_positions();
		to_test->mtx[0][1] = 'd';
		int expected[2][13]; memset(expected, 0, sizeof(expected));
		expected[0][0] = 1; expected[1][0] = 2;
		expected[0][1] = 2; expected[1][1] = 3;
		expected[0][2] = 3; expected[1][2] = 4;
		expected[0][3] = 4; expected[1][3] = 5;
		expected[0][4] = 5; expected[1][4] = 6;
		expected[0][5] = 6; expected[1][5] = 7;
		expected[0][6] = 1; expected[1][6] = 0;
		int num_ex = 7; int flag;
		int real = to_test->find_comp_possible_steps(to_test->mtx, 0, 1, flag);
		REQUIRE(check_exp(expected, to_test->comp_posible_steps, num_ex, real) == true);
	}
	TEST_CASE("find_possible_steps_for_black_12")
	{
		current_positions *to_test = new current_positions();
		to_test->mtx[0][1] = 'd';
		to_test->mtx[3][4] = 'b';
		int expected[2][13]; memset(expected, 0, sizeof(expected));
		expected[0][0] = 1; expected[1][0] = 2;
		expected[0][1] = 2; expected[1][1] = 3;
		expected[0][2] = 1; expected[1][2] = 0;
		int num_ex = 3; int flag;
		int real = to_test->find_comp_possible_steps(to_test->mtx, 0, 1, flag);
		REQUIRE(check_exp(expected, to_test->comp_posible_steps, num_ex, real) == true);
	}
	TEST_CASE("find_possible_steps_for_black_13")
	{
		current_positions *to_test = new current_positions();
		to_test->mtx[0][7] = 'd';
		to_test->mtx[2][5] = 'w';
		to_test->mtx[1][6] = 'w';
		int expected[2][13]; memset(expected, 0, sizeof(expected));
		int num_ex = 0; int flag;
		int real = to_test->find_comp_possible_steps(to_test->mtx, 0, 7, flag);
		REQUIRE(check_exp(expected, to_test->comp_posible_steps, num_ex, real) == true);
	}
	TEST_CASE("find_possible_steps_for_simple_black_1")
	{
		current_positions *to_test = new current_positions();
		to_test->mtx[2][5] = 'b';
		to_test->mtx[1][4] = 'w';
		to_test->mtx[3][4] = 'w';
		to_test->mtx[1][6] = 'w';
		to_test->mtx[3][6] = 'w';
		int expected[2][13]; memset(expected, 0, sizeof(expected));
		expected[0][0] = 4; expected[1][0] = 3;
		expected[0][1] = 0; expected[1][1] = 3;
		expected[0][2] = 4; expected[1][2] = 7;
		expected[0][3] = 0; expected[1][3] = 7;
		int num_ex = 4; int flag;
		int real = to_test->find_comp_possible_steps(to_test->mtx, 2, 5, flag);
		REQUIRE(check_exp(expected, to_test->comp_posible_steps, num_ex, real) == true);
	}
	TEST_CASE("find_possible_steps_for_simple_black_2")
	{
		current_positions *to_test = new current_positions();
		to_test->mtx[2][5] = 'b';
		int expected[2][13]; memset(expected, 0, sizeof(expected));
		expected[0][0] = 1; expected[1][0] = 6;
		expected[0][1] = 3; expected[1][1] = 6;
		int num_ex = 2; int flag;
		int real = to_test->find_comp_possible_steps(to_test->mtx, 2, 5, flag);
		REQUIRE(check_exp(expected, to_test->comp_posible_steps, num_ex, real) == true);
	}
	TEST_CASE("find_possible_steps_for_simple_black_3")
	{
		current_positions *to_test = new current_positions();
		to_test->mtx[2][5] = 'b';
		to_test->mtx[1][6] = 'b';
		int expected[2][13]; memset(expected, 0, sizeof(expected));
		expected[0][0] = 3; expected[1][0] = 6;
		int num_ex = 1; int flag;
		int real = to_test->find_comp_possible_steps(to_test->mtx, 2, 5, flag);
		REQUIRE(check_exp(expected, to_test->comp_posible_steps, num_ex, real) == true);
	}
	TEST_CASE("find_possible_steps_for_simple_black_4")
	{
		current_positions *to_test = new current_positions();
		to_test->mtx[2][5] = 'b';
		to_test->mtx[1][6] = 'b';
		to_test->mtx[3][6] = 'b';
		int expected[2][13]; memset(expected, 0, sizeof(expected));
		int num_ex = 0; int flag;
		int real = to_test->find_comp_possible_steps(to_test->mtx, 2, 5, flag);
		REQUIRE(check_exp(expected, to_test->comp_posible_steps, num_ex, real) == true);
	}
	TEST_CASE("find_dif_1")
	{
		current_positions *to_test = new current_positions();
		char mtx[8][8];
		mtx[0][1] = 'b';
		mtx[0][3] = 'b';
		mtx[0][5] = 'b';
		mtx[0][7] = 'q';
		mtx[7][0] = 'w';
		mtx[7][2] = 'w';
		mtx[7][4] = 'd';
		mtx[7][6] = 'd';
		int real = to_test->find_dif(mtx);
		REQUIRE(real == 5);
	}
	TEST_CASE("get_step1")
	{
		current_positions *to_test = new current_positions();
		char mtx[8][8];
		to_test->mtx[0][1] = 'b'; to_test->mtx[0][3] = 'b'; to_test->mtx[0][5] = 'b'; to_test->mtx[0][7] = 'b';
		to_test->mtx[1][0] = 'b'; to_test->mtx[1][2] = 'b'; to_test->mtx[1][4] = 'b'; to_test->mtx[1][6] = 'b';
		to_test->mtx[2][1] = 'b'; to_test->mtx[2][3] = 'b'; to_test->mtx[2][5] = 'b'; to_test->mtx[2][7] = 'b';
		to_test->mtx[5][0] = 'w'; to_test->mtx[5][2] = 'w'; to_test->mtx[5][4] = 'w'; to_test->mtx[5][6] = 'w';
		to_test->mtx[6][1] = 'w'; to_test->mtx[6][3] = 'w'; to_test->mtx[6][5] = 'w'; to_test->mtx[6][7] = 'w';
		to_test->mtx[7][0] = 'w'; to_test->mtx[7][2] = 'w'; to_test->mtx[7][4] = 'w'; to_test->mtx[7][6] = 'w';
		current_positions::comp_step expected; int beat = 0;
		expected.x0 = 2; expected.y0 = 1; expected.pos = 0; expected.beat = 0;
		to_test->c_step = to_test->get_comp_step(beat, -1, -1);
		int res=1; 
		if (expected.x0 != to_test->c_step.x0) res = -1;
		if (expected.y0 != to_test->c_step.y0) res = -1;
		if (expected.pos != to_test->c_step.pos) res = -1;
		if (expected.beat != to_test->c_step.beat) res = -1;
		REQUIRE(res==1);
	}
	TEST_CASE("get_step2")
	{
		current_positions *to_test = new current_positions();
		char mtx[8][8];
		to_test->mtx[0][1] = 'b'; to_test->mtx[0][3] = 'b'; to_test->mtx[0][5] = 'b'; to_test->mtx[0][7] = 'b';
		to_test->mtx[2][1] = 'b'; to_test->mtx[1][2] = 'b'; to_test->mtx[1][4] = 'b'; to_test->mtx[1][6] = 'b';
		to_test->mtx[3][0] = 'b'; to_test->mtx[2][3] = 'b'; to_test->mtx[2][5] = 'b'; to_test->mtx[2][7] = 'b';
		to_test->mtx[3][2] = 'w'; to_test->mtx[5][2] = 'w'; to_test->mtx[5][4] = 'w'; to_test->mtx[4][7] = 'w';
		to_test->mtx[6][1] = 'w'; to_test->mtx[6][3] = 'w'; to_test->mtx[6][5] = 'w'; to_test->mtx[6][7] = 'w';
		to_test->mtx[7][0] = 'w'; to_test->mtx[7][2] = 'w'; to_test->mtx[7][4] = 'w'; to_test->mtx[7][6] = 'w';
		current_positions::comp_step expected; int beat = 0;
		expected.x0 = 2; expected.y0 = 3; expected.pos = 0; expected.beat = 1;
		to_test->c_step = to_test->get_comp_step(beat, -1, -1);
		int res = 1;
		if (expected.x0 != to_test->c_step.x0) res = -1;
		if (expected.y0 != to_test->c_step.y0) res = -1;
		if (expected.pos != to_test->c_step.pos) res = -1;
		if (expected.beat != to_test->c_step.beat) res = -1;
		REQUIRE(res == 1);
	}
}