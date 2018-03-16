#ifndef AGENDAUI_H
#define AGENDAUI_H

#include "AgendaService.hpp"
#include <iostream>
#include <string>

class AgendaUI {
   public:
    AgendaUI();
    void OperationLoop(void);
void OperationLoop2();
   private:
    /**
     * constructor
     */
    void startAgenda(void);

    /**
     * catch user's operation
     * @return the operation
     */
    std::string getOperation();
std::string getOperation2();
    /**
     * execute the operation
     * @return if the operationloop continue
     */
    bool executeOperation(std::string t_operation);

    /**
     * user Login
     */
    void userLogIn(void);

    /**
     * user regist
     */
    void userRegister(void);

    /**
     * quit the Agenda
     */
    void quitAgenda(void);

    /**
     * user logout
     */
    void userLogOut(void);

    /**
     * delete a user from storage
     */
    void deleteUser(void);

    /**
     * list all users from storage
     */
    void listAllUsers(void);

    /**
     * user create a meeting with someone else
     */
    void createMeeting(void);

    /**
     * list all meetings from storage
     */
    void listAllMeetings(void);

    /**
     * list all meetings that this user sponsored
     */
    void listAllSponsorMeetings(void);

    /**
     * list all meetings that this user take part in
     */
    void listAllParticipateMeetings(void);

    /**
     * search meetings by title from storage
     */
    void queryMeetingByTitle(void);

    /**
     * search meetings by timeinterval from storage
     */
    void queryMeetingByTimeInterval(void);

    /**
     * delete meetings by title from storage
     */
    void deleteMeetingByTitle(void);

    /**
     * delete all meetings that this user sponsored
     */
    void deleteAllMeetings(void);

    /**
     * show the meetings in the screen
     */
    void printMeetings(std::list<Meeting> t_meetings);
    // dates

    void modify_password();
    bool modify_phone();

void modify_password2();
bool modify_phone2();



    /**
     * catch user's operation
     * @return the operation
     */


    /**
     * execute the operation
     * @return if the operationloop continue
     */
    bool executeOperation2(std::string t_operation);

    /**
     * user Login
     */
    void userLogIn2(void);

    /**
     * user regist
     */
    void userRegister2(void);

    /**
     * quit the Agenda
     */


    /**
     * user logout
     */
    void userLogOut2(void);

    /**
     * delete a user from storage
     */
    void deleteUser2(void);

    /**
     * list all users from storage
     */
    void listAllUsers2(void);

    /**
     * user create a meeting with someone else
     */
    void createMeeting2(void);

    /**
     * list all meetings from storage
     */
    void listAllMeetings2(void);

    /**
     * list all meetings that this user sponsored
     */
    void listAllSponsorMeetings2(void);

    /**
     * list all meetings that this user take part in
     */
    void listAllParticipateMeetings2(void);

    /**
     * search meetings by title from storage
     */
    void queryMeetingByTitle2(void);

    /**
     * search meetings by timeinterval from storage
     */
    void queryMeetingByTimeInterval2(void);

    /**
     * delete meetings by title from storage
     */
    void deleteMeetingByTitle2(void);

    /**
     * delete all meetings that this user sponsored
     */
    void deleteAllMeetings2(void);
    void find_back2();
    void find_back();
    std::string m_userName;
    std::string m_userPassword;
    AgendaService m_agendaService;
};

#endif
