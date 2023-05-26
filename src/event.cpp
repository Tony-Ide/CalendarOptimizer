#include "../header/event.hpp"

Event::Event(int r, Date* d, string n, int p, int t, int dur)
    : Todo(d, n, p, t, dur), recall(r) {
}
