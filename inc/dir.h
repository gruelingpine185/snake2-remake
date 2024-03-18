#ifndef S2_DIR_H
#define S2_DIR_H


namespace s2 {
    enum class dir;
    enum class axis;


    enum class dir {
        up,
        down,
        left,
        right
    };

    enum class axis {
        x,
        y
    };


    constexpr bool on_axis(const axis _axis, const dir _dir) {
        if(_axis == s2::axis::x) {
            return ((_dir == s2::dir::left) || (_dir == s2::dir::right));
        }

        return ((_dir == s2::dir::up) || (_dir == s2::dir::down));
    }
}

#endif // S2_DIR_H
