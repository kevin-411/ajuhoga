#include "databaseconnector.h"
#include "encryption.h"
// the class to handle the user credentials and login staff
class UserLogin: public Databases{
 protected:
  string ID;
  string password;
  string sqlQuery;
  string usergroup;

 public:
  bool login();
  void createNewUser();
  
};

void UserLogin::createNewUser(){
  cout << "enter username \n" << endl ;
  cin >> ID;
  cout << " did you say " << ID;
  cout << "\nenter password \n" << endl;
  cin >> password;
  password = encrypt(password);
  cout << "enter usergroup; admin, caretaker or student \n" << endl;
  cin >> usergroup;
  sqlQuery = "insert into users (username, passphrase, usergroup) values ('"+ ID +"','" + password +"','"+ usergroup+ "')";
  connectDatabase(sqlQuery);
}

class Students{
 private:
  int studID;
  string review;
 public:
  void addReview();
  void giveID();
};

class Administrator: public UserLogin{
 
 public:
  void resetpassword();
  void addCaretaker();
  void deleteCareTaker();
  void editCareTaker();
  void createHostel(); 
};


class Caretaker: public UserLogin{
 
 public:
  void uploadPicture();
  void updateDescription();
  void updateRoomsAvailable();
  void updateLocation();
};

class Hostel{
 private:
  string name;
  int careTakerID;
  string location;
  string description;
  int bedSpace;
  string reviews[];

 public:
  void setName();
  void setCaretakerID();
  void setLocation();
  void setDescription();
  void setBedSpace();
  void addReviews();
  void getName();
  void getCaretakerID();
  void getLocation();
  void getDescription();
  void getBedSpace();
  void getReviews();
};
	
int main(){
  Administrator senior;
  senior.createNewUser();
  return 0;
}
