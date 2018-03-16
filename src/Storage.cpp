#include"Path.hpp"
#include"Storage.hpp"
#include<iostream>
#include<sstream>
#include<fstream>
// #define EOF (-1)
#include<cstdio>
using namespace std;
shared_ptr<Storage> Storage :: m_instance = NULL;
Storage :: Storage() {
m_dirty = false;
readFromFile();
}
bool Storage :: modify_password(std::function<bool(const User &)> filter, const std :: string& new_password) {
   list<User> :: iterator iter = m_userList.begin();
   for (iter; iter != m_userList.end(); iter++) {
    if (filter(*iter)) {
      iter -> setPassword(new_password);
      m_dirty = true;
      sync();
      return true;
    }
   }
}
void Storage :: modify_phone(std::function<bool(const User &)> filter, const std :: string& new_password) {
   list<User> :: iterator iter = m_userList.begin();
   for (iter; iter != m_userList.end(); iter++) {
    if (filter(*iter)) {
      iter -> setPhone(new_password);
      m_dirty = true;
       sync();
      return;
    }
   }
}

bool Storage :: readFromFile() {
ifstream rfile;
rfile.open(Path :: userPath);
if (!rfile.is_open()) {
return false;
}
char ch;
while(rfile.peek() != EOF) {
  string re = "";
  getline(rfile, re);
string arr[4];

int i = 0;
int j = 0;

while (j < 4) {

for (i; i < re.length(); i++) {
  if (re[i] == ',')
    break;
arr[j] += re[i];
}
j++;
i++;
// cout << arr[j-1] << endl;  //ceshi
// cout << arr[j-1].length() << endl;



}
if (arr[0].length() == 0 || arr[1].length() == 0 || arr[2].length() == 0 || arr[3].length() == 0) {
  // cout << "fanghui\n";
  return false;    //youxiugai


}
// for (int i = 0; i <= 3; i++) {
//   cout << arr[i].substr(1, arr[0].length()-2) << endl; //ceshi


  //
  //
// }
User temp(arr[0].substr(1, arr[0].length()-2), arr[1].substr(1, arr[1].length()-2), arr[2].substr(1, arr[3].length()-2), arr[3].substr(1, arr[3].length()-2));
m_userList.push_back(temp);
}
rfile.close();

ifstream rfile2;
rfile2.open(Path :: meetingPath);
if (!rfile2.is_open())
return false;




while(rfile2.peek() != EOF) {
  std::vector<string> str;
  string re2 = "";
  getline(rfile2, re2);
string arr2[5];
int i = 0;
int j = 0;
while (j < 5) {

  for (i; i < re2.length(); i++) {
    if (re2[i] == ',')
      break;
    arr2[j] += re2[i];
  }
  j++;
  i++;
  // cout << arr2[j-1] << endl;  //ceshi
  //
  //
  //

}
//  for (int i = 0; i <= 4; i++) {
//   cout << arr2[i].substr(1, arr2[i].length()-2) << endl;
// }
int sum = 0;
for (int t = 0; t < arr2[1].length(); t++) {
  if (arr2[1][t] == '&')
    sum++;
  // cout << sum << endl;   //test??

}
sum++;
string part[sum+1];
int ccout = 0;
int s = 0;
arr2[1] = arr2[1].substr(1, arr2[1].length()-2);
while (sum--) {
  for (s; s < arr2[1].length(); s++) {
    if (arr2[1][s] == '&')
      break;
    part[ccout] += arr2[1][s];
  }
  ccout++;
  s++;
  // cout << part[ccout-1] << endl;
  // cout << part[ccout-1].length() << " length" << endl;
   // cout << part[ccout-1].substr(1, part[ccout-1].length()) << "cut "<< endl; //tes
  str.push_back(part[ccout-1]);
}
//  std::vector<string> :: iterator iter = str.begin();
// for (iter; iter != str.end(); iter++)
// cout << *iter << "  iterator "<< endl;

Meeting temp2(arr2[0].substr(1, arr2[0].length()-2), str, Date :: stringToDate(arr2[2].substr(1, arr2[2].length()-2)), Date :: stringToDate(arr2[3].substr(1, arr2[3].length()-2)), arr2[4].substr(1, arr2[4].length()-2));
m_meetingList.push_back(temp2);
// cout << temp2.getSponsor() << endl;
//  cout << Date :: dateToString(temp2.getStartDate()) << endl;
//  cout << Date :: dateToString(temp2.getEndDate())<< endl;
}

rfile2.close();
return true;
}

bool Storage :: writeToFile() {


    ofstream file;
file.open(Path ::userPath);
if (!file.is_open())
  return false;
string re = "";
list<User> :: iterator iter = m_userList.begin();
for (iter; iter != m_userList.end(); iter++) {
  re += "\"";
  re += iter -> getName();
  re += "\",";
  re += "\"";
  re += iter ->getPassword();
  re += "\",";
  re += "\"";
  re += iter -> getEmail();
  re += "\",";
  re += "\"";
  re += iter -> getPhone();
  re += "\"\n";
}
file << re;
file.close();
re = "";
ofstream file2;
file2.open(Path :: meetingPath);
if (!file2.is_open())
  return false;
list<Meeting> :: iterator iter2 = m_meetingList.begin();

for (iter2; iter2 != m_meetingList.end(); iter2++) {
  re += "\"";
  re += iter2 -> getSponsor();
  re += "\",";
  std::vector<string> str2(iter2 -> getParticipator());
  re += "\"";
  for (auto iter3 = str2.begin(); iter3 != str2.end(); iter3++) {
    std::vector<string> :: iterator v = iter3;
    if (++v != str2.end()) {
    re += (*iter3);
    re += "&";
  } else {
    re += (*iter3);
  }

  }
  re += "\",";
  re += "\"";
  re += Date :: dateToString(iter2 -> getStartDate());
  re += "\",";
  re += "\"";
  re += Date :: dateToString(iter2 -> getEndDate());
  re += "\",";
  re += "\"";
  re += iter2 -> getTitle();
  re += "\"\n";

}
file2 << re;
file2.close();
m_dirty = false;
return true;
  

}
shared_ptr<Storage> Storage :: getInstance() {
if (m_instance == NULL)
m_instance = (shared_ptr<Storage>) new Storage;
return m_instance;
}

Storage :: ~Storage() {
  sync();
m_instance.reset();
while (!m_userList.empty()) {
  m_userList.pop_back();
}
while (!m_meetingList.empty()) {
  m_meetingList.pop_back();
}
m_dirty = false;
}

void Storage :: createUser(const User & t_user) {
  m_userList.push_back(t_user);
  m_dirty = true;
 // sync();
}

list<User> Storage :: queryUser(function<bool(const User &user)> filter) const {
list<User> temp;
bool flag;
list<User> :: const_iterator it = this -> m_userList.begin();
for (it; it != m_userList.end(); it++) {
flag = filter(*it);
if (flag) {
  temp.push_back(*it);
}
}

return temp;
}

int Storage :: updateUser(std::function<bool(const User &u)> filter,
                 std::function<void(User &)> switcher) {
  int sum = 0;
bool flag = false;
  list<User> :: const_iterator it = this -> m_userList.begin();
list<User> :: iterator it2 = this -> m_userList.begin();
for (it; it != m_userList.end(); it++, it2++) {
flag = filter(*it);
if (flag) {
  switcher(*it2);
  sum++;
}
}
if (sum != 0)
m_dirty = true;
//sync();
return sum;
}

int Storage :: deleteUser(std::function<bool(const User &u)> filter) {
  int sum = 0;
  list<User> :: iterator it = this -> m_userList.begin();
for (it; it != m_userList.end();) {
if (filter(*it)) {
  it = m_userList.erase(it);
  sum++;
} else {
  it++;
}

}if (sum != 0)
  m_dirty = true;
 // sync();
return sum;
}

void Storage :: createMeeting(const Meeting & t_meeting) {
  m_meetingList.push_back(t_meeting);
  m_dirty = true;
  //sync();
}

list<Meeting> Storage :: queryMeeting(function<bool(const Meeting &meeting)> filter) const {
list<Meeting> temp;
bool flag;
list<Meeting> :: const_iterator it = this -> m_meetingList.begin();
for (it; it != m_meetingList.end(); it++) {
flag = filter(*it);
//cout << flag << endl;
if (flag) {
  // cout << it -> getSponsor() << endl;
  // cout << it -> getTitle() << endl;
  // cout << Date :: dateToString(it -> getStartDate()) << "kaishi"<< endl;  //test

  // 
  //
  // cout <<"get\n" << endl;
temp.push_back(*it);
}
}

return temp;
}

int Storage :: updateMeeting(std::function<bool(const Meeting &m)> filter,
                 std::function<void(Meeting &)> switcher) {
  int sum = 0;
  list<Meeting> :: const_iterator it = this -> m_meetingList.begin();
list<Meeting> :: iterator it2 = this -> m_meetingList.begin();
bool flag;
for (it; it != m_meetingList.end(); it++, it2++) {
flag = filter(*it);
if (flag) {
  switcher(*it2);
  sum++;
}
}
if (sum != 0)
m_dirty = true;
//sync();
return sum;
}

int Storage :: deleteMeeting(std::function<bool(const Meeting &m)> filter) {
  int sum = 0;
list<Meeting> :: iterator it = this -> m_meetingList.begin();
for (it; it != m_meetingList.end();) {
if (filter(*it)) {
  it = m_meetingList.erase(it);
  sum++;
} else {
  it++;
}
}
if (sum != 0)
m_dirty = true;
//sync();
return sum;
}

bool Storage :: sync() {
if (m_dirty)
writeToFile();
return m_dirty;
}
