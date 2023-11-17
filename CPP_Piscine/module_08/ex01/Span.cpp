#include "Span.hpp"

Span::Span() {
	_num = 0;
}
Span::Span (unsigned int num) : _num(num) {

}
Span::~Span() {

}
Span::Span(const Span &copy) {
	(*this) = copy;
}
Span &Span::operator=(const Span &other) {
	if (this != &other) {
		this->_num = other._num;
		this->_vec = other._vec;
	}
	return (*this);
} 

void Span::addNumber(unsigned int value) {
	if (_vec.size() >= _num) 
		throw SpanIsFull();
	_vec.push_back(value);
}

int Span::shortestSpan() {
	if (_vec.size() <= 1)
		throw SpanSizeLess();
	std::sort(_vec.begin(), _vec.end());
	int min = _vec[1] - _vec[0];
	for (unsigned int i = 1; i < _vec.size() - 1; i++) {
		if ((_vec[i + 1] - _vec[i]) < min)
			min = (_vec[i + 1] - _vec[i]);
	}
	return (min);
}

int Span::longestSpan() {
	if (_vec.size() <= 1)
		throw SpanIsFull();
	std::sort(_vec.begin(), _vec.end());
	// int min = *std::min_element(_vec.begin(), _vec.end());
	// int max = *std::max_element(_vec.begin(), _vec.end());
	// return (max - min);
	std::vector<int>::iterator min_it = std::min_element(_vec.begin(), _vec.end());
	std::vector<int>::iterator max_it = std::max_element(_vec.begin(), _vec.end());
	return (*max_it - *min_it);
}

const char* Span::SpanIsFull::what() const throw() {
    return "The data is full!";
}
const char* Span::SpanSizeLess::what() const throw() {
    return "You should add more data!";
}
const char* Span::SpanSizeNotEnough::what() const throw() {
    return "Span size less than this size!";
}

void Span::addRandomNumbers(unsigned int count) {
        if (count > (_num - _vec.size())) {
            throw SpanSizeNotEnough();
        }
		srand(time(NULL));
        for (unsigned int i = 0; i < count; i++) {
            _vec.push_back(std::rand() % 10000);
        }
}
void Span::printSpan() {
        for (unsigned int i = 0; i < _vec.size(); i++) {
            std::cout << _vec[i] << std::endl;
        }
}