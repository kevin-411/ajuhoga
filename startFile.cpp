#include "databaseconnector.h"
#include "encrypt.h"
#include <string>

class User: public Databases{
 protected:
  string ID;
  string password;
  string sqlQuery;
  string usergroup;

 public:
  bool login();
    
};

bool User::login(){
  string opertnType = "select";
string sqlQuery;
  cout << "enter username" <<endl;
  cin >> ID;
  cout << "enter password" <<endl;
  cin >> password;
  password = encryptDecrypt(password);
  sqlQuery = "select * from users where username='"+ID+"' and passphrase='"+password+"'";
  connectToDatabase();
  if(executeQuery(sqlQuery, opertnType)){
    cout<< "\nincorrect username or password\n";
    return false;
  }
  else{
    cout << "successful";
    destroyQuery();
    return true;
  }
}

class Student:public User{
 private:
  string studID;
  string review;
 public:
  void addReview();
  void giveID();
};

void Student::giveID(){
  srand(time(NULL));
  studID = to_string(rand()%1000 + 99); 
  cout << "studID given is " << studID <<endl;
}
void Student::addReview(){
  
  cout << "enter review of hostel" << endl;
  cin >> review;
  sqlQuery = "insert into reviews (review, reviewerID) values('"+review+"','"+studID+"')";
  connectToDatabase();
  executeQuery(sqlQuery, "insert");
  destroyQuery();
}

class Administrator: public User{
  string usernameToChange;
  string newPassword;
 
 public:
  void deleteUser();
  void createNewUser();
  void editPassword();
  void createHostel(); 
};

void Administrator::editPassword(){
  cout << "enter username to modify password for" << endl;
  cin >> usernameToChange;
  cout << "enter new password" << endl;
  cin >> newPassword;
  newPassword = encryptDecrypt(newPassword);
  sqlQuery = "update users set passphrase='" + newPassword + "' where username='"+usernameToChange + "'";
  connectToDatabase();
  executeQuery(sqlQuery, "update");
  destroyQuery();
  cout << "password change successful " << endl;
}

void Administrator::deleteUser(){
  cout << "enter caretaker to delete " << endl;
  cin >> usernameToChange;
  sqlQuery = "delete from users where username='"+usernameToChange+"'";
  connectToDatabase();
  executeQuery(sqlQuery, "delete");
  destroyQuery();
  cout << "destroy successful" << endl;
}

void Administrator::createHostel(){

}

void Administrator::createNewUser(){
  string opertnType = "insert";
  
  cout << "enter username \n";
  cin >> ID;
  //cout << " did you say " << ID;
  cout << "enter password \n";
  cin >> password;
  password = encryptDecrypt(password);
  cout << "enter usergroup; administrator or caretaker\n";
  cin >> usergroup;
  cout<<"";
  sqlQuery = "insert into users (username,passphrase,usergroup) values ('"+ ID +"','" + password +"','"+ usergroup+ "')";
  cout<<""<<endl; 
  connectToDatabase();
  cout << "" << endl;
  executeQuery(sqlQuery, opertnType);
  cout << "" << endl;
  destroyQuery();
 cout << "destroy Query done successfully" << endl;
}

class Hostel:public Databases{
 private:
  string name;
  string sqlQuery;
  string careTakerID;
  string location;
  string description;
  int bedSpace;
  int rent;
  string review;

 public:
  void setName();
  void setCaretakerID();
  void setLocation();
  void setDescription();
  void setBedSpace();
  void setRent();
  void addReviews();
  string getName();
  string getCaretakerID();
  string getLocation();
  string getDescription();
  int getBedSpace();
  string getReviews();
  void updateDatabase();
};

void Hostel::setName(){
  cout << "Enter the hostel name " << endl;
  cin >> name;
}

void Hostel::setCaretakerID(){
  cout << "Enter caretaker ID" << endl;
  cin >> careTakerID;
}

void Hostel::setLocation(){
  cout << "Enter the location of Hostel" << endl;
  cin >> location;
}

void Hostel::setDescription(){
  cout << "Enter Hostel description" << endl;
  cin >> description;
}

void Hostel::setBedSpace(){
  cout << "Enter bedspace" << endl;
  cin >> bedSpace;
}

void Hostel::setRent(){
  cout << "Enter hostel rent" << endl;
  cin >> rent;
}
void Hostel::addReviews(){
  cout << "Enter review of hostel" << endl;
  cin >> review;
}

void Hostel::updateDatabase(){
  sqlQuery = "insert into hostels (hostelname, bedspace, description, location, rent, caretakerID) values ('" + \
    name + "'," + to_string(bedSpace)  + ",'" + description + "','" + location + "'," + to_string(rent) + ",'" + careTakerID + "')";
  connectToDatabase();
  executeQuery(sqlQuery, "insert");
  destroyQuery();
}

string Hostel::getName(){
  cout << "Enter caretakerID" << endl;
  cin >> careTakerID;
  sqlQuery = "select hostelname from hostels where caretakerID = '"+careTakerID +"'";
  connectToDatabase();
  executeQuery(sqlQuery, "select");
  return getResult("hostelname");
}

string Hostel::getCaretakerID(){
  cout << "Enter hostelname "<<endl;
  cin >> name;
  sqlQuery = "select caretakerID from hostels where hostelname = '"+ name +"'";
  connectToDatabase();
  executeQuery(sqlQuery, "select");
  return getResult("caretakerID");
}

string Hostel::getLocation(){
  cout << "Enter hostelname "<<endl;
  cin >> name;
  sqlQuery = "select location from hostels where hostelname = '"+ name +"'";
  connectToDatabase();
  executeQuery(sqlQuery, "select");
  return getResult("location");
}

string Hostel::getDescription(){
  cout << "Enter hostelname "<< endl;
  cin >> name;
  sqlQuery = "select description from hostels where hostelname = '"+ name +"'";
  connectToDatabase();
  executeQuery(sqlQuery, "select");
  return getResult("description");
}

int Hostel::getBedSpace(){
  cout << "Enter hostelname "<<endl;
  cin >> name;
  sqlQuery = "select bedspace from hostels where hostelname = '"+ name +"'";
  connectToDatabase();
  executeQuery(sqlQuery, "select");
  return stoi(getResult("bedspace"));
}

string Hostel::getReviews(){
  cout << "Enter hostelname "<<endl;
  cin >> name;
  sqlQuery = "select review from hostels where hostelname = '"+ name +"'";
  connectToDatabase();
  executeQuery(sqlQuery, "select");
  return getResult("review");
}

class Caretaker: public User{
private:
  string hosteldescription;
  string hostelname3;
  int bedspace;
  string location;

 public:
  void uploadPicture();
  void updateDescription();
  void updateRoomsAvailable();
  void updateLocation();
};

void Caretaker::uploadPicture(){
}

void Caretaker::updateDescription(){
  cout << "which hostel do you want to work with?" <<endl;
  cin >> hostelname3; 
  cout << "Enter new Hostel Description" << endl;
  cin >> hosteldescription;
  sqlQuery = "update hostels set description ='"+hosteldescription+"' where hostelname='"+hostelname3+"'";
  connectToDatabase();
  executeQuery(sqlQuery, "insert");
  destroyQuery();
}

void Caretaker::updateRoomsAvailable(){
  cout << "which hostel do you want to work with?" << endl;
  cin >> hostelname3; 
  cout << "Enter new bedspace" << endl;
  cin >> bedspace;
  sqlQuery = "update hostels set bedspace ="+to_string(bedspace)+" where hostelname='"+hostelname3+"'";
  connectToDatabase();
  executeQuery(sqlQuery, "insert");
  destroyQuery();
}

void Caretaker::updateLocation(){
  cout << "which hostel do you want to work with?" << endl;
  cin >> hostelname3; 
  cout << "Enter new location" << endl;
  cin >> location;
  sqlQuery = "update hostels set location='"+location+"' where hostelname='"+hostelname3+"'";
  connectToDatabase();
  executeQuery(sqlQuery, "insert");
  destroyQuery();
}
	
int main(){

  return 0;
}
