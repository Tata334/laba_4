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
     
    cout << "=== Раннее связывание (по одному объекту каждого класса) ===\n";

    

    FeatureFilm ff("Начало", "Фантастика", 2010, 8.8, false, "К. Нолан");
    PrintFilm(ff);
    ff.Watch();
    cout << "\n";

    Series s("Уэнтворт", "Драма", 2013, 8.6, false,
        "Кевин Карлин", 8, 100);
    PrintFilm(s);
    s.Watch();
    cout << "\n";

    Documentary d("Майкл Джексон: Вот и всё", "Документальный",
        2009, 7.8, false,
        "Репетиции тура This Is It");
    PrintFilm(d);
    d.Watch();
    cout << "\n";
     
    cout << "=== Позднее связывание: выберите объект ===\n";
    cout << "1 - FeatureFilm\n";
    cout << "2 - Series\n";
    cout << "3 - Documentary\n";
    cout << "Ваш выбор: ";

    int choice;
    cin >> choice;

    Film* poly = nullptr;   

    switch (choice) {
    case 1:
        poly = new FeatureFilm("Аватар", "Фантастика",
            2009, 7.9, false, "Джеймс Кэмерон");
        break;
    case 2:
        poly = new Series("Уэнтворт", "Драма", 2013, 8.6, false,
            "Кевин Карлин", 8, 80);
        break;
    case 3:
        poly = new Documentary("Майкл Джексон: Вот и всё",
            "Документальный", 2009, 7.3, false,
            "Репетиции тура This Is It");
        break;
    default:
        cout << "Неверный выбор. Создан FeatureFilm по умолчанию.\n";
        poly = new FeatureFilm();
        break;
    }
     
    PrintFilm(*poly);
    poly->Watch();           

    delete poly;             

    return 0;
}