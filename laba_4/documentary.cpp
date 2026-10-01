#include "documentary.h"
#include <iostream>
using namespace std;

Documentary::Documentary()
    : Film(), topic("Неизвестная тема")
{
    cout << "[DEBUG] Documentary()\n";
}

Documentary::Documentary(const string& t, const string& g,
    int y, double r, bool w,
    const string& top)
    : Film(t, g, y, r, w), topic(top)
{
    cout << "[DEBUG] Documentary(...)\n";
}

Documentary::~Documentary()
{
    cout << "[DEBUG] ~Documentary()\n";
}

void Documentary::SetTopic(const string& value)
{
    if (!value.empty()) topic = value;
    else cout << "[ОШИБКА] Пустая тема.\n";
}

string Documentary::GetTopic() const { return topic; }

void Documentary::Watch()
{
    Film::Watch();
    cout << "  (документальный, тема: " << topic << ")\n";
}