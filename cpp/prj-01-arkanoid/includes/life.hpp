#ifndef LIFE_HPP
#define LIFE_HPP

#include <cstdint>

namespace gm{

class Life
{
public:
	explicit Life(uint16_t life);
    Life(Life const& other) = default;
    Life& operator=(Life const& other) = default;
	virtual ~Life() = default;

    uint16_t getCount() const;
    bool isKill() const;
    void add(uint16_t n);
    void sub(uint16_t n);

private:
    uint16_t m_count;
};

} // namespace gm

#endif
