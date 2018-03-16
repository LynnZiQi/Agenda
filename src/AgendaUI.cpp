#include"AgendaUI.hpp"
#include<iostream>
#include<stdlib.h>
#include<iomanip>
using namespace std;
AgendaUI :: AgendaUI() {
	cout << "chooce English(1) or Chinese(2)" << endl; //buchong//
cout << "选择英文版（1） 或者 中文版（2）" << endl;
startAgenda();
	
}
void AgendaUI :: startAgenda() {


//
//
//
string s;
cin >> s;
if (s == "1")
OperationLoop();
if (s == "2")
OperationLoop2();
 else {
cout << "chooce English(1) or Chinese(2)" << endl; //buchong//
cout << "选择英文版（1） 或者 中文版（2）" << endl;
startAgenda();
}
}

void AgendaUI :: OperationLoop() {
cout << "-------------------Agenda-----------------------" << endl;
cout << "Action :\n" << endl;
cout << "l    - log in Agenda by user name and password\n";

cout << "r    - register an Agenda accout\n";

cout << "q    - quit Agenda\n";

cout << "f    - modify your password" << endl;

cout << "------------------------------------------------\n";
cout << endl;
cout << endl;
cout << "Agenda : ~$ ";

string str = getOperation();
	if (str == "l") {
		userLogIn();
	} else if (str == "r") {
		userRegister();
	} else if (str == "q") {
		quitAgenda();
	} else if (str == "f") {
		find_back();
	}
		else {
    cout << "error!\n";
    OperationLoop();
  }
}
void AgendaUI :: OperationLoop2() {
cout << "-------------------Agenda-----------------------" << endl;
cout << "操作 :\n" << endl;
cout << "l    - 输入用户名和密码登录\n";

cout << "r    - 注册新账户\n";

cout << "q    - 退出程序\n";

cout << "f    - 通过手机号和邮箱找回密码" << endl;

cout << "------------------------------------------------\n";
cout << endl;
cout << endl;
cout << "Agenda : ~$ ";

string str = getOperation2();
	if (str == "l") {
		userLogIn2();
	} else if (str == "r") {
		userRegister2();
	} else if (str == "q") {
		quitAgenda();
	} else if (str == "f") {
		find_back2();
	}
		else {
    cout << "error!\n";
    OperationLoop2();
  }

}

void AgendaUI :: find_back() {
	cout << "[find back] ";
	string phone;
	string password;
	string name;
	cout << "[username] ";
	cin >> name;
	cout << endl << "[phone] ";
	cin >> phone;
	cout << endl << "[email] ";
	string email;
	cin >> email;
	cout << "[your new password] ";
	cin >> password;
	bool flag = m_agendaService.find_back(name, phone, email, password);
	if (flag) {
	cout << "succed!" << endl;
	userLogIn();
} else {
	cout << "error!" << endl;
	OperationLoop();
}
}
void AgendaUI :: find_back2() {
	cout << "[找回] ";
	string phone;
	string password;
	string name;
	cout << "[用户名] ";
	cin >> name;
	cout << endl << "[手机号] ";
	cin >> phone;
	cout << endl << "[邮箱] ";
	string email;
	cin >> email;
	cout << "[输入新密码] ";
	cin >> password;
	bool flag = m_agendaService.find_back(name, phone, email, password);
	if (flag) {
	cout << "修改成功， 返回登录！" << endl;
	userLogIn2();
} else {
	cout << "修改失败！请检查信息！" << endl;
	OperationLoop2();
}
}
void AgendaUI :: userLogIn2() {
	cout << endl;
	cout << "[登录] [用户名] [密码]\n";
	cout << "[登录] ";
	string name, password;
	cin >> name >> password;
	bool flag = m_agendaService.userLogIn(name, password);
	if (flag) {
		m_userName = name;
		m_userPassword = password;
		cout << "[登录] 登录成功!\n";

		cout << "-------------------Agenda-----------------------" << endl;
		cout << "操作 : \n";
		cout << "o     - 退出当前账户\n";
		cout << "dc    - 删除该账户\n";
		cout << "lu    - 列出应用中所有账户信息\n";
		cout << "cm    - 创建一个新会议\n";
		cout << "la    - 列出当前用户的所有会议\n";
		cout << "las   - 列出当前用户发起的会议\n";
		cout << "lap   - 列出当前用户被邀请参加的会议\n";
		cout << "qm    - 通过会议标题查询会议\n";
		cout << "qt    - 通过时间间隔查询会议\n";
		cout << "dm    - 通过会议标题删除会议\n";
		cout << "da    - 删除当前用户所发起的会议\n";
		cout << "mp    - 修改密码\n";
		cout << "mph   - 修改手机号\n";
		cout << "------------------------------------------------\n";
		cout << "\n\n";
    cout << "Agenda@" << m_userName << ": # ";
		while(executeOperation2(getOperation2()));
		OperationLoop2();
	} else {
		cout << "[错误] 登录失败\n";
    OperationLoop2();
	}
}
void AgendaUI :: userLogIn() {
	cout << endl;
	cout << "[log in] [username] [password]\n";
	cout << "[log in] ";
	string name, password;
	cin >> name >> password;
	bool flag = m_agendaService.userLogIn(name, password);
	if (flag) {
		m_userName = name;
		m_userPassword = password;
		cout << "[log in] succed!\n";

		cout << "-------------------Agenda-----------------------" << endl;
		cout << "Action : \n";
		cout << "o     - log out Agenda\n";
		cout << "dc    - delete Agenda account\n";
		cout << "lu    - list all Agenda user\n";
		cout << "cm    - creat a meeting\n";
		cout << "la    - list all meetings\n";
		cout << "las   - list all sponsor meetings\n";
		cout << "lap   - list all participate meetings\n";
		cout << "qm    - query meeting by title\n";
		cout << "qt    - query meeting by time interval\n";
		cout << "dm    - delete meeting by title\n";
		cout << "da    - delte all meetings\n";
		cout << "mp    - modify password\n";
		cout << "mph   - modify phone\n";
		cout << "------------------------------------------------\n";
		cout << "\n\n";
    cout << "Agenda@" << m_userName << ": # ";
		while(executeOperation(getOperation()));
		OperationLoop();
	} else {
		cout << "[error] log in fail!\n";
    OperationLoop();
	}
}
void AgendaUI :: modify_password2() {
	string str;
	cout << "[新密码] ";
	cin >> str;
	m_agendaService.modify_password(m_userName, str);

	cout << "修改密码成功\n";
OperationLoop2();

}
void AgendaUI :: modify_password() {
	string str;
	cout << "[new password] ";
	cin >> str;
	m_agendaService.modify_password(m_userName, str);

	cout << "modify password succed!\n";
OperationLoop();

}
bool AgendaUI :: modify_phone() {
	string str;
	cout << "[new phone] ";
	cin >> str;
	m_agendaService.modify_phone(m_userName, str);
	cout << "modify phone succed!\n";
		cout << "-------------------Agenda-----------------------" << endl;
		cout << "Action : \n";
		cout << "o     - log out Agenda\n";
		cout << "dc    - delete Agenda account\n";
		cout << "lu    - list all Agenda user\n";
		cout << "cm    - creat a meeting\n";
		cout << "la    - list all meetings\n";
		cout << "las   - list all sponsor meetings\n";
		cout << "lap   - list all participate meetings\n";
		cout << "qm    - query meeting by title\n";
		cout << "qt    - query meeting by time interval\n";
		cout << "dm    - delete meeting by title\n";
		cout << "da    - delte all meetings\n";
		cout << "mp    - modify password\n";
		cout << "mph   - modify phone\n";
		cout << "------------------------------------------------\n";
		cout << "\n\n";
cout << "Agenda@" << m_userName << ": # ";
}
bool AgendaUI :: modify_phone2() {
	string str;
	cout << "[新号码] ";
	cin >> str;
	m_agendaService.modify_phone(m_userName, str);
	cout << "修改手机号码成功\n";
		cout << "-------------------Agenda-----------------------" << endl;
		cout << "操作 : \n";
		cout << "o     - 退出当前账户\n";
		cout << "dc    - 删除该账户\n";
		cout << "lu    - 列出应用中所有账户信息\n";
		cout << "cm    - 创建一个新会议\n";
		cout << "la    - 列出当前用户的所有会议\n";
		cout << "las   - 列出当前用户发起的会议\n";
		cout << "lap   - 列出当前用户被邀请参加的会议\n";
		cout << "qm    - 通过会议标题查询会议\n";
		cout << "qt    - 通过时间间隔查询会议\n";
		cout << "dm    - 通过会议标题删除会议\n";
		cout << "da    - 删除当前用户所发起的会议\n";
		cout << "mp    - 修改密码\n";
		cout << "mph   - 修改手机号\n";
		cout << "------------------------------------------------\n";
		cout << "\n\n";
    cout << "Agenda@" << m_userName << ": # ";
}

// 

string AgendaUI :: getOperation() {
string str;
cin >> str;
return str;
}
string AgendaUI :: getOperation2() {
string str;
cin >> str;
return str;
}

bool AgendaUI :: executeOperation(string t_operation) {
if (t_operation == "o") {
userLogOut();return false;
}
	if (t_operation == "dc") {
    deleteUser();
    return true;
  }
	if (t_operation == "lu") { 
    listAllUsers();
    return true;
  }
	if (t_operation == "cm") {
    createMeeting();
    return true;
  }
if (t_operation == "la") {
  listAllMeetings();
  return true;
}
if (t_operation == "las") {
  listAllSponsorMeetings();
  return true;
}
if (t_operation == "lap") {
  listAllParticipateMeetings();
  return true;
}
if (t_operation == "qm") {
  queryMeetingByTitle();
  return true;
}
if (t_operation == "qt") {
  queryMeetingByTimeInterval();
  return true;
}
if (t_operation == "dm") {
  deleteMeetingByTitle();
  return true;
}
if (t_operation == "da") {
  deleteAllMeetings();
  return true;
}
if (t_operation == "mp") {
	modify_password();
	return true;
}
if (t_operation == "mph") {
	modify_phone();
	return true;
}
else {
  cout << "error!" << endl;
cout << "-------------------Agenda-----------------------" << endl;
    cout << "Action : \n";
    cout << "o     - log out Agenda\n";
    cout << "dc    - delete Agenda account\n";
    cout << "lu    - list all Agenda user\n";
    cout << "cm    - creat a meeting\n";
    cout << "la    - list all meetings\n";
    cout << "las   - list all sponsor meetings\n";
    cout << "lap   - list all participate meetings\n";
    cout << "qm    - query meeting by title\n";
    cout << "qt    - query meeting by time interval\n";
    cout << "dm    - delete meeting by title\n";
    cout << "da    - delte all meetings\n";
    cout << "mp    - modify password\n";
    cout << "mph   - modify phone\n";
    cout << "------------------------------------------------\n";
    cout << "\n\n";
    cout << "Agenda@" << m_userName << ": # ";
}
return true;
}
bool AgendaUI :: executeOperation2(string t_operation) {
if (t_operation == "o") {
userLogOut2();return false;
}
	if (t_operation == "dc") {
    deleteUser2();
    return true;
  }
	if (t_operation == "lu") { 
    listAllUsers2();
    return true;
  }
	if (t_operation == "cm") {
    createMeeting2();
    return true;
  }
if (t_operation == "la") {
  listAllMeetings2();
  return true;
}
if (t_operation == "las") {
  listAllSponsorMeetings2();
  return true;
}
if (t_operation == "lap") {
  listAllParticipateMeetings2();
  return true;
}
if (t_operation == "qm") {
  queryMeetingByTitle2();
  return true;
}
if (t_operation == "qt") {
  queryMeetingByTimeInterval2();
  return true;
}
if (t_operation == "dm") {
  deleteMeetingByTitle2();
  return true;
}
if (t_operation == "da") {
  deleteAllMeetings2();
  return true;
}
if (t_operation == "mp") {
	modify_password2();
	return true;
}
if (t_operation == "mph") {
	modify_phone2();
	return true;
}
else {
  cout << "错误" << endl;
cout << "-------------------Agenda-----------------------" << endl;
		cout << "操作 : \n";
		cout << "o     - 退出当前账户\n";
		cout << "dc    - 删除该账户\n";
		cout << "lu    - 列出应用中所有账户信息\n";
		cout << "cm    - 创建一个新会议\n";
		cout << "la    - 列出当前用户的所有会议\n";
		cout << "las   - 列出当前用户发起的会议\n";
		cout << "lap   - 列出当前用户被邀请参加的会议\n";
		cout << "qm    - 通过会议标题查询会议\n";
		cout << "qt    - 通过时间间隔查询会议\n";
		cout << "dm    - 通过会议标题删除会议\n";
		cout << "da    - 删除当前用户所发起的会议\n";
		cout << "mp    - 修改密码\n";
		cout << "mph   - 修改手机号\n";
		cout << "------------------------------------------------\n";
		cout << "\n\n";
    cout << "Agenda@" << m_userName << ": # ";
}
return true;
}

void AgendaUI :: userRegister() {
	cout << "\n\n";
	cout << "[register] [username] [password] [email] [phone]\n";
	cout << "[register] ";
	string name, password, email, phone;
	cin >> name >> password >> email >> phone;
	bool flag = m_agendaService.userRegister(name, password, email, phone);
	if (flag) {
		m_userName = name;
		m_userPassword = password;
		cout << "[register] succed!" << endl;
		userLogIn();
	} else {
		cout << "[error] register fail!\n";
    OperationLoop();
	}


}

void AgendaUI :: userRegister2() {
	cout << "\n\n";
	cout << "[注册] [用户名] [密码] [邮箱] [手机号]\n";
	cout << "[注册] ";
	string name, password, email, phone;
	cin >> name >> password >> email >> phone;
	bool flag = m_agendaService.userRegister(name, password, email, phone);
	if (flag) {
		m_userName = name;
		m_userPassword = password;
		cout << "[注册] 成功！请登录！" << endl;
		userLogIn2();
	} else {
		cout << "[错误] 注册失败\n";
    OperationLoop2();
	}


}
void AgendaUI :: quitAgenda() {
	m_userPassword = "";
	m_userName = "";
exit(1);
}

void AgendaUI :: userLogOut() {
	OperationLoop();
}
void AgendaUI :: userLogOut2() {
	OperationLoop2();
}
void AgendaUI :: deleteUser2() {
	bool flag = m_agendaService.deleteUser(m_userName, m_userPassword);
	if (flag) {
		cout << endl;
		cout << "[删除用户] 成功！\n";
		OperationLoop2();
	} else {
		cout << endl;
		cout << "错误" << endl;

        cout << "-------------------Agenda-----------------------" << endl;
		cout << "操作 : \n";
		cout << "o     - 退出当前账户\n";
		cout << "dc    - 删除该账户\n";
		cout << "lu    - 列出应用中所有账户信息\n";
		cout << "cm    - 创建一个新会议\n";
		cout << "la    - 列出当前用户的所有会议\n";
		cout << "las   - 列出当前用户发起的会议\n";
		cout << "lap   - 列出当前用户被邀请参加的会议\n";
		cout << "qm    - 通过会议标题查询会议\n";
		cout << "qt    - 通过时间间隔查询会议\n";
		cout << "dm    - 通过会议标题删除会议\n";
		cout << "da    - 删除当前用户所发起的会议\n";
		cout << "mp    - 修改密码\n";
		cout << "mph   - 修改手机号\n";
		cout << "------------------------------------------------\n";
		cout << "\n\n";
    cout << "Agenda@" << m_userName << ": # ";
	}
}
void AgendaUI :: deleteUser() {
	bool flag = m_agendaService.deleteUser(m_userName, m_userPassword);
	if (flag) {
		cout << endl;
		cout << "[delete agenda account] succed!\n";
		OperationLoop();
	} else {
		cout << endl;
		cout << "error!" << endl;

        cout << "-------------------Agenda-----------------------" << endl;
		cout << "Action : \n";
		cout << "o     - log out Agenda\n";
		cout << "dc    - delete Agenda account\n";
		cout << "lu    - list all Agenda user\n";
		cout << "cm    - creat a meeting\n";
		cout << "la    - list all meetings\n";
		cout << "las   - list all sponsor meetings\n";
		cout << "lap   - list all participate meetings\n";
		cout << "qm    - query meeting by title\n";
		cout << "qt    - query meeting by time interval\n";
		cout << "dm    - delete meeting by title\n";
		cout << "da    - delte all meetings\n";
cout << "mp    - modify password\n";
    cout << "mph   - modify phone\n";
		cout << "------------------------------------------------\n";
		cout << "\n\n";
		cout << "Agenda@" << m_userName << ": # ";
	}
}
void AgendaUI :: listAllUsers() {
	list<User>temp = m_agendaService.listAllUsers();
  // cout.setf(ios :: left);
	cout << setiosflags(ios :: left) << setw(15) << "name" << setw(15) << "email" << setw(15) << "phone" << endl;
	while(!temp.empty()) {
cout.setf(ios :: left);
		cout << setiosflags(ios :: left) << setw(15)   << temp.begin() -> getName() << setiosflags(ios :: left) << setw(15) << temp.begin() -> getEmail()
		     << setiosflags(ios :: left) << setw(15)  <<  temp.begin() -> getPhone() << endl;
		temp.pop_front();
	}
cout << "Agenda@" << m_userName << ": # ";
}
void AgendaUI :: listAllUsers2() {
	list<User>temp = m_agendaService.listAllUsers();
  // cout.setf(ios :: left);
	cout << setiosflags(ios :: left) << setw(15) << "姓名" << setw(15) << "邮箱" << setw(15) << "手机号" << endl;
	while(!temp.empty()) {
cout.setf(ios :: left);
		cout << setiosflags(ios :: left) << setw(15)   << temp.begin() -> getName() << setiosflags(ios :: left) << setw(15) << temp.begin() -> getEmail()
		     << setiosflags(ios :: left) << setw(15)  <<  temp.begin() -> getPhone() << endl;
		temp.pop_front();
	}
cout << "Agenda@" << m_userName << ": # ";
}
void AgendaUI :: createMeeting() {
string title, startDate, endDate;
	std::vector<string> participator;
	string temp = "";
	cout << "[creat meeting] [the number of participators]\n";
	int number;
	cout << "[create meeting] ";
	cin >> number;
	for (int i = 1; i <= number; i++) {
		cout << "[create meeting] [please enter the participator " << i << " ]\n";
		cin >> temp;
		participator.push_back(temp);
	}
	cout << "[create meeting] [title] [start time(yyyy-mm-dd/hh:mm)] [end time(yyyy-mm-dd/hh:mm)]\n";
	cout << "[create meeting] ";
	cin >> title >> startDate >> endDate;
bool flag = m_agendaService.createMeeting(m_userName, title, startDate, endDate, participator);
if (flag) {
	cout << "[crete meeting] succed!\n";
  cout << "Agenda@" << m_userName << ": # ";

} else {
	cout << "[create meeting] error!\n";
      cout << "-------------------Agenda-----------------------" << endl;
    cout << "Action : \n";
    cout << "o     - log out Agenda\n";
    cout << "dc    - delete Agenda account\n";
    cout << "lu    - list all Agenda user\n";
    cout << "cm    - creat a meeting\n";
    cout << "la    - list all meetings\n";
    cout << "las   - list all sponsor meetings\n";
    cout << "lap   - list all participate meetings\n";
    cout << "qm    - query meeting by title\n";
    cout << "qt    - query meeting by time interval\n";
    cout << "dm    - delete meeting by title\n";
    cout << "da    - delte all meetings\n";
    cout << "mp    - modify password\n";
    cout << "mph   - modify phone\n";
    cout << "------------------------------------------------\n";
    cout << "\n\n";
    cout << "Agenda@" << m_userName << ": # ";
    string strr;
    cin >> strr;
  executeOperation(strr);
}

}
void AgendaUI :: createMeeting2() {
string title, startDate, endDate;
	std::vector<string> participator;
	string temp = "";
	cout << "[创建会议] [请输入被邀请的用户]\n";
	int number;
	cout << "[创建会议] ";
	cin >> number;
	for (int i = 1; i <= number; i++) {
		cout << "[创建会议] [请输入被邀请人的名字 " << i << " ]\n";
		cin >> temp;
		participator.push_back(temp);
	}
	cout << "[创建会议] [标题] [开始时间(yyyy-mm-dd/hh:mm)] [结束时间(yyyy-mm-dd/hh:mm)]\n";
	cout << "[创建会议] ";
	cin >> title >> startDate >> endDate;
bool flag = m_agendaService.createMeeting(m_userName, title, startDate, endDate, participator);
if (flag) {
	cout << "[创建会议] 成功!\n";
  cout << "Agenda@" << m_userName << ": # ";

} else {
	cout << "[创建会议] 失败！\n";
      cout << "-------------------Agenda-----------------------" << endl;
		cout << "操作 : \n";
		cout << "o     - 退出当前账户\n";
		cout << "dc    - 删除该账户\n";
		cout << "lu    - 列出应用中所有账户信息\n";
		cout << "cm    - 创建一个新会议\n";
		cout << "la    - 列出当前用户的所有会议\n";
		cout << "las   - 列出当前用户发起的会议\n";
		cout << "lap   - 列出当前用户被邀请参加的会议\n";
		cout << "qm    - 通过会议标题查询会议\n";
		cout << "qt    - 通过时间间隔查询会议\n";
		cout << "dm    - 通过会议标题删除会议\n";
		cout << "da    - 删除当前用户所发起的会议\n";
		cout << "mp    - 修改密码\n";
		cout << "mph   - 修改手机号\n";
		cout << "------------------------------------------------\n";
		cout << "\n\n";
    cout << "Agenda@" << m_userName << ": # ";
    string strr;
    cin >> strr;
  executeOperation2(strr);
}

}
void AgendaUI :: listAllMeetings() {
	cout << "[list all meetings]\n\n";
    cout.setf(ios :: left);
	cout << setiosflags(ios :: left) << setw(15) << "title" << setw(15) << setiosflags(ios :: left)  << "sponsor" << setiosflags(ios :: left) << setw(20) << "start time"
	     << setiosflags(ios :: left) << setw(20) << "end time" << setw(20) << setiosflags(ios :: left) <<  "participator" << endl;
	list<Meeting>temp = m_agendaService.listAllMeetings(m_userName);
  // cout << temp.begin() -> getSponsor() << " sponsor\n";//tes
	std::vector<string> :: iterator it;
	while(!temp.empty()) {
  cout.setf(ios :: left);
		cout << setiosflags(ios :: left) << setw(15) << temp.begin() -> getTitle() <<setiosflags(ios :: left) << setw(15) << temp.begin() -> getSponsor()
		     << setiosflags(ios :: left) << setw(20) << Date :: dateToString(temp.begin() -> getStartDate())
		     << setiosflags(ios :: left) << setw(20) << Date :: dateToString(temp.begin() -> getEndDate());
         std::vector<string> get = temp.begin() -> getParticipator();
 for (it = get.begin(); it != get.end(); it++) {
 	cout << (*it) << " ";
 }
 cout << endl;
temp.pop_front();
	}
    cout << endl;
  cout << "Agenda@" << m_userName << ": # ";
}
void AgendaUI :: listAllMeetings2() {
	cout << "[列出所有会议]\n\n";
    cout.setf(ios :: left);
	cout << setiosflags(ios :: left) << setw(20) << "标题" << setw(20) << setiosflags(ios :: left)  << "发起者" << setiosflags(ios :: left) << setw(25) << "开始时间"
	     << setiosflags(ios :: left) << setw(25) << "结束时间" << setw(30) << setiosflags(ios :: left) <<  "参与者" << endl;
	list<Meeting>temp = m_agendaService.listAllMeetings(m_userName);
  // cout << temp.begin() -> getSponsor() << " sponsor\n";//tes
	std::vector<string> :: iterator it;
	while(!temp.empty()) {
  cout.setf(ios :: left);
		cout << setiosflags(ios :: left) << setw(20) << temp.begin() -> getTitle() <<setiosflags(ios :: left) << setw(15) << temp.begin() -> getSponsor()
		     << setiosflags(ios :: left) << setw(20) << Date :: dateToString(temp.begin() -> getStartDate())
		     << setiosflags(ios :: left) << setw(20) << Date :: dateToString(temp.begin() -> getEndDate());
         std::vector<string> get = temp.begin() -> getParticipator();
 for (it = get.begin(); it != get.end(); it++) {
 	cout << (*it) << " ";
 }
 cout << endl;
temp.pop_front();
	}
    cout << endl;
  cout << "Agenda@" << m_userName << ": # ";
}
void AgendaUI :: listAllSponsorMeetings(void) {
	cout << "\n";
	cout << "[list all sponsor meetings]\n";
	cout << endl;
   cout.setf(ios :: left);
cout << setiosflags(ios :: left) << setw(15) << "title" << setw(15) << setiosflags(ios :: left)  << "sponsor" << setiosflags(ios :: left) << setw(20) << "start time"
       << setiosflags(ios :: left) << setw(20) << "end time" << setw(20) << setiosflags(ios :: left) <<  "participator" << endl;
	list<Meeting>temp = m_agendaService.listAllSponsorMeetings(m_userName);
	std::vector<string> :: iterator it;
  while(!temp.empty()) {
  cout.setf(ios :: left);
    cout << setiosflags(ios :: left) << setw(15) << temp.begin() -> getTitle() <<setiosflags(ios :: left) << setw(15) << temp.begin() -> getSponsor()
         << setiosflags(ios :: left) << setw(20) << Date :: dateToString(temp.begin() -> getStartDate())
         << setiosflags(ios :: left) << setw(20) << Date :: dateToString(temp.begin() -> getEndDate());
         std::vector<string> get = temp.begin() -> getParticipator();
 for (it = get.begin(); it != get.end(); it++) {
  cout << (*it) << " ";
 }
 cout << endl;
temp.pop_front();
  }
// 	}
         cout << endl;
  cout << "Agenda@" << m_userName << ": # ";
}
void AgendaUI :: listAllSponsorMeetings2(void) {
	cout << "\n";
	cout << "[列出发起的所有会议]\n";
	cout << endl;
cout << setiosflags(ios :: left) << setw(20) << "标题" << setw(20) << setiosflags(ios :: left)  << "发起者" << setiosflags(ios :: left) << setw(25) << "开始时间"
	     << setiosflags(ios :: left) << setw(25) << "结束时间" << setw(30) << setiosflags(ios :: left) <<  "参与者" << endl;
	list<Meeting>temp = m_agendaService.listAllSponsorMeetings(m_userName);
  // cout << temp.begin() -> getSponsor() << " sponsor\n";//tes
	std::vector<string> :: iterator it;
	while(!temp.empty()) {
  cout.setf(ios :: left);
		cout << setiosflags(ios :: left) << setw(20) << temp.begin() -> getTitle() <<setiosflags(ios :: left) << setw(15) << temp.begin() -> getSponsor()
		     << setiosflags(ios :: left) << setw(20) << Date :: dateToString(temp.begin() -> getStartDate())
		     << setiosflags(ios :: left) << setw(20) << Date :: dateToString(temp.begin() -> getEndDate());
         std::vector<string> get = temp.begin() -> getParticipator();
 for (it = get.begin(); it != get.end(); it++) {
  cout << (*it) << " ";
 }
 cout << endl;
temp.pop_front();
  }
// 	}
         cout << endl;
  cout << "Agenda@" << m_userName << ": # ";
}

void AgendaUI :: listAllParticipateMeetings(void) {
	cout << "\n";
	cout << "[list all participate meetings]\n";
	cout << endl;
     cout.setf(ios :: left);

	cout << setiosflags(ios :: left) << setw(15) << "title" << setw(15) << setiosflags(ios :: left)  << "sponsor" << setiosflags(ios :: left) << setw(20) << "start time"
       << setiosflags(ios :: left) << setw(20) << "end time" << setw(20) << setiosflags(ios :: left) <<  "participator" << endl;
  list<Meeting>temp = m_agendaService.listAllParticipateMeetings(m_userName);
  std::vector<string> :: iterator it;
  while(!temp.empty()) {
  cout.setf(ios :: left);
    cout << setiosflags(ios :: left) << setw(15) << temp.begin() -> getTitle() <<setiosflags(ios :: left) << setw(15) << temp.begin() -> getSponsor()
         << setiosflags(ios :: left) << setw(20) << Date :: dateToString(temp.begin() -> getStartDate())
         << setiosflags(ios :: left) << setw(20) << Date :: dateToString(temp.begin() -> getEndDate());
         std::vector<string> get = temp.begin() -> getParticipator();
 for (it = get.begin(); it != get.end(); it++) {
  cout << (*it) << " ";
 }
 cout << endl;
temp.pop_front();
  }
    cout << endl;
  cout << "Agenda@" << m_userName << ": # ";
}

void AgendaUI :: listAllParticipateMeetings2(void) {
	cout << "\n";
	cout << "[列出所有参与的会议]\n";
	cout << endl;
     cout.setf(ios :: left);

	cout << setiosflags(ios :: left) << setw(20) << "标题" << setw(20) << setiosflags(ios :: left)  << "发起者" << setiosflags(ios :: left) << setw(25) << "开始时间"
	     << setiosflags(ios :: left) << setw(25) << "结束时间" << setw(30) << setiosflags(ios :: left) <<  "参与者" << endl;
  list<Meeting>temp = m_agendaService.listAllParticipateMeetings(m_userName);
  // cout << temp.begin() -> getSponsor() << " sponsor\n";//tes
	std::vector<string> :: iterator it;
	while(!temp.empty()) {
  cout.setf(ios :: left);
		cout << setiosflags(ios :: left) << setw(20) << temp.begin() -> getTitle() <<setiosflags(ios :: left) << setw(15) << temp.begin() -> getSponsor()
		     << setiosflags(ios :: left) << setw(20) << Date :: dateToString(temp.begin() -> getStartDate())
		     << setiosflags(ios :: left) << setw(20) << Date :: dateToString(temp.begin() -> getEndDate());
         std::vector<string> get = temp.begin() -> getParticipator();
 for (it = get.begin(); it != get.end(); it++) {
  cout << (*it) << " ";
 }
 cout << endl;
temp.pop_front();
  }
    cout << endl;
  cout << "Agenda@" << m_userName << ": # ";
}

void AgendaUI :: queryMeetingByTitle(void) {
	cout << endl;
	cout << "[query meeting] [title]:\n";
	cout << "[query meeting] ";
	string title;
	cin >> title;
	list<Meeting>temp = m_agendaService.meetingQuery(m_userName, title);
      cout.setf(ios :: left);
cout << setiosflags(ios :: left) << setw(15) << "title" << setw(15) << setiosflags(ios :: left)  << "sponsor" << setiosflags(ios :: left) << setw(20) << "start time"
       << setiosflags(ios :: left) << setw(20) << "end time" << setw(20) << setiosflags(ios :: left) <<  "participator" << endl;
std::vector<string> :: iterator it;
  while(!temp.empty()) {
  cout.setf(ios :: left);
    cout << setiosflags(ios :: left) << setw(15) << temp.begin() -> getTitle() <<setiosflags(ios :: left) << setw(15) << temp.begin() -> getSponsor()
         << setiosflags(ios :: left) << setw(20) << Date :: dateToString(temp.begin() -> getStartDate())
         << setiosflags(ios :: left) << setw(20) << Date :: dateToString(temp.begin() -> getEndDate());
         std::vector<string> get = temp.begin() -> getParticipator();
 for (it = get.begin(); it != get.end(); it++) {
  cout << (*it) << " ";
 }
 cout << endl;
temp.pop_front();
  }
  cout << endl;
  cout << "Agenda@" << m_userName << ": # ";
}
void AgendaUI :: queryMeetingByTitle2(void) {
	cout << endl;
	cout << "[查询会议] [请输入会议标题]:\n";
	cout << "[查询会议] ";
	string title;
	cin >> title;
	list<Meeting>temp = m_agendaService.meetingQuery(m_userName, title);
      cout.setf(ios :: left);
cout << setiosflags(ios :: left) << setw(20) << "标题" << setw(20) << setiosflags(ios :: left)  << "发起者" << setiosflags(ios :: left) << setw(25) << "开始时间"
	     << setiosflags(ios :: left) << setw(25) << "结束时间" << setw(30) << setiosflags(ios :: left) <<  "参与者" << endl;
	
  // cout << temp.begin() -> getSponsor() << " sponsor\n";//tes
	std::vector<string> :: iterator it;
	while(!temp.empty()) {
  cout.setf(ios :: left);
		cout << setiosflags(ios :: left) << setw(20) << temp.begin() -> getTitle() <<setiosflags(ios :: left) << setw(15) << temp.begin() -> getSponsor()
		     << setiosflags(ios :: left) << setw(20) << Date :: dateToString(temp.begin() -> getStartDate())
		     << setiosflags(ios :: left) << setw(20) << Date :: dateToString(temp.begin() -> getEndDate());
         std::vector<string> get = temp.begin() -> getParticipator();
 for (it = get.begin(); it != get.end(); it++) {
  cout << (*it) << " ";
 }
 cout << endl;
temp.pop_front();
  }
  cout << endl;
  cout << "Agenda@" << m_userName << ": # ";
}

void AgendaUI :: queryMeetingByTimeInterval(void) {
	cout << endl;
	cout << "[qurey meetings] [[start time(yyyy-mm-dd/hh:mm)] [end time(yyyy-mm-dd/hh:mm)]" << endl;
	string start, end;
	cout << "[qurey meetings] ";
	cin >> start >> end;
	cout << "[query meetings]\n";
	cout << endl;
	list<Meeting>temp = m_agendaService.meetingQuery(m_userName,start, end);
   cout.setf(ios :: left);
cout << setiosflags(ios :: left) << setw(15) << "title" << setw(15) << setiosflags(ios :: left)  << "sponsor" << setiosflags(ios :: left) << setw(20) << "start time"
       << setiosflags(ios :: left) << setw(20) << "end time" << setw(20) << setiosflags(ios :: left) <<  "participator" << endl;
  std::vector<string> :: iterator it;
  while(!temp.empty()) {
  cout.setf(ios :: left);
    cout << setiosflags(ios :: left) << setw(15) << temp.begin() -> getTitle() <<setiosflags(ios :: left) << setw(15) << temp.begin() -> getSponsor()
         << setiosflags(ios :: left) << setw(20) << Date :: dateToString(temp.begin() -> getStartDate())
         << setiosflags(ios :: left) << setw(20) << Date :: dateToString(temp.begin() -> getEndDate());
         std::vector<string> get = temp.begin() -> getParticipator();
 for (it = get.begin(); it != get.end(); it++) {
  cout << (*it) << " ";
 }
 cout << endl;
temp.pop_front();
  }
  cout << endl;
//        }
  cout << "Agenda@" << m_userName << ": # ";
}
void AgendaUI :: queryMeetingByTimeInterval2(void) {
	cout << endl;
	cout << "[查询会议 请输入时间段] [开始(yyyy-mm-dd/hh:mm)] [结束(yyyy-mm-dd/hh:mm)]" << endl;
	string start, end;
	cout << "[查询会议] ";
	cin >> start >> end;
	cout << "[查询会议]\n";
	cout << endl;
	 list<Meeting>temp = m_agendaService.meetingQuery(m_userName,start, end);
   cout.setf(ios :: left);
cout << setiosflags(ios :: left) << setw(20) << "标题" << setw(20) << setiosflags(ios :: left)  << "发起者" << setiosflags(ios :: left) << setw(25) << "开始时间"
	     << setiosflags(ios :: left) << setw(25) << "结束时间" << setw(30) << setiosflags(ios :: left) <<  "参与者" << endl;

  // cout << temp.begin() -> getSponsor() << " sponsor\n";//tes
	std::vector<string> :: iterator it;
	while(!temp.empty()) {
  cout.setf(ios :: left);
		cout << setiosflags(ios :: left) << setw(20) << temp.begin() -> getTitle() <<setiosflags(ios :: left) << setw(15) << temp.begin() -> getSponsor()
		     << setiosflags(ios :: left) << setw(20) << Date :: dateToString(temp.begin() -> getStartDate())
		     << setiosflags(ios :: left) << setw(20) << Date :: dateToString(temp.begin() -> getEndDate());
         std::vector<string> get = temp.begin() -> getParticipator();
 for (it = get.begin(); it != get.end(); it++) {
  cout << (*it) << " ";
 }
 cout << endl;
temp.pop_front();
  }
  cout << endl;
//        }
  cout << "Agenda@" << m_userName << ": # ";
}
void AgendaUI :: deleteMeetingByTitle(void) {
	cout << endl;
	cout << "[delte meeting] [title]" << endl;
	cout << "[delte meeting] ";
	string title;
	cin >> title;
	bool flag = m_agendaService.deleteMeeting(m_userName, title);
	if (flag) {
		cout << "[delte meeting by title] succed!\n";
    cout << "Agenda@" << m_userName << ": # ";
	} else {
		cout << "[error] delete meeting fail!\n";
    cout << "Agenda@" << m_userName << ": # ";
	}
}
void AgendaUI :: deleteMeetingByTitle2(void) {
	cout << endl;
	cout << "[删除会议] [请输入会议标题]" << endl;
	cout << "[删除会议] ";
	string title;
	cin >> title;
	bool flag = m_agendaService.deleteMeeting(m_userName, title);
	if (flag) {
		cout << "[删除会议] 成功!\n";
    cout << "Agenda@" << m_userName << ": # ";
	} else {
		cout << "[错误] 操作失败!\n";
    cout << "Agenda@" << m_userName << ": # ";
	}
}
void AgendaUI :: deleteAllMeetings(void) {
	cout << endl;
	bool flag = m_agendaService.deleteAllMeetings(m_userName);
	if (flag) {
	cout << "[delete all meetings] succed!\n";
  cout << "Agenda@" << m_userName << ": # ";
} else {
	cout << "[error] delete meeting fail!\n";
  cout << "Agenda@" << m_userName << ": # ";
}
}
void AgendaUI :: deleteAllMeetings2(void) {
	cout << endl;
	bool flag = m_agendaService.deleteAllMeetings(m_userName);
	if (flag) {
	cout << "[删除会议] 成功!\n";
  cout << "Agenda@" << m_userName << ": # ";
} else {
	cout << "[错误] 失败!\n";
  cout << "Agenda@" << m_userName << ": # ";
}
}
void AgendaUI :: printMeetings(std::list<Meeting> temp) {
    cout.setf(ios :: left);
  cout << setiosflags(ios :: left) << setw(15) << "title" << setw(15) << setiosflags(ios :: left)  << "sponsor" << setiosflags(ios :: left) << setw(15) << "start time"
       << setiosflags(ios :: left) << setw(15) << "end time" << setw(15) << setiosflags(ios :: left) <<  "participator" << endl;
	std::vector<string> :: iterator it;
	while(!temp.empty()) {
        cout.setf(ios :: left);
cout << setiosflags(ios :: left) << setw(15) << temp.begin() -> getTitle() <<setiosflags(ios :: left) << setw(15) << temp.begin() -> getSponsor()
		     << setiosflags(ios :: left) << setw(15) << Date :: dateToString(temp.begin() -> getStartDate())
		     <<setiosflags(ios :: left) <<  setw(15) << Date :: dateToString(temp.begin() -> getEndDate());
for (it = temp.begin() -> getParticipator().begin(); it != temp.begin() -> getParticipator().end(); it++) {
	cout << *it << " ";
}
temp.pop_front();
	}
    cout << endl;
  cout << "Agenda@" << m_userName << ": # ";
}
