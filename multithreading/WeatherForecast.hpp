#include <map>
#include <string>
#include <iostream>
#include <chrono>
#include <thread>

class WeatherForecast
{
    public:
    WeatherForecast();
    void refreshWeatherForecast(std::map<std::string, int> weatherData);
};