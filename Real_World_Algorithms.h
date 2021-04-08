#pragma once
//#define PART2
//#define PART1
#define PART3
//generates random int
#include <random>
#include <functional>
int RAND(int left, int right)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(left, right);

    return dist(gen);
}

#ifdef PART1

#include <array>

//Algorithm 1.1
template <typename T, size_t SIZE>
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
    std::array<T, SIZE>* spans = new std::array<T, SIZE>;
    spans->operator[](0) = 1;
    std::vector<T> S;
    S.push_back(0);

    // std::cout << "i" << "  " << "k" << std::endl;
    for (size_t i = 0; i < SIZE; i++)
    {
        while (!S.empty() && (quotes->operator[](S.back()) <= quotes->operator[](i)))
        {
            S.pop_back();
        }
        if (S.empty())spans->operator[](i) = i + 1;
        else spans->operator[](i) = i - S.back();
        S.push_back(i);
    }

    return spans;
}

#include <random>
#include <type_traits>

//generates random array
template<typename T, size_t SIZE>
std::array<T, SIZE>* GenerateRandomArray()
{
    std::array<T, SIZE>* array = new std::array<T, SIZE>;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 100);

    for (size_t i = 0; i < SIZE; i++)
    {
        array->operator[](i) = (T)dist(gen);
    }

    return array;
}
//print pointer to array
template <typename T, size_t SIZE>
void print(std::array<T, SIZE>* arr)
{
    for (auto& a : *arr)std::cout << a << " "; std::cout << std::endl;
}

//exercise 1.3.1. Stack

template<class T, size_t SIZE = 100>
class ouMyStack
{
    bool is_empty_bool = true;
    size_t current_pos = 0;
    std::array<T, SIZE>* stack;
public:
    ouMyStack() { stack = new std::array<T, SIZE>; }
    bool is_full() { return current_pos == SIZE - 1 ? true : false; }
    bool is_empty() { return is_empty_bool; }
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
            if (current_pos == 1) { is_empty_bool = true; current_pos--; }
            else current_pos--;
        }
        else std::cout << "Stack is empty! Pop failed." << std::endl;
    }


    T top()
    {
        if (!is_empty_bool)return stack->operator[](current_pos - 1);

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
        if (is_empty_bool)std::cout << "[empty]" << std::endl;
        else {
            std::cout << "[ ";
            for (size_t i = 0; i < current_pos; i++)std::cout << stack->operator[](i) << " "; std::cout << "]";
        }
    }

    void reverse()
    {
        auto* newStack = new std::array<T, SIZE>;
        for (size_t i = 0; i < current_pos; i++)newStack->operator[](i) = stack->operator[](current_pos - 1 - i);
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


        while (!input.is_empty())
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
            output.print(); if (!input.is_empty())std::cout << ",";

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
            else if (bracers_stack.top() == ' ')bracers_stack.pop();
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

#ifdef PART2
//2.1
template <class T>
class ouMyList
{
    struct Node {
        T data;
        Node* next;
    };

    Node* first = nullptr;

public:
    ouMyList() {};
    Node* insert(T&& after, T&& data) {

        Node* n = new Node();
        n->data = data;

        if (first == nullptr)
        {
            first = n;
            n->next = nullptr;
        }
        else
        {
            Node* current = find(std::move(after));
            n->next = current->next;
            current->next = n;
        }

        return n;
    };
    Node* insert(T&& data) {

        Node* n = new Node();
        n->data = data;
        n->next = first;
        first = n;

        return n;
    };

    Node* find(T&& data)
    {
        Node* current = first;
        while (current != nullptr)
        {
            if (current->data == data) return current;
            else current = current->next;
        };
        return nullptr;
    };

    Node* find_prev(T&& data)
    {
        if (first != nullptr && first->data == data) return nullptr;

        Node* current = first;
        while (current != nullptr)
        {
            if (current->next->data == data)  return current;
            else current = current->next;
        };
        return nullptr;
    };

    void remove(T&& data) {

        auto current = find(std::move(data));
        if (current == first)
            if (first->next == nullptr) { delete first; first = nullptr; }
            else { first = first->next; delete current; }
        else {
            current = find_prev(std::move(data));
            auto next = current->next->next;
            delete current->next;
            current->next = next;
        }
    }

    void print() {

        Node* current = first;

        while (current != nullptr) {
            std::cout << current->data << "->";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    };

    void cleanup() {

        while (first != nullptr) {
            auto next = first->next;
            delete first;
            first = next;
        }
        std::cout << "list deleted" << std::endl;
    };

};
//2.2
#include <array>
template <class T, size_t SIZE = 10>
class ouMyQueue
{
    std::array<T, SIZE>* queue_;
public:
    ouMyQueue() { queue_ = new std::array<T, SIZE>; };

public:
    struct possition {
        size_t pos;
        possition(size_t pos_) { pos = pos_; };
        possition() { pos = 0; };

        possition& operator++()
        {
            if ((pos + 1) < SIZE)++pos;
            else pos = 0;
            return *this;
        };
        possition operator++(int)
        {
            possition temp = *this;
            ++* this;
            return temp;
        };

        possition& operator--()
        {
            if (pos != 0)--pos;
            else pos = SIZE - 1;
            return *this;
        };

        possition operator--(int)
        {
            possition temp = *this;
            --* this;
            return temp;
        };

        //auto operator<=>(const possition&)const = default;

    };
private:
    possition Head_;
    possition Tail_;

    bool b_is_full = false;
    bool b_is_empty = true;
    bool b_is_one_element = false;

public:
    bool is_full() { return b_is_full; }
    bool is_empty() { return b_is_empty; }
    void push(T data)
    {
        if (is_full()) std::cout << "push failed. queue is full" << std::endl;
        else if (is_empty())
        {
            queue_->operator[](Tail_.pos) = data;
            b_is_empty = false;
            b_is_one_element = true;
        }
        else
        {
            b_is_one_element = false;
            Tail_++;
            queue_->operator[](Tail_.pos) = data;
            Tail_++;
            if (Tail_.pos == Head_.pos) b_is_full = true;
            Tail_--;
        }
    };

    T pop()
    {
        if (is_empty())std::cout << "pop failed. queue is empty" << std::endl;
        else {
            b_is_full = false;
            auto current = Head_.pos;

            if ((Tail_.pos == Head_.pos) && b_is_one_element) { b_is_empty = true; b_is_one_element = false; }
            else Head_++;

            if (Tail_.pos == Head_.pos && !b_is_one_element) { b_is_one_element = true; }
            return queue_->operator[](current);
        }
    };

    void print()
    {
        possition current(Head_.pos);
        std::array <std::string, SIZE>* print_array = new std::array <std::string, SIZE>;
        for (auto& s : *print_array)s = " ";

        if (!is_empty())
            while (true)
            {

                print_array->operator[](current.pos) = std::to_string(queue_->operator[](current.pos));
                if (b_is_one_element)break;

                current++;

                if (current.pos == Tail_.pos) {
                    print_array->operator[](current.pos) = std::to_string(queue_->operator[](current.pos));
                    break;
                };
            };
        for (size_t i = 0; i < SIZE; i++) std::cout << i << " ";
        std::cout << std::endl;

        for (size_t i = 0; i < SIZE; i++) std::cout << print_array->operator[](i) << " ";
        std::cout << std::endl;

        for (size_t i = 0; i < SIZE; i++) if (Head_.pos == i)std::cout << "H"; else std::cout << "  ";
        std::cout << std::endl;

        for (size_t i = 0; i < SIZE; i++) if (Tail_.pos == i)std::cout << "T"; else std::cout << "  ";
        std::cout << std::endl;

    };
};

#include <vector>
#include <tuple>
//2.3
template<typename T,size_t N = 10>
struct graph
{
    
    std::vector<T> V;
    std::vector<std::pair<T, T>> E;
    std::vector<bool> visited;
    bool first_DFS_iteration = true;
    T last_visited_node;
    bool last_visited_node_color;
    int number_path_started = 0;
  
    T getLastVisitedNode() { return last_visited_node;}
    int getNumberCurrentPath() { return number_path_started;}
    bool getLastVisitedNodeColor() { return last_visited_node_color;}
 
    void cleanup() {
        V.clear();
        E.clear();
        visited.clear();
        first_DFS_iteration = true;
        number_path_started = 0;

    }

    bool isVisitedTrue() {
        bool b=true;
        for (auto v : visited) b = b && v;
        return b;
    }

    void print() {
        std::cout << "V = { ";
        for (auto& v : V)std::cout << v << " ";
        std::cout << " }" << std::endl
            << "E = { ";
        for (auto& e : E)std::cout << "{" << e.first << "," << e.second << "} ";
        std::cout << " }" << std::endl;

    }

    std::vector<int> makeAdjacencyList(int node) {
    
        std::vector<int> vec{};
        for (auto& e : E)
        {
            if (e.first == node&&!visited[e.second])vec.push_back(e.second);
            else if (e.second == node && !visited[e.first])vec.push_back(e.first);
        }

        return std::move(vec);

    } 

    //without visited checking
    std::vector<int> makeAdjacencyList2(int node) {

        std::vector<int> vec{};
        for (auto& e : E)
        {
            if (e.first == node)vec.push_back(e.second);
            else if (e.second == node)vec.push_back(e.first);
        }

        return std::move(vec);

    }

    void DFS_recurcive(int node, std::function<void()> visualisation_func = []{}) {
       // std::cout << "getLastVisitedNode() = " << getLastVisitedNode() << std::endl;
        if (node<0 || node>N) { std::cout << __FUNCDNAME__ << " error. first node not in range." << std::endl; }

        if (first_DFS_iteration) {
            visited.resize(N + 1);
            std::cout << "DFS_Recurcive: "<<node;
            first_DFS_iteration = false;

            for (size_t i = 0; i < visited.size(); i++)visited[i] = false;
            
        }

        visited[node] = true;

        last_visited_node = node;
        visualisation_func();

        bool bl=true;
        for (auto b : visited) { bl = b && bl; }; 
        if (bl)first_DFS_iteration = true;

        std::vector<int> AdjacencyList=makeAdjacencyList(node);
        //for (auto& a : AdjacencyList)std::cout << a << " "; std::cout << std::endl;

        for (auto& a : AdjacencyList) 
            if (!visited[a]){
                std::cout << "->" << a;
                DFS_recurcive(a, visualisation_func);}

    };
    void DFS_stack(int node, std::function<void()> visualisation_func = [] {})
    {
        if (node<0 || node>N) { std::cout <<__FUNCDNAME__<< " error. first node not in range." << std::endl; }
        std::cout << std::endl;
     
        visited.resize(N + 1);
        for (size_t i = 0; i < visited.size(); i++)visited[i] = false;
       // std::cout << "DFS_Stack:visited: "; for (auto v : visited)std::cout << v; std::cout << std::endl;
        std::cout << "DFS_Stack: " << node;
        
        ouMyStack<int,N*N> stack;
        stack.push(node);
        while (!stack.is_empty()) {
            auto c = stack.top();
            stack.pop();
            visited[c] = true;
            last_visited_node = c;
            visualisation_func();
            std::vector<int> AdjacencyList = makeAdjacencyList(c);
            for (auto& a : AdjacencyList)
            {
                if (!visited[a]) {
                std::cout << "->" << a;
                stack.push(a);}
            }
        };
    }

    void DFS_stack_2(int  node, std::function<void()> visualisation_func = [] {})
    {
        if (node<0 || node>N) { std::cout << __FUNCDNAME__ << " error. first node not in range." << std::endl; }
        std::cout << std::endl;
        std::vector<int> instack;

        instack.resize(N + 1);
        visited.resize(N + 1);

        for (size_t i = 0; i < visited.size(); i++) 
        {
            visited[i] = false; 
            instack[i] = false;
        }

        //std::cout << "DFS_stack_2:visited: "; for (auto v : visited)std::cout << v; std::cout << std::endl;
        std::cout << "DFS_stack_2: " << node;
        
        ouMyStack<int,N*N> stack;
        stack.push(node);

        instack[node] = true;

        while (!stack.is_empty()) {
            auto c = stack.top();
            stack.pop();
            instack[c] = false;
            visited[c] = true;
            last_visited_node = c;
            visualisation_func();
            std::vector<int> AdjacencyList = makeAdjacencyList(c);
            for (auto& a : AdjacencyList)
            {
                if (!visited[a]&&!instack[a]) {
                    std::cout << "->" << a;
                    stack.push(a);
                    instack[a] = true;
                }
            }
        }//while
        std::cout << std::endl;
    }

    void DFS_stack_2_random(int  node, std::function<void()> visualisation_func = [] {})
    {
        if (node<0 || node>N) { std::cout << __FUNCDNAME__ << " error. first node not in range." << std::endl; }
        std::cout << std::endl;
        std::vector<bool> instack;
        std::vector<int> not_in_visited;
        for (int i = 0; i < N; i++)not_in_visited.push_back(i);
        instack.resize(N );
        visited.resize(N );

        for (size_t i = 0; i < visited.size(); i++)
        {
            visited[i] = false;
            instack[i] = false;
        }
        
        ouMyStack<int, N*N> stack;
        stack.push(node);
        instack[node] = true;
        visited[node] = true;
        auto current = stack.top();

        auto iter = std::find(not_in_visited.begin(), not_in_visited.end(), current);
        if (iter != not_in_visited.end())
        not_in_visited.erase(iter);

        bool all_visited_true = false;
        std::vector<int> AdjacencyList = makeAdjacencyList(current);

        while(!all_visited_true){
            
        while (AdjacencyList.empty()) {
            
            current = not_in_visited[RAND(0,not_in_visited.size()-1)];

            AdjacencyList = makeAdjacencyList(current);
            if (AdjacencyList.empty())AdjacencyList.push_back(current);
            }
            

		while (!AdjacencyList.empty())
		{
            auto r = RAND(0, AdjacencyList.size() - 1); //std::cout << "AdjacencyList.size() = " << AdjacencyList.size() << " RAND(0, AdjacencyList.size()) = " << r << std::endl;
            current = AdjacencyList[r];

            auto iter = std::find(not_in_visited.begin(), not_in_visited.end(), current);
            if (iter != not_in_visited.end())
            not_in_visited.erase(iter);

            if (!visited[current] && !instack[current])
            {
                stack.push(current);
                instack[current] = true;
                AdjacencyList.clear();
                AdjacencyList = makeAdjacencyList(current);
            }
            else {
                auto iter = std::find(AdjacencyList.begin(), AdjacencyList.end(), current);
                if(iter!=AdjacencyList.end())
                AdjacencyList.erase(iter);
            }   
		};

        
        while (!stack.is_empty()) 
        {
            current = stack.top();
            visited[current] = true;
            std::cout << "->" << current;
            last_visited_node = current;
            visualisation_func();
            stack.pop();
        
            if(stack.is_empty())number_path_started++;
        }

        
        bool bl = true;
        for (auto b : visited) { bl = b && bl; };

        if (bl)all_visited_true = true;
        }
        number_path_started = 0;
        std::cout << std::endl;
    }

    void BFS(int  node, std::function<void()> visualisation_func = [] {})
    {

        std::vector<bool> inqueue;

        inqueue.resize(N + 1);
        visited.resize(N + 1);

        for (size_t i = 0; i < visited.size(); i++)
        {
            visited[i] = false;
            inqueue[i] = false;
        }

       
        std::cout << "BFS: " << node;

        ouMyQueue<int,N> queue;
        queue.push(node);

        inqueue[node] = true;

        while (!queue.is_empty()) {
            auto c = queue.pop();
            inqueue[c] = false;
            visited[c] = true;
            last_visited_node = c;
            visualisation_func();
            std::vector<int> AdjacencyList = makeAdjacencyList(c);
            for (auto& a : AdjacencyList)
            {
                if (!visited[a] && !inqueue[a]) {
                    std::cout << "->" << a;
                    queue.push(a);
                    inqueue[a] = true;
                }
            }
        }//while
        std::cout << std::endl;
    }

  

    bool bipartiteGraphCheck(int node, std::function<void()> visualisation_func = [] {})
    {   
      

        enum class colors_enum:bool { RED, GREEN } current_color = colors_enum::RED;
        using enum colors_enum;

        std::vector<bool> color;
        std::vector<bool> inqueue;

        inqueue.resize(N+1);
        visited.resize(N + 1);
        color.resize(N + 1);

        for (size_t i = 0; i < visited.size(); i++)
        {
            visited[i] = false;
            inqueue[i] = false;
            
        }

        std::cout << "BFS_colorify: " << node;

        ouMyQueue<int, N> queue;
        queue.push(node);

        inqueue[node] = true;
        color[node] = static_cast<bool>(current_color);

        while (!queue.is_empty()) {
            current_color=(current_color==RED?GREEN:RED);
            auto c = queue.pop();
            inqueue[c] = false;
            visited[c] = true;

            last_visited_node_color = color[c];
            last_visited_node = c;
            visualisation_func();

            std::vector<int> AdjacencyList = makeAdjacencyList(c);
            for (auto& a : AdjacencyList)
            {

                if (!visited[a] && !inqueue[a]) {
                    color[a] = static_cast<bool>(current_color);
                    std::cout << "->" << a << "(" << color[a] << ")";
                    queue.push(a);
                    inqueue[a] = true;
                }
               
            }
        }//while

        
        auto is_colorfied_biportied = [&] {

            for (auto& v : V) {
                auto alist = makeAdjacencyList2(v);
                for (auto& a : alist)if(a!=v)if(color[a] == color[v])return false;
            };

            return true;
        };

        auto result = is_colorfied_biportied();
        std::cout << "result: " << result << std::endl;;
        this->print();
        std::cout << std::endl;
        return result;

    }
   
};

template<typename T, int N = 10>
graph<T,N> generateRandomGraph() {
    graph<T,N> G;
    G.visited.resize(N + 1);

    for (int i = 0; i <= N; i++)
    {
        G.V.push_back(i);
        G.E.push_back({ i,RAND(0,N) });
        if (RAND(0, 1000) % 2)G.E.push_back({ i,RAND(0,N) });
        if (RAND(0, 1000) % 3)G.E.push_back({ i,RAND(0,N) });
        if (RAND(0, 1000) % 5)G.E.push_back({ i,RAND(0,N) });
    }

    //remove duplicates
    std::sort(G.E.begin(), G.E.end());
    auto last = std::unique(G.E.begin(), G.E.end());
    if(last!=G.E.end())
     G.E.erase(last, G.E.end());

    //remove loops
    auto loop = std::find_if(G.E.begin(), G.E.end(), [](std::pair<int, int>& pair) {return pair.first == pair.second; });
    while(loop!=G.E.end()){
        G.E.erase(loop);
        loop = std::find_if(G.E.begin(), G.E.end(), [](std::pair<int, int>& pair) {return pair.first == pair.second; });
    }

    return G;
}

template<typename T,int X,int Y>
graph<T, X * Y> generateLabirinthGraph()
{
    graph<T, X * Y> G;

    for (int i = 0; i < X; i++)
        for (int j = 0; j < Y; j++)
        {
            int xy =  i*Y + j;
            G.V.push_back(xy);

            if (i == X - 1 && j == Y - 1)break;
            else if (i == X - 1)
                G.E.push_back({xy,xy+1});
            else if (j == Y - 1)
                G.E.push_back({xy,xy+Y});
            else {
                G.E.push_back({ xy, xy + 1 });
                G.E.push_back({ xy, xy + Y });
            };
        };
    return std::move(G);
}



#endif

#ifdef PART3
#include <sstream>
#include <iomanip>
#include <concepts>
#include <tuple>
#include <map>
#include <vector>
#include <iostream>
#include <string>
#include <utility>
#include <algorithm>
#include <set>

template<typename T, typename ... Ts>
concept allTheSame = (std::same_as<T, Ts>&&...);

//3.2
template<typename T>
struct Node {
    T data;
    Node<T>* left = nullptr;
    Node<T>* right = nullptr;
};

template<typename T>
class tree;

template<class T>
class ouMyPriorityQueue
{ 
  
public:   
    using T_Freq = std::pair<T, int>;
    enum class TypeOfPriority :bool { min_priority, max_priority };
  
    using T_Freq_map =typename std::map<typename T_Freq::first_type, typename T_Freq::second_type>;

    using Queue_Tree_T = typename ouMyPriorityQueue<tree<T>>;

    ouMyPriorityQueue() = delete;
    ouMyPriorityQueue(bool queue_type, T_Freq root) :priority(queue_type) { queue.push_back(root); };

    ouMyPriorityQueue(bool queue_type, std::set<std::pair<int,char>> mp) :priority(queue_type)
    {
    
        for (auto& m : mp)
        {
           tree<char> t;
           auto pr = std::pair<char, int>{ m.second, m.first };
           Node<std::pair<char,int>>* n = t.CreateTree(pr);

           t.setRoot(n);

            queue.push_back(T_Freq(t,m.first));

        }


    };
  
    void insert(T_Freq data)requires std::same_as<T, char> {
        using enum TypeOfPriority;
        if (priority == static_cast<bool>(min_priority))
        {
            auto data_ = data;
            queue.push_back(data_);
            auto current_ = (queue.end()-1);

            while (current_ != queue.begin())
            {
                auto parent_ = parent(current_);
                if (!((current_->second) < (parent(current_)->second)))break;
                std::iter_swap(current_, parent_);
                current_ = parent_;
            }
        }
        else
        {

        }
    };
    //insert for ouMyPriorityQueue<tree<char>>
    void insert(std::pair<tree<char>,int> data)requires std::same_as<T, tree<char>> {
        using enum TypeOfPriority;
        if (priority == static_cast<bool>(min_priority))
        {
            auto data_ = data;
            queue.push_back(data_);
            auto current_ = (queue.end() - 1);

            while (current_ != queue.begin())
            {
                auto parent_ = parent(current_);
                if (!((current_->second) < (parent(current_)->second)))break;
                std::iter_swap(current_, parent_);
                current_ = parent_;
            }
        }
        else
        {

        }
    };

    template<typename ... Ts>
    void insert(Ts ... args) requires allTheSame<Ts...>
    {
        (insert(args),...);
    };

    T_Freq find()
    {
        if (!queue.empty())return queue.front();
        else {
            std::cout << "find() ERROR. queue is empty." << std::endl;
            return 0;
        }
    };

    T_Freq extract() requires std::same_as<T, char>
    {
        using enum TypeOfPriority;

        auto result = queue.front();
        std::iter_swap(queue.begin(), (queue.end() - 1));
        queue.pop_back();
        auto current_ = queue.begin();

        if (priority == static_cast<bool>(min_priority))
        {
            while (hasChild(current_))
            {
                auto child_=min_child(current_);
                if (current_->second < child_->second)break;
                std::iter_swap(current_, child_);
                current_ = child_;
            }
            return result;
        }

        else
        {
            return result;
        }
        return result;
    };

    T_Freq extract() requires std::same_as<T, tree<char>>
    {
        using enum TypeOfPriority;

        auto result = queue.front();
        std::iter_swap(queue.begin(), (queue.end() - 1));
        queue.pop_back();
        auto current_ = queue.begin();

        if (priority == static_cast<bool>(min_priority))
        {
            while (hasChild(current_))
            {
                auto child_ = min_child(current_);
                if (current_->second < child_->second)break;
                std::iter_swap(current_, child_);
                current_ = child_;
            }
            return result;
        }

        else
        {
            return result;
        }
        return result;
    };
    
    size_t size() { return queue.size();};

private:
    bool priority;
    std::vector<T_Freq> queue;

public:
   void print() requires std::same_as<T, char>
    {
       
        for (auto& q : queue)std::cout <<q.first<<"("<<q.second<<") ";
        std::cout << std::endl;

        int row = 0;
        int pos_in_row = 0;

        int num_of_rows = log2f(queue.size())+1;

        for (auto& q : queue)
        {
            
            int r = float(pow(2, num_of_rows - row)-1);

            if (pos_in_row == 0)
                r /= 2;
             if (pos_in_row<(pow(2, row) - 1))
             {
                 
                 pos_in_row ++;
                
                 while(r--)
                 std::cout << "  ";
                 std::cout << q.first << "(" << q.second << ")";
             }
             else
             {
                 
                 while (r--)
                     std::cout << "  ";
                 std::cout << q.first << "(" << q.second << ")";
                 pos_in_row=0;
                 row++;

                 std::cout << "\n";
             }
        }
        std::cout << std::endl;
    };

   void print() requires std::same_as<T, tree<char>>
   {
       int i = 0;
       for (auto& q : queue) {
           std::cout << q.second << "[" << i++ << "] " << std::endl;
           q.first.print();
       }
     

       std::cout << std::endl;
   };

    std::vector<T_Freq>::iterator parent(std::vector<T_Freq>::iterator iter)
    {
        size_t pos = (std::distance(queue.begin(), iter) - 1) / 2;

        return queue.begin() + pos ;
    };

    std::vector<T_Freq>::iterator child_left(std::vector<T_Freq>::iterator iter)
    {
        size_t pos = std::distance(queue.begin(), iter);
        if (2 * pos + 1 < queue.size()) return queue.begin() + (2 * pos + 1);
        else return queue.end();
    }

    std::vector<T_Freq>::iterator child_right(std::vector<T_Freq>::iterator iter)
    {
        size_t pos = std::distance(queue.begin(), iter);
        if (2 * pos + 2 < queue.size()) return queue.begin() + (2 * pos + 2);
        
        else return queue.end();
    }

    bool hasChild(std::vector<T_Freq>::iterator iter)
    {
        if (child_left(iter) != queue.end() || child_right(iter) != queue.end()) return true;
        else return false;

    }

    std::vector<T_Freq>::iterator min_child(std::vector<T_Freq>::iterator iter)
    {
		if (hasChild(iter))
		{
			if (child_left(iter) != queue.end() && child_right(iter) != queue.end())
				if (child_left(iter)->second < child_right(iter)->second)return child_left(iter);
				    else return child_right(iter);
			else  if (child_left(iter) != queue.end())return child_left(iter);
			      else return child_right(iter);
		}
		else return queue.end();
    }
};

//3.4
template<typename T>
class tree
{
public:

    using TF = ouMyPriorityQueue<T>::T_Freq;

    Node<TF>* CreateTree(TF data, Node<TF>* left = nullptr, Node<TF>* right = nullptr)
    {
        return new Node<TF>(data, left, right);
    };


    void print(Node<TF>* root)
    {
     
        std::cout << root->data.first<<"("<<root->data.second<<")";

        std::cout << "(";
        if (root->left) std::cout<<root->left->data.first << "(" << root->left->data.second << ")";
        else std::cout << "nullptr";
        std::cout << ",";
        if (root->right) std::cout << root->right->data.first << "(" << root->right->data.second << ")";
        else std::cout << "nullptr";
        std::cout << ") " << std::endl;

        if(root->left)  print(root->left); 
        if(root->right) print(root->right);
    };

    void print()
    {
        print(root);
       
    }

    void setRoot(Node<TF>* n) {root=n;}
    auto getRoot() { return root; }

    Node<TF>* root= nullptr;
};

#include <map>
#include <bitset>
class HuffmanCodding
{
    ouMyPriorityQueue<tree<char>>* PQ;
    using TF = ouMyPriorityQueue<char>::T_Freq;
    
    std::set<std::pair<TF::second_type, TF::first_type>> charFrequency_;
    std::map<char, std::string> alphabet;
    tree<char> result_tree;
    std::string text_;
    std::map<char, std::string> morseAlphabet = 
    {
        {'A',"01"},
        {'B',"1000"},
        {'C',"0101"},
        {'D',"100"},
        {'E',"0"},
        {'F',"0010"},
        {'G',"110"},
        {'H',"0000"},
        {'I',"00"},
        {'J',"0111"},
        {'K',"101"},
        {'L',"0100"},
        {'M',"11"},
        {'N',"10"},
        {'O',"111"},
        {'P',"0110"},
        {'Q',"1101"},
        {'R',"010"},
        {'S',"000"},
        {'T',"1"},
        {'U',"001"},
        {'V',"0001"},
        {'W',"011"},
        {'X',"1001"},
        {'Y',"1011"},
        {'Z',"1100"},
        {'1',"01111"},
        {'2',"00111"},
        {'3',"00011"},
        {'4',"00001"},
        {'5',"00000"},
        {'6',"10000"},
        {'7',"11000"},
        {'8',"11100"},
        {'9',"11110"},
        {'0',"11111"}
    };


public:
    HuffmanCodding(std::string text): text_(text)
    {
        charFrequency_ = charFrequency(text);
        PQ = new ouMyPriorityQueue<tree<char>>(0,charFrequency_);

       // std::cout << text << std::endl;

        //PQ->print();

        std::cout<<std::endl;

        while (PQ->size() > 1) {
            auto x = PQ->extract();
            auto y = PQ->extract();
            auto sum = x.second + y.second;
            auto pr = TF{ '#', sum };
            tree<char> t;
            auto z = t.CreateTree(pr,x.first.getRoot(),y.first.getRoot());
            PQ->insert(std::pair<tree<char>,int>(z,sum));
        }
        result_tree = PQ->extract().first;

        //create new alphabet
        for (auto& s : charFrequency_)
        {
           std::string result,str;
            
           tree_walking(result_tree.getRoot(), str, s.second, result);

           alphabet[s.second] = result;
        }
    };

   void tree_walking(Node<TF>* node, std::string way, char c,std::string& result)
    {
       if (node->data.first == c) {
           result = way; return;
       }

        if (node->right) {
            tree_walking(node->right, std::string(way + "1"), c, result);
        }

        if (node->left) {
            tree_walking(node->left, std::string(way + "0"), c, result);
        }
    };

    std::set<std::pair<TF::second_type, TF::first_type>> charFrequency(std::string text)
    {
        std::map<TF::first_type, TF::second_type> charFrequency_;

        for (auto& c : text) charFrequency_[c]++;

        std::set<std::pair<TF::second_type, TF::first_type>> charFreq;
        for (auto const& [k, v] : charFrequency_) charFreq.emplace(v, k);

   return charFreq;
    }

    void printQueue()
    {
        result_tree.print();
    };

    void printAlphabet()
    {
        std::cout << "alphabet:" << std::endl;
        for (auto& a : alphabet)
            std::cout << a.first << " - "<<a.second << std::endl;
    };

    int ascii_num_of_bits()
    {

        return text_.size() * 8;;
    }

    int huffman_num_of_bits()
    {
        int res(0);

        for (auto& t : text_) 
        {
            auto code = alphabet[t];
            for (auto& c : code)  res++;
        }

        return res;
    }

    int morse_num_of_bits()
    {

        int res(0);

        for (auto& t : text_)
        {
            char t_;
            std::string code;
            
            if (std::isalpha((t>0)?t:(t+255)))
            {
                t_ = std::toupper(t);
                code = morseAlphabet[t_];
            }
            else code = "111111";

            for (auto& c : code)  res++;
        }

        return res;
    }

    int text_size() 
    {
        return text_.size();
    }

    void printComparision() {

        auto ascii = this->ascii_num_of_bits();
        auto huffman = this->huffman_num_of_bits();
        auto morse = this->morse_num_of_bits();
      
        std::cout << "text size = " << this->text_size() << " symbols" << std::endl;
        std::cout << "ascii_num_of_bits = " << ascii << std::endl;
        std::cout << "huffman_num_of_bits = " << huffman << std::endl;
        std::cout << "morse_num_of_bits = " << morse << " (all symbols formatted to UPPER)" << std::endl;
      
    }
};

#include <random>
std::string generateRandomString(size_t num)
{
    std::random_device r;
    std::uniform_int_distribution<int> char_dist(1, 255);

    std::string res;
    while (num--)res += char(char_dist(r));
    return res;

}
#endif