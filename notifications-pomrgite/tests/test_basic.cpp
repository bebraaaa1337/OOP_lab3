#include <gtest/gtest.h>
#include <sstream>
#include "library.hpp" 

TEST(SmsNotifierTest, SendsCorrectSms) {
    std::ostringstream output; 
    std::streambuf* old_cout_buffer = std::cout.rdbuf(output.rdbuf()); 

    template_library::SmsNotifier sms("+7-495-777-77-77");
    sms.Notify("Hello! How are you?");

    std::cout.rdbuf(old_cout_buffer); 

    EXPECT_EQ(output.str(), "Send 'Hello! How are you?' to number +7-495-777-77-77\n");
}

TEST(EmailNotifierTest, SendsCorrectEmail) {
    std::ostringstream output; 
    std::streambuf* old_cout_buffer = std::cout.rdbuf(output.rdbuf()); 

    template_library::EmailNotifier email("test@mail.ru");
    email.Notify("Let's learn C++!");

    std::cout.rdbuf(old_cout_buffer); 

    EXPECT_EQ(output.str(), "Send 'Let's learn C++!' to e-mail test@mail.ru\n");
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
