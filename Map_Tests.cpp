//
//  Map_Tests.cpp
//  STL_Tests
//
//  Created by MariyaShestakova on 9/22/19.
//  Copyright © 2019 MariyaShestakova. All rights reserved.
//

#include "STL_Header.h"

TEST(single_element_insert_with_indexing_operator, indexing_operator)
{
    std::map<char, std::string> fruits;
    
    fruits['A'] = "Apple";
    fruits['B'] = "Banana";
    fruits['C'] = "Cherry";
    
    EXPECT_EQ(fruits.size(), 3);
    EXPECT_EQ(fruits['A'], "Apple");
    EXPECT_EQ(fruits['B'], "Banana");
    EXPECT_EQ(fruits['C'], "Cherry");
}

TEST(change_value_by_the_key_with_indexing_operator, indexing_operator)
{
    std::map<char, std::string> fruits;
    
    fruits['A'] = "Apple";
    fruits['B'] = "Banana";
    fruits['C'] = "Cherry";
    
    fruits['A'] = "Apricot";
    
    EXPECT_EQ(fruits.size(), 3);
    EXPECT_EQ(fruits['A'], "Apricot");
    EXPECT_EQ(fruits['B'], "Banana");
    EXPECT_EQ(fruits['C'], "Cherry");
}

TEST(single_element_insert_function, insert)
{
    std::map<char, std::string> fruits;
    
    std::pair<std::map<char, std::string>::iterator, bool> returnValue = fruits.insert(std::pair<char, std::string>('A', "Apple"));
    EXPECT_TRUE(returnValue.second);
    EXPECT_EQ(returnValue.first, fruits.find('A'));
    
    returnValue = fruits.insert(std::pair<char, std::string>('B', "Banana"));
    EXPECT_TRUE(returnValue.second);
    EXPECT_EQ(returnValue.first, fruits.find('B'));
    
    returnValue = fruits.insert(std::pair<char, std::string>('C', "Cherry"));
    EXPECT_TRUE(returnValue.second);
    EXPECT_EQ(returnValue.first, fruits.find('C'));
    
    EXPECT_EQ(fruits.size(), 3);
    EXPECT_EQ(fruits['A'], "Apple");
    EXPECT_EQ(fruits['B'], "Banana");
    EXPECT_EQ(fruits['C'], "Cherry");
}

TEST(single_element_insert_function_by_equal_key, insert)
{
    std::map<char, std::string> fruits;
    
    std::pair<std::map<char, std::string>::iterator, bool> returnValue = fruits.insert(std::pair<char, std::string>('A', "Apple"));
    EXPECT_TRUE(returnValue.second);
    EXPECT_EQ(returnValue.first, fruits.find('A'));
    
    returnValue = fruits.insert(std::pair<char, std::string>('B', "Banana"));
    EXPECT_TRUE(returnValue.second);
    EXPECT_EQ(returnValue.first, fruits.find('B'));
    
    returnValue = fruits.insert(std::pair<char, std::string>('C', "Cherry"));
    EXPECT_TRUE(returnValue.second);
    EXPECT_EQ(returnValue.first, fruits.find('C'));

    returnValue = fruits.insert(std::pair<char, std::string>('C', "Cherry"));
    EXPECT_FALSE(returnValue.second);
    EXPECT_EQ(returnValue.first, fruits.find('C'));
    
    
    EXPECT_EQ(fruits.size(), 3);
    EXPECT_EQ(fruits['A'], "Apple");
    EXPECT_EQ(fruits['B'], "Banana");
    EXPECT_EQ(fruits['C'], "Cherry");
}

TEST(single_value_insert_function_with_hint, insert)
{
    std::map<char, std::string> fruits;

    std::map<char, std::string>::iterator iter = fruits.insert(fruits.end(), std::pair<char, std::string>('A', "Apple"));

    fruits.insert(iter, std::pair<char, std::string>('B', "Banana"));

    fruits.insert(iter, std::pair<char, std::string>('C', "Cherry"));

    EXPECT_EQ(fruits.size(), 3);
    EXPECT_EQ(fruits['A'], "Apple");
    EXPECT_EQ(fruits['B'], "Banana");
    EXPECT_EQ(fruits['C'], "Cherry");
}

TEST(insert_range, insert)
{
    std::map<char, std::string> fruitsForInserting;
    
    fruitsForInserting['A'] = "Apple";
    fruitsForInserting['B'] = "Banana";
    fruitsForInserting['C'] = "Cherry";
    
    std::map<char, std::string> fruits;
    
    fruits.insert(fruitsForInserting.begin(), fruitsForInserting.end());
    
    EXPECT_EQ(fruits.size(), 3);
    EXPECT_EQ(fruits['A'], "Apple");
    EXPECT_EQ(fruits['B'], "Banana");
    EXPECT_EQ(fruits['C'], "Cherry");
}

TEST(insert_range_with_keys_existed_in_the_destination_map, insert)
{
    std::map<char, std::string> fruitsForInserting;
    
    fruitsForInserting['A'] = "Apple";
    fruitsForInserting['B'] = "Banana";
    fruitsForInserting['C'] = "Cherry";
    
    std::map<char, std::string> fruits;
    fruits['A'] = "Apricot";
    fruits['W'] = "Watermelon";
    
    fruits.insert(fruitsForInserting.begin(), fruitsForInserting.end());
    
    EXPECT_EQ(fruits.size(), 4);
    EXPECT_EQ(fruits['A'], "Apricot");
    EXPECT_EQ(fruits['B'], "Banana");
    EXPECT_EQ(fruits['C'], "Cherry");
    EXPECT_EQ(fruits['W'], "Watermelon");
}

TEST(emplace_single_value_to_map, emplace)
{
    std::map<char, std::string> fruits;
    
    std::pair<std::map<char, std::string>::iterator, bool> iter = fruits.emplace('A', "Apple");
    EXPECT_EQ(iter.first, fruits.find('A'));
    EXPECT_TRUE(iter.second);
    
    iter = fruits.emplace('B', "Banana");
    EXPECT_EQ(iter.first, fruits.find('B'));
    EXPECT_TRUE(iter.second);
    
    iter = fruits.emplace('C', "Cherry");
    EXPECT_EQ(iter.first, fruits.find('C'));
    EXPECT_TRUE(iter.second);
    
    EXPECT_EQ(fruits.size(), 3);
    EXPECT_EQ(fruits['A'], "Apple");
    EXPECT_EQ(fruits['B'], "Banana");
    EXPECT_EQ(fruits['C'], "Cherry");
}

TEST(emplace_single_value_with_key_existed_in_map, emplace)
{
    std::map<char, std::string> fruits;

    std::pair<std::map<char, std::string>::iterator, bool> iter = fruits.emplace('A', "Apple");
    EXPECT_EQ(iter.first, fruits.find('A'));
    EXPECT_TRUE(iter.second);

    iter = fruits.emplace('B', "Banana");
    EXPECT_EQ(iter.first, fruits.find('B'));
    EXPECT_TRUE(iter.second);

    iter = fruits.emplace('C', "Cherry");
    EXPECT_EQ(iter.first, fruits.find('C'));
    EXPECT_TRUE(iter.second);

    iter = fruits.emplace('A', "Apricot");
    EXPECT_EQ(iter.first, fruits.find('A'));
    EXPECT_FALSE(iter.second);

    EXPECT_EQ(fruits.size(), 3);
    EXPECT_EQ(fruits['A'], "Apple");
    EXPECT_EQ(fruits['B'], "Banana");
    EXPECT_EQ(fruits['C'], "Cherry");
}

TEST(emplace_single_value_with_hint_to_map, emplace_hint)
{
    std::map<char, std::string> fruits;
    
    std::map<char, std::string>::iterator iter = fruits.emplace_hint(fruits.begin(), 'A', "Apple");
    EXPECT_EQ(iter, fruits.find('A'));
    
    iter = fruits.emplace_hint(iter, 'B', "Banana");
    EXPECT_EQ(iter, fruits.find('B'));
    
    iter = fruits.emplace_hint(iter, 'C', "Cherry");
    EXPECT_EQ(iter, fruits.find('C'));
    
    EXPECT_EQ(fruits.size(), 3);
    EXPECT_EQ(fruits['A'], "Apple");
    EXPECT_EQ(fruits['B'], "Banana");
    EXPECT_EQ(fruits['C'], "Cherry");
}

TEST(erase_single_element_by_iterator, erase)
{
    std::map<char, std::string> fruits;
    
    fruits['A'] = "Apple";
    fruits['B'] = "Banana";
    fruits['C'] = "Cherry";
    
    fruits.erase(fruits.find('A'));
    EXPECT_EQ(fruits.size(), 2);

    fruits.erase(fruits.find('B'));
    EXPECT_EQ(fruits.size(), 1);

    fruits.erase(fruits.find('C'));
    EXPECT_EQ(fruits.size(), 0);
}

TEST(erase_single_element_by_key, erase)
{
    std::map<char, std::string> fruits;
    
    fruits['A'] = "Apple";
    fruits['B'] = "Banana";
    fruits['C'] = "Cherry";
    
    fruits.erase('A');
    EXPECT_EQ(fruits.size(), 2);
    
    fruits.erase('B');
    EXPECT_EQ(fruits.size(), 1);
    
    fruits.erase('C');
    EXPECT_EQ(fruits.size(), 0);
}

TEST(erase_range_of_elements, erase)
{
    std::map<char, std::string> fruits;
    
    fruits['A'] = "Apple";
    fruits['B'] = "Banana";
    fruits['C'] = "Cherry";
    fruits['L'] = "Lemon";
    fruits['P'] = "Plum";
    fruits['W'] = "Watermelon";
    
    fruits.erase(fruits.find('B'), fruits.find('L'));
    EXPECT_EQ(fruits.size(), 4);
    
    auto iter = fruits.find('A');
    EXPECT_EQ(iter->second, "Apple");
    
    iter = fruits.find('L');
    EXPECT_EQ(iter->second, "Lemon");
    
    iter = fruits.find('P');
    EXPECT_EQ(iter->second, "Plum");
    
    iter = fruits.find('W');
    EXPECT_EQ(iter->second, "Watermelon");
}

TEST(clear_the_map, clear)
{
    std::map<char, std::string> fruits;
    
    fruits['A'] = "Apple";
    fruits['B'] = "Banana";
    fruits['C'] = "Cherry";
    fruits['L'] = "Lemon";
    fruits['P'] = "Plum";
    fruits['W'] = "Watermelon";

    EXPECT_EQ(fruits.size(), 6);
    
    fruits.clear();
    EXPECT_EQ(fruits.size(), 0);
}

TEST(find_existing_element_in_map, find)
{
    std::map<char, std::string> fruits;
    
    fruits['A'] = "Apple";
    fruits['B'] = "Banana";
    fruits['C'] = "Cherry";
    fruits['L'] = "Lemon";
    fruits['P'] = "Plum";
    fruits['W'] = "Watermelon";

    EXPECT_TRUE(fruits.find('A') != fruits.end());
    EXPECT_TRUE(fruits.find('B') != fruits.end());
    EXPECT_TRUE(fruits.find('C') != fruits.end());
    EXPECT_TRUE(fruits.find('L') != fruits.end());
    EXPECT_TRUE(fruits.find('P') != fruits.end());
    EXPECT_TRUE(fruits.find('W') != fruits.end());
}

TEST(find_non_existing_element_in_map, find)
{
    std::map<char, std::string> fruits;
    
    fruits['A'] = "Apple";
    fruits['B'] = "Banana";
    fruits['C'] = "Cherry";
    fruits['L'] = "Lemon";
    fruits['P'] = "Plum";
    fruits['W'] = "Watermelon";
    
    EXPECT_TRUE(fruits.find('G') == fruits.end());
}

struct Person
{
    std::string m_firstName;
    std::string m_lastName;
    int m_age;
    int m_passportId;
    
    Person(std::string firstName, std::string lastName, int age, int passportId) : m_firstName(firstName), m_lastName(lastName), m_age(age), m_passportId(passportId) {}
    
    bool operator==(const Person& p) const
    {
        return this->m_passportId == p.m_passportId;
    }
    
    bool operator<(const Person& p) const
    {
        return this->m_passportId < p.m_passportId;
    }
};

TEST(struct_as_key_in_map, find)
{
    std::map<Person, std::string> persons;

    std::string description = "Person - FirstName LastName.\n";
    
    Person p1("FirstName", "LastName", 25, 1);
    persons[p1] = description;
    EXPECT_EQ(persons.size(), 1);
    EXPECT_TRUE(persons.find(p1) != persons.end());
    
    Person p2("FirstName", "LastName", 25, 2);
    persons.insert(std::pair<Person, std::string>(p2, description));
    EXPECT_EQ(persons.size(), 2);
    EXPECT_TRUE(persons.find(p2) != persons.end());
    
    persons.emplace(Person("FirstName", "LastName", 25, 3), description);
    EXPECT_EQ(persons.size(), 3);
    EXPECT_TRUE(persons.find(Person("FirstName", "LastName", 25, 3)) != persons.end());
    
    persons.erase(persons.find(p1));
    EXPECT_EQ(persons.size(), 2);
    EXPECT_TRUE(persons.find(p1) == persons.end());
    
    persons.erase(persons.find(p2), persons.find(Person("FirstName", "LastName", 25, 3)));
    EXPECT_EQ(persons.size(), 1);
    EXPECT_TRUE(persons.find(p2) == persons.end());
    
    EXPECT_TRUE(persons.find(Person("FirstName", "LastName", 25, 3)) != persons.end());
}



