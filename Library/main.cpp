#include <iostream>
#include <vector>
#include <algorithm>

struct Day{
    explicit Day(int day){
        this->day = day;
    }
    int day;
};

struct Month{
    explicit Month(int month){
        this->month = month;
    }
    int month;
};

struct Year{
    explicit Year(int year){
        this->year = year;
    }
    int year;
};

struct Date{
    Date(Day newDay, Month newMonth, Year newYear){
        this->day = newDay.day;
        this->month = newMonth.month;
        this->year = newYear.year;
    }
    int getDayIndex(int days, int month, int year){
        for (int i = 0; i < month - 1; i++)
        {
            days += daysOfTheMonth[i];
        }
        if ( year%4==0 and year%100==0 and year%400==0){
            days += 1;
        }
        return days;
    }
    int daysOfTheMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int day;
    int month;
    int year;
};

struct Book {
private:
    Date date;
    std::string name;
    std::string author;
    std::string genre;
    int coast;
    int rating;
    int id;
    int idReader = 0;
    int idDayOfReceipt = 0;

public:
    Date getDate() const{
        return date;
    }
    std::string getName() const {
        return name;
    }

    std::string getAuthor()  const {
        return author;
    }

    std::string getGenre()  const{
        return genre;
    }
    int getCoast()  const {
        return coast;
    }
    int getRating() const {
        return rating;
    }
    int getId() const {
        return id;
    }

    int getIdReader () const {
        return idReader;
    }

    int getDayOfReceipt() const {
        return idDayOfReceipt;
    }

    void setIdReader(int id) {
        this->idReader = id;
    }

    void setIdDayOfReceipt( int day){
        this->idDayOfReceipt = day;
    }

    void setDate(Date date){
        this->date = date;
    }

    void setName(std::string name){
        this->name = name;
    }

    void setAuthor(std::string author){
        this->author = author;
    }

    void setGenre(std::string genre){
        this->genre = genre;
    }

    void setCoast(int coast){
        this->coast = coast;
    }

    void setRating(int rating){
        this->rating = rating;
    }

    void setId(int id){
        this->id = id;
    }

    bool operator == (const Book & book) const {
        return (this->id == book.id);
    }
    //Можно выборочно изменить данные, можно изменить все
    void editData(){
        std::string choise = "";
        std::string data = " ";
        int numericalData = 0;
        std::cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<std::endl;
        std::cout<<"Введите название ячейки, которую хотите изменить"<<std::endl;
        std::cout<<"1. Дата издания"<<'\n'<<"2. Название"<<'\n'<<"3. Автор"<<'\n'
                 <<"4. Жанр"<<'\n'<<"5. Стоимость"<<'\n'<<"6. Рейтинг"<<'\n'<<"7. ID"<<'\n'
                 <<"8. Все"<<'\n'<<"9. Ничего"<<std::endl;
        std::cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<std::endl;
        while( true ){
            std::cin>>choise;
            if (choise == "Дата издания"){
                int day, month, year;
                std::cout<<"Введите дату издания в формате dd mm yy"<<std::endl;
                std::cin>>day>>month>>year;
                setDate(Date(Day{day},Month{month}, Year{year}));
                break;
            } else if (choise == "Название"){
                std::cin>>data;
                setName(data);
                break;
            } else if (choise == "Автор"){
                std::cin>>data;
                setAuthor(data);
                break;
            } else if (choise == "Жанр"){
                std::cin>>data;
                setGenre(data);
                break;
            } else if (choise == "Стоимость"){
                std::cin>>numericalData;
                setCoast(numericalData);
                break;
            } else if (choise == "Рейтинг"){
                std::cin>>numericalData;
                setRating(numericalData);
                break;
            } else if (choise == "ID"){
                std::cin>>numericalData;
                setId(numericalData);
                break;
            } else if (choise == "Все"){
                std::string intermediateChoice = "";
                while (true){
                    int day, month, year;
                    std::cout<<"Введите дату издания в формате dd mm yy"<<std::endl;
                    std::cin>>day>>month>>year;
                    setDate(Date(Day{day},Month{month}, Year{year}));
                    std::cout<<"Хотите закончить изменений данных?"<<'\n'
                    <<"Введите да или нет"<<std::endl;
                    std::cin>>intermediateChoice;
                    if (intermediateChoice == "Да" or intermediateChoice == "да"){
                        break;
                    }

                    std::cout<<"Введите название"<<std::endl;
                    std::cin>>data;
                    setName(data);
                    std::cout<<"Хотите закончить изменений данных?"<<'\n'
                             <<"Введите да или нет"<<std::endl;
                    std::cin>>intermediateChoice;
                    if (intermediateChoice == "Да" or intermediateChoice == "да"){
                        break;
                    }

                    std::cout<<"Введите Автора"<<std::endl;
                    std::cin>>data;
                    setAuthor(data);
                    std::cout<<"Хотите закончить изменений данных?"<<'\n'
                             <<"Введите да или нет"<<std::endl;
                    std::cin>>intermediateChoice;
                    if (intermediateChoice == "Да" or intermediateChoice == "да"){
                        break;
                    }

                    std::cout<<"Введите жанр"<<std::endl;
                    std::cin>>data;
                    setGenre(data);
                    std::cout<<"Хотите закончить изменений данных?"<<'\n'
                             <<"Введите да или нет"<<std::endl;
                    std::cin>>intermediateChoice;
                    if (intermediateChoice == "Да" or intermediateChoice == "да"){
                        break;
                    }

                    std::cout<<"Введите цену"<<std::endl;
                    std::cin>>numericalData;
                    setCoast(numericalData);
                    std::cout<<"Хотите закончить изменений данных?"<<'\n'
                             <<"Введите да или нет"<<std::endl;
                    std::cin>>intermediateChoice;
                    if (intermediateChoice == "Да" or intermediateChoice == "да"){
                        break;
                    }

                    std::cout<<"Введите цену"<<std::endl;
                    std::cin>>numericalData;
                    setCoast(numericalData);
                    std::cout<<"Хотите закончить изменений данных?"<<'\n'
                             <<"Введите да или нет"<<std::endl;
                    std::cin>>intermediateChoice;
                    if (intermediateChoice == "Да" or intermediateChoice == "да"){
                        break;
                    }

                    std::cout<<"Введите рейтинг"<<std::endl;
                    std::cin>>numericalData;
                    setRating(numericalData);
                    std::cout<<"Хотите закончить изменений данных?"<<'\n'
                             <<"Введите да или нет"<<std::endl;
                    std::cin>>intermediateChoice;
                    if (intermediateChoice == "Да" or intermediateChoice == "да"){
                        break;
                    }
                    std::cout<<"Введите Id"<<std::endl;
                    std::cin>>numericalData;
                    setId(numericalData);
                    break;
                }
            }else if (choise == "Ничего"){
                break;
            } else {
                std::cout<<"Вы ввели что-то не то, попробуйте еще раз"<<std::endl;
            }
        }
    }
};

struct Reader{
    std::string lastName;
    std::string firstName;
    std::string patronymic;
    std::string dateOfBirth;
    int passport;
    int id;
    int numberOfBooksRead;
    //std::vector<Book> listOfBooks;
    bool operator == (const Reader & reader) const {
        return (this->id == reader.id);
    }
};

class Library{
public:

    void issuingBook(Book book, Reader reader){
        if(book.getIdReader() == 0 ){
            std::cout<<"Книга занята"<<std::endl;
        } else {
            book.setIdReader(reader.getId());
            int day, month, year;
            std::cout<<"Введите предположительную дату возвращения в формате dd mm yy"<<std::endl;
            std::cin>>day>>month>>year;
            book.setIdDayOfReceipt(Date(Day{day},Month{month},
                                        Year{year}).getDayIndex(day,month,year));

        }
    }

    void returnBook(Book book, Reader reader){
        book.setIdReader(0);
        int day, month, year;
        std::cout<<"Введите дату возвращения в формате dd mm yy"<<std::endl;
        std::cin>>day>>month>>year;
        int returnDay = Date(Day{day},Month{month},
                             Year{year}).getDayIndex(day,month,year);
        if (book.getDayOfReceipt() >= returnDay){
            std::cout<<"Пени нет"<<std::endl;
        } else {
            std::cout<<"Вы должны вернуть пени: "<< (returnDay - book.getDayOfReceipt())*3
            <<" грн"<<std::endl;
        }
    }
    void addBook(const Book &book){
        books.push_back(book);
    }

    void removeBook(int id){
      books.erase(std::remove(books.begin(), books.end(),
                              findBook(id)), books.end());
    }

    void addReader(const Reader &reader){
        readers.push_back(reader);
        std::cout<<readers.size()<<std::endl;
    }

    void removeReader(int id){
        readers.erase(std::remove(readers.begin(), readers.end(),
                                  findReader(id)),readers.end());
        std::cout<<readers.size()<<std::endl;
    }


private:
    Book findBook(int id){
        for(auto i : books){
            if(i.getId() == id){
                return i;
            }
        }
    }


    Reader findReader(int id){
        for(auto i : readers){
            if(i.id == id){
                return i;
            }
        }
    }

    std::vector<Book> books;
    std::vector<Reader> readers;
};

int main(){
    Reader reader1 = {"L","F","A","11/12/2020",
                      1111111, 3,2};
    Reader reader2 = {"L","F","A","11/12/2020",
                      1111111, 1,2};
    Reader reader3 = {"L","F","A","11/12/2020",
                      1111111, 2,2};
    //Book book;
    Library library;
    library.addReader(reader2);
    library.addReader(reader1);
    library.addReader(reader3);
    library.removeReader(1);

    return 0;


}