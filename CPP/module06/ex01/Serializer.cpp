#include "Serializer.hpp"

Serializer::Serializer() {
}

Serializer::Serializer(Serializer const &cpy) {
	*this = cpy;
}

Serializer& Serializer::operator=(Serializer const &value) {
	(void)value;
	return *this;
}

uintptr_t Serializer::serialize(Data *ptr) {
	uintptr_t raw = reinterpret_cast<uintptr_t>(ptr);
	return raw;
}

Data *Serializer::deserialize(uintptr_t raw) {
	Data *ptr = reinterpret_cast<Data*>(raw);
	return ptr;
}

Serializer::~Serializer() {
}

