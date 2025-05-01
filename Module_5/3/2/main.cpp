#include <iostream>
#include <catch2/catch_test_macros.hpp>
#include <cstdint>


struct ListNode
{
public:
    ListNode(int value, ListNode* prev = nullptr, ListNode* next = nullptr)
        : value(value), prev(prev), next(next)
    {
        if (prev != nullptr) prev->next = this;
        if (next != nullptr) next->prev = this;
    }

public:
    int value;
    ListNode* prev;
    ListNode* next;
};


class List
{
public:
    List()
        : m_head(new ListNode(static_cast<int>(0))), m_size(0),
        m_tail(new ListNode(0, m_head))
    {       
    }

    virtual ~List()
    {
        Clear();
        delete m_head;
        delete m_tail;
    }

    bool Empty() { return m_size == 0; }

    unsigned long Size() { return m_size; }

    void PushFront(int value)
    {
        new ListNode(value, m_head, m_head->next);
        ++m_size;
    }

    void PushBack(int value)
    {
        new ListNode(value, m_tail->prev, m_tail);
        ++m_size;
    }

    int PopFront()
    {
        if (Empty()) throw std::runtime_error("list is empty");
        auto node = extractPrev(m_head->next->next);
        int ret = node->value;
        delete node;
        return ret;
    }

    int PopBack()
    {
        if (Empty()) throw std::runtime_error("list is empty");
        auto node = extractPrev(m_tail);
        int ret = node->value;
        delete node;
        return ret;
    }

    void Clear()
    {
        auto current = m_head->next;
        while (current != m_tail)
        {
            current = current->next;
            delete extractPrev(current);
        }
    }

private:
    ListNode* extractPrev(ListNode* node)
    {
        auto target = node->prev;
        target->prev->next = target->next;
        target->next->prev = target->prev;
        --m_size;
        return target;
    }

private:
    ListNode* m_head;
    ListNode* m_tail;
    unsigned long m_size;
};



//Unit-test
TEST_CASE( "List functions testing", "[list]" ) {
    List list;

    SECTION("PushBack/PopBack operations") {
        list.PushBack(10);
        REQUIRE(list.Size() == 1);
        REQUIRE(list.PopBack() == 10);
        REQUIRE(list.Empty());
        
        // Check PopBack on empty list
        REQUIRE_THROWS_AS(list.PopBack(), std::runtime_error);
    }


    SECTION("PushFront/PopFront operations") {
        list.PushFront(20);
        REQUIRE(list.Size() == 1);
        REQUIRE(list.PopFront() == 20);
        REQUIRE(list.Empty());
        
        // Check PopFront on empty list
        REQUIRE_THROWS_AS(list.PopFront(), std::runtime_error);
    }


    SECTION("Complex oparations") {
        // Add elements at the begining and end
        list.PushFront(1);
        list.PushBack(2);
        list.PushFront(3);
        list.PushBack(4);
        
        REQUIRE(list.Size() == 4);
        
        // Check continious pop
        REQUIRE(list.PopFront() == 3);
        REQUIRE(list.PopBack() == 4);
        REQUIRE(list.PopFront() == 1);
        REQUIRE(list.PopBack() == 2);
        REQUIRE(list.Empty());
        
        // And again and clear
        list.PushBack(5);
        list.PushFront(6);
        list.Clear();
        REQUIRE(list.Empty());
    }
}
