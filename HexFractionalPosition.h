#ifndef HEXFRACTIONALPOSITION_H_INCLUDED
#define HEXFRACTIONALPOSITION_H_INCLUDED

#include "Coordinate/HexPosition.h"

namespace netWars
{

struct HexFractionalPosition {
    const double q, r, s;
    HexFractionalPosition(double q_, double r_, double s_)
    : q(q_), r(r_), s(s_) {}
    operator HexPosition()
    {
        int q_ = int(round(q));
        int r_ = int(round(r));
        int s_ = int(round(s));
        double q_diff = abs(q_ - q);
        double r_diff = abs(r_ - r);
        double s_diff = abs(s_ - s);
        if (q_diff > r_diff and q_diff > s_diff) {
            q_ = -r_ - s_;
        } else if (r_diff > s_diff) {
            r_ = -q_ - s_;
        } else {
            s_ = -q_ - r_;
        }
        return HexPosition(q_, r_, s_);
    }

};

}
#endif // HEXFRACTIONALPOSITION_H_INCLUDED
