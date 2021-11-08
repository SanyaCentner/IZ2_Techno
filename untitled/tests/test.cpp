#include <gtest/gtest.h>

extern "C" {
#include <string.h>
#include "parallel.h"
#include "sequential.h"
#include "utils.h"
};

//TEST(test_sequential, test1) {
//    char result_sequential[25] = {};
//    const char *file_with_mailers;
//    file_with_mailers = "mailer_test_1.txt";
//    const char *file_with_names;
//    file_with_names = "names_test_1.txt";
//    const char *file_with_recipients;
//    file_with_recipients = "recipients_test_1.txt";
//    const char *file_with_topic;
//    file_with_topic = "topic_test_1.txt";
//    const char *file_with_letter;
//    file_with_letter = "letter_test_1.txt";
//    const char *file_with_date;
//    file_with_date = "date_test_1.txt";
//    char date_start[12] = "2012.1.1";
//    char date_finish[12] = "2021.1.1";
//    sequential(file_with_names, file_with_mailers, file_with_recipients, file_with_topic,
//               file_with_letter, file_with_date, result_sequential, 32,
//               10, date_start, date_finish);
//    ASSERT_STREQ(result_sequential, "CaqJjZ@rambler.ru\n");
//}

TEST(test_parallel, test2) {
    char result_parallel[25] = {};
    const char *file_with_mailers;
    file_with_mailers = "mailer_test_1.txt";
    const char *file_with_names;
    file_with_names = "names_test_1.txt";
    const char *file_with_recipients;
    file_with_recipients = "recipients_test_1.txt";
    const char *file_with_topic;
    file_with_topic = "topic_test_1.txt";
    const char *file_with_letter;
    file_with_letter = "letter_test_1.txt";
    const char *file_with_date;
    file_with_date = "date_test_1.txt";
    char date_start[11] = "2012.1.1";
    char date_finish[11] = "2021.1.1";
    parallel(file_with_names, file_with_mailers, file_with_recipients, file_with_topic,
             file_with_letter, file_with_date, result_parallel, 32,
             10, date_start, date_finish);
    ASSERT_STREQ(result_parallel, "CaqJjZ@rambler.ru\n");
}

TEST(test_comparison, test3) {
char data_start[12] = "2014.9.9";
char data_finish[12] = "2020.12.1";
char data_test_1[12] = "2018.11.10";
char data_test_2[12] = "2012.10.29";
ASSERT_EQ(comparasion_date(data_start, data_finish, data_test_1), 0);
ASSERT_NE(comparasion_date(data_start, data_finish, data_test_2), 0);
}

TEST(test_maximum, test4) {
int massiv_number[6] = {1, 0, 6, 2, 10, 4};
ASSERT_NE(maximum(massiv_number, 6), 5);
ASSERT_EQ(maximum(massiv_number, 6), 4);
}

int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}


