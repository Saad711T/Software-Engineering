#include <iostream>
#include <string>
using namespace std;

struct book {
	string name;
	int id;
	string author;
	double price;
};


void searchBook(book books[], int size, string searchName) {
	bool found = false;
	for (int i = 0; i < size; i++) {
		if (books[i].name == searchName) {
			cout << "\nBook found!\n";
			cout << "Name: " << books[i].name << endl;
			cout << "ID: " << books[i].id << endl;
			cout << "Author: " << books[i].author << endl;
			cout << "Price: $" << books[i].price << endl;
			found = true;
			break;
		}
	}
	if (!found) {
		cout << "\nBook not found.\n";
	}
}

int main() {

	book book1 = { "The Mysterious Affair at Styles" , 1 , "Agatha Christie" , 29.99 };
	book book2 = { "Macbeth" , 2 , "William Shakespeare" , 19.00 };
	book book3 = { "Al-Bidyah w Al Nihayh" , 3 , "Ibn Katheer" , 129.00 };
	book book4 = { "Animal Farm" , 4 , "George Orwell" , 35.00 };
	book book5 = { "Oliver Twist" , 5 , "Charles Dickens" , 26.00 };
	book book6 = { "Hamlet" , 2 , "William Shakespeare" , 35.50 };
	book book7 = { "Tales of Mystery & Imagination" , 6 , "Edgar Allan Poe" , 21.99 };
	book book8 = { "The History of the World" , 7 , "Frank Welsh" , 57.00 };
	book book9 = { "Java: A Beginner's Guide" , 8 , "Herbert Schildt" , 53.40 };
	book book10 = { "Qeiss Al-Anbyaa" , 3 , "Ibn Katheer" , 18.00 };
	book book11 = { "Mecca History" , 9 , "Ahmed Al-Sebaeea" , 28.50 };
	book book12 = { "The Brothers Karamazov" , 10 , "Fyodor Dostoevsky" , 55.00 };


	book books[] = { book1, book2, book3, book4, book5, book6, book7, book8, book9, book10, book11, book12};
	int size = sizeof(books) / sizeof(books[0]);
	string searchName;

	cout << "Enter the name of the book to search: ";
	getline(cin, searchName);

	searchBook(books, size, searchName);

	return 0;
}
