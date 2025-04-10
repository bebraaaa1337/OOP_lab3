#include <gtest/gtest.h>
#include "library.hpp"

using template_library::Vector;

TEST(VectorTest, PushBackAndAccess) {
    Vector<int> vec;
    EXPECT_EQ(vec.size(), 0);

    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    EXPECT_EQ(vec.size(), 3);
    EXPECT_EQ(vec[0], 10);
    EXPECT_EQ(vec[1], 20);
    EXPECT_EQ(vec[2], 30);
}

TEST(VectorTest, InitializerList) {
    Vector<int> vec = {1, 2, 3, 4, 5};
    EXPECT_EQ(vec.size(), 5);
    for (size_t i = 0; i < vec.size(); ++i) {
        EXPECT_EQ(vec[i], static_cast<int>(i + 1));
    }
}

TEST(VectorTest, AtMethodThrowsOutOfRange) {
    Vector<int> vec = {1, 2, 3};
    EXPECT_NO_THROW(vec.at(2));
    EXPECT_THROW(vec.at(3), std::out_of_range);
}

TEST(VectorTest, ResizeReserveClear) {
    Vector<int> vec;
    
    vec.resize(5, 42);
    EXPECT_EQ(vec.size(), 5);
    for (size_t i = 0; i < vec.size(); ++i) {
        EXPECT_EQ(vec[i], 42);
    }
    
    size_t oldCapacity = vec.capacity();
    vec.reserve(oldCapacity + 10);
    EXPECT_GE(vec.capacity(), oldCapacity + 10);
    
    vec.clear();
    EXPECT_EQ(vec.size(), 0);
}

TEST(VectorTest, CopyConstructorAndAssignment) {
    Vector<int> vec = {100, 200, 300};
    
    Vector<int> copy(vec);
    EXPECT_EQ(copy.size(), vec.size());
    for (size_t i = 0; i < vec.size(); ++i) {
        EXPECT_EQ(copy[i], vec[i]);
    }
    
    Vector<int> assign;
    assign = vec;
    EXPECT_EQ(assign.size(), vec.size());
    for (size_t i = 0; i < vec.size(); ++i) {
        EXPECT_EQ(assign[i], vec[i]);
    }
}

TEST(VectorTest, PopBack) {
    Vector<int> vec = {10, 20, 30};
    EXPECT_EQ(vec.size(), 3);
    vec.pop_back();
    EXPECT_EQ(vec.size(), 2);
    EXPECT_EQ(vec[1], 20);

    vec.clear();
    EXPECT_THROW(vec.pop_back(), std::out_of_range);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}