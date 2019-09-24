//
//  Vector_Tests.cpp
//  STL_Tests
//
//  Created by MariyaShestakova on 9/9/19.
//  Copyright © 2019 MariyaShestakova. All rights reserved.
//

#include "STL_Header.h"

void Fill(std::vector<int>& vec, int count, int leftBound = 0, int rightBound = 100)
{
    srand(time(0));
    
    for(int i = 0; i < count; i++)
    {
        vec.push_back(leftBound + rand() % (rightBound - leftBound));
    }
}

TEST(Fill, fill_vector_with_random_values)
{
    std::vector<int> vec;
    Fill(vec, g_numberOfElements);
    
    EXPECT_EQ(g_numberOfElements, vec.size());
}

void FillWithStandartRandomGenerator(std::vector<int>& vec, int count, int leftBound = 0, int rightBound = 100)
{
    std::random_device randDev;
    std::mt19937 randGen;
    std::uniform_int_distribution<> dis(leftBound, rightBound);
    
    vec.resize(count);
    std::generate(vec.begin(), vec.end(), std::bind(dis, std::ref(randGen)));
}

TEST(FillWithStandartRandomGenerator, fill_vector_with_standart_random_generator)
{
    std::vector<int> vec;
    FillWithStandartRandomGenerator(vec, g_numberOfElements);
    
    EXPECT_EQ(g_numberOfElements, vec.size());
}

TEST(pop_back, pop_back_value_from_vector)
{
    std::vector<std::string> vecStr = {"One", "Two", "Three", "Four", "Five"};
    
    vecStr.pop_back();
    std::vector<std::string> result = {"One", "Two", "Three", "Four"};
    EXPECT_EQ(vecStr, result);
    
    vecStr.pop_back();
    std::vector<std::string> result1 = {"One", "Two", "Three"};
    EXPECT_EQ(vecStr, result1);
}

TEST(indexing, receive_values_from_vector_using_indexing_operator)
{
    std::vector<std::string> vecStr = {"One", "Two", "Three", "Four", "Five"};

    std::string firstWord = vecStr[0];
    EXPECT_EQ(firstWord, "One");

    std::string secondWord = vecStr[1];
    EXPECT_EQ(secondWord, "Two");

    std::string thirdWord = vecStr[2];
    EXPECT_EQ(thirdWord, "Three");

    std::string fourthWord = vecStr[3];
    EXPECT_EQ(fourthWord, "Four");

    std::string fifthWord = vecStr[4];
    EXPECT_EQ(fifthWord, "Five");
}

TEST(at, receive_values_from_vector_using_at)
{
    std::vector<std::string> vecStr = {"One", "Two", "Three", "Four", "Five"};
    
    std::string firstWord = vecStr.at(0);
    EXPECT_EQ(firstWord, "One");
    
    std::string secondWord = vecStr.at(1);
    EXPECT_EQ(secondWord, "Two");
    
    std::string thirdWord = vecStr.at(2);
    EXPECT_EQ(thirdWord, "Three");
    
    std::string fourthWord = vecStr.at(3);
    EXPECT_EQ(fourthWord, "Four");
    
    std::string fifthWord = vecStr.at(4);
    EXPECT_EQ(fifthWord, "Five");
}

TEST(insert, insert_single_value_into_vector)
{
    std::vector<int> vec;
    Fill(vec, g_numberOfElements);
    
    int pos = rand() % g_numberOfElements;
    auto iter = vec.begin() + pos;
    
    int value = rand() % g_numberOfElements;
    
    iter = vec.insert(iter, value);
    
    EXPECT_EQ(value, vec[pos]);
    EXPECT_EQ(value, *iter);
    EXPECT_EQ(g_numberOfElements + 1, vec.size());
}

TEST(insert, insert_count_equal_values_into_vector)
{
    std::vector<int> vec;
    Fill(vec, g_numberOfElements);
    
    int pos = rand() % g_numberOfElements;
    auto iter = vec.begin() + pos;
    
    int value = rand() % g_numberOfElements;
    int count = rand() % g_numberOfElements;
    
    iter = vec.insert(iter, count, value);
    auto iterPointedToFirstValueAfterInsertedRange = iter + count;
    
    bool result = true;
    while(iter != iterPointedToFirstValueAfterInsertedRange)
    {
        if(*iter != value)
        {
            result = false;
            break;
        }
        iter++;
    }
    
    EXPECT_TRUE(result);
    EXPECT_EQ(g_numberOfElements + count, vec.size());
}

TEST(insert, insert_range)
{
    std::vector<int> vec1;
    Fill(vec1, g_numberOfElements);
    
    int pos = rand() % g_numberOfElements;
    auto iterFirstVector = vec1.begin() + pos;
    
    std::vector<int> vec2;
    int count = rand() % g_numberOfElements;
    Fill(vec2, count);
    
    iterFirstVector = vec1.insert(iterFirstVector, vec2.begin(), vec2.end());
    
    bool result = true;
    auto iterSecondVector = vec2.begin();
    while(iterSecondVector != vec2.end())
    {
        if(*iterSecondVector != *iterFirstVector)
        {
            result = false;
            break;
        }
        iterFirstVector++;
        iterSecondVector++;
    }
    EXPECT_TRUE(result);
    EXPECT_EQ(g_numberOfElements + count, vec1.size());
}

TEST(insert, insert_empty_range)
{
    std::vector<int> vec1;
    Fill(vec1, g_numberOfElements);
    
    int pos = rand() % g_numberOfElements;
    auto iterFirstVector = vec1.begin() + pos;
    
    std::vector<int> vec2;
    int count = 0;
    Fill(vec2, count);
    
    iterFirstVector = vec1.insert(iterFirstVector, vec2.begin(), vec2.end());
    
    bool result = true;
    auto iterSecondVector = vec2.begin();
    while(iterSecondVector != vec2.end())
    {
        if(*iterSecondVector != *iterFirstVector)
        {
            result = false;
            break;
        }
        iterFirstVector++;
        iterSecondVector++;
    }
    
    EXPECT_TRUE(result);
    EXPECT_EQ(g_numberOfElements + count, vec1.size());
}


TEST(insert, insert_range_initializer_list)
{
    std::vector<int> vec;
    Fill(vec, g_numberOfElements);

    int pos = rand() % g_numberOfElements;
    auto iter = vec.begin() + pos;

    std::initializer_list<int> initList = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    iter = vec.insert(iter, initList);
    
    bool result = true;
    auto initListIter = initList.begin();
    while(initListIter != initList.end())
    {
        if(*iter != *initListIter)
        {
            result = false;
            break;
        }
        iter++;
        initListIter++;
    }
    
    EXPECT_TRUE(result);
    EXPECT_EQ(g_numberOfElements + initList.size(), vec.size());
}

TEST(merge, merge_two_vectors)
{
    std::vector<int> inputVec1;
    FillWithStandartRandomGenerator(inputVec1, g_numberOfElements);
    std::sort(inputVec1.begin(), inputVec1.end());
    
    std::vector<int> inputVec2;
    Fill(inputVec2, g_numberOfElements / 2);
    std::sort(inputVec2.begin(), inputVec2.end());
    
    std::vector<int> outputVec;
    outputVec.reserve(inputVec1.size() + inputVec2.size());
    
    std::merge(inputVec1.begin(), inputVec1.end(), inputVec2.begin(), inputVec2.end(), std::back_inserter(outputVec));
    
    EXPECT_EQ(inputVec1.size() + inputVec2.size(), outputVec.size());
}

TEST(find, find_zero_values_in_vector)
{
    std::vector<int> vec {0, 5, 7, 1, 0, 4, 3, 5, 2, 0, 9, 34, 0, 23, 55, 0, 98, 100, 0, 8, 0};
    
    int count = 0;
    auto iter = vec.begin();
    while(iter++ != vec.end())
    {
        iter = std::find(iter, vec.end(), 0);
        ++count;
    }
    EXPECT_EQ(count, 7);
}

TEST(remove, remove_all_zero_values_from_vector)
{
    std::vector<int> vec;
    FillWithStandartRandomGenerator(vec, g_numberOfElements, 0, 10);

    vec.erase(std::remove(vec.begin(), vec.end(), 0), vec.end());

    auto iter = std::find(vec.begin(), vec.end(), 0);

    EXPECT_EQ(iter, vec.end());
}

bool IsNegativeValue(int x)
{
    return (x < 0);
}

TEST(remove, remove_all_negative_values_from_vector)
{
    std::vector<int> vec;
    FillWithStandartRandomGenerator(vec, g_numberOfElements, -10, 10);
    
    vec.erase(std::remove_if(vec.begin(), vec.end(), IsNegativeValue), vec.end());
    
    auto iter = vec.begin();
    iter = std::find_if(vec.begin(), vec.end(), IsNegativeValue);
    
    EXPECT_EQ(iter, vec.end());
}

struct Pet
{
    std::string name;
    std::string breed;
    int age;
    
    Pet(std::string petName, std::string petBreed, int petAge) : name(petName), breed(petBreed), age(petAge) {}
};


TEST(find, find_object_by_field_using_lambda)
{
    std::vector<Pet> vec = { Pet("Bonya", "European", 8), Pet("Alpha", "Pitbull", 7), Pet("Elya", "Miniature schnauzer", 15)};
    
    auto iter = vec.begin();
    iter = std::find_if(iter, vec.end(), [](Pet pet) { return (pet.name == "Alpha"); });
    
    EXPECT_TRUE(iter != vec.end());
}

TEST(copy, copy_one_vector_to_another_in_reverse_order)
{
    std::vector<int> destinationVec;
    
    std::vector<int> vecForCopy;
    FillWithStandartRandomGenerator(vecForCopy, g_numberOfElements);
    
    destinationVec.resize(vecForCopy.size());
    std::reverse_copy(vecForCopy.begin(), vecForCopy.end(), destinationVec.begin());
    
    bool result = true;
    auto iterDestination = destinationVec.begin();
    auto iterSource = vecForCopy.rbegin();
    while(iterDestination != destinationVec.end())
    {
        if(*iterDestination != *iterSource)
        {
            result = false;
            break;
        }
        *iterDestination++;
        *iterSource++;
    }
    
    EXPECT_EQ(destinationVec.size(), vecForCopy.size());
    EXPECT_TRUE(result);
}

TEST(sort, sort_vector)
{
    std::vector<int> vec;
    FillWithStandartRandomGenerator(vec, g_numberOfElements);
    
    std::sort(vec.begin(), vec.end());
    
    bool result = true;
    auto iter = vec.begin();
    while(iter != vec.end() - 1)
    {
        if(*iter > *(iter + 1))
        {
            result = false;
        }
        ++iter;
    }
    
    EXPECT_TRUE(result);
}

