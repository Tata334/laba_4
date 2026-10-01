#include "feature_film.h"
#include <iostream>
using namespace std;

FeatureFilm::FeatureFilm()
    : Film(), director("Неизвестный режиссёр")
{
    cout << "[DEBUG] FeatureFilm()\n";
}

FeatureFilm::FeatureFilm(const string& t, const string& g,
    int y, double r, bool w,
    const string& dir)
    : Film(t, g, y, r, w), director(dir)
{
    cout << "[DEBUG] FeatureFilm(...)\n";
}

FeatureFilm::~FeatureFilm()
{
    cout << "[DEBUG] ~FeatureFilm()\n";
}

void FeatureFilm::SetDirector(const string& value)
{
    if (!value.empty()) director = value;
    else cout << "[ОШИБКА] Пустой режиссёр.\n";
}

string FeatureFilm::GetDirector() const { return director; }

void FeatureFilm::Watch()
{
    Film::Watch();
    cout << "  (художественный, режиссёр: " << director << ")\n";
}