#include "ipp.hpp"
#include <fstream>
#include <iostream>
using namespace std;
using namespace HORSE;
string horse::name() {
	return _name;
}
string horse::breed() {
	return _breed;
}
int horse::id() {
	return _id;
}

//operator
horse::horse(string name, string breed, int id) : _name(name), _breed(breed), _id(id) {}
ostream& HORSE::operator << (ostream & out, const horse& h) {
	out << h._name << " " << h._breed << " " << h._id << endl;
	return out;
}
istream& HORSE::operator >> (istream & in, horse& h) {
	in >> h._name >> h._breed >> h._id;
	return in;
}

//#1
horse * HORSE::loadNewHorses(int & count) {
	ifstream in("horse.txt");
	if (!in.is_open())
		return nullptr;
	in >> count;
	if (count < 1)
		return nullptr;
	horse *arr = new horse[count];
	for (int i = 0; i < count; i++)
		in >> arr[i];
	in.close();
	return arr;
}

//#2
horse * HORSE::createNewHorse(int & count) {
	count = 1;
	horse* arr = new horse[count];
	arr[0] = { "Bombastik", "Panzerkvagen III", 1};
	return arr;
}

//#3
void HORSE::saveHorse(horse *arr, int count) {
	ofstream out("horses.txt");
	out << count << endl;
	for (int i = 0; i < count; i++) {
		out << arr[i] << endl;
	}
	out.close();
}
//#4
void HORSE::addHorse(horse** arr, int* count) {
	horse* temp = new (nothrow) horse[*count + 1];
	if (temp == nullptr) {
		cout << "Memory error" << endl;
		return;
	}
	for (int i = 0; i < *count; i++) {
		temp[i] = (*arr)[i];
	}
	string name;
	string breed;
	int id;
	cout << "Enter horse name: " << endl;
	cin >> name;
	cout << "Enter horse breed: " << endl;
	cin >> breed;
	cout << "Enter horse id: " << endl;
	cin >> id;

	temp[*count].setName(name);
	temp[*count].setBreed(breed);
	temp[*count].setId(id);
	delete[] * arr;
	*arr = temp;
	(*count)++;
}
//#5
void HORSE::deleteHorse(horse *arr, int *count) {
	int n = 0;
	cout << "enter horse id: " << endl;
	cin >> n;
	if (n < 0, n >= (*count+1)) {
		cout << "current horse id not fount " << endl;
		return;
	}

	for (int i = (n-1); i < *count - 1; i++) {
		arr[i] = arr[i + 1];
	}
	(*count)--;
}

//#6
void HORSE::editHorse(horse *arr, int count) {
	int n = 0;
	cout << "enter horse id " << endl;
	cin >> n;
	if (n < 0, n >= (count + 1)) {
		cout << "current horse id not fount " << endl;
		return;
	}
	string temp = "";
	cout << "Enter new Horse name: " << endl;
	cin >> temp;
	arr[n-1].setName(temp);
	cout << "Enter new Horse breed: " << endl;
	cin >> temp;
	arr[n-1].setBreed(temp);
	int id = 0;
	cout << "Enter new Horse id: " << endl;
	cin >> id;
	arr[n-1].setId(id);
}

//#7
void HORSE::searchHorse(horse* arr, int count) {
	string name, breed;
	cout << "Enter name: ";
	cin >> name;
	cout << "Enter breed: ";
	cin >> breed;
	for (int i = 0; i < count; i++) {
		if (arr[i].name() == name && arr[i].breed() == breed) {
			cout << "Horse found: " << endl;
			cout << arr[i] << endl;
			return;
		}
	}
	cout << "Horse not found" << endl;
}

//#8
void HORSE::showHorseList(horse* arr, int count) {
	cout << "Horse list:" << endl;
	for (int i = 0; i < count; i++) {
		cout << i+1 << ". " << arr[i] << endl;
	}
}
