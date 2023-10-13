//
// Created by marktiwnzhao on 2022/11/8.
//
#include <cassert>
#include <functional>
#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>

// 除了 TODO 标出的部分，不要修改原有的声明和定义，否则后果自负！

class MemoryContext {
public:
    /**
     * @param parent 父节点，可能为 nullptr
     */
    MemoryContext(MemoryContext *parent);

    ~MemoryContext();

    // 禁止拷贝和移动
    MemoryContext(const MemoryContext &) = delete;
    MemoryContext &operator=(const MemoryContext &) = delete;
    MemoryContext(MemoryContext &&) = delete;
    MemoryContext &operator=(MemoryContext &&) = delete;

    using chunk_id_t = std::string;

    void alloc(const chunk_id_t &chunk_id);

private:
    // TODO: your code
    MemoryContext* son{nullptr};
    MemoryContext* brother{nullptr};
    chunk_id_t* chunkId{nullptr};
};

MemoryContext::MemoryContext(MemoryContext *parent) {
    // TODO: your code
    if(parent) {
        MemoryContext* t = parent->son;
        if(t) brother = t;
        parent->son = this;
    }
}

MemoryContext::~MemoryContext() {
    // TODO: your code
    if(brother != nullptr) delete brother;
    brother = nullptr;
    if(son != nullptr) delete son;
    son = nullptr;
    if(chunkId) {
        int i = 0;
        while (chunkId[i] != "") ++i;
        for (int j = i - 1; j >= 0; --j) {
            std::cout << "Chunk " << chunkId[j] << " freed." << std::endl;
        }
    }
    delete []chunkId;
}

void MemoryContext::alloc(const chunk_id_t &chunk_id) {
    // TODO: your code
    if(!chunkId) {
        chunkId = new chunk_id_t[100];
        for(int i = 0; i < 100; ++i) chunkId[i] = "";
        chunkId[0] = chunk_id;
    } else {
        int i = 0;
        while(chunkId[i] != "") {
            i++;
        }
        chunkId[i] = chunk_id;
    }
}

void test_1() {
    std::unique_ptr<MemoryContext> A = std::make_unique<MemoryContext>(nullptr);
    A->alloc("1");
    A->alloc("2");
    A->alloc("3");
    A->alloc("4");
}

void test_2() {
    std::unique_ptr<MemoryContext> A = std::make_unique<MemoryContext>(nullptr);
    MemoryContext *B = new MemoryContext(A.get());
    MemoryContext *C = new MemoryContext(A.get());

    A->alloc("1");
    A->alloc("2");
    A->alloc("3");
    B->alloc("1/1");
    B->alloc("1/2");
    B->alloc("1/3");
    C->alloc("1/1/1");
    C->alloc("1/1/2");
    C->alloc("1/1/3");
}

void test_3() {
    std::unique_ptr<MemoryContext> A = std::make_unique<MemoryContext>(nullptr);
    MemoryContext *B = new MemoryContext(A.get());
    MemoryContext *C = new MemoryContext(A.get());
    MemoryContext *D = new MemoryContext(B);
    MemoryContext *E = new MemoryContext(C);
    MemoryContext *F = new MemoryContext(C);
    MemoryContext *G = new MemoryContext(E);

    A->alloc("1");
    A->alloc("2");
    A->alloc("3");
    B->alloc("1/1");
    C->alloc("1/2");
    D->alloc("1/1/1");
    D->alloc("1/1/2");
    G->alloc("1/2/1/1");
}

void test_4() {
    std::unique_ptr<MemoryContext> A = std::make_unique<MemoryContext>(nullptr);
    MemoryContext *B = new MemoryContext(A.get());
    MemoryContext *C = new MemoryContext(A.get());
    MemoryContext *D = new MemoryContext(B);
    MemoryContext *E = new MemoryContext(B);
    MemoryContext *F = new MemoryContext(C);
    MemoryContext *G = new MemoryContext(C);

    A->alloc("1");
    A->alloc("2");
    A->alloc("3");
    B->alloc("1/1");
    C->alloc("1/2");
    D->alloc("1/1/1");
    D->alloc("1/1/3");
    E->alloc("1/1/2");
    F->alloc("1/2/1");
    G->alloc("1/2/3");
    G->alloc("1/2/5");
    G->alloc("1/2/2");
    G->alloc("1/2/4");
}

void test_5() {
    std::unique_ptr<MemoryContext> A = std::make_unique<MemoryContext>(nullptr);
    MemoryContext *B = new MemoryContext(A.get());
    MemoryContext *C = new MemoryContext(A.get());
    MemoryContext *D = new MemoryContext(B);
    MemoryContext *G = new MemoryContext(C);

    A->alloc("2");
    A->alloc("1");
    A->alloc("3");
    A->alloc("4");
    B->alloc("2/1");
    B->alloc("3/5");
    C->alloc("1024/2");
    C->alloc("1024/1");
    G->alloc("8192/1/4095");
}

#define REGISTER_TEST_CASE(name) \
  { #name, name }

int main() {
    std::unordered_map<std::string, std::function<void()>>
            test_functions_by_name = {
            REGISTER_TEST_CASE(test_1), REGISTER_TEST_CASE(test_2),
            REGISTER_TEST_CASE(test_3), REGISTER_TEST_CASE(test_4),
            REGISTER_TEST_CASE(test_5),
    };

    std::string test_case_name;
    std::cin >> test_case_name;
    auto it = test_functions_by_name.find(test_case_name);
    assert(it != test_functions_by_name.end());
    auto fn = it->second;
    fn();
}
