#include "ipp.hpp"
using namespace std;
using namespace HORSE;
int main() {
	horse *arr = nullptr;
	int count = 0;
	arr = loadNewHorses(count);
	int a;
	do {
		cout << ("Horse list\n") << endl;
		cout << ("1. download horse\n") << endl;
		cout << ("2. Show horse list\n") << endl;
		cout << ("3. Add a new horse\n") << endl;
		cout << ("4. Delete horse\n") << endl;
		cout << ("5. Edit\n") << endl;
		cout << ("6. Find horse\n") << endl;
		cout << ("0. Exit\n") << endl;
		cin >> a;
		switch (a) {
		case 1:
			arr = createNewHorse(count);
			break;
		case 2:
			showHorseList(arr, count);
			break;
		case 3:
			addHorse(&arr, &count);
			break;
		case 4:
			deleteHorse(arr, &count);
			break;
		case 5:
			editHorse(arr, count);
			break;
		case 6:
			searchHorse(arr, count);
			break;
		case 0:
			cout << "" << endl;
			saveHorse(arr, count);
			delete[] arr;
			break;
		default:
			printf("hz \n");
		}
	} while (a != 0);
	return 0;}
