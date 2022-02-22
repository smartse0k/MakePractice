#include <iostream>
#include <string>

#include "calculator.h"

#include "adder-module.h"
#include "subtractor-module.h"
#include "multiplier-module.h"
#include "divider-module.h"

extendable::calculator::Calculator *calculator;

void init()
{
    std::cout << "The program is starting." << std::endl;

    calculator = new extendable::calculator::Calculator();

    extendable::calculator::Module *adder = new extendable::calculator::AdderModule();
    extendable::calculator::Module *substractor = new extendable::calculator::SubtractorModule();
    extendable::calculator::Module *multiplier = new extendable::calculator::MultiplierModule();
    extendable::calculator::Module *divider = new extendable::calculator::DividerModule();

    std::cout << "Calculator and modules are loaded." << std::endl;

    calculator->addModule("add", adder);
    calculator->addModule("sub", substractor);
    calculator->addModule("mul", multiplier);
    calculator->addModule("div", divider);

    std::cout << "Modules are attached to calculator." << std::endl;

    std::cout << "Testing some expression." << std::endl;
    std::cout << "1 + 2 = " << calculator->execute("add", 1, 2) << std::endl;
    std::cout << "10 - 7 = " << calculator->execute("sub", 10, 7) << std::endl;
    std::cout << "3 x 4 = " << calculator->execute("mul", 3, 4) << std::endl;
    std::cout << "48 / 8 = " << calculator->execute("div", 48, 8) << std::endl;
    std::cout << "Testing complete." << std::endl;

    std::cout << "The program is started." << std::endl;
}

void printUsage()
{
    std::cout << "== USAGE ==" << std::endl;
    std::cout << "COMMAND number number" << std::endl;
    std::cout << "COMMAND: add|sub|mul|div|exit" << std::endl;
    std::cout << "===========" << std::endl;
}

void run()
{
    std::string input;
    double number1, number2;
    
    while (true) {
        std::cout << ">";
        std::cin >> input;

        if (input == "exit") {
            break;
        }

        std::cin >> number1 >> number2;

        double ret = calculator->execute(input, number1, number2);
        std::cout << ret << std::endl;
    }
}

int main()
{
    init();
    printUsage();
    run();

    return 0;
}