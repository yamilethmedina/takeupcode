//
//  NewClass.cpp
//  CPlusPlusClassSkeleton
//
//  Created by Wahid Tanner on 12/12/15.
//  Copyright © 2015 TakeUpCode. All rights reserved.
//

#include "NewClass.h"

using namespace std;
using namespace NewNamespace;

NewClass::NewClass ()
: NewClass("", 0)
{
}

NewClass::NewClass (const std::string & name)
: NewClass(name, 0)
{
}

NewClass::NewClass (const std::string & name, int age)
: mpData(new NewClassData())
{
    mpData->mName = name;
    mpData->mAge = age;
}

NewClass::NewClass (const NewClass & src)
: mpData(new NewClassData())
{
    mpData->mName = src.mpData->mName;
    mpData->mAge = src.mpData->mAge;
}

NewClass::NewClass (NewClass && src)
: mpData(src.mpData.release())
{
}

NewClass::~NewClass ()
{
}

NewClass & NewClass::operator = (const NewClass & rhs)
{
    if (this == &rhs)
    {
        return *this;
    }

    mpData->mName = rhs.mpData->mName;
    mpData->mAge = rhs.mpData->mAge;

    return *this;
}

NewClass & NewClass::operator = (NewClass && rhs)
{
    if (this == &rhs)
    {
        return *this;
    }

    mpData.reset(rhs.mpData.release());

    return *this;
}

void NewClass::swap (NewClass & other)
{
    unique_ptr<NewClassData> thisData(mpData.release());
    unique_ptr<NewClassData> otherData(other.mpData.release());

    mpData.reset(otherData.release());
    other.mpData.reset(thisData.release());
}

string NewClass::name () const
{
    return mpData->mName;
}

void NewClass::setName (const string & name)
{
    mpData->mName = name;
}

int NewClass::age () const
{
    return mpData->mAge;
}

void NewClass::setAge (int age)
{
    mpData->mAge = age;
}

string NewClass::toString () const
{
    return "(" + name() + ": " + to_string(age()) + ")";
}

bool NewClass::operator == (const NewClass & rhs) const
{
    return (mpData->mName == rhs.mpData->mName) &&
        (mpData->mAge == rhs.mpData->mAge);
}

bool NewClass::operator != (const NewClass & rhs) const
{
    return (mpData->mName != rhs.mpData->mName) ||
        (mpData->mAge != rhs.mpData->mAge);
}
