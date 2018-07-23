#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>

struct Review 
{
	std::string title;
	int rating;
	double price;
};

bool operator<(const Review & r1, const Review & r2);
bool worseThan(const Review & r1, const Review & r2);
bool operator<(const std::shared_ptr<Review>& p1, const std::shared_ptr<Review>& p2);
bool ratingWorse(const std::shared_ptr<Review>& p1, const std::shared_ptr<Review>& p2);
bool priceWorse(const std::shared_ptr<Review>& p1, const std::shared_ptr<Review>& p2);
bool FillReview(Review & rr);
void ShowbookReview(const Review & rr);
void ShowReview(const std::shared_ptr<Review>& p);

int main()
{
	using namespace std;
	vector<Review> books;
	Review temp;
	while (FillReview(temp))
		books.push_back(temp);

	vector<shared_ptr<Review>> books_ptr;
	for (auto it : books)
		books_ptr.push_back(shared_ptr<Review>(new Review(it)));


	if (books_ptr.size() > 0)
	{
		cout << "Thank you. You entered the following " << books_ptr.size() << " ratings:\n" << "Rating\tBook\n";
		for_each(books_ptr.begin(), books_ptr.end(), ShowReview);

		sort(books_ptr.begin(), books_ptr.end());
		cout << "Sorted by title:\nRating\tBook\n";
		for_each(books_ptr.begin(), books_ptr.end(), ShowReview);

		sort(books_ptr.begin(), books_ptr.end(), ratingWorse);
		cout << "Sorted by rating:\nRating\tBook\n";
		for_each(books_ptr.begin(), books_ptr.end(), ShowReview);

		sort(books_ptr.begin(), books_ptr.end(), priceWorse);
		cout << "Sorted by price:\nRating\tBook\n";
		for_each(books_ptr.begin(), books_ptr.end(), ShowReview);

		random_shuffle(books_ptr.begin(), books_ptr.end());
		cout << "After shuffling:\nRating\tBook\n";
		for_each(books_ptr.begin(), books_ptr.end(), ShowReview);
	}
	else
		cout << "No entries. ";
	cout << "Bye.\n";

	system("pause");
	return 0;
}

bool operator<(const Review & r1, const Review & r2)
{
		if (r1.title < r2.title)
			return true;
		else if (r1.title == r2.title && r1.rating < r2.rating)
			return true;
		else
			return false;
}

bool worseThan(const Review & r1, const Review & r2)
{
	if (r1.rating < r2.rating)
		return true;
	else
		return false;
}

bool ratingWorse(const std::shared_ptr<Review>& p1, const std::shared_ptr<Review>& p2)
{
	if (p1->rating < p2->rating)
		return true;
	else
		return false;
}

bool priceWorse(const std::shared_ptr<Review>& p1, const std::shared_ptr<Review>& p2)
{
	if (p1->price < p2->price)
		return true;
	else
		return false;
}


bool operator<(const std::shared_ptr<Review>& p1, const std::shared_ptr<Review>& p2)
{
	if (p1->title < p2->title)
		return true;
	else if (p1->title == p2->title && p1->rating < p2->rating)
		return true;
	else
		return false;
}

bool FillReview(Review & rr)
{
	std::cout << "Enter book title (quit to quit): ";
	std::getline(std::cin, rr.title);

	if (rr.title == "quit")
		return false;

	std::cout << "Enter book rating: ";
	std::cin >> rr.rating;
	if (!std::cin)
		return false;
	std::cout << "Enter book price: ";
	std::cin >> rr.price;
	if (!std::cin)
		return false;
	// get rid of rest of input line
	while (std::cin.get() != '\n')
		continue;
	return true;
}

void ShowbookReview(const Review & rr)
{
	std::cout << rr.rating << "\t" << rr.title << std::endl;
}

void ShowReview(const std::shared_ptr<Review>& p)
{
	std::cout << p->rating << "\t" << p->title << "\t" << p->price << std::endl;
}