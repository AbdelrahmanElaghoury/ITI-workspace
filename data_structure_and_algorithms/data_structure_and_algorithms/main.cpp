//
//  main.cpp
//  data_structure_and_algorithms
//
//  Created by Abdelrahman Hassan on 30/12/2021.
//

#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool arePair(char opener, char closer){
    if(opener == '(' && closer == ')'){
        return true;
    }
    else if(opener == '{' && closer == '}'){
        return true;
    }
    else if(opener == '[' && closer == ']'){
        return true;
    }
    return false;
}
bool areBalanced(std::string expression){
    std::stack<char>s;
    for(int i=0; i<expression.length(); i++){
        char cur_char = expression[i];
        if(cur_char == '(' || cur_char == '{' || cur_char == '['){
            s.push(cur_char);
        }
        else if(cur_char == ')' || cur_char == '}' || cur_char == ']'){
            if(s.empty() || !arePair(s.top(), cur_char)){
                return false;
            }
            else{
                s.pop();
            }
        }
        //std::cout << s.top() << std::endl;
    }
    return s.empty()?true:false;
}

class node{
public:
    int val;
    node *next;
    node(int x){
        val = x;
        next = nullptr;
    }
};

class Entity{
public:
    string GetName() {return "Entity";}
};

class Player : public Entity{
private:
    string Name;
public:
    Player(const string& name): Name(name) {}
    string GetName() { return Name; }
};

template <typename T, size_t n>
void arr_size(T (&arr)[n]){
    cout << sizeof(arr) << endl;
}



void func(int& x){
    x = 10;
}
void func_2(int *x){
    *x = 20;
}

class vector2{
private:
    int x;
    int y;
public:
    vector2(int y)
    : y(y){}
    
    
    void print_vec(){
        cout << ", " << y << endl;
    }
    
    vector2 operator+(const vector2& other) const
    {
        return vector2(y + other.y);
    }
};

class shape{
public:
    shape(int l, int w)
    :length(l), width(w){}
    
    virtual void GetArea(){
        cout << "parent class" << endl;
    }
protected:
    int length, width;
};

class rectangular : public shape{
public:
    rectangular(int l, int w)
        :shape(l, w) {}
    void GetArea() override{
        cout << length * width << endl;
    }
};

class String{
private:
    int m_size;
    char *m_Buffer;
public:
    String(const char* string){
        m_size = (int) strlen(string);
        m_Buffer = new char[m_size + 1];
        memcpy(m_Buffer, string, m_size + 1);
        m_Buffer[m_size] = 0;
    }
    String(const String& other)
    : m_size(other.m_size){
        m_Buffer = new char[m_size + 1];
        memcpy(m_Buffer, other.m_Buffer, m_size + 1);
    }
    ~String(){
        delete [] m_Buffer;
    }
    char& operator[](unsigned int index){
        return m_Buffer[index];
    }
    friend std::ostream& operator<<(std::ostream& stream, const String& string);
};

std::ostream& operator<<(std::ostream& stream, const String& string){
    stream << string.m_Buffer;
    return stream;
}
int main(int argc, const char * argv[]) {

    String s1("Abdelrahman");
    String s2 = s1;
    
    cout << s1 << endl;
    cout << s2 << endl;
    
    s2[3] = '_';
    
    cout << s1 << endl;
    cout << s2 << endl;
//    shape* s;
//    rectangular rect(20, 10);
//    rect.GetArea();
//    s = &rect;
//
//    s->GetArea();
    
//    int x = 10;
//    int y = 20;
//
//    int* const ptr = &x;
//    ptr = &y;
//
//    *ptr = 30;
    
    
//    //operator overloading
//    vector2 speed = 10; // implicit conversion
//    vector2 position(39);
//    vector2 sum = speed + position;
//
//    sum.print_vec();
//    speed.print_vec();
//    position.print_vec();
    
//    int x = 90;
//
//    func_2(&x);
//    cout << x << "\n";
    

//    char arr[4] = {1, 2, 3, 4};
//    cout << sizeof(arr) << endl;
//    arr_size(arr);
    
    
//    Entity *e = new Entity();
//    cout << e->GetName() << endl;
//
//    Player *p = new Player("Abdelrahman");
//    Entity *entity = p;
//    cout << entity->GetName() << endl;
//
    
    
//    std::string expresion = "(12 + 12}";
//
//    if(areBalanced(expresion)){
//        std::cout << "Balanced\n";
//    }
//    else{
//        std::cout << "Not Balanced\n";
//    }
    
//    node *test_node = new node(292992);
//    std::cout << test_node->val << std::endl;
}
