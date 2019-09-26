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

    EXPECT_EQ(std::count(list.begin(), list.end(), 0), 3);
}

TEST(find_if, find_all_negative_values_in_the_list)
{
    auto list = MakeList();
    
    EXPECT_EQ(std::count_if(list.begin(), list.end(), [](int i) { return i < 0; }), 3);
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
    
    EXPECT_EQ(list, std::list<int>({5, 0, -1, -8, 0, -5}));
}


