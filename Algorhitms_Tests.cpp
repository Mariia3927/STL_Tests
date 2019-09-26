//
//  Algorhitms_Tests.cpp
//  STL_Tests
//
//  Created by MariyaShestakova on 9/22/19.
//  Copyright © 2019 MariyaShestakova. All rights reserved.
//

#include "STL_Header.h"

TEST(sort, sort_array_using_sort_function)
{
    int mas[] = {7, 3, 90, 25, 67, 34, 1, 87, 0, 45, 99, 2, 15, 76, 45, 0, 25, -7, 37, 19, -45, 12, 90, -67, 82, 5, 43, -56, 78, 0, 33, 71, -6, 89, -45, 81, 29, -8, 0, 38, 44, -71, 98, 53, -65, 88, 39, 27, 17, -69, 0, 47, 19, 77, -24, 0, 55, 73, 68, 54, -71, 15, 0, 40, 32, 13, 0, -51, 90, 44, 17, -93, 58, 69, 34, 0, 55, 22, 11, 99, 100, -58, 7, 3, 90, 25, 67, 34, 1, 87, 0, 45, 99, 2, 15, 76, 45, 0, 25, -7};
    int sortedMas[] = {-93,-71,-71,-69,-67,-65,-58,-56,-51,-45,-45,-24,-8,-7,-7,-6,0,0,0,0,0,0,0,0,0,0,0,1,1,2,2,3,3,5,7,7,11,12,13,15,15,15,17,17,19,19,22,25,25,25,25,27,29,32,33,34,34,34,37,38,39,40,43,44,44,45,45,45,45,47,53,54,55,55,58,67,67,68,69,71,73,76,76,77,78,81,82,87,87,88,89,90,90,90,90,98,99,99,99,100};

    std::sort(mas, mas + 100);

    EXPECT_TRUE(std::equal(mas, mas + 100, sortedMas, sortedMas + 100));
}

struct Dog
{
    std::string m_name;
    std::string m_breed;
    int m_id;
    
    Dog(const std::string& name, const std::string& breed, int id) : m_name(name), m_breed(breed), m_id(id) { }
    
    bool operator ==(const Dog& dog) const
    {
        return this->m_id == dog.m_id;
    }
};

struct DogCompare
{
    bool operator()(const Dog& dog1, const Dog& dog2) const
    {
        return dog1.m_id < dog2.m_id;
    }
} dogCompare;

TEST(sort, sort_array_of_user_defined_type)
{
    Dog dogs[] = { Dog("Alpha", "Pitbull", 123), Dog("Elya", "Miniature schnauzer", 2), Dog("Achill", "Miniature schnauzer", 35)};
    Dog sortedDogs[] = { Dog("Elya", "Miniature schnauzer", 2),  Dog("Achill", "Miniature schnauzer", 35), Dog("Alpha", "Pitbull", 123) };
    
    std::sort(dogs, dogs + 3, dogCompare);

    EXPECT_TRUE(std::equal(dogs, dogs + 3, sortedDogs, sortedDogs + 3));
}

TEST(partial_sort, sort_part_of_the_array)
{
    int mas[] = {7, 3, 90, 25, 67, 34, 1, 87, 0, 45, 99, 2, 15, 76, 45, 0, 25, -7, 37, 19, -45, 12, 90, -67, 82, 5, 43, -56, 78, 0, 33, 71, -6, 89, -45, 81, 29, -8, 0, 38, 44, -71, 98, 53, -65, 88, 39, 27, 17, -69, 0, 47, 19, 77, -24, 0, 55, 73, 68, 54, -71, 15, 0, 40, 32, 13, 0, -51, 90, 44, 17, -93, 58, 69, 34, 0, 55, 22, 11, 99, 100, -58, 7, 3, 90, 25, 67, 34, 1, 87, 0, 45, 99, 2, 15, 76, 45, 0, 25, -7};
    int sortedPartOfMas[] = {-93,-71,-71,-69,-67,-65,-58,-56,-51,-45,-45,-24,-8,-7,-7,-6,0,0,0,0};

    std::partial_sort(mas, mas + 20, mas + 100);
    EXPECT_TRUE(std::equal(mas, mas + 20, sortedPartOfMas, sortedPartOfMas + 20));
}

TEST(partial_sort, sort_part_of_the_array_using_lambda_as_compare_parameter)
{
    int mas[] = {7, 3, 90, 25, 67, 34, 1, 87, 0, 45, 99, 2, 15, 76, 45, 0, 25, -7, 37, 19, -45, 12, 90, -67, 82, 5, 43, -56, 78, 0, 33, 71, -6, 89, -45, 81, 29, -8, 0, 38, 44, -71, 98, 53, -65, 88, 39, 27, 17, -69, 0, 47, 19, 77, -24, 0, 55, 73, 68, 54, -71, 15, 0, 40, 32, 13, 0, -51, 90, 44, 17, -93, 58, 69, 34, 0, 55, 22, 11, 99, 100, -58, 7, 3, 90, 25, 67, 34, 1, 87, 0, 45, 99, 2, 15, 76, 45, 0, 25, -7};
    int sortedPartOfMas[] = {-93,-71,-71,-69,-67,-65,-58,-56,-51,-45,-45,-24,-8,-7,-7,-6,0,0,0,0};
    
    std::partial_sort(mas, mas + 20, mas + 100, [](int a, int b) -> bool { return a < b; });
    
    EXPECT_TRUE(std::equal(mas, mas + 20, sortedPartOfMas, sortedPartOfMas + 20));
}

TEST(nth_element, sort_part_of_the_array_using_nth_element)
{
    int mas[] = {7, 3, 90, 25, 67, 34, 1, 87, 0, 45, 99, 2, 15, 76, 45, 0, 25, -7, 37, 19, -45, 12, 90, -67, 82, 5, 43, -56, 78, 0, 33, 71, -6, 89, -45, 81, 29, -8, 0, 38, 44, -71, 98, 53, -65, 88, 39, 27, 17, -69, 0, 47, 19, 77, -24, 0, 55, 73, 68, 54, -71, 15, 0, 40, 32, 13, 0, -51, 90, 44, 17, -93, 58, 69, 34, 0, 55, 22, 11, 99, 100, -58, 7, 3, 90, 25, 67, 34, 1, 87, 0, 45, 99, 2, 15, 76, 45, 0, 25, -7};
    int sortedPartOfMas[] = {-93,-71,-71,-69,-67,-65,-58,-56,-51,-45,-45,-24,-8,-7,-7,-6,0,0,0,0};
    
    std::nth_element(mas, mas + 20, mas + 100);
    EXPECT_EQ(mas[19], 0);
    
    std::sort(mas, mas + 20);
    EXPECT_TRUE(std::equal(mas, mas + 20, sortedPartOfMas, sortedPartOfMas + 20));
}

bool Compare(int a, int b) { return a < b; }

TEST(nth_element, sort_part_of_the_array_using_nth_element_and_compare_function)
{
    int mas[] = {7, 3, 90, 25, 67, 34, 1, 87, 0, 45, 99, 2, 15, 76, 45, 0, 25, -7, 37, 19, -45, 12, 90, -67, 82, 5, 43, -56, 78, 0, 33, 71, -6, 89, -45, 81, 29, -8, 0, 38, 44, -71, 98, 53, -65, 88, 39, 27, 17, -69, 0, 47, 19, 77, -24, 0, 55, 73, 68, 54, -71, 15, 0, 40, 32, 13, 0, -51, 90, 44, 17, -93, 58, 69, 34, 0, 55, 22, 11, 99, 100, -58, 7, 3, 90, 25, 67, 34, 1, 87, 0, 45, 99, 2, 15, 76, 45, 0, 25, -7};
    int sortedPartOfMas[] = {-93,-71,-71,-69,-67,-65,-58,-56,-51,-45,-45,-24,-8,-7,-7,-6,0,0,0,0};
    
    std::nth_element(mas, mas + 20, mas + 100, Compare);
    EXPECT_EQ(mas[19], 0);
    
    std::sort(mas, mas + 20);
    EXPECT_TRUE(std::equal(mas, mas + 20, sortedPartOfMas, sortedPartOfMas + 20));
}

struct Predicate
{
    bool IsOdd(int i) { return i % 2; }
    bool operator()(int i) { return IsOdd(i); }
} pred;

TEST(partition, split_the_array_on_even_and_odd_values)
{
    int mas[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int masOfOddValues[] = {1, 3, 5, 7, 9};
    int masOfEvenValues[] = {0, 2, 4, 6, 8};
    
    std::partition(mas, mas + 10, pred);
    
    std::sort(mas, mas + 5);
    EXPECT_TRUE(std::equal(mas, mas + 5, masOfOddValues, masOfOddValues + 5));
    
    std::sort(mas + 5, mas + 10);
    EXPECT_TRUE(std::equal(mas + 5, mas + 10, masOfEvenValues, masOfEvenValues + 5));
}

TEST(min_element, find_min_element_in_the_array)
{
    int mas[] = {7, 3, 90, 25, 67, 34, 1, 87, 0, 45, 99, 2, 15, 76, 45, 0, 25, -7, 37, 19, -45, 12, 90, -67, 82, 5, 43, -56, 78, 0, 33, 71, -6, 89, -45, 81, 29, -8, 0, 38, 44, -71, 98, 53, -65, 88, 39, 27, 17, -69, 0, 47, 19, 77, -24, 0, 55, 73, 68, 54, -71, 15, 0, 40, 32, 13, 0, -51, 90, 44, 17, -93, 58, 69, 34, 0, 55, 22, 11, 99, 100, -58, 7, 3, 90, 25, 67, 34, 1, 87, 0, 45, 99, 2, 15, 76, 45, 0, 25, -7};
    
    EXPECT_EQ(*std::min_element(mas, mas + 100), -93);
}

enum WindDirection
{
    South, North, East, West
};

struct Weather
{
    int m_temperature;
    int m_windDirection;
  
    bool operator ==(const Weather& w) const { return this->m_temperature == w.m_temperature && this->m_windDirection == w.m_windDirection; }
    
    Weather(int temperature, int windDirection) : m_temperature(temperature), m_windDirection(windDirection) {}
};

struct CompareByTemperature
{
    bool operator()(const Weather& w1, const Weather& w2) const { return w1.m_temperature < w2.m_temperature; }
} compare;

TEST(min_element, find_min_temperature)
{
    Weather weatherByDays[] = { Weather(25, 1), Weather(20, 2), Weather(15, 3), Weather(10, 0) };
    
    EXPECT_EQ(*std::min_element(weatherByDays, weatherByDays + 4, compare), Weather(10, 0));
}

TEST(find_max_element_in_the_array, max_element)
{
    int mas[] = {7, 3, 90, 25, 67, 34, 1, 87, 0, 45, 99, 2, 15, 76, 45, 0, 25, -7, 37, 19, -45, 12, 90, -67, 82, 5, 43, -56, 78, 0, 33, 71, -6, 89, -45, 81, 29, -8, 0, 38, 44, -71, 98, 53, -65, 88, 39, 27, 17, -69, 0, 47, 19, 77, -24, 0, 55, 73, 68, 54, -71, 15, 0, 40, 32, 13, 0, -51, 90, 44, 17, -93, 58, 69, 34, 0, 55, 22, 11, 99, 100, -58, 7, 3, 90, 25, 67, 34, 1, 87, 0, 45, 99, 2, 15, 76, 45, 0, 25, -7};
    
    EXPECT_EQ(*std::max_element(mas, mas + 100), 100);
}

TEST(max_element, find_max_temperature)
{
    Weather weatherByDays[] = { Weather(20, 2), Weather(15, 3), Weather(25, 1), Weather(10, 0) };
    
    EXPECT_EQ(*std::max_element(weatherByDays, weatherByDays + 4, compare), Weather(25, 1));
}

TEST(min, find_min_from_two_values)
{
    int a = 27, b = 28;
    EXPECT_EQ(std::min(a, b), 27);
}

TEST(min, find_min_temperature_with_compare_object)
{
    Weather today(12, 2);
    Weather yesterday(10, 3);
    
    EXPECT_EQ(std::min(today, yesterday, compare), yesterday);
}

TEST(max, find_max_from_two_values)
{
    int a = 27, b = 28;
    EXPECT_EQ(std::max(a, b), 28);
}

TEST(max, find_max_temperature_with_compare_object)
{
    Weather today(12, 2);
    Weather yesterday(10, 3);
    
    EXPECT_EQ(std::max(today, yesterday, compare), today);
}



