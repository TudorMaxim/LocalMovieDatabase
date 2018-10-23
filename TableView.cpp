#include "TableView.h"
#include <QFont>
#include <QBrush>

TableView::TableView(Controller& c, QObject* parent) : QAbstractTableModel (parent), ctrl(c) { }

TableView::~TableView() {}

int TableView::rowCount(const QModelIndex & parent) const {
	return this->ctrl.GetWatchList().size() + 1;
}

int TableView::columnCount(const QModelIndex & parent) const {
	return 6;
}

QVariant TableView::data(const QModelIndex & index, int role) const {
	int row = index.row();
	int column = index.column();
	std::vector<Movie> movies = this->ctrl.GetWatchList();
	if (row == movies.size()) {
		return QVariant();
	}
	Movie m = movies[row];

	if (role == Qt::DisplayRole || role == Qt::EditRole) {
		switch (column) {
		case 0:
			return QString::fromStdString(m.GetTitle());
		case 1:
			return QString::fromStdString(m.GetGenre());
		case 2:
			return QString::fromStdString(std::to_string(m.GetYear()));
		case 3:
			return QString::fromStdString((std::to_string(m.GetLikes())));
		case 4:
			return QString::fromStdString((std::to_string(m.GetDuration())));
		case 5:
			return QString::fromStdString(m.GetLink());
		default:
			break;
		}
	}
	if (role == Qt::FontRole) {
		QFont font("Times", 15, 10, true);
		font.setItalic(false);
		return font;
	}
	if (role == Qt::BackgroundRole) {
		if (row % 2 == 1) {
			return QBrush{ QColor{ 0, 200, 150 } };
		}
		else {
			return QBrush{ QColor{ 0, 150, 200 } };
		}
	}
	return QVariant{};
}

QVariant TableView::headerData(int section, Qt::Orientation orientation, int role) const {
	if (role == Qt::DisplayRole) {
		if (orientation == Qt::Horizontal) {
			switch (section) {
			case 0:
				return QString{ "Title" };
			case 1:
				return QString{ "Genre" };
			case 2:
				return QString{ "Year" };
			case 3:
				return QString{ "Likes" };
			case 4:
				return QString{ "Duration" };
			case 5:
				return QString{ "Link" };
			default:
				break;
			}
		}
	}
	if (role == Qt::FontRole) {
		QFont font("Times", 15, 10, true);
		font.setBold(true);
		font.setItalic(false);
		return font;
	}
	return QVariant{};
}

bool TableView::setData(const QModelIndex & index, const QVariant & value, int role) {
	if (!index.isValid() || role != Qt::EditRole) return false;

	int movieIndex = index.row();
	std::vector <Movie> movies = this->ctrl.GetWatchList();

	if (movieIndex == movies.size()) {
		this->beginInsertRows(QModelIndex{}, movieIndex, movieIndex);
		QString quotes = "";
		switch (index.column()) {
		case 0:
			this->ctrl.Add(Movie{ value.toString().toStdString(), quotes.toStdString(), quotes.toInt(), quotes.toInt(), quotes.toInt(), quotes.toStdString() });
			break;
		case 1:
			this->ctrl.Add(Movie{ quotes.toStdString(), value.toString().toStdString(), quotes.toInt(), quotes.toInt(), quotes.toInt(), quotes.toStdString() });
			break;
		case 2:
			this->ctrl.Add(Movie{ quotes.toStdString(), quotes.toStdString(), value.toInt(), quotes.toInt(), quotes.toInt(), quotes.toStdString() });
			break;
		case 3:
			this->ctrl.Add(Movie{ quotes.toStdString(), quotes.toStdString(), quotes.toInt(), value.toInt(), quotes.toInt(), quotes.toStdString() });
			break;

		case 4:
			this->ctrl.Add(Movie{ quotes.toStdString(), quotes.toStdString(), quotes.toInt(), quotes.toInt(), value.toInt(), quotes.toStdString() });
			break;

		case 5:
			this->ctrl.Add(Movie{ quotes.toStdString(), quotes.toStdString(), quotes.toInt(), quotes.toInt(),  quotes.toInt(),  value.toString().toStdString() });
			break;

		default:
			break;

		}
		this->endInsertRows();
		return true;
	}
	Movie& currentMovie = movies[movieIndex];
	switch (index.column()) {
	case 0:
		currentMovie.SetTitle(value.toString().toStdString());
		break;
	case 1:
		currentMovie.SetGenre(value.toString().toStdString());
		break;
	case 2:
		currentMovie.SetYear(value.toInt());
		break;
	case 3:
		currentMovie.SetLikes(value.toInt());
		break;
	case 4:
		currentMovie.SetDuration(value.toInt());
		break;
	case 5:
		currentMovie.SetLink(value.toString().toStdString());
		break;
	default:
		break;
	}
	this->ctrl.Update(currentMovie.GetTitle(), currentMovie);
	emit dataChanged(index, index);
	return true;
}
