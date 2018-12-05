//
// Created by pobi on 05.12.18.
//

#ifndef POBIZ01_REPOSITORY_H
#define POBIZ01_REPOSITORY_H

#include <list>
#include <memory>

class Repository;

typedef std::shared_ptr<Repository> RepositoryPtr;

class Repository {
    std::list<RepositoryPtr> repository;

public:
    virtual void create(RepositoryPtr);

    virtual void remove(RepositoryPtr);

    //virtual void update();

    virtual std::list<RepositoryPtr> getAll();

    virtual RepositoryPtr find(int);

    virtual RepositoryPtr operator()(int);
};

#endif //POBIZ01_REPOSITORY_H
