#include "domainValidator.h"

MovieException::MovieException(std::vector<std::string> err) : error(err) {}

std::vector<std::string> MovieException::getErrors() const {
	return this->error;
}

MovieValidator::MovieValidator() {}

void MovieValidator::validate(const Movie& film) {
	std::vector<std::string> errors;

	if (!isupper(film.GetTitle()[0]))
		errors.push_back("The title of the movie must start with a capital letter!\n");

	if (film.GetDuration() == 0)
		errors.push_back("The duration cannot be 0!\n");

	int posWww = film.GetLink().find("www");
	int posHttp = film.GetLink().find("http");
	if (posWww != 0 && posHttp != 0)
		errors.push_back("The youtube link must start with \"www\" or \"http\"");

	if (errors.size() > 0)
		throw MovieException(errors);
}