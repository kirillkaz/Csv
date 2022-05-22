#include "Csv.h"
#include "tests.h"
#include <gtest/gtest.h>

void test::runTests() {
    RUN_ALL_TESTS();
}

TEST(CSVTest,parsing){
    Csv CSVTEST;
    CSVTEST.parsing("test1");

    Csv CSV;
    std::vector<std::string> stroke;
    stroke.push_back("привет");
    stroke.push_back("как дела");
    stroke.push_back(" а?");
    CSV.CsvArray.push_back(stroke);
    for (int i = 0;i<CSVTEST.CsvArray.size();i++) EXPECT_EQ(CSV.CsvArray[i],CSVTEST.CsvArray[i]);
}

TEST(CSVTest2,parsing2){
    Csv CSVTEST;
    CSVTEST.parsing("test2");

    Csv CSV;
    std::vector<std::string> stroke;
    stroke.push_back("привет");
    stroke.push_back("как дела");
    stroke.push_back(" а?");
    CSV.CsvArray.push_back(stroke);

    stroke.clear();
    stroke.push_back("а тут");
    stroke.push_back("собственно");
    stroke.push_back("вторая строка и все хорошо, ибо число полей одинаковое");
    CSV.CsvArray.push_back(stroke);
    for (int i = 0;i<CSVTEST.CsvArray.size();i++) EXPECT_EQ(CSV.CsvArray[i],CSVTEST.CsvArray[i]);
}

TEST(CSVTest3,parsing3){
    Csv CSVTEST;
    CSVTEST.parsing("test3");

    Csv CSV;
    std::vector<std::string> stroke;
    stroke.push_back("один");
    stroke.push_back(" два");
    stroke.push_back(" три");
    stroke.push_back(" четыре");
    CSV.CsvArray.push_back(stroke);

    stroke.clear();
    stroke.push_back("один");
    stroke.push_back(" два");
    stroke.push_back(" три");
    CSV.CsvArray.push_back(stroke);
    for (int i = 0;i<CSVTEST.CsvArray.size();i++) EXPECT_EQ(CSV.CsvArray[i],CSVTEST.CsvArray[i]);
}

TEST(CSVTest4,parsing4){
    Csv CSVTEST;
    CSVTEST.parsing("test4");

    Csv CSV;
    std::vector<std::string> stroke;
    stroke.push_back("тут тещу ковычки");
    stroke.push_back("в ковычках можно писать слова с ,,,,,");
    stroke.push_back("а еще, \"в ковычках можно писать ковычки\"");
    CSV.CsvArray.push_back(stroke);

    for (int i = 0;i<CSVTEST.CsvArray.size();i++) EXPECT_EQ(CSV.CsvArray[i],CSVTEST.CsvArray[i]);
}

