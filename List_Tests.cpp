//
//  List_Tests.cpp
//  STL_Tests
//
//  Created by MariyaShestakova on 9/22/19.
//  Copyright © 2019 MariyaShestakova. All rights reserved.
//

#include "STL_Header.h"

std::list<int> MakeList()
{
    std::list<int> list = {5, 0, -1, 3, 9, 0, 7, -8, 0, -5};
    
    return list;
}

TEST(find, find_first_value_in_the_list_equal_three)
{
    auto list = MakeList();
    
    EXPECT_TRUE(std::find(list.begin(), list.end(), 3) != list.end());
}

TEST(find, find_not_existing_value_in_the_list)
{
    auto list = MakeList();
    
    EXPECT_TRUE(std::find(list.begin(), list.end(), 10) == list.end());
}

TEST(find, find_all_zero_values_in_the_list)
{
    auto list = MakeList();
    
    int count = 0;
    auto iter = list.begin();
    
xyz:    iter = std::find(iter, list.end(), 0);
    
    if(iter++ != list.end())
    {
        ++count;
        goto xyz;
    }
    
    EXPECT_EQ(count, 3);
}

TEST(find_if, find_all_negative_values_in_the_list)
{
    auto list = MakeList();
    
    int count = 0;
    auto iter = list.begin();
    while(iter != list.end())
    {
        iter = std::find_if(iter, list.end(), [](int i) -> bool { return i < 0; });
        ++iter;
        ++count;
    }
    
    EXPECT_EQ(count, 3);
}

TEST(erase, erase_single_element_from_the_list)
{
    auto list = MakeList();
    
    list.erase(std::find(list.begin(), list.end(), 3));
    
    EXPECT_EQ(9, list.size());
}

TEST(erase, erase_range_of_elements_from_the_list)
{
    auto list = MakeList();
    
    auto iterStartOfRange = list.begin();
    std::advance(iterStartOfRange, 3);
    
    auto iterEndOfRange = list.begin();
    std::advance(iterEndOfRange, 7);
    
    list.erase(iterStartOfRange, iterEndOfRange);
    
    std::list<int> tmp = {5, 0, -1, -8, 0, -5};
    
    EXPECT_EQ(list, tmp);
}


