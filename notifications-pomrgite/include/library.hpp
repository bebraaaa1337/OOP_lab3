#ifndef NOTIFY_H
#define NOTIFY_H

#include <iostream>
#include <string>

namespace template_library {

// Объявление функций для отправки уведомлений
void SendSms(const std::string& number, const std::string& message);
void SendEmail(const std::string& email, const std::string& message);

class NotifierBase {
public:
    NotifierBase(const std::string& message) : message_(message) {}
    virtual void Notify(const std::string& message) const {
        std::cout << message_ << " " << message << std::endl;
    }
    virtual ~NotifierBase() = default;
    protected:
    std::string message_;
};

class SmsNotifier : public NotifierBase {
public:
    SmsNotifier(const std::string& number) : NotifierBase(number) {}
    
    void Notify(const std::string& message) const override {
        SendSms(message_, message);
    }
    ~SmsNotifier() override = default;
};

class EmailNotifier : public NotifierBase {
public:
    EmailNotifier(const std::string& email) : NotifierBase(email) {}
    
    void Notify(const std::string& message) const override {
        SendEmail(message_, message);
    }
    ~EmailNotifier() override = default;
};
}
#endif 