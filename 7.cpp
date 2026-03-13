#include <vector>

template <typename T>
class MyList {
    std::vector<T> data;

public:
    MyList(std::vector<T> d) : data(d) {}

    template <typename Predicate>
    MyList filter(Predicate cond) const {
        std::vector<T> result;
        for (const T& x : data)
            if (cond(x)) result.push_back(x);
        return MyList(result);
    }

    const std::vector<T>& get() const { return data; }
};