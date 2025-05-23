#include <iostream>
#include <string>
namespace HORSE {
	class horse {
		std::string _name;
		std::string _breed;
		int _id;
	public:
		horse() = default;
	        horse(std::string name, std::string breed, int id);
		std::string name();
		std::string breed();
		int id();
		friend std::ostream& operator << (std::ostream & out, const horse& h);
		friend std::istream& operator >> (std::istream & in, horse& h);
		void setName(const std::string& name) { _name = name; }
		void setBreed(const std::string& breed) { _breed = breed; }
		void setId(int id) { _id = id; }
	};
	std::ostream& operator << (std::ostream & out, const horse& h);
	std::istream& operator >> (std::istream & in, horse& h);
        horse * loadNewHorses(int & count);
	horse * createNewHorse(int & count);
	void saveHorse(horse *arr, int count);
	void addHorse(horse **arr, int *count);
	void deleteHorse(horse *arr, int *count);
	void editHorse(horse *arr, int count);
	void searchHorse(horse *arr, int count);
	void showHorseList(horse *arr, int count);
}
