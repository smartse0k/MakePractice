#pragma once

#include "module.h"

namespace extendable::calculator {
    class DividerModule : public Module {
        public:
            double execute(double, double);
    };
}
