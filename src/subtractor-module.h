#pragma once

#include "module.h"

namespace extendable::calculator {
    class SubtractorModule : public Module {
        public:
            double execute(double, double);
    };
}
