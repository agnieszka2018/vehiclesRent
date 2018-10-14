//
// Created by pobi on 14.10.18.
//

#ifndef ZAJECIA_2_CLIENT_H
#define ZAJECIA_2_CLIENT_H


class Client {
    std::string firstName;
    std::string lastName;
    std::string personalID;
    Address registeredAddress;
    Address address;

public:

    std::string clientInfo();

    Client(std::string firstName, std::string lastName, std::string personalID);

    ~Client();
};



#endif //ZAJECIA_2_CLIENT_H
