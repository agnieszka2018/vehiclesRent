//
// Created by pobi on 05.12.18.
//

#include "Repository.h"

void Repository::create(RepositoryPtr singleRepo) {

    repository.push_back(singleRepo);
}

void Repository::remove(RepositoryPtr singleRepo) {

    repository.remove(singleRepo);
}

std::list<RepositoryPtr> Repository::getAll() {

    return repository;
}

RepositoryPtr Repository::find(int number) {

    int liczba = 1;

    std::list<RepositoryPtr>::iterator iter;
    for (iter = repository.begin(); iter != repository.end(); iter++) {
        if (liczba == number)
            return (*iter);
        liczba++;
    }
}

RepositoryPtr Repository::operator()(int number) {

    return find(number);
}