#include <iostream>
#include <clocale>
#include <vector>
#include "film.h"
#include "feature_film.h"
#include "series.h"
#include "documentary.h"
using namespace std;

void PrintFilm(const Film& f)
{
    cout << "--------------------------------\n";
    cout << "Название:    " << f.GetTitle() << "\n";
    cout << "Жанр:        " << f.GetGenre() << "\n";
    cout << "Год выпуска: " << f.GetYear() << "\n";
    cout << "Рейтинг:     " << f.GetRating() << "\n";
    cout << "Просмотрен:  " << (f.GetWatched() ? "Да" : "Нет") << "\n";

    if (const Series* s = dynamic_cast<const Series*>(&f)) {
        cout << "Режиссёр:    " << s->GetDirector() << "\n";
        cout << "Сезонов:     " << s->GetSeasons() << "\n";
        cout << "Серий:       " << s->GetEpisodes() << "\n";
    }
    else if (const FeatureFilm* ff = dynamic_cast<const FeatureFilm*>(&f)) {
        cout << "Режиссёр:    " << ff->GetDirector() << "\n";
    }
    else if (const Documentary* d = dynamic_cast<const Documentary*>(&f)) {
        cout << "Тема:        " << d->GetTopic() << "\n";
    }
    cout << "--------------------------------\n";
}

int main()
{
    setlocale(LC_ALL, "ru");

    cout << "=== 1. Film ===\n";
    Film film("Бойцовский клуб", "Триллер", 1999, 8.7, false);
    PrintFilm(film);
    film.Watch();
    cout << "\n";

    cout << "=== 2. FeatureFilm ===\n";
    FeatureFilm ff("Начало", "Фантастика", 2010, 8.8, false, "К. Нолан");
    PrintFilm(ff);
    ff.Watch();
    cout << "\n";


    cout << "=== 3. Series ===\n";
    Series s("Уэнтворт", "Драма", 2013, 8.6, false,
        "Кевин Карлин", 8, 100);
    PrintFilm(s);
    s.Watch();
    cout << "\n";

    cout << "=== 4. Documentary ===\n";
    Documentary d("Майкл Джексон: Вот и всё", "Документальный",
        2009, 7.8, false,
        "Репетиции тура This Is It");
    PrintFilm(d);
    d.Watch();
    cout << "\n";

    cout << "=== 5. Полиморфизм (vector<Film*>) ===\n";
    vector<Film*> all;
    all.push_back(new Film("Титаник", "Драма", 1997, 7.9, false));
    all.push_back(new FeatureFilm("Аватар", "Фантастика",
        2009, 7.9, false, "Джеймс Кэмерон"));
    all.push_back(new Series("Уэнтворт", "Драма", 2013, 8.6, false,
        "Кевин Карлин", 8, 80));
    all.push_back(new Documentary("Майкл Джексон: Вот и всё",
        "Документальный", 2009, 7.3, false,
        "Репетиции тура This Is It"));

    for (Film* p : all) {
        PrintFilm(*p);
        p->Watch();     
        cout << "\n";
    }

    for (Film* p : all) delete p;

    return 0;
}