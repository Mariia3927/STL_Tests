//
//  String_Tests.cpp
//  STL_Tests
//
//  Created by MariyaShestakova on 9/22/19.
//  Copyright © 2019 MariyaShestakova. All rights reserved.
//

#include "STL_Header.h"

TEST(find, find_non_existing_substring)
{
    std::string mainStr = "Flowers... I found a lot of beautiful flowers on the field.";
    
    EXPECT_TRUE(mainStr.find("dogs and cats") == std::string::npos);
}

TEST(find, find_substring)
{
    std::string mainStr = "I found a lot of beautiful flowers on the field.";
   
    EXPECT_TRUE(mainStr.find("flower") != std::string::npos);
}

TEST(find, find_substring_from_the_declared_position)
{
    std::string mainStr = "Flowers... I found a lot of beautiful flowers on the field.";
    
    EXPECT_TRUE(mainStr.find("flower", 6) != std::string::npos);
}

TEST(find, find_substring_from_the_declared_position_and_number_of_characters)
{
    std::string mainStr = "Flowers... I found a lot of beautiful flowers on the field.";
    
    EXPECT_TRUE(mainStr.find("flower is fragrant", 0, 6) != std::string::npos);
}

TEST(find, find_character_in_the_string)
{
    std::string mainStr = "Flowers... I found a lot of beautiful flowers on the field.";
    
    EXPECT_TRUE(mainStr.find('.', 10) != std::string::npos);
}

TEST(replace, replace_substring_in_the_string)
{
    std::string str = "Flowers... I found a lot of beautiful flowers on the field.";
    
    EXPECT_EQ(str.replace(19, 8, "a great many of"), "Flowers... I found a great many of beautiful flowers on the field.");
    
    EXPECT_EQ(str.replace(str.begin() + 19, str.begin() + 34, "a lot of"), "Flowers... I found a lot of beautiful flowers on the field.");
    
    EXPECT_THROW(str.replace(str.begin() + str.length() + 5, str.begin(), "throw an error"), std::out_of_range);
}

TEST(replace, replace_one_part_of_the_string_with_substring_of_another_string)
{
    std::string str1 = "Flowers... I found a lot of beautiful flowers on the field.";
    std::string str2 = "There is a nice day, the sun is shining brightly and there is not any clouds on the sky.";
    
    EXPECT_EQ(str1.replace(28, 9, str2, 11, 4), "Flowers... I found a lot of nice flowers on the field.");
    EXPECT_THROW(str1.replace(28, 9, str2, str2.length() + 1, 4), std::out_of_range);
}

TEST(replace, replace_part_of_string_with_c_string)
{
    std::string str = "Flowers... I found a lot of beautiful flowers on the field.";
    const char* cStr1 = "a great many of";
    const char* cStr2 = "a lot of";
    
    EXPECT_EQ(str.replace(19, 8, cStr1), "Flowers... I found a great many of beautiful flowers on the field.");
    EXPECT_EQ(str.replace(str.begin() + 19, str.begin() + 34, cStr2), "Flowers... I found a lot of beautiful flowers on the field.");
}

TEST(replace, replace_part_of_the_string_with_first_characters_of_the_c_string)
{
    std::string str = "Flowers... I found a lot of beautiful flowers on the field.";
    const char* cStr1 = "nice sunny day";
    const char* cStr2 = "beautiful fragrant";
    
    EXPECT_EQ(str.replace(28, 9, cStr1, 4), "Flowers... I found a lot of nice flowers on the field.");
    EXPECT_EQ(str.replace(str.begin() + 28, str.begin() + 32, cStr2, 9), "Flowers... I found a lot of beautiful flowers on the field.");
}

TEST(replace, replace_part_of_the_string_with_character)
{
    std::string str = "I found a lot of beautiful flowers on the field!";
    
    EXPECT_EQ(str.replace(str.length() - 1, 1, 3, '.'), "I found a lot of beautiful flowers on the field...");
    EXPECT_EQ(str.replace(str.begin() + str.length() - 3, str.end(), 7, '*'), "I found a lot of beautiful flowers on the field*******");
}

TEST(replace, replace_string_using_iterators)
{
    std::string str1 = "Flowers... I found a lot of beautiful flowers on the field.";
    std::string str2 = "Flowers... I found a great many of beautiful flowers on the field.";
    
    EXPECT_EQ(str1.replace(str1.begin() + 21, str1.begin() + 24, str2.begin() + 21, str2.begin() + 31), "Flowers... I found a great many of beautiful flowers on the field.");
}

TEST(replace, replace_string_using_initializer_list_of_characters)
{
    std::string str = "Flowers... I found a lot of beautiful flowers on the field.";
    std::initializer_list<char> initList = {'a', ' ', 'g', 'r', 'e', 'a', 't', ' ', 'm', 'a', 'n', 'y', ' ', 'o', 'f'};
    
    EXPECT_EQ(str.replace(str.begin() + 19, str.begin() + 27, initList), "Flowers... I found a great many of beautiful flowers on the field.");
}


