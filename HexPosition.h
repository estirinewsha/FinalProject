#ifndef HEXPOSITION_H_INCLUDED
#define HEXPOSITION_H_INCLUDED

namespace netWars
{

struct HexPosition
{
    // Cube storage, axial constructor
    const int q, r, s;
    HexPosition(int q_, int r_): q(q_), r(r_), s(-q_ - r_) {}
    HexPosition(int q_, int r_, int s_): q(q_), r(r_), s(s_) {}

    bool operator == (HexPosition b) {
        return q == b.q && r == b.r && s == b.s;
    }

    bool operator != (HexPosition b) {
        return !(*this == b);
    }
    operator sf::Vector2f()
    {
        sf::Vector2f pos;
        pos.x = ( sqrt(3.0) * q  + (sqrt(3.0)/2) *r)*71;
        pos.y =  ( 0.0 * q + (3.0/2) *r)*71;
        return pos;
    }

};

}
#endif // HEXPOSITION_H_INCLUDED
