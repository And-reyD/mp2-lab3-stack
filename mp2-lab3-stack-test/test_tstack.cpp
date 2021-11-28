#include "pch.h"
#include "..\mp2-lab3-stack\TStack.h"
#include <iostream>

TEST(TStack, can_create_stack_with_positive_size) {
	ASSERT_NO_THROW(TStack<int> s(100));
}

TEST(TStack, cant_create_stack_with_negative_size) {
	ASSERT_ANY_THROW(TStack<int> s(-10));
}

TEST(TStack, cant_create_stack_with_zero_size) {
	ASSERT_ANY_THROW(TStack<int> s(0));
}

TEST(TStack, can_create_copied_stack) {
	TStack<int> st(10);
	ASSERT_NO_THROW(TStack<int> copy = st);
}

TEST(TStack, copied_stack_is_equal_to_source_one) {
	TStack<int> st(10);
	for (int i = 0; i < 10; i++) {
		st.push(i);
	}

	TStack<int> copy = st;
	EXPECT_EQ(copy, st);
}

TEST(TStack, copied_stack_has_its_own_memory) {
	TStack<int> st(10);
	for (int i = 0; i < 10; i++) {
		st.push(i);
	}

	TStack<int> copy = st;
	copy.clear();
	for (int i = 0; i < 10; i++) {
		copy.push(i + 1);
	}

	for (int i = 0; i < 10; i++) {
		EXPECT_NE(st.pop(), copy.pop());
	}
}

TEST(TStack, can_assign_stacks_of_equal_size) {
	TStack<int> st1(10);
	for (int i = 0; i < 10; i++) {
		st1.push(i);
	}

	TStack<int> st2(10);
	for (int i = 0; i < 10; i++) {
		st2.push(i * 2);
	}
	st2 = st1;

	EXPECT_EQ(st2, st1);
}

TEST(TStack, can_assign_stacks_of_different_size) {
	TStack<int> st1(10);
	for (int i = 0; i < 10; i++) {
		st1.push(i);
	}

	TStack<int> st2(15);
	for (int i = 0; i < 15; i++) {
		st2.push(i * 2);
	}
	st2 = st1;

	EXPECT_EQ(st2, st1);
}

TEST(TStack, can_assign_stack_to_itself) {
	TStack<int> st(10);
	for (int i = 0; i < 10; i++) {
		st.push(i);
	}
	st = st;

	EXPECT_EQ(st, st);
}

TEST(TStack, equal_stacks_comparison_returns_true) {
	TStack<int> st1(10);
	for (int i = 0; i < 10; i++) {
		st1.push(i);
	}

	TStack<int> st2(10);
	for (int i = 0; i < 10; i++) {
		st2.push(i);
	}

	EXPECT_EQ(st1, st2);
}

TEST(TStack, unequal_stacks_comparison_returns_false) {
	TStack<int> st1(10);
	for (int i = 0; i < 10; i++) {
		st1.push(i);
	}

	TStack<int> st2(10);
	for (int i = 0; i < 10; i++) {
		st2.push(i * 2);
	}

	EXPECT_NE(st1, st2);
}

TEST(TStack, stacks_with_different_sizes_are_not_equal) {
	TStack<int> st1(10);
	TStack<int> st2(20);

	EXPECT_NE(st1, st2);
}

TEST(TStack, empty_stack_isempty_true) {
	TStack<int> st(10);
	ASSERT_TRUE(st.empty());
}

TEST(TStack, not_empty_stack_isempty_false) {
	TStack<int> st(10);
	st.push(10);
	ASSERT_FALSE(st.empty());
}

TEST(TStack, full_stack_isfull_true) {
	TStack<int> st(10);
	for (int i = 0; i < 10; i++) {
		st.push(10);
	}

	ASSERT_TRUE(st.full());
}

TEST(TStack, not_full_stack_isfull_false) {
	TStack<int> st(10);
	ASSERT_FALSE(st.full());
}

TEST(TStack, can_push_and_pop_normally) {
	TStack<int> st(10);
	int elem = 10;
	int poped;

	ASSERT_NO_THROW(st.push(elem));
	ASSERT_NO_THROW(poped = st.pop());
	EXPECT_EQ(poped, elem);
}

TEST(TStack, cant_push_when_stack_is_full) {
	TStack<int> st(10);
	for (int i = 0; i < 10; i++) {
		st.push(i);
	}

	ASSERT_ANY_THROW(st.push(10));
}

TEST(TStack, cant_pop_when_stack_is_empty) {
	TStack<int> st(10);

	ASSERT_ANY_THROW(st.pop());
}

TEST(TStack, can_give_top) {
	TStack<int> st(10);
	st.push(10);
	EXPECT_EQ(st.top(), 10);
}

TEST(TStack, cant_give_top_when_stack_is_empty) {
	TStack<int> st(5);
	ASSERT_ANY_THROW(st.top());
}

TEST(TStack, can_clear_stack) {
	TStack<int> st(10);
	for (int i = 0; i < 10; i++) {
		st.push(i);
	}

	ASSERT_NO_THROW(st.clear());
}