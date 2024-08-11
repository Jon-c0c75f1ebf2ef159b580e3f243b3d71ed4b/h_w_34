//godbolt.org x86-64 clang (trunk) -std=c++20
#include <concepts>
#include <string>

template <typename T> 
concept ComplexConcept = requires(const T v) {
	{v.hash()}->std::convertible_to<long>;
	{v.toString()}->std::same_as<std::string>;
    } && !std::has_virtual_destructor<T>::value
;

struct Task {
	long hash() const {long w = 0; return w;};
    std::string toString() const { std::string q = "Hello, world!"; return q;};
}; 

void the_thing (ComplexConcept auto& t) {
	long tmp1 = t.hash();
    std::string tmp2 = t.toString();
}

int main() {
    Task task{};
    the_thing(task);

    return 0;
}
