//Real-World Algorithms - > Beginners guide - Panos Louridas book examples and tasks.

#include <iostream>
#include <timedelay.h> //https://github.com/ikvasir/timedelay
#include <timedelay.cpp>

#include "Real_World_Algorithms.h"
    int main()
    {
        timedelay T;

#ifdef PART1


        //ex 1.3.1
        constexpr size_t STACK_SIZE = 3;
        ouMyStack<int, STACK_SIZE> stack;
        stack.push(11);
        stack.push(12);
        std::cout << "stack.size() = " << stack.size() << " stack.top() = " << stack.top() << std::endl;
        stack.push(1);
        stack.push(2);
        std::cout << "stack.size() = " << stack.size() << " stack.top() = " << stack.top() << std::endl;
        stack.pop();
        stack.pop();
        stack.pop();
        stack.pop();
        stack.print(); std::cout << std::endl;
        std::cout << "stack.size() = " << stack.size() << " stack.top() = " << stack.top() << std::endl;
        stack.push(3);
        stack.push(4);
        stack.push(5);
        stack.push(6);
        std::cout << "stack.size() = " << stack.size() << " stack.top() = " << stack.top() << std::endl;
        stack.print(); std::cout << std::endl;

        //ex 1.3.2
        std::cout << std::endl;
        constexpr size_t ARRAY_SIZE = 3;
        std::array<int, ARRAY_SIZE>* quotes1 = GenerateRandomArray<int, ARRAY_SIZE>();
        print(quotes1);

        T.addTimer("algorithm1.1");
        auto spans11 = SimpleStockSpan(quotes1);
        std::cout << T.readTimer("algorithm1.1") << std::endl;


        T.addTimer("algorithm1.2");
        auto spans12 = StackStockSpan(quotes1);
        std::cout << T.readTimer("algorithm1.2") << std::endl;
      
        //ex 1.3.3
        std::cout << std::endl;
        Calc calculator1,calculator2,c3;
        calculator1.getExpression("1 2 3 * +");
        calculator1.execute();

        calculator2.getExpression("1 2 3 * + 2 - ");
        calculator2.execute();
        
        c3.getExpression("2 2 + 3 3 + *");
        c3.execute();

        //ex 1.3.4
        std::cout << std::endl;
        bracers br,br2,br3,br4,br5;
        br.getExpression("(()()()())");
        std::cout << br.checkBracers()<<std::endl;
        br2.getExpression("[][[]]");
        std::cout << br2.checkBracers() << std::endl;
        br3.getExpression("{}{}{}{{{{}}}}");
        std::cout << br3.checkBracers() << std::endl;
        br4.getExpression("{]");
        std::cout << br4.checkBracers() << std::endl;
        br5.getExpression("[](){}");
        std::cout << br5.checkBracers() << std::endl;

#endif

#ifdef PART2
        //2.1
        ouMyList<int> lst;
        lst.print();
        lst.insert(1);
        lst.insert(3);
        lst.print();
        lst.insert(3, 2);
        lst.insert(1, 0);
        lst.print();
        lst.remove(1);
        lst.print();
        lst.cleanup();
        lst.print();

        //2.2
        std::cout << std::endl;
        ouMyQueue<int> que;
        //std::cout<<que.Head_.pos<<std::endl;
        //que.Head_++;        que.Head_++;        que.Head_++;        que.Head_++;        que.Head_++;        que.Head_++;        que.Head_++;        que.Head_++;    
        //std::cout << que.Head_.pos << std::endl;
        //++que.Head_;        ++que.Head_;
        //std::cout << que.Head_.pos << std::endl;
        //que.Head_--;
        //std::cout << que.Head_.pos << std::endl;
        //--que.Head_;
        //std::cout << que.Head_.pos << std::endl;
        //--que.Head_;
        //std::cout << que.Head_.pos << std::endl;
        que.push(1); que.push(1);
        que.push(1); que.push(1);
        que.push(1); que.push(1);
        que.print();
        que.pop(); que.pop();que.pop();
        que.print();
        que.push(1); que.push(1);
        que.push(1); que.push(1);
        que.push(1); que.push(1);
        que.push(1); que.push(1);
        que.print();
        que.pop(); que.pop(); que.pop();
        que.print();
        que.pop(); que.pop(); que.pop(); que.pop(); que.pop();
        que.print();
        que.pop();
        que.print();
        que.pop();
        que.print();
        que.pop();
        que.print();
        que.push(1); que.push(1);
        que.push(1); que.push(1);
        que.push(1); que.push(1);
        que.push(1); que.push(1);
        que.print();
        que.push(1); que.push(1);
        que.print();
        que.push(1);
        que.print();

        //2.3
        graph<int,5> gr1 = generateRandomGraph<int,5>();
        gr1.print();
        std::cout << std::endl;
        gr1.DFS_recurcive(0);
        gr1.DFS_stack(0);
        gr1.DFS_stack_2(0);
        gr1.BFS(0);

        graph<int, 625> gr_labirinth = generateLabirinthGraph<int, 25, 25>();
        //gr_labirinth.print();
        gr_labirinth.DFS_stack_2_random(0);

        graph<int, 8> gr_labirinth2 = generateLabirinthGraph<int, 2, 4>();
        gr_labirinth2.print();

        graph<int, 8> gr_labirinth3 = generateLabirinthGraph<int, 4, 2>();
        gr_labirinth3.print();

        graph<int, 3> bipartCheck;
        bipartCheck.V = { 0,1,2,3 };
        bipartCheck.E = { {1,0}, {2,0}, {2,3}, {3,1}, {3,1}, {3,3} };
        bipartCheck.print();
        bipartCheck.bipartiteGraphCheck(0);

        auto rand_graph = generateRandomGraph<int, 5>();
        rand_graph.print();
        
#endif

#ifdef PART3
       
        std::string input("abcd");
        std::cout << "str input: ";
        std::cout << input << std::endl;

        std::stringstream output;
        std::cout << "str to int: ";
        for(auto&c:input)
        {
            output<<std::hex<<int(c);
            std::cout << int(c) << " ";
        }
        std::cout << std::endl;

        std::string output_hex (output.str());
        std::cout << "int to hex: ";
        std::cout << output_hex <<std::endl;

        std::cout << "hex to dec: ";
        for (auto& c : output_hex)
        {
            std::cout <<int((c > 'a') ? (c - 'a' + 10) : (c - '0'));
        }
        std::cout << std::endl;

        std::cout << "dec * 360/16: ";
        for (auto& c : output_hex)
        {
            std::cout << float(int((c > 'a') ? (c - 'a' + 10) : (c - '0')) * 22.5f) << " ";
        }

        std::cout << std::endl;
        std::cout << std::endl;

        ouMyPriorityQueue Q1(0, 4);



        Q1.insert(9, 8, 7, 6, 5, 3, 2, 1);
        Q1.print();

        
#endif
    };

