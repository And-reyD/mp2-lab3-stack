#include "pch.h"
#include "..\mp2-lab3-stack\TCalc.h"

TEST(TCalc, can_create_calculator) {
	ASSERT_NO_THROW(TCalc c);
}

TEST(TCalc, can_set_and_get_expression) {
	TCalc c;
	string expr = "3.2 + 3";
	string result;

	ASSERT_NO_THROW(c.set_expr(expr));
	ASSERT_NO_THROW(result = c.get_expr());

	EXPECT_EQ(result, expr);
}

TEST(TCalc, can_check_brackets) {
	TCalc c;
	c.set_expr("3 + 3");
	ASSERT_NO_THROW(c.check_expr());
}

TEST(TCalc, can_detect_correct_brackets) {
	TCalc c;
	c.set_expr("(3)");
	ASSERT_TRUE(c.check_expr());
}

TEST(TCalc, can_detect_incorrect_brackets) {
	TCalc c;
	c.set_expr("3)(");
	ASSERT_FALSE(c.check_expr());
}

TEST(TCalc, can_convert_to_postfix_1) {
	TCalc c;
	c.set_expr("3");

	ASSERT_NO_THROW(c.to_pstfix());
	EXPECT_EQ(c.get_pstfix(), "3");
}

TEST(TCalc, can_convert_to_postfix_2) {
	TCalc c;
	c.set_expr("1.3 + 3");

	ASSERT_NO_THROW(c.to_pstfix());
	EXPECT_EQ(c.get_pstfix(), "1.3 3 +");
}

TEST(TCalc, can_convert_to_postfix_3) {
	TCalc c;
	c.set_expr("(1 + 3) * 3.5");

	ASSERT_NO_THROW(c.to_pstfix());
	EXPECT_EQ(c.get_pstfix(), "1 3 + 3.5 *");
}

TEST(TCalc, can_convert_to_postfix_4) {
	TCalc c;
	c.set_expr("6 + 3.3^(4 / 2) - 4");

	ASSERT_NO_THROW(c.to_pstfix());
	EXPECT_EQ(c.get_pstfix(), "6 3.3 4 2 / ^ + 4 -");
}

TEST(TCalc, can_add) {
	TCalc c;
	c.set_expr("3.5 + 3");
	c.to_pstfix();

	EXPECT_EQ(c.calc_pstfix(), 3.5 + 3);
	EXPECT_EQ(c.calc(), 3.5 + 3);
}

TEST(TCalc, can_substract) {
	TCalc c;
	c.set_expr("3 - 5.0");
	c.to_pstfix();

	EXPECT_EQ(c.calc_pstfix(), 3 - 5.0);
	EXPECT_EQ(c.calc(), 3- 5.0);
}

TEST(TCalc, can_multiply) {
	TCalc c;
	c.set_expr("3 * 5");
	c.to_pstfix();

	EXPECT_EQ(c.calc_pstfix(), 3 * 5);
	EXPECT_EQ(c.calc(), 3 * 5);
}

TEST(TCalc, can_divide) {
	TCalc c;
	c.set_expr("9 / 3");
	c.to_pstfix();

	EXPECT_EQ(c.calc_pstfix(), 9 / 3);
	EXPECT_EQ(c.calc(), 9 / 3);
}

TEST(TCalc, can_raise_to_the_power) {
	TCalc c;
	c.set_expr("3^2");
	c.to_pstfix();

	EXPECT_EQ(c.calc_pstfix(), pow(3, 2));
	EXPECT_EQ(c.calc(), pow(3, 2));
}

TEST(TCalc, can_calculate_complex_expression_1) {
	TCalc c;
	c.set_expr("1 - 2.5 + 3 * 3^2");
	c.to_pstfix();

	EXPECT_EQ(c.calc_pstfix(), 1 - 2.5 + 3 * pow(3, 2));
	EXPECT_EQ(c.calc(), 1 - 2.5 + 3 * pow(3, 2));
}

TEST(TCalc, can_calculate_complex_expression_2) {
	TCalc c;
	c.set_expr("((2 + 10) / 3 * 4^2) - 2.5 + 4");
	c.to_pstfix();

	EXPECT_EQ(c.calc_pstfix(), ((2 + 10) / 3 * pow(4, 2)) - 2.5 + 4);
	EXPECT_EQ(c.calc(), ((2 + 10) / 3 * pow(4, 2)) - 2.5 + 4);
}

TEST(TCalc, can_calculate_complex_expression_3) {
	TCalc c;
	c.set_expr("((4 + 2) / (6 - 7.0 / 2.0) + 2 - 4 ^ (5 - 2))");
	c.to_pstfix();

	EXPECT_EQ(c.calc_pstfix(), (4 + 2) / (6 - 7.0 / 2.0) + 2 - pow(4, 5 - 2));
	EXPECT_EQ(c.calc(), (4 + 2) / (6 - 7.0 / 2.0) + 2 - pow(4, 5 - 2));
}