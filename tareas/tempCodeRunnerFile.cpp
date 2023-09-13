
template <typename T>
T suma_producto(T value) {
    return value;
}

template<typename T, typename... Args>
T suma_producto(T value, Args... args) {
    if constexpr(sizeof...(args) == 0) {
        return value;
    } else if constexpr(sizeof...(args) % 2 == 0) {
        return value * suma_producto(args...) + suma_producto();
    } else {
        T last_value = std::get<sizeof...(args) - 1>(std::make_tuple(args...));
        return value * suma_producto(args...) + last_value;
    }
}