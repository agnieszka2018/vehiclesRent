//
// Created by pobi on 05.12.18.
//

#ifndef POBIZ01_REPOSITORY_H
#define POBIZ01_REPOSITORY_H

#include <list>

template<typename T>

class Repository {
    std::list<T> repository;

public:
    virtual void create(T singleRepo);

    virtual void remove(T singleRepo);

    virtual void update();

    virtual std::list<T> getAll();

    virtual T find(int number);

    virtual T operator()(int);
};

#endif //POBIZ01_REPOSITORY_H
