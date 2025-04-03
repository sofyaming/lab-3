#ifndef NOTIFY_H
#define NOTIFY_H

#include <iostream>
#include <sstream>
#include <string>

//namespace template_library {

	// Реализуйте код классов и опеределение методов здесь
    class NotifierBase {
    public:
        virtual ~NotifierBase() = default;
        virtual void Notify(const std::string& message) const = 0;
    };

    class SmsNotifier : public NotifierBase {
    public:
        SmsNotifier(const std::string& number) : number_(number) {}
        void Notify(const std::string& message) const override;

    private:
        std::string number_;
    };

    class EmailNotifier : public NotifierBase {
    public:
        EmailNotifier(const std::string& email) : email_(email) {}
        void Notify(const std::string& message) const override;

    private:
        std::string email_;
    };
//}

#endif 
