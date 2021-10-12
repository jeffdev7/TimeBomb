#include <iostream>
#include <boost/asio.hpp>
#include <vector>

enum Wire {
    Blue = 1,
    Red,
    Green
};

void LessTime() {
    boost::asio::io_context io;
    boost::asio::steady_timer timer = boost::asio::steady_timer(io, boost::asio::chrono::seconds(2));
    std::cout << "You've only got 2 seconds to get out!" << std::endl;
    timer.wait();
    io.run();
    std::cout << "\nHASTA LA VISTA!";
};

void SpeedUp() {
    boost::asio::io_context io;
    boost::asio::steady_timer timer = boost::asio::steady_timer(io, boost::asio::chrono::seconds(1));
    std::cout << "\nHASTA LA VISTA!";
    timer.wait();
    io.run();
};
void Safe() {
    boost::asio::io_context io;
    boost::asio::steady_timer timer = boost::asio::steady_timer(io, boost::asio::chrono::seconds(3));
    std::cout << "\nBOMB DISARMED!";
    timer.cancel();
}

int main()
{
    std::cout << "\t=================Time Bomb====================\n\t\n\tDisarm the bomb before it explodes. \n\tYou have 3 seconds.\n" << std::endl;

    std::vector<std::pair<int, std::string>> wires{
        {1, "Blue"},
        {2, "Red"},
        {3, "Green"},
    };
    for (auto w = wires.begin(); w != wires.end(); ++w) {
        std::cout << "\t"<< w->first << " " << w->second << std::endl;
    }

    int choice;
    std::cout << "\t"; std::cin >> choice;

    switch (choice)
    {
    case Wire::Blue:Safe();
        break;
    case Wire::Green:LessTime();
        break;
    case Wire::Red:SpeedUp();
        break;
    default:
        break;
    }
    std::cin.get();
}