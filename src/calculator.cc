#include "calculator.h"

namespace extendable::calculator 
{
    void Calculator::addModule(std::string name, Module *module)
    {
        modules.insert({name, module});
    }

    double Calculator::execute(std::string name, double input1, double input2)
    {
        auto it = modules.find(name);
        if (it == modules.end()) {
            throw -1;
        }

        Module *mod = it->second;
        
        double result = mod->execute(input1, input2);
        return result;
    }
}
