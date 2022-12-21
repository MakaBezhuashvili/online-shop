#include <iostream>
using namespace std;

//It's online book shop.

class AbstractBook{
    protected:
        string Name;
        string Author;
        float Price;

    public:
        static int BookCount;

        AbstractBook(string Name, string Author, float Price) {
            this->Name = Name;
            this->Author = Author;
            this->Price = Price;
            BookCount++;
        }

        string getName() {
            return Name;
        }

        void setName(string Name) {
            this->Name = Name;
        }

        string getAuthor() {
            return Author;
        }

        void setAuthor(string Author) {
            this->Author = Author;
        }

        float getPrice() {
            return Price;
        }

        void setPrice(int Price) {
            this->Price = Price;
        }

        virtual void bookChoice()=0;

        void findOutPrice(){
            cout<<"Price of the book"<<endl;
        }

        void findBook(){
            cout<<"enter the name of the book: "<<endl;
        }
};

int AbstractBook::BookCount = 0;

class Book: public AbstractBook {
    public:
        Book(string Name, string Author, float Price): AbstractBook(Name, Author, Price){}

        void bookChoice() {
            cout<<"Your choice is "<<this->Name<<" by "<<this->Author<<endl;
        }

        void findOutPrice(){
                cout<<"Price is: "<<this->Price<<"$"<<endl<<endl;
        }

        string x;

        void findBook(){
            cout<<"Enter the name of the book: ";
            cin>>x;
             if(x == this->Name){
                bookChoice();
                findOutPrice();
            } else {
                cout<<"Please try again"<<endl;
            }
        }
};

class OnlineShop {

    public:
        string ShopName;
        static int SoldBookCount;

        OnlineShop(string ShopName) {
            this->ShopName = ShopName;
        }

        void sellBook() {
            cout<<ShopName<<" sold book to customer"<<endl;
            SoldBookCount++;

            if(AbstractBook::BookCount > SoldBookCount){
                AbstractBook::BookCount--;
                cout<<"We have "<<AbstractBook::BookCount<<" books in our shop"<<endl<<endl;
            } else {
                AbstractBook::BookCount--;
                cout<<"We have "<<AbstractBook::BookCount<<" books left"<<endl<<endl;
            }
        
        }

};

int OnlineShop::SoldBookCount = 0;

int main()
{
    Book book1("Goals","Brian Tracy",15);
    Book book2("Atomic Habits","James Clear",10);

    book1.findBook();

    OnlineShop bookShop("book shop");

    bookShop.sellBook();

    return 0;
}