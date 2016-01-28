//
//  NewClass.h
//  CPlusPlusClassSkeleton
//
//  Created by Wahid Tanner on 12/12/15.
//  Copyright © 2015 TakeUpCode. All rights reserved.
//

#pragma once

#include <memory>
#include <string>

namespace NewNamespace
{
    class NewClass
    {
        struct NewClassData
        {
            std::string mName;
            int mAge;
        };

    public:
        NewClass ();
        explicit NewClass (const std::string & name);
        NewClass (const std::string & name, int age);

        NewClass (const NewClass & src);
        NewClass (NewClass && src);

        virtual ~NewClass ();

        NewClass & operator = (const NewClass & rhs);
        NewClass & operator = (NewClass && rhs);

        void swap (NewClass & other);

        std::string name () const;
        void setName (const std::string & name);

        int age () const;
        void setAge (int age);

        std::string toString () const;

        bool operator == (const NewClass & rhs) const;
        bool operator != (const NewClass & rhs) const;

    private:
        std::unique_ptr<NewClassData> mpData;
    };
}
