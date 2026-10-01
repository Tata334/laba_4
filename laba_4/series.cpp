#include "series.h"
#include <iostream>
using namespace std;

Series::Series()
    : FeatureFilm(), seasons(1), episodes(1)
{
    cout << "[DEBUG] Series()\n";
}

Series::Series(const string& t, const string& g,
    int y, double r, bool w,
    const string& dir,
    int s, int e)
    : FeatureFilm(t, g, y, r, w, dir),
    seasons(s > 0 ? s : 1),
    episodes(e > 0 ? e : 1)
{
    cout << "[DEBUG] Series(...)\n";
}

Series::~Series()
{
    cout << "[DEBUG] ~Series()\n";
}

void Series::SetSeasons(int s)
{
    if (s > 0) seasons = s;
    else cout << "[ОШИБКА] Сезонов должно быть > 0.\n";
}

void Series::SetEpisodes(int e)
{
    if (e > 0) episodes = e;
    else cout << "[ОШИБКА] Серий должно быть > 0.\n";
}

int Series::GetSeasons()  const { return seasons; }
int Series::GetEpisodes() const { return episodes; }

void Series::Watch()
{
    Film::Watch();
    cout << "  (сериал: " << seasons << " сезон(ов), "
        << episodes << " серий, режиссёр: " << director << ")\n";
}