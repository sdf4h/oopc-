#include <string>
#include <vector>
using namespace std;

class Store {
public:
    
    Store(const string& address, const string& workingHours, 
          const string& contactInfo, const vector<string>& photos)
        : address(address), workingHours(workingHours), 
          contactInfo(contactInfo), photos(photos) {}

    
    string getAddress() const {
        return address;
    }

    string getWorkingHours() const {
        return workingHours;
    }

    string getContactInfo() const {
        return contactInfo;
    }

    vector<std::string> getPhotos() const {
        return photos;
    }
private:
    string address;
    string workingHours;
    string contactInfo;
    vector<string> photos;
};
