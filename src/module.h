#pragma once

namespace extendable::calculator {
    class Module {
        public:
            virtual double execute(double, double) = 0;
    };
}
