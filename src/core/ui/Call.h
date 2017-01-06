//
// Created by sunyi on 2016/12/22.
//

#pragma once

#include "Function.h"

namespace TCUIEdit { namespace core { namespace ui
{
    //***************************************************************************
    // [TriggerCalls]
    // Defines function calls which may be used as parameter values
    // Key: Function name

    // Value 0: first game version in which this function is valid
    // Value 1: flag (0 or 1) indicating if the call can be used in events
    // Value 2: return type
    // Value 3+: argument types
    //
    // Note: Operators are specially handled by the editor


    class Call : public Function
    {
    protected:
        QString m_eventFlag, m_returnType;
    public:
        Call(package::Package *package, QPair<QString, QStringList> pair);

        ~Call();

        const QString &eventFlag() const;

        void setEventFlag(const QString &eventFlag);

        const QString &returnType() const;

        void setReturnType(const QString &returnType);

        const QString formDisplay() const;

        QString trigData();
    };


}}}


