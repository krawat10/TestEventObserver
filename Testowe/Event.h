#pragma once
#include <vector>

template<class C> class Event {
    std::vector<C> list;
public:
    template<class... ARGS> inline void add(ARGS&&... args)
    {
        list.emplace_back(args...);
    }
    template<class... ARGS> inline void notifyAll(ARGS&&... args)
    {
        for (auto&& x : list) x(args...);
    }
};

