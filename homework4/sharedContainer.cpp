//
// Created by marktiwnzhao on 2022/11/8.
//
#include <iostream>

class Content {
public:
    explicit Content(int id) : id(id) {
        std::cout << "create " << std::to_string(id) << std::endl;
    }

    ~Content() {
        std::cout << "destroy " << std::to_string(id) << std::endl;
    }

private:
    int id{-1};
    char data[1024]{};
};

class SharedContainer {
public:
    //TODO
    explicit SharedContainer(int mem_id);
    //TODO
    ~SharedContainer();
    //TODO
    SharedContainer(const SharedContainer &other);
    //TODO
    SharedContainer& operator=(const SharedContainer &other);
    //TODO
    int get_count() const;

    SharedContainer(const SharedContainer &&) = delete;
    SharedContainer &operator=(const SharedContainer &&) = delete;

private:
    Content *_data{nullptr};
    //TODO: design your own reference counting mechanism
    int* _count{nullptr};
};

SharedContainer::SharedContainer(int mem_id) : _data(new Content(mem_id)), _count(new int(1)){
}
SharedContainer::~SharedContainer() {
    --(*_count);
    if(*_count == 0) {
        delete _data;
        _data = nullptr;
        delete _count;
        _count = nullptr;
    }
}
SharedContainer::SharedContainer(const SharedContainer &other) : _data(other._data), _count(other._count){
    (*_count)++;
}
SharedContainer& SharedContainer::operator=(const SharedContainer &other) {
    if(this == &other) return *this;
    --(*_count);
    if(*_count == 0) {
        delete _data;
        delete _count;
    }
    _data = other._data;
    _count = other._count;
    (*_count)++;
}

int SharedContainer::get_count() const {
    return (*_count);
}
void test1(){
    SharedContainer m1(1);
    SharedContainer m2 = m1;
    SharedContainer m3(m2);
    std::cout << m1.get_count() << std::endl;
    std::cout << m2.get_count() << std::endl;
    std::cout << m3.get_count() << std::endl;
}

void test2(){
    SharedContainer m1(1);
    SharedContainer m2 = m1;
    m1 = m1;
    {
        SharedContainer m3 = m1;
        std::cout << m1.get_count() << std::endl;
    }
    std::cout << m1.get_count() << std::endl;
    std::cout << m2.get_count() << std::endl;
}

void test3(){
    SharedContainer m1(1);
    SharedContainer m2(2);
    m1 = m2;
    std::cout << m1.get_count() << std::endl;
    std::cout << m2.get_count() << std::endl;
    {
        SharedContainer m3(3);
        m1 = m3;
        std::cout << m1.get_count() << std::endl;
        std::cout << m2.get_count() << std::endl;
        std::cout << m3.get_count() << std::endl;
    }
    std::cout << m1.get_count() << std::endl;
    std::cout << m2.get_count() << std::endl;

}

int main(){
    test1();
    test2();
    test3();
    return 0;
}
