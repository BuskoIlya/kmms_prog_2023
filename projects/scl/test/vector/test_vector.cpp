#include <gtest/gtest.h>

#include "vector.hpp"

using IBusko::Vector;

class Vectors : public testing::Test {
public:
    Vector<int> v1;
    Vector<double> v2;
    Vector<long long> v3;
};

TEST_F(Vectors, initialize_of_vector){
    ASSERT_EQ(v1.get_size(), 0)
        << "Пустой вектор int";
    ASSERT_EQ(v2.get_size(), 0)
        << "Пустой вектор double";
    ASSERT_EQ(v3.get_size(), 0)
        << "Пустой вектор long long";
};
TEST_F(Vectors, get_size){
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    ASSERT_EQ(v1.get_size(), 3)
        << "Неверный размер";
    v1.remove_first(1);
    v1.remove_first(2);
    v1.remove_first(3);
    ASSERT_EQ(v1.get_size(), 0)
        << "Неверный размер";
}

TEST_F(Vectors, push_back){
    v1.push_back(1);
    ASSERT_EQ(v1.get_size(), 1)
        << "Неверный размер";

    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(5);
    v1.push_back(6);
    v1.push_back(7);
    v1.push_back(8);
    v1.push_back(9);
    v1.push_back(10);
    v1.push_back(11);
    v1.push_back(12);
    v1.push_back(13);
    v1.push_back(14);

    ASSERT_EQ(v1.get_size(), 14)
        << "Неверный размер";
}
TEST_F(Vectors, remove_element){
    v1.push_back(1);
    v1.push_back(1);
    v1.remove_first(1);
    ASSERT_EQ(v1.get_size(), 1)
        << "Ошибка удаления существующего элемента";
    v1.remove_first(-1);
    ASSERT_EQ(v1.get_size(), 1)
        << "Ошибка удаления не существующего элемента";
    v1.remove_first(1);
    ASSERT_EQ(v1.get_size(), 0)
        << "Ошибка при удалении дублируюшеегося элемента";
}
TEST_F(Vectors, searching){
    v1.push_back(1);
    ASSERT_EQ(v1.has_item(1), true)
        << "Элемент не найден в векторе";
    ASSERT_EQ(v1.has_item(-1), false)
        << "Несуществующий элемент найден в векторе";
    v1.push_back(2);
    ASSERT_EQ(v1.has_item(2), true)
        << "Новый элемент не найден в векторе";
}

TEST_F(Vectors, insert){
    v1.insert(20, 10);
    ASSERT_EQ(v1.has_item(10), true)
        << "Нового элемента нет в векторе";
    ASSERT_EQ(v1.get_size(), 1)
        << "Новый элемент внёс неверное изменние в размер вектора";

    v1.insert(1, -10);

    ASSERT_EQ(v1.has_item(-10), true)
        << "Нового элемента нет в векторе";
    ASSERT_EQ(v1.get_size(), 2)
        << "Новый элемент внёс неверное изменние в размер вектора";
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
