#pragma once
#include <gtest.h>
#include <List.h>
#include "Polynom.h";
int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}