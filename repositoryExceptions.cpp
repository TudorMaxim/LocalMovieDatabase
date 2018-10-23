#include "repositoryExceptions.h"

FileException::FileException(const std::string & msg) : message(msg) {}

const char* FileException::what() {
	return message.c_str();
}

RepositoryException::RepositoryException() : exception{}, message("") {}

RepositoryException::RepositoryException(const std::string & msg) : message(msg) {}

const char* RepositoryException::what() {
	return this->message.c_str();
}

const char* DuplicateMovieException::what() {
	return "The movie already exists!";
}

const char* InexistentMovieException::what() {
	return "The movie does not exist!";
}

const char* EmptyWatchListException::what() {
	return "The watch list is empty!";
}