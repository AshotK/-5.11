#include <iostream> // size_t
#include <algorithm> // swap
struct Unit{
    Unit(const char *str=""):size(strlen(str)), str(new char[size + 1]){
        strcpy(this->str, str);
    }

    ~Unit(){
            delete [] str;
    }

    char get(int i){
            return str[i];
    }

    void set(int i, char c){
        str[i]=c;
    }

    size_t strlen(const char * str) const{
        const char *s=str;
        for (; *s; ++s){
        };
        return (s-str);
    }

    void strcpy(char * str, const char * toCopy){
        while((*str++ = *toCopy++) != '\0'){
        };
    }

    void append(Unit &other){
        char *temp = new char[size + other.size + 1];
        strcpy(temp, str);\
        for (int i=size; i < size + other.size; ++i)
            temp[i] = other.str[i - size];
        delete [] str;
        size += other.size;
        temp[size] = '\0';
        str = temp;
    }

    Unit(const Unit &other) : size(other.size), str(new char[size+1]){
        for (int i=0; i < size; ++i)
            str[i] = other.str[i];
        str[size] = '\0';
    }

    Unit &operator = (const Unit &other){
        Unit(other).swap(*this);
        return *this;
    }

    void swap(Unit &a) {
        std::swap(size, a.size);
        std::swap(str, a.str);
    }

private:
    size_t size;
    char *str;
};

int main(){
    return 0;
}
