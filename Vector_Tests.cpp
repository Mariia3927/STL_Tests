//
//  Vector_Tests.cpp
//  STL_Tests
//
//  Created by MariyaShestakova on 9/9/19.
//  Copyright © 2019 MariyaShestakova. All rights reserved.
//

#include "STL_Header.h"

std::vector<int> MakeRandomVector(int count, int leftBound = 0, int rightBound = 100)
{
    srand(time(0));
    
    std::vector<int> vec;
    vec.reserve(count);
    
    for(int i = 0; i < count; i++)
    {
        vec.push_back(leftBound + rand() % (rightBound - leftBound));
    }
    
    return vec;
}

TEST(Fill, fill_vector_with_random_values)
{
    auto vec = MakeRandomVector(g_numberOfElements);
    
    EXPECT_EQ(g_numberOfElements, vec.size());
}

std::vector<int> MakeVectorWithRandomGenerator(int count, int leftBound = 0, int rightBound = 100)
{
    std::random_device randDev;
    std::mt19937 randGen;
    std::uniform_int_distribution<> dis(leftBound, rightBound);
    
    std::vector<int> vec;
    vec.resize(count);
    
    std::generate(vec.begin(), vec.end(), std::bind(dis, std::ref(randGen)));
    
    return vec;
}

TEST(FillWithStandartRandomGenerator, fill_vector_with_standart_random_generator)
{
    auto vec = MakeVectorWithRandomGenerator(g_numberOfElements);
    
    EXPECT_EQ(g_numberOfElements, vec.size());
}

std::vector<int> MakeVector()
{
    std::vector<int> vec = {7, 3, 90, 25, 67, 34, 1, 87, 0, 45, 99, 2, 15, 76, 45, 0, 25, -7, 37, 19, -45, 12, 90, -67, 82, 5, 43, -56, 78, 0, 33, 71, -6, 89, -45, 81, 29, -8, 0, 38, 44, -71, 98, 53, -65, 88, 39, 27, 17, -69, 0, 47, 19, 77, -24, 0, 55, 73, 68, 54, -71, 15, 0, 40, 32, 13, 0, -51, 90, 44, 17, -93, 58, 69, 34, 0, 55, 22, 11, 99, 100, -58, 7, 3, 90, 25, 67, 34, 1, 87, 0, 45, 99, 2, 15, 76, 45, 0, 25, -7};
    
    return vec;
}


TEST(pop_back, pop_back_value_from_vector)
{
    std::vector<std::string> vecStr = {"One", "Two", "Three", "Four", "Five"};
    
    vecStr.pop_back();
    EXPECT_EQ(vecStr, std::vector<std::string>({"One", "Two", "Three", "Four"}));
    
    vecStr.pop_back();
    EXPECT_EQ(vecStr, std::vector<std::string>({"One", "Two", "Three"}));
}

TEST(indexing, receive_values_from_vector_using_indexing_operator)
{
    std::vector<std::string> vecStr = {"One", "Two", "Three", "Four", "Five"};

    EXPECT_EQ(vecStr[0], "One");

    EXPECT_EQ(vecStr[1], "Two");

    EXPECT_EQ(vecStr[2], "Three");

    EXPECT_EQ(vecStr[3], "Four");

    EXPECT_EQ(vecStr[4], "Five");
    
    EXPECT_NO_THROW(vecStr[200]); //it is weird, the indexing operator does not throw any exception even if we get out from the range bounds
}

TEST(at, receive_values_from_vector_using_at)
{
    std::vector<std::string> vecStr = {"One", "Two", "Three", "Four", "Five"};
    
    EXPECT_EQ(vecStr.at(0), "One");
    
    EXPECT_EQ(vecStr.at(1), "Two");
    
    EXPECT_EQ(vecStr.at(2), "Three");
    
    EXPECT_EQ(vecStr.at(3), "Four");
    
    EXPECT_EQ(vecStr.at(4), "Five");
    
    EXPECT_THROW(vecStr.at(100), std::out_of_range);
}

TEST(insert, insert_single_value_into_vector)
{
    auto vec = MakeVector();
    
    auto iter = vec.insert(vec.begin() + 10, 55);
    
    EXPECT_EQ(55, vec[10]);
    EXPECT_EQ(55, *iter);
    EXPECT_EQ(g_numberOfElements + 1, vec.size());
}

TEST(insert, insert_count_equal_values_into_vector)
{
    auto vec = MakeVector();
    
    auto iter = vec.begin() + 10;
    
    int value = 55;
    int count = 8;
    
    iter = vec.insert(iter, count, value);
    
    EXPECT_EQ(std::find_if(iter, iter + count, [value](int i) -> bool { return i != value; }), iter + count);
    EXPECT_EQ(g_numberOfElements + count, vec.size());
}

TEST(insert, insert_range)
{
    auto vec1 = MakeVector();
    
    auto vec2 = MakeVector();
    
    EXPECT_TRUE(std::equal(vec2.begin(), vec2.end(), vec1.insert(vec1.begin() + 15, vec2.begin(), vec2.end())));
    EXPECT_EQ(2 * g_numberOfElements, vec1.size());
}

TEST(insert, insert_empty_range)
{
    auto vec1 = MakeVector();
    
    std::vector<int> vec2{};
    
    EXPECT_TRUE(std::equal(vec2.begin(), vec2.end(), vec1.insert(vec1.begin() + 20, vec2.begin(), vec2.end())));
    EXPECT_EQ(g_numberOfElements, vec1.size());
}


TEST(insert, insert_range_initializer_list)
{
    auto vec = MakeVector();

    std::initializer_list<int> initList = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    EXPECT_TRUE(std::equal(initList.begin(), initList.end(), vec.insert(vec.begin() + 30, initList)));
    EXPECT_EQ(g_numberOfElements + initList.size(), vec.size());
}

TEST(merge, merge_two_vectors)
{
    auto inputVec1 = MakeVector();
    std::sort(inputVec1.begin(), inputVec1.end());
    
    auto inputVec2 = MakeVector();
    std::sort(inputVec2.begin(), inputVec2.end());
    
    std::vector<int> outputVec;
    outputVec.reserve(inputVec1.size() + inputVec2.size());
    
    std::merge(inputVec1.begin(), inputVec1.end(), inputVec2.begin(), inputVec2.end(), std::back_inserter(outputVec));
    
    EXPECT_EQ(inputVec1.size() + inputVec2.size(), outputVec.size());
}

TEST(find, find_zero_values_in_vector)
{
    std::vector<int> vec {0, 5, 7, 1, 0, 4, 3, 5, 2, 0, 9, 34, 0, 23, 55, 0, 98, 100, 0, 8, 0};
    
    EXPECT_EQ(std::count(vec.begin(), vec.end(), 0), 7);
}

TEST(remove, remove_all_zero_values_from_vector)
{
    auto vec = MakeVector();

    vec.erase(std::remove(vec.begin(), vec.end(), 0), vec.end());

    EXPECT_EQ(std::find(vec.begin(), vec.end(), 0), vec.end());
}

TEST(remove, remove_all_negative_values_from_vector)
{
    auto vec = MakeVector();
    
    auto lambda = [](int i) -> bool { return i < 0; };
    
    vec.erase(std::remove_if(vec.begin(), vec.end(), lambda), vec.end());
    
    EXPECT_EQ(std::find_if(vec.begin(), vec.end(), lambda), vec.end());
}

struct Pet
{
    std::string name;
    std::string breed;
    int age;
    
    Pet(const std::string& petName, const std::string& petBreed, int petAge) : name(petName), breed(petBreed), age(petAge) {}
};

TEST(find, find_object_by_field_using_lambda)
{
    std::vector<Pet> vec = { Pet("Bonya", "European", 8), Pet("Alpha", "Pitbull", 7), Pet("Elya", "Miniature schnauzer", 15)};
    
    EXPECT_TRUE(std::find_if(vec.begin(), vec.end(), [](Pet pet) { return pet.name == "Alpha"; }) != vec.end());
}

TEST(copy, copy_one_vector_to_another_in_reverse_order)
{
    auto vecForCopy = MakeVector();
    
    std::vector<int> destinationVec;
    destinationVec.reserve(vecForCopy.size());
    
    std::reverse_copy(vecForCopy.begin(), vecForCopy.end(), back_inserter(destinationVec));
    
    EXPECT_TRUE(std::equal(vecForCopy.rbegin(), vecForCopy.rend(), destinationVec.begin()));
    EXPECT_EQ(destinationVec.size(), vecForCopy.size());
}

TEST(sort, sort_vector)
{
    std::vector<int> vec {3, 2, 5, 4, 1};
    
    std::sort(vec.begin(), vec.end());
    
    EXPECT_EQ(vec, std::vector<int>({1, 2, 3, 4, 5}));
}

