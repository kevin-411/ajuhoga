
#include <iostream>

using namespace std;

string encryptDecrypt(string toEncrypt){
  char key = 'K';
  string output = toEncrypt;

  for (unsigned int i =0; i< toEncrypt.size(); i++)
    output[i] = toEncrypt[i] ^ key;

  return output;
}
