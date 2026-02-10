#include "WeatherForecast.hpp"

using namespace std::chrono_literals;

/** main.cpp ->
 * 
 * std::map<std::string, int> weatherData = {{"Temperature", 30}, {"Humidity", 70}};

    std::thread t1(WeatherForecast::refreshWeatherForecast, WeatherForecast(), weatherData);

    t1.join();
 */


WeatherForecast::WeatherForecast()
{
    std::cout << "WeatherForecast Constructor called" << std::endl;
}

void WeatherForecast::refreshWeatherForecast(std::map<std::string, int> weatherData)
{
    while(true)
    {
        for (auto& item: weatherData)
        {
            item.second++;
            std::cout << item.first << " : " << item.second << std::endl;
        }
        std::this_thread::sleep_for(2000ms);
    }
}