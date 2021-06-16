#include "pch.h"

#include "../Real_World_Algorithms/Real_World_Algorithms.h"

#include <timedelay.h> //https://github.com/ikvasir/timedelay
#include <timedelay.cpp>

/// @brief test for part 1 exesice number one - stack data structure
    TEST(RealWorldAlgorithm, part1exercice1)
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

    TEST(RealWorldAlgorithm, part1exercice2)
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

    TEST(RealWorldAlgorithm, part1exercice3)
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

    TEST(RealWorldAlgorithm, part1exercice4)
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

    TEST(RealWorldAlgorithm, part2exercice1)
    {
        ASSERT_NO_THROW(
        ouMyList<int> lst;
        lst.insert(1);
        lst.insert(3);
        lst.print();
        lst.remove(1);
        lst.print();
        lst.cleanup();
        lst.print();
        );

        ouMyList<int> lst;

        EXPECT_EQ("nullptr", lst.print());

        lst.insert(1);
        lst.insert(3);
        EXPECT_EQ("3->1->nullptr", lst.print());

        lst.insert(3, 2);
        lst.insert(1, 0);
        EXPECT_EQ("3->2->1->0->nullptr", lst.print());

        lst.remove(1);
        EXPECT_EQ("3->2->0->nullptr", lst.print());

        lst.cleanup();
        EXPECT_EQ("nullptr", lst.print());

    }

    TEST(RealWorldAlgorithm, part2exercice2)
    {
        ASSERT_NO_THROW(
            ouMyQueue<int> que(5);
        que.push(1); que.push(1);
        que.print(); que.pop();
        );

        ouMyQueue<int> que(5);
        que.push(1); que.push(2);
        que.push(3); que.push(4);
        que.push(5); que.push(6);
        EXPECT_EQ("1 2 3 4 5", que.print());

        que.pop(); que.pop();
        EXPECT_EQ("3 4 5", que.print());

        que.push(6); que.push(7);
        EXPECT_EQ("3 4 5 6 7", que.print());
    }

    TEST(RealWorldAlgorithm, part2exercise3)
    {
        ASSERT_NO_THROW(
        graph<int> gr1 = generateRandomGraph<int>(5, 1, 2, GP::LOOPS | GP::FULL);
        gr1.DFS_recurcive(0);
        gr1.DFS_stack(0);
        gr1.DFS_stack_2(0);
        gr1.BFS(0);
        );
        graph<int> gr1;
        gr1.V = { 0, 1, 2, 3, 4 };
        gr1.E = { {0,1}, {1,4}, {2,1}, {3,4}, {4,0}, {4,2} };

        EXPECT_EQ("0->1->4->1->3->2->1", gr1.DFS_stack(0));
        EXPECT_EQ("0->1->4->3->2", gr1.DFS_stack_2(0));
        EXPECT_EQ("0->1->4->2->3", gr1.BFS(0));
    }

    TEST(RealWorldAlgorithm, part2exercise4)
    {
        ASSERT_NO_THROW(
            graph<int> gr_labirinth(625); gr_labirinth = generateLabirinthGraph<int>(25, 25);

        );
    }
    TEST(RealWorldAlgorithm, part2exercise5)
    {
        graph<int> gr1;
        gr1.V = { 0, 1, 2, 3, 4 };
        gr1.E = { {0,1}, {1,4}, {2,1}, {3,4}, {4,0}, {4,2} };
        EXPECT_EQ(false, gr1.bipartiteGraphCheck(0));

        graph<int> gr2;
        gr2.V = { 0,1,2,3 };
        gr2.E = { {1,0}, {2,0}, {2,3}, {3,1}, {3,1}, {3,3} };
        EXPECT_EQ(true, gr2.bipartiteGraphCheck(0));
    }




