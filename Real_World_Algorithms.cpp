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
        ouMyStack<int> stack(STACK_SIZE);
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
        graph<int> gr1 = generateRandomGraph<int>(5,1,3,GP::LOOPS|GP::FULL);
        gr1.print();
        std::cout << std::endl;
        gr1.DFS_recurcive(0);
        gr1.DFS_stack(0);
        gr1.DFS_stack_2(0);
        gr1.BFS(0);

        graph<int> gr_labirinth(625); gr_labirinth = generateLabirinthGraph<int>(25,25);
        //gr_labirinth.print();
        gr_labirinth.DFS_stack_2_random(0);

        graph<int> gr_labirinth2(8); gr_labirinth2 = generateLabirinthGraph<int>(2,4);
        gr_labirinth2.print();

        graph<int> gr_labirinth3 = generateLabirinthGraph<int>(4,2);
        gr_labirinth3.print();

        graph<int> bipartCheck(3);
        bipartCheck.V = { 0,1,2,3 };
        bipartCheck.E = { {1,0}, {2,0}, {2,3}, {3,1}, {3,1}, {3,3} };
        bipartCheck.print();
        bipartCheck.bipartiteGraphCheck(0);

        auto rand_graph = generateRandomGraph<int>(5, 1, 3, GP::LOOPS);
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

        //3.2
        using TF = ouMyPriorityQueue<char>::T_Freq;
        ouMyPriorityQueue<char> Q1(0, TF{'a',5});

        

        Q1.insert(TF{'g',6 }, TF{ 'b',7 }, TF{ 'c',3 }, TF{ 'd',4 }, TF{ 'e',1 }, TF{ 'f',2 });
        Q1.print();
      
        auto e1 = Q1.extract();
        std::cout << e1.first<< " = " << e1.second << std::endl;
        auto e2 = Q1.extract();
        std::cout << e2.first << " = " << e2.second << std::endl;
        auto e3 = Q1.extract();
        std::cout << e3.first << " = " << e3.second << std::endl;
        Q1.print();

        //3.3
        tree<char> t;
        using TF = ouMyPriorityQueue<char>::T_Freq;
        auto n1 = t.CreateTree(TF{ 'a',7 });
        auto n2 = t.CreateTree(TF{ 'b',6 });
        auto n3 = t.CreateTree(TF{ 'c',5 });
      
        auto n4 = t.CreateTree((TF{ 'd',4 }), n1, n2);
        auto n5 = t.CreateTree((TF{ 'e',3 }), n3);

        auto n6 = t.CreateTree((TF{ 'f',2 }), n4, n5);
        t.setRoot(n6);

        std::cout<<std::endl;
        t.print();
        std::cout << std::endl;

        HuffmanCodding hc("So we’re driving along, a road in the middle of nowhere, a few trees now and then on each side of the road, mountains in the distance, there hasn’t been a town for ages and then you see this sign, not really a proper sign at all, just a piece of card with some words scribbled on it: ‘Bungee Jumping, 5km’, and an arrow pointing to the left. I can’t even see a road going left, and there’s certainly no sign of any bungee jumping, but you insist, the idea has taken you, you’re crazy about it, you’ve always wanted to do bungee jumping. I know, you think I’m boring because I don’t want to go.‘Go on!’ you insist.‘We don’t even have to do the bungee jumping, we can just go thereand see what’s happening.It’ll be interesting!’ As usual, you get your way.I give inand off we go along this dirt road, for what seems much more than five kilometres to me.But then, after driving for ages, suddenly, out of nowhere, some trees appear, like a small wood.‘This must be the place, ’ you say.The road narrows into just a path, so we pull over to the side of the road.I couldn’t drive down there if I wanted to.As soon as we’re out of the car we can hear voices : people shoutingand laughing.They sound like young people, they sound like they’re having a good time.We slowly walk to where the noiseand people are.In the middle of the wood there’s a group of about 20 people.The youngest are about 15 or 16, while some of them are perhaps in their late 20s.They look up and see us, then say hello to us.They’re polite, friendly even, but I feel like we’re interrupting a private party – gatecrashing something they’re doing.Once there had been a river running through the middle of the forest, but now there was just a dry ditch.It doesn’t matter; nobody is interested in swimming.A metal bridge crosses the ditch.The bridge doesn’t look too stable.I think the kids had built it themselves.There’s a big group of the kids in the middle of the bridge.They’re all leaning overand looking down into the ditch.They’re all shoutingand laughing.Another person is hanging from a long piece of elastic rope in the middle of the ditch.He is laughing like he is mad.The other people slowly pull him up to the bridge.As the guy comes to the top he looks exhilaratedand shocked, but also very, very happyI look at youand can see what you’re thinking.‘I want to do that!’ you say.I knew it.And you know what I want to say : ‘Danger!!!Damage to internal organs!Safety procedures!Damage to your eyes!The rope can burn you!You can get tangled up in the rope!You can dislocate your arm or your leg!It’s certain that you will get bruises on your arms!What happens if the rope breaks ? Who knows who these people are ? Have you any idea how far away from a hospital we are ? ’ I don’t say it, but, yes, you’re right, I am thinking it.I don’t say anything, because I know that you won’t have answers for any of my questions.You know that I’m right, really.You’ve always been a lot more adventurous than me.I know you think I’m boringand safeand always worried about dangerand risk.Perhaps you’re right.Perhaps I am too boring.I don’t know why people do it.I really don’t know.I remember when I was a kid, my friend had a bicycle that had no brakes.We used to take his bike without brakesand go down a big hill on it.I think about that, that old bike so many years ago, and I remember how I felt then.I breathe in, close my eyes, don’t think about anything.I jump.I think I’m going foreverand wonder when I’ll stop.But it feels great.I feel scaredand thrilledand alive.Then there’s a pulland I’m going back up again, and, yes, it is dangerous, but, yes, it is thrilling.But the most exciting, thrilling, wonderful thing of all is seeing your face as I come back up to the bridge.Chris Rose");
        //HuffmanCodding hc("aaaabbbcccddd");
        hc.printQueue();
        hc.printAlphabet();

        hc.printComparision();

        HuffmanCodding hc_rand(generateRandomString(100));
        hc_rand.printComparision();

        HuffmanCodding hc_rand2(generateRandomString(10000));
        hc_rand2.printComparision();

#endif
    };

