//
// Created by pobi on 05.12.18.
//

#ifndef POBIZ01_REPOSITORY_H
#define POBIZ01_REPOSITORY_H

#include <list>
#include <memory>

template<typename T>

class Repository {
    std::list<std::shared_ptr<T>> repository;

public:
    virtual void create(std::shared_ptr<T> singleRepo) {
        repository.push_back(singleRepo);
    }

    virtual void remove(std::shared_ptr<T> singleRepo) {
        repository.remove(singleRepo);
    }

    //virtual void update();

    virtual std::list<std::shared_ptr<T>> getAll() {
        return repository;
    }

    virtual std::shared_ptr<T> find(int number) {

        int liczba = 1;

        typename std::list<std::shared_ptr<T>>::iterator iter;
        for (iter = repository.begin(); iter != repository.end(); iter++) {
            if (liczba == number)
                return (*iter);
            liczba++;
        }
    }

    virtual std::shared_ptr<T> operator()(int number) {
        return find(number);
    }
};

#endif //POBIZ01_REPOSITORY_H
