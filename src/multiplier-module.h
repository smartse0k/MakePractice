#pragma once

#include "module.h"

namespace extendable::calculator {
    class MultiplierModule : public Module {
        public:
            double execute(double, double);
    };
}
