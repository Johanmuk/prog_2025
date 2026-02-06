#include <iostream>
#include <ctime>
#include <clocale>
#include <string> 

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8"); 

    std::string input;
    time_t currentTime = time(0);
    struct tm *locateTime = localtime(&currentTime);
    int DayOfMonth = locateTime->tm_mday;
    int Month = locateTime->tm_mon + 1; 
    int Year = locateTime->tm_year + 1900;

    std::cout << "Введите фразу: ";
    std::getline(std::cin, input); 

    // Проверяем наличие ключевых слов вместо точного сравнения
    if (input.find("ебут") != std::string::npos || 
        input.find("раком") != std::string::npos || 
        input.find("крыс") != std::string::npos) {
        std::cout << "Да, сегодня " << DayOfMonth << "." << Month << "." << Year << "\t Что значит что оцельхира канон"<< std::endl;
    } else {
        std::cout << "Вы еблан. Длина ввода: " << input.length() << std::endl;
    }

    return 0;
}