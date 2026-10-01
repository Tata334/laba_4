#pragma once
#include "film.h"

class FeatureFilm : public Film
{
protected:
    std::string director;  

public:
    FeatureFilm();
    FeatureFilm(const std::string& t, const std::string& g,
        int y, double r, bool w,
        const std::string& dir);
    virtual ~FeatureFilm();

    void SetDirector(const std::string& value);
    std::string GetDirector() const;

    void Watch() override;
};
