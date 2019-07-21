/*
Obsevrer pattern has subject and observer interfaces and concrete classes.
Idea is based on the notification mechanism.
Output:
Weather Updated
App : AccuWeather Temperature : 20 Humidity : 30
App : DarkSky Temperature : 20 Humidity : 30
Weather Updated
App : AccuWeather Temperature : 50 Humidity : 30
*/

#include <bits/stdc++.h>
using namespace std;

class IWeatherData {
public:
    virtual int getTempRature() = 0;
    virtual int getHumidity() = 0;
};

class IWeatherApp {
public:
    virtual void weatherUpdated(shared_ptr<IWeatherData> wd) = 0;
};

class IWeather {
public:
    virtual void addAppHandle(shared_ptr<IWeatherApp> c) = 0;
    virtual void removeAppHandle(shared_ptr<IWeatherApp> c) = 0;
};

class WeatherStation : public IWeatherData, public IWeather, public std::enable_shared_from_this<WeatherStation> {
    int temperature_;
    int humidity_;
    list<shared_ptr<IWeatherApp>> AppHandles_;
public:
    //~WeatherStation() { cout << __FUNCTION__ << __LINE__ << endl; }
    
    virtual void addAppHandle(shared_ptr<IWeatherApp> c) override {
        AppHandles_.push_back(c);
    }
    
    virtual void removeAppHandle(shared_ptr<IWeatherApp> c) override {
        auto it = find(AppHandles_.begin(), AppHandles_.end(),c) ;
        if(it != AppHandles_.end())
            AppHandles_.erase(it);
    }
    
    void changeWeather(int temp, int hum) {
        temperature_ = temp;
        humidity_ = hum;
        
        cout << "Weather Updated\n";
        for(auto f : AppHandles_)
            f->weatherUpdated(shared_from_this());
    }
    
    int getTempRature(){
        return temperature_;
    }
    int getHumidity() {
        return humidity_;
    }
};

class AccuWeather : public IWeatherApp {
    string AppName_ = "AccuWeather";
public:
    //~AccuWeather() { cout << __FUNCTION__ << __LINE__ << endl; }

    void weatherUpdated(shared_ptr<IWeatherData> wd) {
        cout << "App : " << AppName_ << " Temperature : " << wd->getTempRature() << " Humidity : " << wd->getHumidity() << endl;
    }
};

class DarkSky : public IWeatherApp {
    string AppName_ = "DarkSky";
public:
    //~DarkSky() { cout << __FUNCTION__ << __LINE__ << endl; }

    void weatherUpdated(shared_ptr<IWeatherData> wd) {
        cout << "App : " << AppName_ << " Temperature : " << wd->getTempRature() << " Humidity : " << wd->getHumidity() << endl;
    }
};

int main() {
    shared_ptr<WeatherStation> ws(new WeatherStation());
    shared_ptr<AccuWeather> aw(new AccuWeather());
    shared_ptr<DarkSky> ds(new DarkSky());
    ws->addAppHandle(aw);
    ws->addAppHandle(ds);
    ws->changeWeather(20, 30);
    ws->removeAppHandle(ds);
    ws->changeWeather(50, 30);
    ws->removeAppHandle(ds);
    return 0;
}
