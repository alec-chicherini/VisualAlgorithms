//Real-World Algorithms - > Beginners guide - Panos Louridas book examples and tasks.

#include <iostream>
#include <timedelay.h>
#include <timedelay.cpp>
#define PART1

#ifdef PART1

#include <array>

//Algorithm 1.1
template <typename T,size_t SIZE>
std::array<T, SIZE>* SimpleStockSpan(std::array<T, SIZE>* quotes)
{
    std::array<T, SIZE>* spans = new std::array<T, SIZE>;

    spans->operator[](0) = 1;
   // std::cout << "i" << "  " << "k" << std::endl;
    for (size_t i = 0; i < SIZE; i++)
    {
        //std::cout << i << std::endl;
        size_t k = 1;
        bool span_end = false;
        
        while ((int)(i - k) >= 0 && !span_end)
        {
            //std::cout <<"   " << k << std::endl;
            if (quotes->operator[](i - k) <= quotes->operator[](i)) k = k + 1;
                else span_end = true;
        }
   
        spans->operator[](i) = k;
    }

    return spans;
}
//Algorithm 1.2
#include <vector>
template <typename T, size_t SIZE>
std::array<T, SIZE>* StackStockSpan(std::array<T, SIZE>* quotes)
{
    std::array<T, SIZE>* spans=new std::array<T, SIZE>;
    spans->operator[](0) = 1;
    std::vector<T> S;
    S.push_back(0);

    // std::cout << "i" << "  " << "k" << std::endl;
    for (size_t i = 0; i < SIZE; i++)
    {
        while (!S.empty()&&(quotes->operator[](S.back())<=quotes->operator[](i)))
        { S.pop_back();}
        if (S.empty())spans->operator[](i) = i + 1;
                 else spans->operator[](i) = i - S.back();
        S.push_back(i);
    }

    return spans;
}

#include <random>
#include <type_traits>

//generates random array
template<typename T,size_t SIZE>
std::array<T, SIZE>* GenerateRandomArray()
{
    std::array<T, SIZE>* array = new std::array<T, SIZE>;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 100);

    for (size_t i = 0; i < SIZE; i++)
    {array->operator[](i) = (T)dist(gen);}

    return array;
}
//print pointer to array
template <typename T, size_t SIZE>
void print(std::array<T, SIZE>* arr)
{
    for (auto& a : *arr)std::cout << a << " "; std::cout << std::endl;
}

//exercise 1.3.1. Stack

template<class T,size_t SIZE=100>
class ouMyStack
{
    bool is_empty_bool = true;
    size_t current_pos = 0;
    std::array<T, SIZE>* stack;
public:
    ouMyStack() { stack = new std::array<T, SIZE>;}
    bool is_full() { return current_pos == SIZE - 1 ? true : false;}
    bool is_empty() { return is_empty_bool;}
    void push(T x) 
    {
        if (!this->is_full()) {
            stack->operator[](current_pos++) = x;
            is_empty_bool = false;
        }
        else 
            std::cout << "Stack is full! Push failed." << std::endl;
    }
    void pop()
    {
        if (!is_empty_bool) {
            if (current_pos == 1){is_empty_bool = true; current_pos--;}
            else current_pos--;
        }
        else std::cout << "Stack is empty! Pop failed." << std::endl;
    }

   
    T top()
    {
        if (!is_empty_bool)return stack->operator[](current_pos-1);

        else {
            std::cout << "Stack is empty! top failed.";
            return T();
        }
    }
    size_t size() {
            return current_pos;
        }

    void print()
    {
     if (is_empty_bool)std::cout<<"[empty]"<<std::endl;
     else {
         std::cout << "[ ";
         for (size_t i = 0; i < current_pos; i++)std::cout << stack->operator[](i) << " "; std::cout << "]";
     }
    }

    void reverse()
    {
        auto* newStack = new std::array<T, SIZE>;
        for (size_t i = 0; i < current_pos; i++)newStack->operator[](i) = stack->operator[](current_pos-1-i);
        delete stack;
        stack = newStack;
    }
};

class Calc
{
    ouMyStack<std::string, 10> input;
    ouMyStack<int, 100> output;
public:
    void getExpression(std::string&& str) {
        std::string current = "";
        for (size_t i = 0; i < str.size(); i++)
        {
            if ((str[i] == ' ') || (i == (str.size() - 1))) {
                if (i == (str.size() - 1))
                {
                    current += str[i];
                    input.push(current);
                    break;
                }
                else
                {
                    input.push(current);
                    current = "";
                }
            }
            else current += str[i];
        }

        //input.print(); std::cout << std::endl;
        input.reverse();
        input.print(); std::cout << std::endl;
    }


    void execute() {

        
        while(!input.is_empty())
        {
           
            if (isdigit(input.top()[0]))
            {
                output.push(stoi(input.top()));
                input.pop();
            }
            else if (input.top()[0] == '+')
            {
                input.pop();
                int first = output.top(); output.pop();
                int second = output.top(); output.pop();
                output.push(first + second);
            }
            else if (input.top()[0] == '-')
            {
                input.pop();
                int first = output.top(); output.pop();
                int second = output.top(); output.pop();
                output.push(second - first);
            }
            else if (input.top()[0] == '*')
            {
                input.pop();
                int first = output.top(); output.pop();
                int second = output.top(); output.pop();
                output.push(first * second);
            }
            else if (input.top()[0] == '/')
            {
                input.pop();
                int first = output.top(); output.pop();
                int second = output.top(); output.pop();
                output.push(second / first);
            }
            output.print(); if(!input.is_empty())std::cout << ",";
           
        }
        std::cout << std::endl;
    };
};

class bracers
{
    ouMyStack<char, 100> bracers_stack;
    ouMyStack<char, 10> round_bracers_stack;
    ouMyStack<char, 10> courvie_bracers_stack;
    ouMyStack<char, 10> square_bracers_stack;

public:
    void getExpression(std::string&& br)
    {
        for (size_t i = 0; i < br.size(); i++)
        {
            bracers_stack.push(br[i]);

        }

        bracers_stack.print();
    }

    std::string checkBracers()
    {
    while (!bracers_stack.is_empty())
         {

        if (bracers_stack.top() == '(')
        {
            bracers_stack.pop();

            if (round_bracers_stack.is_empty())return " ) - bracer required";
            else round_bracers_stack.pop();
           
        }
        else if (bracers_stack.top() == ')')
        {
            bracers_stack.pop();
            round_bracers_stack.push(')');
        }
        else if (bracers_stack.top() == '[')
        {
            bracers_stack.pop();
            if (square_bracers_stack.is_empty())return " ] - bracer required";
            else square_bracers_stack.pop();
        }
        else if (bracers_stack.top() == ']')
        {
            bracers_stack.pop();
            square_bracers_stack.push(']');
        }
        else if (bracers_stack.top() == '{')
        {
            bracers_stack.pop();
            if (courvie_bracers_stack.is_empty())return " } - bracer required";
            else courvie_bracers_stack.pop();
        }
        else if (bracers_stack.top() == '}')
        {
            bracers_stack.pop();
            courvie_bracers_stack.push('}');
        }
        else if(bracers_stack.top()==' ')bracers_stack.pop();
         }


    if (bracers_stack.is_empty())
    {
        if (!round_bracers_stack.is_empty())return " ( - bracer required";
        if (!square_bracers_stack.is_empty())return " [ - bracer required";
        if (!courvie_bracers_stack.is_empty())return " { - bracer required";
        
    }
    return " everithing fine";
    }

};

#endif

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

    };

