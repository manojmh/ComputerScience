#include <iostream>

enum Genre {
    Comedy=0,
    Thriller,
    Horror,
};

enum Langauge {
    Hindi = 0,
    Marathi,
    Kannada,
    Sanskrit
};

class Address {
public:
    std::string buildingName;
    std::string streatName;
    std::string areaName;
    std::string cityName;
    std::string pinCode;
};

class Seat {
public:
    Seat(std::string cinemaHallName, std::string audiName, std::string movieName, int col, int row, Show show, bool isAvailable = true)
        :
        , cinemaHallName(cinemaHallName)
        , audiName(audiName)
        , movieName(movieName)
        , col(col)
        , row(row)
        , show(show)
        , isAvailable(isAvailable) {}
private:
    std::string cinemaHallName;
    std::string audiName;
    std::string movieName;
    int col;
    int row;
    Show show;
    bool isAvailable;
};

class Audi {
public:
    Audi(std::string CinemaHall, std::string AudiName, const std::vector<std::shared<Seat>> &seats)
        : cinemaHall(cinemaHall)
        , audiName(audiName)
        , seats(seats) {}
private:
    std::string cinamaHall;
    std::string audiName;
    std::vector<shared_ptr<Seat>> seats;
};

class Movie {
public:
    Movie(std::string name, std::string desc, Language lang, Genre genre)
        : name(name), desc(desc), lang(lang), genre(genre), shows(shows) {}
private:
    std::string name;
    std::string desc;
    std::string lang;
    Genre genre;
    std::vector<Show> shows;
};

class Show {
public:
    Show(Audi audi, Movie movie, std::string startTime, std::string endTime)
        : audi(audi)
        , movie(movie)
        , startTime(startTime)
        , endTime(endTime)
private:
    Audi audi;
    Movie movie;
    str::string startTime;
    std::string endTime;
};

class City {
public:
    void CreateMovie();
private:
    std::map<Genre, std::vector<Movie>> moviesByGenre;
    std::map<Language, std::vector<Movie>> movieByLanguage;
};

class Admin {
public:
    std::shared<Cinema> CreateCinema();
    std::shared<Audi>   CreateAudi();
    
};

int main() {
        //create seats in audi
        int rows=0, cols=0;
        std::cout << "To Create Show Enter number of rows and cols : \n";
        std::cin >> rows >> cols;
        for(int row=0; row<rows; row++) {
            for (int col=0; col<cols; col++) {
                auto seat = make_shared<Seat>(cinemaName, audiName, movieName, col+1, row+1);
                seats.push_back(seat);       
            }
        }
        
        
        auto show = std::make_shared<Show>("DDLG", "Orion", "Audi1" seats);
        auto show = std::make_shared<Show>("KNPH", "Orion", "Audi2", audiName, seats);
    return 0;
}
