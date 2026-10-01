#pragma once
#include "feature_film.h"

class Series : public FeatureFilm
{
private:
    int seasons;
    int episodes;

public:
    Series();
    Series(const std::string& t, const std::string& g,
        int y, double r, bool w,
        const std::string& dir,
        int s, int e);
    ~Series() override;

    void SetSeasons(int s);
    void SetEpisodes(int e);
    int  GetSeasons()  const;
    int  GetEpisodes() const;

    void Watch() override;
};
