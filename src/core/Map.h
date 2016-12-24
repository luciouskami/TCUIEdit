//
// Created by liu on 2016/12/4.
//

#pragma once

#include <QMultiHash>
#include <QList>
#include "core.h"
#include "ui/Base.h"
#include "Exception.h"

namespace TCUIEdit { namespace core
{
    class Map
    {
    private:

    protected:
        /**
         * The Map is saved as an unordered_map (hash map)
         */
        QMultiHash<QString, ui::Base *> hashtable;
        //std::unordered_map<std::string, std::list<UIBase *>> map;
    public:
        Map();

        /**
         * Add a UI to the Map
         * @param UI
         */
        void addUI(ui::Base *UI);

        /**
         * Get all UIs of this name from the Map
         * @param name
         * @return a reference to a list with all UIs of this name
         */
        //QList<UIBase *> getUI(QString &name) const;

        QList<ui::Base *> getUI(const QString &name) const;

        /**
         * Remove a UI to the Map
         * @param UI
         */
        void removeUI(ui::Base *UI);
    };
}}



