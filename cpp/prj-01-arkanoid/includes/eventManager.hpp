#ifndef EVENT_HPP
#define EVENT_HPP

#include <memory>
#include "platform.hpp"
#include "ball.hpp"
#include "definitions.hpp"

namespace gm{

void keystrokeManager(std::shared_ptr<gm::Platform>& paddle, std::shared_ptr<gm::Ball>& ball);

}// namespace gm

#endif
