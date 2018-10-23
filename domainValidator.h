#include "domain.h"
#include <vector>

class MovieException {
private:
	std::vector <std::string> error;
public:
	MovieException(std::vector<std::string> err);
	std::vector<std::string> getErrors() const;
};

class MovieValidator {
public:
	MovieValidator();
	void validate(const Movie& film);
};