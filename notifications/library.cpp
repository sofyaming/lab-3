#include "library.hpp"

//namespace template_library {

    // Функция для отправки смс. Не менять!
    void SendSms(const std::string& number, const std::string& message) {
        std::cout << "Send '" << message << "' to number " << number << std::endl;
    }

    // Функция для отправки email. Не менять!
    void SendEmail(const std::string& email, const std::string& message) {
        std::cout << "Send '" << message << "' to e-mail " << email << std::endl;
    }

    // Реализация методов классов ниже...
    void SmsNotifier::Notify(const std::string& message) const {
        SendSms(number_, message);
    }

    void EmailNotifier::Notify(const std::string& message) const {
        SendEmail(email_, message);
    }

//}
int main() {

    //TEST(SmsNotifierTest, SendsCorrectSms)
    std::ostringstream output1;
    std::streambuf* old_cout_buffer1 = std::cout.rdbuf(output1.rdbuf());
    SmsNotifier sms("+7-495-777-77-77");
    sms.Notify("Hello! How are you?");
    std::cout.rdbuf(old_cout_buffer1);
    if (output1.str() != "Send 'Hello! How are you?' to number +7-495-777-77-77\n") {
        std::cout << "False" << "\n";
    }
    else {
        std::cout << "True" << "\n";
    }

    //TEST(EmailNotifierTest, SendsCorrectEmail)
    std::ostringstream output2;
    std::streambuf* old_cout_buffer2 = std::cout.rdbuf(output2.rdbuf());
    EmailNotifier email("test@mail.ru");
    email.Notify("Let's learn C++!");
    std::cout.rdbuf(old_cout_buffer2);
    if (output2.str() != "Send 'Let's learn C++!' to e-mail test@mail.ru\n") {
        std::cout << "False" << "\n";
    }
    else {
        std::cout << "True" << "\n";
    }
}
