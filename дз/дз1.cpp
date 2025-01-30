#include <iostream>
using namespace std;
class Product {
private:
    string name;
    int price;
    int quantity;
public:
    string getName(){
        return this->name;
    }
    int getPrice (){
        return this->price;
    }
    int getQuantity (){
        return this->quantity;
    }
    void setQantity(int quantity){
        if (quantity < 0) {
            return;
        }
        this->quantity = quantity;
        
    }
};
int main()
{
    
}
