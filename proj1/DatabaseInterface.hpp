#ifndef DATABASEINTERFACE_HPP
#define DATABASEINTERFACE_HPP
#include "database.hpp"
#include <vector>

database* CreateDatabase(std::string databasename);
bool entry(std::vector<std::string>);


#endif //DATABASEINTERFACE_HPP