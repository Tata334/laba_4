#pragma once
#include "film.h"

class Documentary : public Film
{
private:
    std::string topic;

public:
    Documentary();
    Documentary(const std::string& t, const std::string& g,
        int y, double r, bool w,
        const std::string& top);
    ~Documentary() override;

    void SetTopic(const std::string& value);
    std::string GetTopic() const;

    void Watch() override;
};