#include "HTMLWatchList.h"

using namespace std;

void HTMLWatchList::writeToFile() {
	ofstream fout(this->file_name);
	char quote = '"';

	if (!fout.is_open())
		throw FileException("The file could not be opened!");

	fout << "<!DOCTYPE html>" << "\n";
	fout << "<html>\n<head>\n<title>WatchList</title>\n</head>\n<body>\n";
	fout << "<table border=" << "1" << "> \n";
	fout << "<tr>\n<td>Title</td>\n<td>Genre</td>\n<td>Year</td>\n<td>Likes</td>\n<td>Duration</td>\n<td>Youtube link</td>\n</tr>\n";
	for (auto f : this->V) {
		fout << "<tr>\n<td>" << f.GetTitle() << "</td>\n<td>" << f.GetGenre() << "</td>\n<td>" << f.GetYear() << "</td>\n<td>" << f.GetLikes() << "</td>\n<td>" << f.GetDuration() << "</td>\n";
		fout << "<td><a href =" << quote << f.GetLink() << quote << ">Link</a></td>\n</tr>\n";
	}
	fout << "</table>\n</body>\n</html>\n";
	fout.close();
}

void HTMLWatchList::displayWatchList() const {
	string file = "E:\\Documente\\Tudor\\Facultate\\Semestrul_2\\OOP\\Lab5-6\\Lab5-6\\" + this->file_name;
	file = "file://" + file;
	ShellExecuteA(NULL, NULL, "firefox.exe", file.c_str(), NULL, SW_SHOWMAXIMIZED);
}

void HTMLWatchList::readFromFile() {
	ifstream fin(this->file_name);
	if (!fin.is_open()) {
		throw(FileException("The html file could not be opened! \n"));
	}

	string title, genre, year, likes, duration, link, s;
	for (int i = 0; i < 15; i++) {
		getline(fin, s);
	}

	getline(fin, s);
	while (s != "</table>" && !fin.eof()) {
		getline(fin, title);
		title = title.substr(4, title.size() - 9);
		getline(fin, genre);
		genre = genre.substr(4, genre.size() - 9);
		getline(fin, year);
		year = year.substr(4, year.size() - 9);
		getline(fin, likes);
		likes = likes.substr(4, likes.size() - 9);
		getline(fin, duration);
		duration = duration.substr(4, duration.size() - 9);
		getline(fin, link);
		link = link.substr(14, link.size() - 30);
		Movie m(title, genre, stoi(year), stoi(likes), stoi(duration), link);
		this->V.push_back(m);
		getline(fin, s);
		getline(fin, s);
	}
	fin.close();
}