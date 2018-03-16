#include"AgendaService.hpp"
#include<iostream>
#include<algorithm>
using namespace std;
AgendaService :: AgendaService() {
  startAgenda();
}
AgendaService :: ~AgendaService() {
 quitAgenda();
}
bool AgendaService :: modify_password(const std :: string& userName, const string& new_password) {
  auto filter = [userName] (const User& user){
if (user.getName() == userName)
  return true;
return false;
  };
  m_storage -> modify_password(filter, new_password);
  return true;
}
bool AgendaService :: modify_phone(const std :: string& userName, const string& new_password) {
  auto filter = [userName] (const User& user){
if (user.getName() == userName)
  return true;
return false;
  };
  m_storage -> modify_phone(filter, new_password);
  return true;
}
using namespace std;
bool AgendaService :: find_back(const string &name, const string &phone, const string& email, const string& new_password) {
  auto filter = [name, phone, email] (const User& user) {
    if (name != user.getName())
      return false;
    if (phone != user.getPhone())
      return false;
    if (email != user.getEmail())
      return false;
    return true;
  };
 return (m_storage -> modify_password(filter, new_password));
 
}
bool AgendaService :: userLogIn(const std::string userName, const std::string password) {
auto filter = [userName, password] (const User &user) {
  if (userName == user.getName() && password == user.getPassword())
    return true;
  else return false;
};
list<User> temp = m_storage -> queryUser(filter);
if (temp.size() != 0) {
  return true;
} else return false;
}

bool AgendaService :: userRegister(const std::string userName, const std::string password,
                      const std::string email, const std::string phone) {
  auto filter = [userName, password] (const User &user) {
  if (userName == user.getName() && password == user.getPassword())
    return true;
  else return false;
};
list<User> temp = m_storage -> queryUser(filter);
if (temp.size() != 0) {
  return false;
} else {

  User temp2(userName, password, email, phone);
    m_storage -> createUser(temp2);
    return true;
}
}

bool AgendaService :: deleteUser(const std::string userName, const std::string password) {
auto filter1 = [userName, password] (const User &user) {

  if (userName == user.getName() && password == user.getPassword())
    return true;
  else return false;
};
if (m_storage -> deleteUser(filter1) == 0) {
  return false;
}
auto filter2 = [userName] (const Meeting & meeting) {
if (meeting.getSponsor() == userName)
  return true;
else return false;
};
m_storage -> deleteMeeting(filter2);
auto filter3 = [userName] (const Meeting& meeting3) {
if (meeting3.isParticipator(userName))
return true;
return false;
};
m_storage -> deleteMeeting(filter3);
return true;
}

std::list<User> AgendaService :: listAllUsers(void) const{
  auto filter = [] (const User& user) {
return true;
  };
return m_storage -> queryUser(filter);
}

bool AgendaService :: createMeeting(const std::string userName, const std::string title,
                       const std::string startDate, const std::string endDate,
                       const std::vector<std::string> participator) {
  Date date1(startDate), date2(endDate);
if (!Date :: isValid(date1)) {
 
    // cout << "false1\n";  //test
    return false;
  }
  if (!Date :: isValid(date2)) {

    // cout << "false2\n";
    return false;
  }
  if (date1 >= date2)
    return false;
  // if (participator.size() == 0) {
  //   // cout << "false3\n";
  //   return false;
  // }

  auto filter_par = [participator] (const User& user) {
      std::vector<string> :: const_iterator it = participator.begin();
    for (it; it != participator.end(); it++) {
      if (*it == user.getName())
        return true;
    }
    return false;
  };
  list<User> temp1 = m_storage -> queryUser(filter_par);
  if (temp1.size() != participator.size()) {
    // cout << "false\n"; //test!!!!!!!!!!
    return false;
  }
  auto filter = [title, userName, endDate, startDate, participator] (const Meeting& meeting) {
    if (title == meeting.getTitle())
      return false;
    if (userName == meeting.getSponsor()) {
      // cout << "sponsor\n";
      // if (meeting.getStartDate() >= Date :: stringToDate(startDate) && meeting.getStartDate() <= Date :: stringToDate(endDate)) {
      //   // cout << "11\n";
      //   return false;
      // }
      // if (meeting.getEndDate() > Date :: stringToDate(startDate) && Date :: stringToDate(startDate) >= meeting.getStartDate()) {
      //   // cout << "22\n";
      //   return false;
      // }
      // if (meeting.getStartDate()>= Date :: stringToDate(startDate) && meeting.getEndDate() <= Date :: stringToDate(endDate)) {
      //   // cout << "33\n";
      //   return false; 
      // }
      // if (meeting.getStartDate() <= Date :: stringToDate(startDate) && meeting.getEndDate() > Date :: stringToDate(endDate)) {
      //   return false;
      // }
      // // cout << "true\n";
      // return true;
      if (Date :: stringToDate(endDate) <= meeting.getStartDate())
        return true;
      if (Date :: stringToDate(startDate) >= meeting.getEndDate())
        return true;
      return false;
    }
    std::vector<string> :: const_iterator iter = participator.begin();
    for (iter; iter != participator.end(); iter++) {
      if (meeting.isParticipator(*iter) || (*iter) == meeting.getSponsor()) {
        if (Date :: stringToDate(endDate) <= meeting.getStartDate())
        return true;
      if (Date :: stringToDate(startDate) >= meeting.getEndDate())
        return true;
      return false;
        // cout << "participator\n";
// if (meeting.getStartDate() >= Date :: stringToDate(startDate) && meeting.getStartDate() <= Date :: stringToDate(endDate)) {
//         // cout << "11\n";
//         return false;
//       }
//       if (meeting.getEndDate() > Date :: stringToDate(startDate) && Date :: stringToDate(startDate) >= meeting.getStartDate()) {
//         // cout << "22\n";
//         return false;
//       }
//       if (meeting.getStartDate()>= Date :: stringToDate(startDate) && meeting.getEndDate() <= Date :: stringToDate(endDate)) {
//         // cout << "33\n";
//         return false; 
//       }
//             if (meeting.getStartDate() <= Date :: stringToDate(startDate) && meeting.getEndDate() > Date :: stringToDate(endDate)) {
//         return false;
//       }
      }
    }

    //return false;
    // cout << "true\n";
   //return true;
  };
  auto filter2 = [] (const Meeting& meeting2) {
    return true;
  };
  list<Meeting> fil = m_storage -> queryMeeting(filter);
  list<Meeting> fil2 = m_storage -> queryMeeting(filter2);
if (fil.size() != fil2.size()) {
  // cout << "false4\n";
  return false;
}

Meeting temp(userName, participator, startDate, endDate, title);
m_storage -> createMeeting(temp);
return true;

}

std::list<Meeting> AgendaService :: meetingQuery(const std::string userName,
                                    const std::string title) const {
  auto filter = [userName, title] (const Meeting & meeting) {
if (title != meeting.getTitle()) {
  return false;
}

  if (meeting.getSponsor() == userName)
    return true;
std::vector<string>  :: iterator iter;
std::vector<string> v = meeting.getParticipator();

  if (meeting.isParticipator(userName))
    return true;

  // for (iter = v.begin(); iter != v.end(); iter++) {
  //   if (*iter == userName)
  //     return true;
  // }

return false;
  };
  return m_storage -> queryMeeting(filter);
}

std::list<Meeting> AgendaService :: meetingQuery(const std::string userName,
                                    const std::string startDate,
                                    const std::string endDate) const {

auto filter = [userName, startDate, endDate] (const Meeting &meeting) {
    Date date1(startDate);
    Date date2(endDate);
if (!Date :: isValid(date1))
    return false;
  if (!Date :: isValid(date2))
    return false;
  if (date1 > date2)
    return false;
//
  if (userName == meeting.getSponsor()) {
   // if (meeting.getStartDate() >= Date :: stringToDate(startDate) && meeting.getStartDate() <= Date :: stringToDate(endDate)) {
   //      // cout << "11\n";
   //      return true;
   //    }
   //    if (meeting.getEndDate() >= Date :: stringToDate(startDate) && Date :: stringToDate(startDate) >= meeting.getStartDate()) {
   //      // cout << "22\n";
   //      return true;
   //    }
   //    if (meeting.getStartDate()>= Date :: stringToDate(startDate) && meeting.getEndDate() <= Date :: stringToDate(endDate)) {
   //      // cout << "33\n";
   //      return true; 
   //    }
   //    if (meeting.getStartDate() <= Date :: stringToDate(startDate) && meeting.getEndDate() >= Date :: stringToDate(endDate)) {
   //      return true;
   //    }
    if (Date :: stringToDate(endDate) < meeting.getStartDate())
        return false;
      if (Date :: stringToDate(startDate) > meeting.getEndDate())
        return false;
      return true;
  } else if (meeting.isParticipator(userName)) {
 if (Date :: stringToDate(endDate) < meeting.getStartDate())
        return false;
      if (Date :: stringToDate(startDate) > meeting.getEndDate())
        return false;
      return true;

// if (meeting.getStartDate() >= Date :: stringToDate(startDate) && meeting.getStartDate() <= Date :: stringToDate(endDate)) {
//         // cout << "11\n";
//         return true;
//       }
//       if (meeting.getEndDate() >= Date :: stringToDate(startDate) && Date :: stringToDate(startDate) >= meeting.getStartDate()) {
//         // cout << "22\n";
//         return true;
//       }
//       if (meeting.getStartDate()>= Date :: stringToDate(startDate) && meeting.getEndDate() <= Date :: stringToDate(endDate)) {
//         // cout << "33\n";
//         return true; 
//       }
//       if (meeting.getStartDate() <= Date :: stringToDate(startDate) && meeting.getEndDate() >= Date :: stringToDate(endDate)) {
//         return true;
//       }
  

}
return false;
};
return m_storage -> queryMeeting(filter);
}

std::list<Meeting> AgendaService :: listAllMeetings(const std::string userName) const {
auto filter = [userName] (const Meeting &meeting) {
  if (userName == meeting.getSponsor() || meeting.isParticipator(userName)) //{
    return true;
//   } else {
// // std::vector<string>  :: iterator iter;
// //   for (iter = meeting.getParticipator().begin(); iter != meeting.getParticipator().end(); iter++) {
// //     if (*iter == userName)
// //     return true;
// //   }
// }
return false;
};
return m_storage -> queryMeeting(filter);
}

std::list<Meeting> AgendaService :: listAllSponsorMeetings(const std::string userName) const {
auto filter = [userName] (const Meeting &meeting) {
  if (userName == meeting.getSponsor()) {
    return true;
  }
  return false;
};
return m_storage -> queryMeeting(filter);
}
std::list<Meeting> AgendaService :: listAllParticipateMeetings(
        const std::string userName) const {


auto filter1 = [userName] (const Meeting &meeting) {
  if (meeting.isParticipator(userName)) //{
    return true;
//   } else {
// // std::vector<string>  :: iterator iter;
// //   for (iter = meeting.getParticipator().begin(); iter != meeting.getParticipator().end(); iter++) {
// //     if (*iter == userName)
// //     return true;
// //   }
// }
return false;
};
return m_storage -> queryMeeting(filter1);
}
bool AgendaService :: deleteMeeting(const std::string userName, const std::string title) {
auto filter = [userName, title] (const Meeting& meeting) {
if (title == meeting.getTitle()) {
  if (userName == meeting.getSponsor())
    return true;
}
return false;
};
if (m_storage -> deleteMeeting(filter) == 0)
return false;
return true;
}

bool AgendaService :: deleteAllMeetings(const std::string userName) {
  auto filter = [userName] (const Meeting &meeting) {
if (userName == meeting.getSponsor())
  return true;
return false;
  };
if (m_storage -> deleteMeeting(filter) == 0)
return false;
return true;
}

void AgendaService :: startAgenda() {
m_storage = Storage :: getInstance();
}

void AgendaService :: quitAgenda() {
 m_storage -> sync();

}


