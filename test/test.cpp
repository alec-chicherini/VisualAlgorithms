#include "pch.h"

#include "../Real_World_Algorithms/Real_World_Algorithms.h"

#include <timedelay.h> //https://github.com/ikvasir/timedelay
#include <timedelay.cpp>

/// @brief test for part 1 exesice number one - stack data structure
    TEST(RealWorldAlgorithm, part1exercize1)
    {
        constexpr size_t STACK_MAX_SIZE = 3;

        ASSERT_NO_THROW(ouMyStack<int> stack(STACK_MAX_SIZE));
        ouMyStack<int> stack(STACK_MAX_SIZE);
        EXPECT_EQ(0, stack.size());


        stack.push(11);
        stack.push(12);
        EXPECT_EQ(2, stack.size());
        EXPECT_EQ(12, stack.top());
        EXPECT_EQ("[ 11 12 ]", stack.print());

        stack.push(1);
        stack.push(2);
        EXPECT_EQ(3, stack.size());
        EXPECT_EQ(1, stack.top());
        EXPECT_EQ("[ 11 12 1 ]", stack.print());

        stack.pop();
        stack.pop();
        stack.pop();
        stack.pop();

        EXPECT_EQ(0, stack.size());
        EXPECT_EQ("[ empty ]", stack.print());

        stack.push(3);
        stack.push(4);
        stack.push(5);
        stack.reverse();
        EXPECT_EQ("[ 5 4 3 ]", stack.print());
    };

    TEST(RealWorldAlgorithm, part1exercize2)
    {
        timedelay T_D;

        constexpr size_t ARRAY_SIZE = 10000;
        ASSERT_NO_THROW((GenerateRandomArray<int, ARRAY_SIZE>)());
        std::array<int, ARRAY_SIZE>* quotes1 = GenerateRandomArray<int, ARRAY_SIZE>();

        T_D.addTimer("SimpleStockSpan");
        ASSERT_NO_THROW(*SimpleStockSpan(quotes1));
        auto simple_stock_time= T_D.readTimer("SimpleStockSpan");

        T_D.addTimer("StackStockSpan");
        ASSERT_NO_THROW(*StackStockSpan(quotes1));
        auto stack_stock_time = T_D.readTimer("StackStockSpan");

        //expect that time execution of less efficency algoritm higher
        EXPECT_GT(simple_stock_time, stack_stock_time);
    }

    TEST(RealWorldAlgorithm, part1exercize3)
    {

        ASSERT_NO_THROW(Calc calculator1, calculator2, c3);

        Calc calculator1, calculator2, c3;
        ASSERT_NO_THROW(calculator1.getExpression("1 2 3 * +"));
        ASSERT_NO_THROW(calculator1.execute());

        calculator1.getExpression("1 2 3 * +");
        calculator1.execute();
        EXPECT_EQ(7,calculator1.result());

        calculator2.getExpression("1 2 3 * + 2 - ");
        calculator2.execute();
        EXPECT_EQ(5, calculator2.result());

        c3.getExpression("2 2 + 3 3 + *");
        c3.execute();
        EXPECT_EQ(24, c3.result());
    }

    TEST(RealWorldAlgorithm, part1exercize4)
    {
        ASSERT_NO_THROW(
        bracers br, br2, br3, br4, br5;
        br.getExpression("(()()()())");
        br.checkBracers();
        );

        bracers br, br2, br3, br4, br5,br6,br7;

        br.getExpression("(()()()())");
        EXPECT_EQ(" everithing fine",br.checkBracers());

        br2.getExpression("[][[]]");
        EXPECT_EQ(" everithing fine", br2.checkBracers());

        br3.getExpression("{}{}{}{{{{}}}}");
        EXPECT_EQ(" everithing fine", br3.checkBracers());

        br4.getExpression("{]");
        EXPECT_EQ(" } - bracer required", br4.checkBracers());

        br5.getExpression("[](){}");
        EXPECT_EQ(" everithing fine", br5.checkBracers());

        br6.getExpression("([()]()");
        EXPECT_EQ(" ) - bracer required", br6.checkBracers());

        br7.getExpression("{}}}}}");
        EXPECT_EQ(" { - bracer required", br7.checkBracers());
    }



