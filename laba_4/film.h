#pragma once
#include <string>

class Film
{
private:
    std::string* title;
    std::string* genre;
    int* year;
    double* rating;
    bool* watched;

    static bool IsValidTitle(const std::string& t);
    static bool IsValidGenre(const std::string& g);
    static bool IsValidYear(int y);
    static bool IsValidRating(double r);

    bool Init(const std::string& t, const std::string& g,
        int y, double r, bool w);

protected:
    Film();
    Film(const std::string& t, const std::string& g,
        int y, double r, bool w);

public:
    Film(const Film& other);
    Film& operator=(const Film& other);

    virtual ~Film();                 

    virtual void Watch() = 0;           

    void SetTitle(const std::string& value);
    void SetGenre(const std::string& value);
    void SetYear(int value);
    void SetRating(double value);
    void SetWatched(bool value);

    std::string GetTitle()  const;
    std::string GetGenre()  const;
    int         GetYear()   const;
    double      GetRating() const;
    bool        GetWatched()const;
};