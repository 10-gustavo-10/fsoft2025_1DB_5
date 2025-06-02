#ifndef REFEREE_H
#define REFEREE_H

#include <string>

class Referee {
private:
    std::string name;
    std::string nationality;

public:
    Referee(const std::string& name, const std::string& nationality);

    const std::string& getName() const;
    const std::string& getNationality() const;
};

#endif
