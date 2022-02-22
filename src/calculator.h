#pragma once

#include <string>
#include <map>

#include "module.h"

namespace extendable::calculator 
{
    class Calculator 
    {
        public:
            void addModule(std::string, Module*);
            double execute(std::string, double, double);
        private:
            std::map<std::string, Module*> modules;
    };
}
