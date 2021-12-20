#include "pch.h"
#include "..\mp2-lab3-stack\TCalc.h"

TEST(TLCalc, can_create_calculator) {
	ASSERT_NO_THROW(TLCalc c);
}

TEST(TLCalc, can_set_and_get_expression) {
	TLCalc c;
	string expr = "3.2 + 3";
	string result;

	ASSERT_NO_THROW(c.set_expr(expr));
	ASSERT_NO_THROW(result = c.get_expr());

	EXPECT_EQ(result, expr);
}

TEST(TLCalc, can_check_brackets) {
	TLCalc c;
	c.set_expr("3 + 3");
	ASSERT_NO_THROW(c.check_expr());
}

TEST(TLCalc, can_detect_correct_brackets) {
	TLCalc c;
	c.set_expr("(3)");
	ASSERT_TRUE(c.check_expr());
}

TEST(TLCalc, can_detect_incorrect_brackets) {
	TLCalc c;
	c.set_expr("3)(");
	ASSERT_FALSE(c.check_expr());
}

TEST(TLCalc, can_convert_to_postfix_1) {
	TLCalc c;
	c.set_expr("3");

	ASSERT_NO_THROW(c.to_pstfix());
	EXPECT_EQ(c.get_pstfix(), "3");
}

TEST(TLCalc, can_convert_to_postfix_2) {
	TLCalc c;
	c.set_expr("1.3 + 3");

	ASSERT_NO_THROW(c.to_pstfix());
	EXPECT_EQ(c.get_pstfix(), "1.3 3 +");
}

TEST(TLCalc, can_convert_to_postfix_3) {
	TLCalc c;
	c.set_expr("(1 + 3) * 3.5");

	ASSERT_NO_THROW(c.to_pstfix());
	EXPECT_EQ(c.get_pstfix(), "1 3 + 3.5 *");
}

TEST(TLCalc, can_convert_to_postfix_4) {
	TLCalc c;
	c.set_expr("6 + 3.3^(4 / 2) - 4");

	ASSERT_NO_THROW(c.to_pstfix());
	EXPECT_EQ(c.get_pstfix(), "6 3.3 4 2 / ^ + 4 -");
}

TEST(TLCalc, can_add) {
	TLCalc c;
	c.set_expr("3.5 + 3");
	c.to_pstfix();

	EXPECT_EQ(c.calc_pstfix(), 3.5 + 3);
	EXPECT_EQ(c.calc(), 3.5 + 3);
}

TEST(TLCalc, can_substract) {
	TLCalc c;
	c.set_expr("3 - 5.0");
	c.to_pstfix();

	EXPECT_EQ(c.calc_pstfix(), 3 - 5.0);
	EXPECT_EQ(c.calc(), 3- 5.0);
}

TEST(TLCalc, can_multiply) {
	TLCalc c;
	c.set_expr("3 * 5");
	c.to_pstfix();

	EXPECT_EQ(c.calc_pstfix(), 3 * 5);
	EXPECT_EQ(c.calc(), 3 * 5);
}

TEST(TLCalc, can_divide) {
	TLCalc c;
	c.set_expr("9 / 3");
	c.to_pstfix();

	EXPECT_EQ(c.calc_pstfix(), 9 / 3);
	EXPECT_EQ(c.calc(), 9 / 3);
}

TEST(TLCalc, can_raise_to_the_power) {
	TLCalc c;
	c.set_expr("3^2");
	c.to_pstfix();

	EXPECT_EQ(c.calc_pstfix(), pow(3, 2));
	EXPECT_EQ(c.calc(), pow(3, 2));
}

TEST(TLCalc, can_calculate_complex_expression_1) {
	TLCalc c;
	c.set_expr("1 - 2.5 + 3 * 3^2");
	c.to_pstfix();

	EXPECT_EQ(c.calc_pstfix(), 1 - 2.5 + 3 * pow(3, 2));
	EXPECT_EQ(c.calc(), 1 - 2.5 + 3 * pow(3, 2));
}

TEST(TLCalc, can_calculate_complex_expression_2) {
	TLCalc c;
	c.set_expr("((2 + 10) / 3 * 4^2) - 2.5 + 4");
	c.to_pstfix();

	EXPECT_EQ(c.calc_pstfix(), ((2 + 10) / 3 * pow(4, 2)) - 2.5 + 4);
	EXPECT_EQ(c.calc(), ((2 + 10) / 3 * pow(4, 2)) - 2.5 + 4);
}

TEST(TLCalc, can_calculate_complex_expression_3) {
	TLCalc c;
	c.set_expr("((4 + 2) / (6 - 7.0 / 2.0) + 2 - 4 ^ (5 - 2))");
	c.to_pstfix();

	EXPECT_EQ(c.calc_pstfix(), (4 + 2) / (6 - 7.0 / 2.0) + 2 - pow(4, 5 - 2));
	EXPECT_EQ(c.calc(), (4 + 2) / (6 - 7.0 / 2.0) + 2 - pow(4, 5 - 2));
}