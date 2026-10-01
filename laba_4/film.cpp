#include "film.h"
#include <iostream>
using namespace std;

bool Film::IsValidTitle(const string& t) { return !t.empty() && t.length() <= 200; }
bool Film::IsValidGenre(const string& g) { return !g.empty() && g.length() <= 100; }
bool Film::IsValidYear(int y) { return y >= 1888 && y <= 2030; }
bool Film::IsValidRating(double r) { return r >= 0.0 && r <= 10.0; }

bool Film::Init(const string& t, const string& g,
    int y, double r, bool w)
{
    bool ok = true;

    if (IsValidTitle(t)) *title = t;
    else {
        cout << "[ОШИБКА] Некорректное название: \"" << t
            << "\". Значение по умолчанию.\n";
        *title = "Неизвестный фильм"; ok = false;
    }
    if (IsValidGenre(g)) *genre = g;
    else {
        cout << "[ОШИБКА] Некорректный жанр: \"" << g
            << "\". Значение по умолчанию.\n";
        *genre = "Неизвестный жанр"; ok = false;
    }
    if (IsValidYear(y)) *year = y;
    else {
        cout << "[ОШИБКА] Некорректный год: " << y
            << " (1888..2030). Значение по умолчанию.\n";
        *year = 0; ok = false;
    }
    if (IsValidRating(r)) *rating = r;
    else {
        cout << "[ОШИБКА] Некорректный рейтинг: " << r
            << " (0.0..10.0). Значение по умолчанию.\n";
        *rating = 0.0; ok = false;
    }
    *watched = w;
    return ok;
}

Film::Film()
    : title(new string()), genre(new string()),
    year(new int(0)), rating(new double(0.0)),
    watched(new bool(false))
{
    cout << "[DEBUG] Film()\n";
    Init("Неизвестный фильм", "Неизвестный жанр", 0, 0.0, false);
}

Film::Film(const string& t, const string& g,
    int y, double r, bool w)
    : title(new string()), genre(new string()),
    year(new int(0)), rating(new double(0.0)),
    watched(new bool(false))
{
    cout << "[DEBUG] Film(...)\n";
    if (!Init(t, g, y, r, w))
        cout << "[ПРЕДУПРЕЖДЕНИЕ] Некорректные значения заменены.\n";
}

Film::Film(const Film& other)
    : title(new string(*other.title)),
    genre(new string(*other.genre)),
    year(new int(*other.year)),
    rating(new double(*other.rating)),
    watched(new bool(*other.watched))
{
    cout << "[DEBUG] Film(const Film&)\n";
}

Film& Film::operator=(const Film& other)
{
    if (this != &other) {
        *title = *other.title;
        *genre = *other.genre;
        *year = *other.year;
        *rating = *other.rating;
        *watched = *other.watched;
    }
    return *this;
}

Film::~Film()
{
    cout << "[DEBUG] ~Film()\n";
    delete title;
    delete genre;
    delete year;
    delete rating;
    delete watched;
}

void Film::SetTitle(const string& v) { Init(v, *genre, *year, *rating, *watched); }
void Film::SetGenre(const string& v) { Init(*title, v, *year, *rating, *watched); }
void Film::SetYear(int v) { Init(*title, *genre, v, *rating, *watched); }
void Film::SetRating(double v) { Init(*title, *genre, *year, v, *watched); }
void Film::SetWatched(bool v) { *watched = v; }

string Film::GetTitle()  const { return *title; }
string Film::GetGenre()  const { return *genre; }
int    Film::GetYear()   const { return *year; }
double Film::GetRating() const { return *rating; }
bool   Film::GetWatched()const { return *watched; }

void Film::Watch()
{
    *watched = true;
    cout << "Фильм \"" << *title << "\" просмотрен!\n";
}