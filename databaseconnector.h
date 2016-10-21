#include <stdlib.h>
#include <iostream>
#include <string>
/*
Include directly the different
headers from cppconn/ and mysql_driver.h + mysql_util.h
(and mysql_connection.h). This will reduce your build time!
*/
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

using namespace std;

class Databases{
 private:
  sql::Driver *driver;
  sql::Connection *con;
  sql::Statement *stmt;
  sql::ResultSet *res;

public:

  void connectToDatabase()
{

  //try {
/* sql::Driver *driver; */
/* sql::Connection *con; */
/* Create a connection */
 
  driver = get_driver_instance();
  con = driver->connect("tcp://127.0.0.1:3306", "root", "toor");

/* Connect to the MySQL test database */
con->setSchema("ajuhoga1");
 cout << "connection successful";
}

  int executeQuery(string command, string conntype){
    stmt = con->createStatement();
    if (conntype == "select"){
      res = stmt->executeQuery(command);
      if (res->next()){
	cout << "execute query successful" << endl;
	return 0;
      }
      else{
	return 99;
      }
    }
    else{
      stmt->execute(command);
      cout << "execute query successful" << endl;
      return 0;
    }
    
    
  }

  string getResult(string column){
return  res->getString(column);
  }
/* execute commands */
/* sql::Statement *stmt; */
//sql::ResultSet *res;
//stmt = con->createStatement();
//res = stmt->executeQuery(command);
 /* if (conntype == "insert"){ */
 /* stmt->execute(command); */
 /* } */
 /* else{ */
 /* stmt->executeQuery(command); */
 /* } */

/* iterate through the results of the command, in the case of a select statement */
//while (res->next()) {
//cout << "\t... MySQL replies: ";
/* Access column data by alias or column name */
//cout << res->getString("_message") << endl;
//cout << "\t... MySQL says it again: ";
/* Access column data by numeric offset, 1 is the first column */
//cout << res->getString(1) << endl;
//}
//delete res;

  void destroyQuery(){
    cout << "" << endl;
    delete stmt;
    cout << "" << endl;
    delete con;
    cout << "" << endl;
    //delete res;
    cout << "after res statement" << endl;    
}
/*  catch (sql::SQLException &e) { */
/* cout << "# ERR: SQLException in " << __FILE__; */
/*  cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl; */
/* cout << "# ERR: " << e.what(); */
/* cout << " (MySQL error code: " << e.getErrorCode(); */
/* cout << ", SQLState: " << e.getSQLState() << " )" << endl; */
/*   cout << "error occured" << endl; */
/*   return 1; */
/* } */

/*
 *compiled with the following command: 
 *g++ --std=c++11 -Wall -I/usr/include/cppconn -o databaseConnect databaseconnect.cpp -L/usr/lib -lmysqlcppconn
 *
 */
//return EXIT_SUCCESS;

};
