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
    virtual void create(T singleRepo) = 0;

    virtual void remove(T singleRepo) = 0;

    virtual void update() = 0;

    virtual std::list<T> getAll() = 0;

    virtual T find(int number) = 0;

    virtual T operator()(int) = 0;
};

#endif //POBIZ01_REPOSITORY_H
