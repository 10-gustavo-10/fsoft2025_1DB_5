#ifndef STADIUM_H
#define STADIUM_H

#include <string>

class Stadium {
private:
    std::string name;
    int capacity;
    std::string location;

public:
    Stadium(std::string  name, int capacity, std::string  location);

    const std::string& getName() const;
    int getCapacity() const;
    const std::string& getLocation() const;
};

#endif
