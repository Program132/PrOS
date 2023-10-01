#include "GetTimeDate.h"

QString os_getDate() {
    std::time_t rawtime;
    std::tm *timeinfo;
    char buffer[80];
    std::time(&rawtime);
    timeinfo = std::localtime(&rawtime);
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d", timeinfo);
    QString dateString(buffer);
    return dateString;
}

QString os_getTime() {
    std::time_t rawtime;
    std::tm *timeinfo;
    char buffer[80];
    std::time(&rawtime);
    timeinfo = std::localtime(&rawtime);
    std::strftime(buffer, sizeof(buffer), "%H:%M:%S", timeinfo);
    QString timeString(buffer);
    return timeString;
}