#pragma once

#include "module.h"

namespace extendable::calculator {
    class AdderModule : public Module {
        public:
            double execute(double, double);
    };
}
